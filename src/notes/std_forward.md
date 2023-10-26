# std::forward

Most of the article was inspired from this [brilliant](https://stackoverflow.com/a/3582313) answer from stackoverflow.

## Forwarding

Given an expression `E(a,b,c,d ...)`, each of some templated type, we want `f(a,b,c,d...)` to be equivalent. So nest `E` inside `f`.

This cannot be accomplished by C++03.

- Case 1: you use lvalue refs for `f`. This fails to handle rvalue cases.
- Case 2: const lvalue refs. Now the arguments are rendered unmodifiable for `E`.
- Case 3: The infamous `const_cast`. Can lead to undefined behaviour.
- Case 4: Handle all combinations. Overloads become exponential with the number of parameters.

## What std::forward does

- If `f` got an lvalue ref and `E` needs an lvalue ref, then it obviously works out. Neither of them can take ownership of the object so neither of them will have it.
- If `f` got an rvalue ref and `E` needs an rvalue ref, it still checks out. Both can take ownership, both can have it. This mechanism also makes sure that `E` doesn't receive it as an lvalue, which is what happens with an rvalue ref inside a function block (See [rvalue refernces](./rvalue_refs.md))
- If `f` got an lvalue ref and `E` needs an rvalue ref, it will be given an **lvalue ref**. This is because it cannot be given ownership of the object, since `f` doesn't have it itself.
- If `f` got an rvalue ref and `E` needs an lvalue ref, do we even care? Let it have that, it was going to get lvalue ref without intervention anyways.

This combination is called as **perfect forwarding**.
