# rust_notes

## Creating Projects

To create a new project:

```bash
cargo new project
cd project
```

`Cargo.toml` contains and tracks our version info and dependencies. By default the project is set up as a git repo. 

A `main.rs` is already set up in the src repository. 

```bash
cargo run
```
Build and run the project. 

## Using libraries

```rust
use std::io;
```

Includes the `io` library that is used for taking input and output.

## Structure

By default, the `main` function is the one the is executed first. Default Rust style is to indent with four spaces and not a tab. *This is important.* 

## Variables

Declaration of variables occurs as follows:

```rust
fn main() {
    let x = 5;
}
``` 

This is the declaration of an _immutable_ variable. An _immutable_ variable being changed does not compile. All variables are immutable by default. 

To declare a _mutable_ variable (one whose value does not change), we need to use the `mut` keyword after `let`. 

```rust
fn main(){
    let mut x = 5;
    // value of x being changed here.
    x = 6;
}
```

We can use the `let` keyword to redefine a variable. This allows us to change a variable's type, `mut` does not.

```rust
fn main(){
    let x = 5;
    println!({x});
    let x = x + 1;
    println!({x});
}
```

> The previous memory is not being overwritten. Just that `x` now points to a new memory in the storage with the updated value. This creates two blocks of memories that store values, one with the value 5, another with the value 6.

## Constants

Using constants allows you to use hardcoded values in your code. They are always immutable and can be declared globally as well, unlike variables.

> Technically variables can be declared globally but only by the use of `#[unsafe]`.

Unlike variables, the type of constant must be explicitly annotated. Like variables, they can be used to perform minor (extremely limited) calculations. 

## Data Types

### Integers - Signed or Unsigned

| Bit length | Signed | Unsigned |
|:------:|:-----:|:------:|
| 8 | i8 | u8 |
| 16 | i16 | u16 |
| 32 | i32 | u32 |
| 64 | i64 | u64 |
| 128 | i128 | u128 |
| architecture-dependent | isize | usize |

Signed ints are stored as [Two's Complement](https://en.wikipedia.org/wiki/Two%27s_complement).

Integer literals can have `_` in them to make them more readable. They can also be annotated with their type at the last, like `786u16`. They can also be specified to use number bases such as binary (`0b1000`), hexadecimal (`0xa7`), octal (`0o77`), and a single byte representation (`b1`). 

> The single byte representation stores them as u8 behind the scenes.

> Add integer overflow for int Types

### Floating Points

`f32`: 32 bit floating point 
`f64`: 64 bit floating point 

Default is 64 bits. They conform to [IEEE-754 Standards](https://en.wikipedia.org/wiki/IEEE_754)


