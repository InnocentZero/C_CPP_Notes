# static_variables_and_functions

## static variables

Initialised at the beginning of the program, before the `main` function is called. Stored in the `data` section of the program if initialised or `bss` if not. Basically shares a location with a global variable.

It cannot be used as a global var. I expected it to work with extern in another function, mostly `main`, but it didn't. Hence it can only be used by the function in the same scope.

Static variables of classes don't have such restrictions and can be used anywhere.

Static is only meant for file linking, for global static to be used in another file use `extern`.


## static functions

Static functions once again follow the same file level linking that variables follow. More precisely, it is available to the same translation unit. So if a file `A.cpp` has an include `B.cpp` and `B.hpp` then the files will be added.

## static methods

These are methods that do not need the existence of an object to be called. They can be called from the class itself, as `Graph::BST()`.

There are some limitations of static methods includes the fact that you cant use the `this` pointer inside the method.

```cpp
#include <iostream>

class init {
public: 
  init();
  static void printo() { std::cout << "hello" << '\n'; }
  ~init();

private:
  int x;
};

int main() { init::printo(); }
```
