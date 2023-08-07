
# Functions


`int myfunc(int x); //function prototype / declaration`

```cpp
int myfunc(int a){
    //do some shit
    return val;
}
int main(){
    //do some shit
    int c = myfunc(b);
    //do some shit
}
```


Usually it is a good programming practice to have a header file that contains the definitions of functions used along with a comment gitving its function (pun intended), and a separate file containing the function itself (the function is not redefined unless you put a semicolon at its end).

> Format of a function: `return-value-type function-name(parameter-list);`<br/>Parameter list is a comma separated list of values that have to be taken as input.

We can return `void` from a function that doesn't have to return a value, but just perform operations.

Arrays cannot be returned by a function unless the array is declared globally or passed as a heap allocated pointer.

To take an array as an input, simply pass the pointer to its first element and keep incrementing its pointer to access further elements. However, C performs no checks for illegal access if the pointer crosses the array length. It is a good practice for us to pass pointers to arrays along with their lengths as functions.

## Default arguments for functions

```cpp
int func(int x = 6){
    return 2*x;
}

int main(){
    int y = func(); //gets value 12
    int z = func(7); //gets value 14
}
```

## Pure and Impure functions

Since C++ supports functions, _in theory_, it supports functional programming. In functional programming we have the notion of pure and impure functions. Pure functions are those that do not change the value of anything **except** for the parameters that are passed in them. On the other hand, impure functions are changinge values outside of the function's scope. Do note that passing a pointer and dereferencing it to change its value is also an example of an impure function.



