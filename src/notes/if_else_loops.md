
## `if-else`


```cpp
if(expr){statements}
else{statements}
```



Multiple `if-else` can be chained together. 

```cpp
if(expr){statements}
else if(expr){statements}
else if(expr){statements}
```

syntactic sugar for `if else`:  `expr ? output if true : output if false`


> short circuiting: if the first statement in an `&&` structure is false, then the second statement is not evaluated. similarly, if the first statement in an `||` structure is true, the second statement is not evaluated.

> dangling `else`: an `else` is related to the closest `if` unless brackets `{}` are used.

### `switch-case`

only for equality and integers\characters (used as ascii values)

```cpp
scanf("%d",&isd);
switch (isd){
    case 91: printf("india\n"); break;
    case 1: printf("us-canada\n"); break;
    case 61: printf("astralia\n"); break;
    default: printf("india\n"); 
}
```

> Switch case is primarily used for enum types but since enums can be freely typecasted to int we can use that as well.

<div class="epigraph">
<blockquote><p> A computer is like air conditioning - it becomes useless when you open Windows.</p>
<footer>Linus Torvalds</footer></blockquote>
</div>

## Iterators

### For loops


```cpp
int main(){
    int count = 1
    for(int i = 0; i < count; i++){
        printf("%d",i);
    }
}
```

The shortest `for` loop is `for(;;){}` which does nothing.

There can be multiple values and multiple conditions. A for loop can also be written as follows:

```cpp
int main(){
    int stud = 0, NSTUD = 10;
    for(;;){
        if (stud < NSTUD){
            printf("%d",stud);
            stud++;
            continue;
        }
        break;
    }
}
```

Loops can also be nested as usual.

We also have the following syntax for a **for** loop.

```cpp
int v[5] = {1,2,3,4,5};
for (int x: v){ //take x that varies from first value of v to the last value of v
    cout << x;
}

for (int &x: v){ //take them as a reference this time so that values can be modified
    x++;
}
```


### While loops

```cpp
int main(){
    int iterator;
    while (iterator = 0; /*some condition*/){
        //do some shit
        iterator++;
    }
}
```

This can also be written as

```cpp
int main(){
    int iterator = 0;
    while (iterator++ <= 10){
        //do some shit
    }
}
```

This utilises the properties of postincrement operator.

- iterator cannot be declared inside `while`
- `for` and `while` are the same in backend

### Do-while loop

It is possible the while doesn't even execute once. Use do while if the first iteration is known to happen in all scenarios.

```cpp
int main(){
    int iterator = 0;
    do{
        //do some shit
        iterator++;
    } while (iterator != 0);
}
```    

If an equivalent `while` loop would have been written it would have never executed.
