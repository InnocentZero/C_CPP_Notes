# rvalue refs

Introduced on C++11, these are references to rvalues. These exist to extend the object lifetime of an rvalue, say, a function return value.

> Note: `int i = 1; int j = i--;`. Here `i--` is an rvalue.

These are marked with `&&`. An rvalue reference is an object that the caller no longer cares about. It is disposable and so the **ownership** (the ability to destroy the object) goes to the thing it is being bound to.

> NOTE: in case of template parameters and `auto` keyword, `&&` refers to **universal reference** and not rvalue reference.

## move semantics

Usually, with rvalues and rvalue refs, the compiler _moves_ the object rather than copying it. Internally, it means that the storage that was taken up by the object is now being pointed to by the new variable it is bound to. If you want to explicitly move something, we can use `std::move` which is effectively `static_cast<T&&>`. It converts the object to an rvalue reference so that ownership can be moved easily.

- function returns that are local to the function are moved except when they are static.
- When given a parameter as an rvalue ref, it is, **inside the function body**, an lvalue. This is because it is a name and all named things are lvalues.
- This is also true when an rvalue ref is bound to a prvalue. It becomes a named object, and therefore, an lvalue.

```cpp
void fun(int&& x){
    //do something;
}

void fun(int& x){
    //do something
}

int main(){
    int &&ref{5};
    int x = 5;
    fun(x); //calls lvalue ref overload
    fun(ref); //STILL CALLS LVALUE REF overload
    fun(std::move(ref)); //ok, calls rvalue overload
}
```

You can use differing print statements in the above two function overloads to verify.

One major difference between const lvalue refs and rvalue refs is that rvalue refs allow us to modify the temporary and take ownership of it. In case of lvalues it is not possible.
