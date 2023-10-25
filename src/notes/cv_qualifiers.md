# cv_qualifiers

**cv_qualifiers**

Any thing that is const, or volatile, or both.

## Top level cv_qualifiers

What is `const int * x`. What is constant here, the pointer or the underlying data? It is the underlying data that is constant, the pointer can change its value to point to any other `const int`.

By extension, `int * const x` will have a pointer which can be dereferenced and the underlying data's value can be changed, but the pointer itself cannot change to point to something else.

Here the second `const` is referred to as the top level cv-qualifier. Because it is a constness on the highest level, the pointer itself.

## References cannot have top level cv-qualifiers

A reference is not an object in itself. It is an _alias_, an alternative name for an object. Therefore there is no such thing as `int & const x`. You cannot change what a reference is an alias for. However `const int & x` is still valid as it is an alias to a `const int`.
