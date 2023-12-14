# C_notes

Must read: [Brian Jorgensen Hall's blog](https://beej.us/guide/bgc/html/index-wide.html) 


<div class="epigraph"><blockquote><p> C is not a big language, and it is not well served by a big book.</p><footer>
Brian W. Kernighan, Dennis M. Ritchie</footer></blockquote></div>

```c
/* Hello World Program */
#include <stdio.h>

int main(void) { printf("Hello World!\n"); }
```

`#include` is a preprocessor directive.

> How to know what to include?
`man 3 printf`

`main()` is the first function to be executed in a C program.

Compile with `gcc -o hello hello.c`

## Variables

Placeholders for values. Restrictions on names:

- Names can't start with numbers.
- Same for two underscores.
- Same for single underscore and capital A-Z.

### Variable types

- `int`: integer types.
- `float`: floating point types.
- `char`: character type.
- `string`: array of characters.

#### Booleans

Traditionally, `0` is false, and any other value is true. `#include <stdbool.h>` to include a `bool` type.


### Arithmetic

Standard operators. Also, ternary operator. 

Ternary operator is **NOT** flow control. It is an expression that evaluates to something.

Also, there is pre and post decrement. Stir clear of these unless you know what you are doing.

#### Weird Ass comma operators

```c
int x = (1, 2, 3);
/* x is 3 in this case */
```

#### Conditional operators

Standard. `==` means both should be equal for true. Else, it will be false. `!=` is the exact opposite.

`<`, `<=` and `>`, `>=` carry the same meaning as math.

#### Boolean ops

`&&` only of both are true. `||` if atleast one is true. `!` takes the current value and inverts it. They operate on stuff meant to be boolean kinda.

The first two have something called short circuiting. If the first one is false, the second one isn't even evaluated in case of `&&`. Similarly if the first one is true, second one isn't even evaluated in case of `||`.

## Special functions

`printf`: Well, prints stuff. Look up manpage for more info.

`sizeof`: returns the size of anything. It's return type is an unsigned int called `size_t`.

> NOTE: It is compile time to use sizeof

## Control flow

Always remember braces!

### if-else

No surprises here, should work the way you expect it to.

### while

Yeah, same. Can't declare variables in the brackets, so there's that. Else no surprises.

while (*do while this thing is true*)

### for

The below template works pretty much always.

for (initialize things; loop if this is true; do this after each loop)

### Switch case

Always specify when you need a fallthrough.

```c
#include <stdio.h>
int x = 0;

int main() {
  switch (x) {
  case 1:
    printf("1\n");
    break;
  case 2:
    printf("2\n");
    break;
  default:
    printf("any other value\n");
  }
}
```

If break isn't there all the other cases are evaluated unless a break is encountered.

## Functions

If the parentheses in a C function are empty, it means it can take in any number of arguments. To specify no arguments, use `void`.

Arguments are copied. To modify the original thing pass a pointer.

A prototype is the signature that tells the compiler what the function takes in and spits out. Ends with a semicolon.

## Pointers

Hold memory locations. Really, that's all there is to it.

```c
#include <stdio.h>

int main(void)
{
    int i = 10;

    printf("The value of i is %d\n", i);
    printf("And its address is %p\n", (void *)&i);

    // %p expects the argument to be a pointer to void
    // so we cast it to make the compiler happy.
}
```

The address of anything can be obtained with `&` in front of it. To get the value from the address, use `*` in front of it.

> Note on pointer declaration: `int *p, q;` over here only p is a pointer, q is a regular int.

### NULL pointer

This means that the pointer does not point to anything. Dereferencing it causes memory error at best and random behaviour at worst.

### Pointer arithmetic

Integers can be added to pointers and the pointers move forward or backward by those many units. C makes sure that the pointer is incremented by `sizeof(type)` if the pointer is `type *`.

### void pointer

- Can point to anything.
- Cannot be dereferenced.
- No pointer arithmetic.
- sizeof(void *) will most likely crash.


## Arrays

No surprises here either. You cannot have arrays with variable length, (you technically can), and you need to store the value of the length separately.

If you declared an array in the same scope you can check its size using `sizeof(arr)/size(arr[0])`.

Stuff like this also works:

`int a[10] = {0, 11, 22, [5]=55, 66, 77};`

Intermediate values and others are set to be 0. We can leave the size to be blank if we specify all values in the constructor initializer.

Arrays also act as pointers.

```c
int main() {
  int a[10] = {0};
  int *p = a;
  p = &a[0];
}
```

*Always* pass the size of the array as a separate variable.

For multidimensional arrays, you have to pass all the dimensions except for the first one.

### Array and pointer equivalence


`E1[E2] == (*((E1) + (E2)))`


### Strings

Arrays of characters terminated by the null character.

```c
int main() {
  char *s = "Hello world\n";
  char t[] = "Loss pro max\n";
}
```

In the above example, s is *immutable* because it points to a hardcoded place in memory. On the other hand, the array copies the individual bytes from the hardcoded location and is therefore mutable.

`strlen` function returns the length of a null-terminated string and its return type is `size_t`.

`strcpy` makes a copy of the string byte by byte. Notice that doing `t = s` does not exactly copy the string as it only changes t to point to the same hardocded string and is not two different memory locations.

## Structs

Ordered data-type containing various kinds of data fields.

```c
struct car {
    char *name;
    float price;
    int speed;
};

// Now with an initializer! Same field order as in the struct declaration:
struct car saturn = {"Saturn SL/2", 16000.99, 175};

printf("Name:      %s\n", saturn.name);
printf("Price:     %f\n", saturn.price);
printf("Top Speed: %d km\n", saturn.speed);
```

`struct car saturn = {.speed=175, .name="Saturn SL/2"};` something like this can also be done.

Whatever isn't initialized explicitly is initialised to 0 in memory.

Dot to access fields, arrow to access if it is a pointer to a struct.

> Note: Do **NOT** [compare structs directly](https://stackoverflow.com/questions/7179174/why-doesnt-c-provide-struct-comparison). 

## File handling

`FILE *` is a pointer to a file in C. `fprintf` and `fscanf` take the first arguments as the file pointer and the rest is the same as `printf` and `scanf`.

To open a file, use `fopen("file_path", "mode")`. Mode can be r or w (for read or write).

> Note: `fgetc` returns an int. This is because EOF doesn't fit in char.

`fscanf` and `fprintf` take the file pointer as the first argument. `fputc`, `fputs`, `fgetc` and `fgets` take them as the last argument.

### Binary files

Use `fread` and `fwrite` to read and write from files. While writing structs and stuff, serialize your data because of endianness. Append b after the mode to indicate binary data.

`fread` returns the number of bytes read so useful to check if something has ben read or not.

## typedef

Basically creates an alias for an existing type. Scoped. Useful for structs and arrays and pointers.

```c
//  Anonymous struct! It has no name!
//         |
//         v
//      |----|
typedef struct {
    char *name;
    int leg_count, speed;
} animal;                         // <-- new name

//struct animal y;  // ERROR: this no longer works--no such struct!
animal z;           // This works because "animal" is an alias
```

```c
typedef int *intptr;

int a = 10;
intptr x = &a, y = &a;  // "intptr" is type "int*"
```

```c
// Make type five_ints an array of 5 ints
typedef int five_ints[5];

five_ints x = {11, 22, 33, 44, 55};
```
