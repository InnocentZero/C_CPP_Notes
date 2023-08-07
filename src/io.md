
# IO

`iostream` is the header file responsible for input and output. `std` is the namespace for `cout` object which is **normally** connected to the screen. `<<` is the _stream insertion operator_. `endl` is equivalent to `'\n' << flush`. What this basically means is that a newline escape character is inserted into the stream and the output that was buffered in the memory was expelled onto the the screen.



> C++ buffers it because printing is an expensive task for memory and CPU. 

There is another function called `getline` that takes 1 (optionally 2 or 3) arguments. The basic function signature is as follows. It is a part of the `string` header, as opposed to the `iostream` header.

```
getline(istream& stream, str& s, char delim);
```

By default, the stream selected is the default input output stream but it can be a file stream as well.

A simple example:

```cpp
#include <iostream>
#include <string>

int main(){
    string s;
    getline(cin, s, '$'); 
    // takes input from cin, saves it in s and stops when `$` is reached
}
```

There exists another variant that is a method for `cin` (Don't worry about what a method is rn, it'll be covered later).

```cpp
#include <iostream>
#include <string>

int main(){
    string s;
    int MAX_LEN = 6;
    cin.getline(s, MAX_LEN, '$');
    // by default the delimiter is '\n'
}
```

This variant only takes input till the specified length. If the length is crossed the program execution stops. If the length is not specified then the entire input till the delimiter is taken.

