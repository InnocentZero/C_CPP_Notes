# Pointers, Scoping and References

A pointer is nothing but a block of memory that stores the address of another block of memory. It can be an array, a class, an integer, or even a function.

For a variable of type `T`, `T*` is the  type  `pointer to T`.

```cpp
char p = 'c';

char* ptr = &p;
```

Here, ptr holds the address of c, `&` is the address-of operator. 

## How Pointers work

```cpp
int var = 10;

int *ptr = &var; // A pointer that points to an integer value
*ptr = 20; // dereferencing that pointer gives us access to the underlying value

int **pptr = &ptr; // A pointer that points to an integer pointer
**pptr = 30; // double dereferencing works the same way as single dereferencing
```

## Why pointers are necessary - Scoping Explained

Suppose we have the following block of code:

```cpp
void add(int x, int y) {
x = x + y;
}

int main(){
int a = 10;
int b = 30;
add(a, b);
std::cout << a << '\n';
}
```

You'd expect the output to be `40` right? Wrong! But why though? Enter scoping.

When we write `add(a, b)`, what the compiler internally does is that it creates a copy of the variables `a` and `b` for the use within the function `add`. Now the **scope** of the new variables, now referred to as the *copies* of the original variables is the function block, i.e., the copies exist only temporarily till the function block is being executed. 

Once the function block is over, the copies are discarded. Hence the value of *40* that was asssigned to the *copy* of `a` vanishes, and `a` itself retains the value it had.

This is the scope of a function. There can be self-made scopes too.

```cpp
int main(){
int a = 30;
// uncommenting the below line will be an error. A variable with one name will be declared twice in the same scope
// int a = 40;

{// beginning of a new scope.
int a = 40;
//here variables can be redeclared
}

}
```

Now to access the outer variable `a` in the inner scope you can again use a pointer that points to `a`.

```cpp
int main(){
int a = 30;
int *aptr = &a;

{
int a = 40;// redeclaring a inside
a = 60; // doesn't change the value of the a in outer scope
*aptr = 50; // changes the value of a in outer scope
}

}
```

## Arrays are pointers

Arrays are nothing but pointers with a large range of access.


