# cpp_guidelines

## Commenting

When writing comments, write them as English prose, using proper capitalization, punctuation, etc. Aim to describe what the code is trying to do and why, not how it does it at a micro level.

### File Headers

```cpp
//===-- llvm/Instruction.h - Instruction class definition -------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Instruction class, which is the
/// base class for all of the VM instructions.
///
//===----------------------------------------------------------------------===//
```

The `-*- C++ -*-` string on the first line is there to tell Emacs that the source file is a C++ file, not a C file (Emacs assumes .h files are C files by default).

Next line license.

The `///` are doxygen comments describing the purpose of the files. 

Abstract for the file: first sentence or a paragraph beginning with `\brief`.

### Header Guard

Combination of `#ifndef` and `#define`. This is meant for protecting the linker against including the same function / class / whatever multiple times as it causes error during linking.

> Linker cannot determine which declaration to choose from the multiple definitions present, even if they are the same.

The header file’s guard should be the all-caps path that a user of this header would #include, using ‘_’ instead of path separator and extension marker. For example, the header file llvm/include/llvm/Analysis/Utils/Local.h would be #include-ed as #include `llvm/Analysis/Utils/Local.h`, so its guard is `LLVM_ANALYSIS_UTILS_LOCAL_H`.

#### Classes, methods and global functions

Single line comment explaining the purpose. If non-trivial, use Doxygen comment blocks.

For functions and methods, single line about what it does and a description of edge cases. 

#### Commenting

In general, C++ style comments. (//, ///). C style comments are useful if the comment strictly needs to be inline. Eg. `Object.emitName(/*Prefix=*/nullptr);`


Don't comment out large blocks of code. If extremely necessary, (for instance, to give a debugging example), use `#if 0` and `#endif`. Better than C style comments.


