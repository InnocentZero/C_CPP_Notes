# branch_predictors

We can usually fit many operations in one clock cycle. So if all instructions
were independent, we can in theory do like 5 or 6 instructions at once.

There are 2 types of dependencies in software: data dependency and conditional
dependency.

Data dependency happens when you need the result of the previous computation
in the current one. Solution: [pipelining](./cs2600#Processor%20Pipelining).
Interleave the instructions for multiple iterations and it helps a lot.

However, this is all fun and games until the branch condition isn't satisfied.
To prevent this, CPUs have **branch predictors**.

## Mispredicting

If the branch predictor is wrong, several things need to be done:

- All predicted stuff needs to be discarded/aborted. That means the pipeline
  needs to be flushed.
- New computations need to be started.
- Any results that were computed need to be undone. If it cannot be undone, it
  cannot be done speculatively.

## Optimization

> Don't optimise unless you're sure that it'll mot mispredict.

Example 1:

```cpp
if (x || y) do(); else do_else();
```

What we see:

- Either of them is true then proceed.

What compiler sees:

- If x is true do it.
- If x is false:
  - if y is true do it.

This is important because of short circuiting. The compiler will always see it
as two branches **because it doesn't have a choice**.

What doesn't work:

- Temporary variable; the compiler will just remove it in most cases.

What *does* work:

- Change it to `bool(x) + bool(y)` or `bool(x) | bool(y)`.
  - Works great while the compiler doesn't optimise it to logical or.
  - Compilers usually do it only for one of those two.

However, there are pitfalls:

- This does more computation so you need to be sure that the overhead is not
  high.
- Also need to make sure the add unit should be free around that time
  (profiling).
- `||` does less work in general.

Example 2:

sum += cond ? expr1 : expr2;

Branchless implementation:

term\[2\] = { expr2, expr1 };

sum += term\[bool(cond)\];

Improves performance if:

- extra computation is small.
- branch is poorly predicted

Though example 2 is very well optimised by pretty much every compiler out in
existence (atleast ones that matter).

However, **NEVER** do number 2 with functions. If function(s) are inlined, then
you fail spectacularly.
