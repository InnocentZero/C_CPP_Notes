# references

C++11 introduced 5 types of objects; **lvalues, rvalues, glvalues, prvalues, xvalues**.

- An _lvalue_ is a regular variable. That's it. A regular variable.
- A _prvalue_ is a literal value.

```cpp
int x = 5;
//here x is an lvalue and 5 is a prvalue
```

- An _xvalue_ is an expiring value. Particularly those that are returned from a function. They were _lvalues_ initially but are going to run out of scope soon. So their contents can be **moved** safely. What does **move** mean here?

It means that the contents can now be safely renamed to something else because the previous name will soon not be valid.

```cpp
int b(int x){
    int y = x*x;
    return y;
    //over here y is an lvalue that is soon going to go out of scope. So internally, its memory need not be copied. Internally the value that is binding to the return value can simply be optimised to refer to the original memory since it is the sole owner of the memory.
}

int main(){
    int z = 0;
    int k = b(z);
    //over here, k will simply start pointing to the original memory owned by y inside the function b; we say that the resource has moved from y inside the function to k outside the function.
}
```

- A _glvalue_ is either an _lvalue_ or an _xvalue_.
- An _rvalue_ is either a _prvalue_ or an _xvalue_.

An **rvalue's** resources can be moved safely.

## lvalue references

An `lvalue` reference can be thought of as an _alias_ to the variable, an alternate name.

```cpp
int x = 5;
int &y = x;

cout << (&y == &x ? "true": "false") << '\n';
//returns true because both the values point to the same location

y = 6;
cout << x << '\n';
// will print 6;
```

Also read [cv-qualifiers](./cv_qualifiers.md).

Lvalues reference can't bind to an rvalue or a const-lvalue. A reference to a const lvalue, however, can.

```cpp
int &x = 5; //error
const int &x = 5; //ok, but x cannot be modified
const int v= 2;
const int &l = v; //ok, but l cannot be modified
```

### Pass by reference in functions

Take the function `void sqr(int x)`. Suppose it does

```cpp
void sqr(int x){
    x = x*x;
}
```

For very obvious reasons it won't work. The assignment is in local scope, and the variable is **copied** into the scope of the function before anything else is done.

In C, we solved this problem using pointers. In C++, we can instead pass the reference to `x`.

```cpp
void sqr(int &x){
    x = x*x;
}
```

Now the function will work as expected.

### Return by reference and Dangling references

When the object being referenced to is destroyed before its reference, it is called a **dangling reference**.

Suppose the function signature is this:

```cpp
int & ret(int &x){
    int y = x; // copy of x being formed
    return y;
}
```

This is clearly problematic. By the time the function's return binds to something, the object it is referring to is already destroyed. This is an example of a dangling reference. This is also true for _prvalues_.

If however, the return type was a `const int&` and the variable being returned was static, then it will work.

```cpp
const int & ret (int &x){
    const static int y = x; // static copy formed
    return y; // ok, object exists till the end of the program lifetime
}
```

> This happens because a static object is created at the beginning of the program and stays in memory till the end of the program.

It would work, in theory, to bind a const reference to a non-const static variable. However, the results can be unpredictable so it isn't advised.

Eg.

```cpp
const int & fun(){
    static int y = 0;
    y++;
    return y;
}

int main(){
    const int& id = fun();
    const int& id1 = fun();
    cout << id << id1 << '\n'; // prints 22 instead of the expected 12
}
```

Instead, we can bind it with a regular variable so that a copy is made.

It is perfectly ok to return a reference to a pass-by-reference parameter, since the object will continue to exist even after the function scope ends.
