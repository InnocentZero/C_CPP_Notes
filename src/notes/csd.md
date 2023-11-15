# csd

> Moore's Law: The number of transistors in a dense integrated circuit doubles every two years.

How to represent a bit (What makes a good bit):

- small and inexpensive
- stable over time
- easy and fast to manipulate

## Using voltage to represent bits

- Ideal bit: 0 and 1
- Real bit using voltage: noise, ranged

- Voltage has a lower limit. 0 V - V<sub>L</sub> is interpreted as a `0`.
- Higher limit; V<sub>H</sub> to 5 V is considered high

- Between that is a forbidden zone.

## transistors

Two types, n type and p type.

![mosfets](./csd/1.png)

N-type acts as a wire when given high voltage at the gate and acts as an open circuit when given a low voltage. P-type works exactly the other way around.

### Logic gates using mosfets

![Acts as a complement/NOT gate](./csd/2.png)

Basically two complementary networks for pull-up and pull-down respectively. Pull up is made from pmos and nmos is used for pull down.

#### Duality

To have the n type equivalent of a p type sub network, do the following:

- If A and B are in parallel in p type ($\bar{A} + \bar{B}$), in n type they will be in series ($\bar{A\cdot B}$).

Also holds the other way.

### Power losses

- Static: $P_{static} = V_{DD} \cdot I_{leakage}$
- Dynamic: $P_{dynamic} = \frac{1}{2}C\cdot \left(V_{DD}\right)^2$.
- Static is due to leakage current, dynamic due to inherent capacitance of the gates.

## Boolean Algebra

### Minterms

- Sum of products of all possible combinations that appear in the input. Eg. $\bar{A}BC + \bar{A}\bar{B}C + AB\bar{C}$
- Each minterm is one particular row in the truth table.
- For any function, find all possible minterms for which the function is true.
- The function is the sum of all those minterms, This is also called _Sum Of Products_ (SOP).
- Since the order of truth table is known, we can represent them as numbers alone. Start with all **FALSE**, then binary increment them.
- A not of any variable is take as a 0, otherwise it is take as a 1. This will give you the row number of that minterm (0 indexed).
- Finally $f = \sum{m\left(n1,n2,\ellipsis\right)}$

### Maxterms

- Exactly the opposite of above, we take the rows that are **FALSE** for the output. For each row, we sum the terms together instead of multiplying them.
- Then we multiply all the sums together. This is called (no shit) _Products Of Sums_ (POS).
- Enumeration is done in the same way as that of SOP. For shorthand notation, use M instead of m.

### Universal gates

- Any boolean function can be written entirely in terms of either one of NAND or NOT gates.

### Boolean Logic simplification

KMaps:

For 4 bits,

|        | AB      | A\~B    | \~A\~B  | \~AB    |
| ------ | ------- | ------- | ------- | ------- |
| CD     | Item2.1 | Item3.1 | Item4.1 | Item5.1 |
| C\~D   | Item2.2 | Item3.2 | Item4.2 | Item5.2 |
| \~C\~D | Item2.3 | Item3.3 | Item4.3 | Item5.3 |
| \~CD   | Item2.3 | Item3.3 | Item4.3 | Item5.3 |

- Circle as big rectangles as possible whose dimensions are powers of two.
- Keep check of wrap arounds.
- Take _don't cares_ in if they increase the size of the block otherwise don't.

## Combinational circuits

### Comparators

- Use NXOR for comparing two numbers.
- If two bits are equal, their NXOR is 1.
- So for equality bitwise NXOR the two numbers.
- If A is greater than B, then there are cases:
  - The first bit of A is greater than the first bit of B. $A_0\bar{B_0}$ will be 1.
  - The first bit is equal and the second bit of A is greater than the second bit of B. $\left(A_0B_0 + \bar{A_0}\bar{B_0}\right)\left(A_1\bar{B_1}\right)$
  - The first two bits are equal and the third bit of A is greater than the third bit of B. We can see that the pattern can be easily extended.

### Decoder

- N:2<sup>N</sup>. Basically creating minterms out of the given bits.

### Encoder

- Given N inputs, out of which only one is active, output its bits. This works properly only if one of the bits is active.
- Use KMaps to make the truth tables for the output lines. Basically check for which numbers the output lines become active and OR them accordingly.

#### Priority encoders

- To resolve the issue of multiple terms being active in an encoder, use _don't care_ conditions in the KMaps.
- Basically we don't care what the output at that instance will be. We can choose it according to our own convenience.

### Multiplexer

- Select one of the N inputs using $\log_2{N}$ selection lines.
- If the inputs are A and B, and the A has to be selected when S is 0, the output is $A\bar{S} + BS$. Logic can similarly be extended for and power of two.
- Treat the selection lines as the bits of the inputs. The first is the least significant and the last is the most significant.

### Adder

- 1 bit half adder:
  - Sum = A XOR B
  - Carry out = A AND B
- bit full adder:
  - Carry out = AB + BC + AC (C is carry in)
  - Sum = A^B^C
  - pass the carry out from the i'th bit to the carry in of the (i+1)'th bit.

## Sequential circuits

> Latches and flip-flops have 10+ transistors per bit.
> SRAM has 6 mosfets/transistors per bit.
> DRAM has 1 transistor + 1 capacitor per cell.
> Non-volatile storage: no transistors. Yay!

### R-S Latches

![R-S latch](./csd/3.png)

- R = 1, S = 1: previous state is held.
- 10 sets Q to 1.
- 01 sets Q to 0.
- 00 is a forbidden state (race condition, infinite toggling)
- Q<sub>NEXT</sub> is S' + RQ

### Gated D Latch

![Gated D latch](./csd/4.png)

When `write-enable` is zero, it holds the previous value. When it is 1, it sets the value of Q equal to D.
