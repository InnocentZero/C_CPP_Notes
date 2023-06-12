
##	Basic Structure



> `#include <iostream>`: searches only in the main directory.

> `#incude “iostream”` : searches in both the current and the main directory.

`#` indicates to open iostream first and then compile the rest of the code. This is called a <span class="texthighlight">preprocessor directive.</span>

`#define a1 a2`: Preprocessor replaces every instance of a1 with a2 literally. `a1` has to be a valid variable.

> `#define` is a macro as it rewrites portions of the code before compilation.

```cpp
#include <iostream>
#define SQ(x) x*x
int main(void){
    cout << SQ(2*3) << endl;
}
```

The above code will print 11 and not 25 because the compiler interprets it as `2 + 3*2 + 3` instead of `(2+3)*(2+3)`. To solve this use `#define SQ(x) (x)*(x)` or use `SQ((2+3))`.

`#include <climits>` is for including all the limits in the compiler.

```cpp
int main(arguments){
    cout << “Hello World!” << endl; 	
}
```

`main` function is the first one to be called, regardless of the order in which the functions are written. This can be overridden by `#pragma`, another preprocessor directive that works as instructions to the compiler. Some compilers only allow `main` to return an `int`.

