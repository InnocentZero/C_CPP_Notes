# static_variables

Initialised at the beginning of the program, before the `main` function is called. Stored in the `data` section of the program if initialised or `bss` if not. Basically shares a location with a global variable.

It cannot be used as a global var. I expected it to work with extern in another function, mostly `main`, but it didn't. Hence it can only be used by the function in the same scope.

Static variables of classes don't have such restrictions and can be used anywhere.

Static is only meant for file linking, for global static to be used in another file use `extern`.
