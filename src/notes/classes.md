# classes

Classes are nothing but a collection of variables and member functions that are also called methods.

Memory-wise the layout is the same as that of a C struct. Only the variables are stored in the class unless it has virtual member functions or inheritance.

> NOTE:
> Memory wise functions are still stored in the code section of the binary. They also take an implicit argument to `this`, the current pointer to the object, unless made `static`.

## Access specifiers

A class has access specifiers such as public, private and protected.

- `public`: accessible by anyone.

- `private`: accessible only by the member functions of the class.

- `protected`: accessible by classes inheriting it and current class.

## Inheritance

When you inherit from a class, you get all the properties of that class. There are three types of inheritances:

- `public`: All the public stuff in base class is public in derived class, and all the protected stuff is still protected.

- `protected`: All the public and protected stuff become protected.

- `private`: All the public and protected stuff become private.

> NOTE:
> Memory of the base class variables still exist there. You just can't access them without haxx. The compiler cries if you try to access them like a sane human being.

### Virtual functions

If you have a base pointer to the derived class, and you call a method that is common to both the base class and the derived class, you will be calling the function of the base class and not the derived class.
This is because at compile time, the compiler sees the type of the pointer as base and thinks that the object must also be base class type.

To resolve such issues, we use the `virtual` keyword for a method. This makes the function dispatch runtime, also known as *late method binding*.

Once a base class function is marked virtual, all the derived classes, no matter how deep the inheritance is, are also virtual implicitly.

#### How it works

The compiler adds a pointer to each object that points to the vtable of functions. The table is called **virtual table**, and the pointer is called **virtual pointer**. During runtime the binary reads the virtual pointer, goes to the virtual table, and checks the function to be executed.

> Rust has something equivalent for traits called `dyn`.
