# concurrency

C++ 11: Threads

- performance improvement 
- asynchronous code

## Memory model

- Kernel threads - independent OS instructions
- OS schedules kernel threads to run on the CPU
- One thread per core at a time

- User threads: what we get from the program
- Usually 1:1 mapping with the kernel threads.
- We can also have N user threads on M kernel threads (N:M model)


User threads: **tasks** executed by **pools** of kernel threads 

`std::thread` is a user thread.

## Problems with threads

Thread overhead - if multiple active kernel threads are computing for much fewer processes. 

Since `std::thread` is user thread, there shouldn't be a problem but since most OS's offer 1:1 thread models, there is. At best, we end up with a badly broken N:M model. A new thread for every computation makes the program slower.

Threads are expensive to start and join. (in 100s of microseconds per thread)

### How to improve perf

Manage threads yourself. Keep them alive for a long time. One thread per core. Give it work once it is done with existing work. Else idle.

## Futures and promises

- `std::async`: execute something eventually.
    - returns a `std::future`

- `std::future`: placeholder for future results
    - asynchronously computed
    - caller can wait (blocking or non-blocking)

- `std::promise`: temp holder for future
    - eventually becomes a future
    - supports **abandon** to take care of exceptions and stuff

- `async` can be done in two ways: serially and concurrently
    - concurrent implementation in most cases: fire up a thread (same problem as `std::thread`)

## Locks

`std::mutex` 

- just forwards the calls to `pthread_mutex_t`
- OS based locking

Very aweful example of a mutex - can lead to a deadlock. Nobody outside of the thread function knows that there is a lock and that has to be freed.


```cpp
int sum = 0;
std::mutex sum_mutex;
void thread_worker(int i) {
sum_mutex.lock();
sum += i;
sum_mutex.unlock();
}
```

`std::lock_guard`: RAII for mutexes

Constructor locks, destructor unlocks

```cpp
void thread_worker(int i) {
std::lock_guard(sum_mutex);
sum += i;
}
```

`std::unique_lock`: moving ownership of the mutex, kinda like `unique_ptr`

- Guaranteed deadlock:

```cpp
std::mutex m;
m.lock(); //thread 1
m.lock(); //thread 2
```

Only thread 1 can unlock the mutex. Thread 2 locking it causes a deadlock since instructions can't move forward. 

If for some reason you have to do that, `std::recursive_mutex` (keeps a reference count).

Interesting scenario of a deadlock.

```cpp
std::mutex m1, m2;
//thread 1
m1.lock();
m2.lock();

//thread 2
m2.lock();
m1.lock();
```

Both are waiting for the other thread to release the lock first. Not happening.

Solution 
- `std::lock(m1, m2, m3, ...)` - guarantees no deadlock.
    - used with `unique_lock` to unlock automatically.
- Alternatively use `std::scoped_lock`
    - `std::lock` is a function, so you still need to manually release them somewhere. `std::scoped lock` wraps the unlock in its destructor.
    ```cpp
    std::scoped_lock l(m1, m2, m3, ...);
    ```

`shared_mutex` - read write lock

Unlike `lock()`, `lock_shared()` only gives you read access. Good in theory, performance not so good in practice. RAII wrapper is `std::shared_lock` for the same. 

### Condition Variables 

- Sync barrier
- paired with a mutex lock

Two threads - producer and consumer

```cpp
std::conditon_variable c;
std::mutex m;

// producer
Data *data = nullptr;
{std::locked_guard l(m); data = new Data;} c.notify_all();

//consumer

std::unique_lock l(m);
c.wait(l, [&]{return bool(data);});
do_work(data);
```

### Function calls

`std::call_once()` & `std::once_flag` to be used in conjunction.

`std::call_once(/* std::once_flag*/ done, []{cout << "running" << endl;});`

- Concurrent calls are safe, only one active call is executed till the end.
- If exception occurs, then call is considered a failure and some other thread will do the call. 
- Passive calls will see the side effect of active calls.

`thread_local` like static but one copy per thread. So the same variable will have multiple addresses.

`std::latch` - synchronization barrier without explicitly joining the thread back to main function. Latches cannot be used multiple times. 

- `std::barrier` is a multi time use latch. Barrier countdown is reset after all threads arrive to an instance.

- `std::counting_semaphore` basically keeps a finite count of the number of acquires that can be had at one time. Other requests are blocked by it. 

Syntax : `std::counting_semaphore<max_num>::release()` for releasing the locks and `std::counting_semaphore<max_num>::acquire()` to acquire a resource.



