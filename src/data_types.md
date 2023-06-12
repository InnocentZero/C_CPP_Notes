
# Data Types

- `int`: Integer. At least as large as `short`.  Usually 32 bits.
- `short`: Short integer. Usually 16 bits.
- `long`: Long integer. At least as large as `int`.  Usually 32 bits.
- `long long`: Very long integer. At least as large as `long`.  Usually 64 bits.

> All these use [two's complement](https://en.wikipedia.org/wiki/Two%27s_complement).

- `unsigned int`: Unsigned integer. At least as large as `unsigned short`.  Usually 32 bits.
- `unsigned short`: Unsigned short integer. Usually 16 bits.
- `unsigned long`: Unsigned long integer. At least as large as `unsigned int`.  Usually 32 bits.
- `unsigned long long`: Unsigned very long integer. At least as large as `unsigned long`.  Usually 64 bits.

> Same sizes as above; only that the ranges are modified and 2's complement is absent.

- `signed char`: -128 to 127. ASCII characters only. Can actually store upto 32 bits. 
- `unsigned char`: 0 to 255. ASCII characters only. Can actually store upto 32 bits. 

|Escape Sequence|Description|
|:----:|:-----:|
|\\n | moves the cursor to the beginning of the next line|
|\\t | tab |
|\\r | Carraige return. Moves the cursor to the beginning of the line.|
|\\a | Alerts the system bell|
|\\\ | Prints backslash|
|\\&#x22; | Prints double quotes|
|\\f | Goes to the line immediately below the cursor and gives a space|
|\\b | Backspace|
|\\&#39; | single quote|
|\\0 | Null character; denotes end of string|
|\\v | tab but in vertical direction|
|\\? | print a question mark|
|\\117 | Octal code for characters|
|\\x45 | Hexadecimal code for characters |
| \\u20B9 | Unicode |


- `float`: Floating point decimal number. Stores 32 bits.

- `double`: Same as `float` except it stores 64 bits.

- `long double`: Same as `double` except it stores 80 bits.

> `%d` for a `char` prints its ASCII value. If a `char` is defined as 'ABC', `%d` prints (ASCII_A)·256^2^ + (ASCII_B)·256 + (ASCII_C) where ASCII_ is the ascii value for that character. `%c` only accesses the last (or first, depending on whether the processor is little Endian or big Endian) valid byte (i.e. `'C'` in this case). If the char is defined as `'ABCDE'`, only the last (or first, again depending on the processor) valid byte is processed and stored, and `%d` accesses all 4 bytes including the 3 following it, while `%c` works the same.

However, there are fixed width integer types as well. All of them are included in `<cstdint>` header file.

They can be annotated using `uintN_t`, where `N` is the size of the integer. It must be a multiple of 8 to fit exact bytes. 

Examples:
- `uint64_t`
- `int24_t`
- `uint8_t`

They have macro constants as well for maximum and minimum values of some fixed sizes.

- `INT8_MAX`/`INT8_MIN`
- `INT16_MAX`/`INT16_MIN`
- `INT32_MAX`/`INT32_MIN`
- `INT64_MAX`/`INT64_MIN`



<div class="epigraph"><blockquote><p> I made up the term 'object-oriented', and I can tell you I didn't have C++ in mind.</p><footer>
Alan Kay, <cite>OOPSLA '97</cite></footer></blockquote></div>
