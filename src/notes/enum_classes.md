# enum_classes

Problems with regular enums:

- Two enums cannot have the same name.

```cpp
enum A {
    lmao,
    ass
};
enum B {
    lmao,
    ass
};
```

- Above example, no variable can have the names `lmao` and `ass`.

- Also, two enums of different kinds can be compared (for some reason).

## Enum classes

```cpp
enum class Color {
red, blue, green
};
Color color = Color::blue;
```

We can also specify the underlying type, egg `char` or `int`.

```cpp
enum class Color : char {
    // whatever
}
```
