
# Strings

Strings in C++ are used to store text or sequences of characters. C++ supports both C style strings and strings as a class.


```cpp
#include <iostream>
#include <string>
using namespace std;

//creating a new string using assignment
string greeting1 = "Hello ";

//Creating a new string using the constructor
string greeeting2("World");
```


There are various cons of using C-style strings:

- If allocated on the stack, it will always occupy a size you specify (a character occupies a byte assuming a byte is 8 bits long) no matter how long the text it contains is.
- If allocated on the heap (using malloc()) or on the Free Store (new char[]) you're responsible for releasing the memory afterwards and you will always have the overhead of a heap allocation. 
- If you copy a text of more than 256 chars into the array, it might crash, produce ugly assertion messages or cause unexplainable (mis-)behavior somewhere else in your program.
- To determine the text's length, the array has to be scanned, character by character, for a \\0 character. 
- You need to check and handle oversized strings yourself else the code will be unsafe (looking at you `strcpy`).

Pros of using C style strings:

- If it is a string literal, it is best to define it as a C style string since allocation on stack is much faster than heap.
- It will certainly be faster lookup wise and memory wise.

There are issues with `std::string` as well:

- Two distinct STL string instances can not share the same underlying buffer. So if we pass a string by value you will always get a new copy - there is some performance penalty.
- Slower overall than stack allocated strings.

However, the benefits are much more:

- Short strings of size 16 bytes (assuming 8 bits) or less are stored on the stack for faster access and less fragmentation of heap (or the Free Store).
- They can contain embedded '\\0' characters.
- `string.size()` (or `string.length()`) have constant time complexity, unlike `strlen()`.
- Appending and inserting characters and text have linear time complexity with the object being added in contrast to strcat being linear in both the array being added to and the array being added.
- A `const` qualified string is hardcoded in memory. So it has zero runtime cost. But be aware while using it as it can literally be read through the binary data.


```cpp
// declare greeting 
string greeting = "aeblablo"

//accessing individual characters of a string
cout << greeting1[1] << " is 'e'" << endl;

//Length of the string
cout << greeting.length() << endl;

//substring from the starting index for a specified length
// gives "ell" in this case
cout << greeting.substr(1, 3) << endl;

//adding two Strings
greeting = greeting1 + greeting2;
cout << greeting << endl;
//OR 
string second_greeting = greeting1.append(greeting2);
cout << greeting << endl;

//find a given substring in the string, starting from the given index
string.find(substring, index)
```
> In the above program, instead of `greeting1.length()`, we could also have used `greeting1.size()` as both are synonymous.

> A special example: converting an `std::string` to a C style heap allocated string. `const char *myStringChars = myString.c_str();`


# Arrays

Arrays are uniform aggregates of one type. Declaration occurs as follows:

```cpp
int main(){
    char arr[length];
    int nums[] = {4, 53, 5, 553, 3}
    nums[1] = 2  \\ but length can’t be changed
    int nums[10] = {2, 3} \\ till 10th index; last 8 would be 0
    nums[9] = 5
    cout << nums[15]; \\ leads to segmentation fault, core dumped
    int bruh[] = {4, 53, 5, 553, 3}
    bruh[1] = 2  \\ but length can’t be changed
    int bruh[10] = {2, 3} \\ till 10th index; last 8 would be 0
    bruh[9] = 5
    int bruh[15]; \\ leads to an error
}
```

Similar to this 2D arrays can be declared as well.

The values for an array are only set to 0 if the length of the array is known at compile-time. If not, the values are garbage values (that may or may not be 0).
