
## Arithmetic and Comparison

### Arithmetic

- Addition: `a + b`
- Subtraction: `a - b`
- Multiplication: `a*b`
- Division: `a/b`
- Remainder / Modulus: `a%b`

> Multiplication can easily run out of the bounds of the given datatype. So take care while multiplying numbers. 

> Division by zero mostly leads to a fatal error. So take care of b being 0 explicitly.

> Remainder can be negative too if you use the modulus operator. SO take care when you need the remainders according to mathematical logic.

> Syntactic sugar for assignment: `c += 3;` and similar for other arithmetic operations as well. 

<div class ="epigraph"><blockquote><p> Every good work of software starts by scratching a developer’s personal itch.</p>
<footer>Eric S. Raymond, <cite>The Cathedral and the Bazaar</cite></footer></bockquote></div>

<span class="texthighlight">An easy method to reverse a number:</span>

```cpp
int rev_num(int num){
    int revnum = 0;
    while (num != 0){
        revnum = revnum*10 + num%10;
        num = num/10;
    }
}
```
### Logical Operators

`&&` logical and

`||` logical or

`!` logical not

### Bit operators

- `&` : bitwise and, take the logical and of each bit of the number.
- `|` : bitwise or, take the logical or of each bit of the number.
- `^` : bitwise xor, take the logical xor of each bit of the number.

- `x << y` : shift the bits of x y bits to to the left. Equivalent to multiplication by 2.
- `x >> y` : same as above except it shifts to the right. Equivalent to floor division by 2.

> Bit operators are extremely fast. If possible, prefer using them over other arithmetic operators.

<span class="texthighlight">An easy method to swap two numbers without additional variables:</span>


```cpp
#define swap (x, y) {x = x^y; y = x^y; x = x^y};
```

### Increment and Decrement Operators

|Operator | Explanation |
| :---: | :---: |
| `a++` | Use the current value of a in the expression in which it resides, and then increment by 1 |
| `++a` | First increment and then use value |
| `a-\-` ; `-\-a` | Same as above except for decrementing |

### Comparison Operators

|Comparison|Purpose|
|:----:|:----:|
| `a == b` | If the numbers are equal|
| `a != b` | If the numbers are not equal to each other|
| `a <= b` | If a is less than or equal to b|
| `a >= b` | If a is greater than or equal to b|
| `a > b` | If a is greater than b|
| `a < b` | If a is less than b|


