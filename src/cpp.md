# C++

 <div class="epigraph">
<blockquote><p>Programming is not all the same. Normal written languages have different rhythms and idioms, right? Well, so do programming languages. The language called C is all harsh imperatives, almost raw computer-speak. The language called Lisp is like one long, looping sentence, full of subclauses, so long in fact that you usually forget what it was even about in the first place. The language called Erlang is just like it sounds: eccentric and Scandinavian. </p>
<footer>Robin Sloane</footer></blockquote>
</div>


> Any valid C code is for most part also a valid C++ code. Some differences exist and they can be found by comparing [this](https://devdocs.io/cpp/) and [this](https://devdocs.io/c/).

<div class="epigraph">
<blockquote><p>C++ is a horrible language. It's made more horrible by the fact that a lot of substandard programmers use it, to the point where it's much much easier to generate total and utter crap with it. </p>
<footer>Linus Torvalds, <cite>Message to gmane.comp.version-control.git mailing list</cite></footer></blockquote>
</div>








### Variable Declaration

> Variables declared outside of main are global variables.

`data_type var` when the value is not known.

`data_type var = value` when the value is known.

We can also use `typedef`.

`typedef existing_name alias_name;` 

This is better than `#define` as it allows you typecast.

`enum var_type {val_1,val_2,val_3};` : This declares a new enumeration type. The default values are 0, 1, 2 and so on. We can also define variables of the `var_type` using `enum var_type {...} new_var;` or by:

```cpp
enum var_type {val_1,val_2,val_3};
enum var_type var;
```

We can also define our own values using `enum var_type {var1 = 1,var_2 = 2};`.
If in between some values are undefined then their value is set as the previous value + 1.

- enum values must be integer constants or characters.

### Typecasting 

To typecast between two different types we use `static_cast<type_to_be_casted_to>(thing to cast)`. See [this](https://en.cppreference.com/w/cpp/language/static_cast) for examples and when they work.

To typecast a `const` pointer to a non-`const` one use `const_cast`. Piece of advice, never use it.

There is another cast that is used to convert a pointer from one type to another. It is `dynamic_cast`. It performs a runtime check, as opposed to a compile time check in `static_cast`. It returns a `nullptr` in case failing to convert the given pointer.

#### C style casts:

**Explicit:** `(type_name) expression`

**Implicit:** `type_name new_var = expression`

Implicit typecasting also occurs when we perform an operation between a lower level data type and a higher level data type. Eg. int & float, int and long, float and double etc. 

In all of the above examples, the first one gets typecased to the second.


<div class="epigraph">
<blockquote><p> Christ, people. Learn C, instead of just stringing random characters together until it compiles (with warnings).</p>
<footer>Linus Torvalds, <cite>LKM mailing list</cite></footer></blockquote>
</div>


> TODO: add references and lvalue, rvalue, xvalue etc.

## Control Structures

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



### `if-else`


```cpp
if(expr){statements}
else{statements}
```



Multiple `if-else` can be chained together. 

```cpp
if(expr){statements}
else if(expr){statements}
else if(expr){statements}
```

syntactic sugar for `if else`:  `expr ? output if true : output if false`


> short circuiting: if the first statement in an `&&` structure is false, then the second statement is not evaluated. similarly, if the first statement in an `||` structure is true, the second statement is not evaluated.

> dangling `else`: an `else` is related to the closest `if` unless brackets `{}` are used.

### `switch-case`

only for equality and integers\characters (used as ascii values)

```cpp
scanf("%d",&isd);
switch (isd){
    case 91: printf("india\n"); break;
    case 1: printf("us-canada\n"); break;
    case 61: printf("astralia\n"); break;
    default: printf("india\n"); 
}
```


<div class="epigraph">
<blockquote><p> A computer is like air conditioning - it becomes useless when you open Windows.</p>
<footer>Linus Torvalds</footer></blockquote>
</div>

## Iterators

### For loops


```cpp
int main(){
    int count = 1
    for(int i = 0; i < count; i++){
        printf("%d",i);
    }
}
```

The shortest `for` loop is `for(;;){}` which does nothing.

There can be multiple values and multiple conditions. A for loop can also be written as follows:

```cpp
int main(){
    int stud = 0, NSTUD = 10;
    for(;;){
        if (stud < NSTUD){
            printf("%d",stud);
            stud++;
            continue;
        }
        break;
    }
}
```

Loops can also be nested as usual.

We also have the following syntax for a **for** loop.

```cpp
int v[5] = {1,2,3,4,5};
for (int x: v){ //take x that varies from first value of v to the last value of v
    cout << x;
}

for (int &x: v){ //take them as a reference this time so that values can be modified
    x++;
}
```


### While loops

```cpp
int main(){
    int iterator;
    while (iterator = 0; /*some condition*/){
        //do some shit
        iterator++;
    }
}
```

This can also be written as

```cpp
int main(){
    int iterator = 0;
    while (iterator++ <= 10){
        //do some shit
    }
}
```

This utilises the properties of postincrement operator.

- iterator cannot be declared inside `while`
- `for` and `while` are the same in backend

### Do-while loop

It is possible the while doesn't even execute once. Use do while if the first iteration is known to happen in all scenarios.

```cpp
int main(){
    int iterator = 0;
    do{
        //do some shit
        iterator++;
    } while (iterator != 0);
}
```    

If an equivalent `while` loop would have been written it would have never executed.

## Functions


`int myfunc(int x); //function prototype / declaration`

```cpp
int myfunc(int a){
    //do some shit
    return val;
}
int main(){
    //do some shit
    int c = myfunc(b);
    //do some shit
}
```


Usually it is a good programming practice to have a header file that contains the definitions of functions used along with a comment gitving its function (pun intended), and a separate file containing the function itself (the function is not redefined unless you put a semicolon at its end).

> Format of a function: `return-value-type function-name(parameter-list);`<br/>Parameter list is a comma separated list of values that have to be taken as input.

We can return `void` from a function that doesn't have to return a value, but just perform operations.

Arrays cannot be returned by a function unless the array is declared globally or passed as a heap allocated pointer.

To take an array as an input, simply pass the pointer to its first element and keep incrementing its pointer to access further elements. However, C performs no checks for illegal access if the pointer crosses the array length. It is a good practice for us to pass pointers to arrays along with their lengths as functions.





## Compiler Process

gcc
: GNU C Compiler


    c => preprocessed file => IR => Assembly Language(.s) => .o => Machine Code (0&1)



    $gcc -E file.c #This gives the preprocessed file

    $gcc -S file.c #This produces the assembly file

    $gcc -c file.c #This gives the machine code



`gcc hello.c` compiles the code.

`a.out` or `./a.out` executes the code.


----


# C++









## Input:

```C++
string name;

cout << “Enter your name:- ”; \\ Prince Garg



cin >> name;

cout << “your name is ” << name; \\ your name is Prince Garg
```

but with

```
getline(cin, name);

cout << “your name is ” << name; => Prince Garg
```

	functions:-

void FuncName(DataType VarName *if func wants to input any data seperated by comma)   => void means that function won’t return anything

{

	cmd lines to execute

}



int main()   => func executed by default

{

	FuncName(VarValue1, VarValue2);  => calling a function

	return 0;

}



additional functions must be declared before the main func. else error. to bypass need to specify the func. above like:- 



void FuncName(DataTypes Variables);



	Return:-

if function has to return also then

 DataType_to_be_returned function_name()

{

	

}



return function break out of the function any cmd line below it would not be executed



	If:-

if(condition){

	

} else if(condition){   => can be on next line also

	

} else{

	

}



and = &&      => can also write “and”

or = ||

not = !



	Comparison:-

<

>

==

>=

<=

!=



	Switch:-

switch(num){

	case 0:   =>if num==0

	commands

	break;     => else will check on next case 

	

	default:   => if no case matches

	commands

}

	While:-

int index = 1;

while(condition){

	commands

	index ++;

}

	do while:-

do{

	commands

	index++;

}while(condition);



first execute and then check the condition



	For Loop:-

for(create variable; looping condition; command after each iteration){

	commands

}

example-

for(int i = 1 ; i <= 5 ; i++0{

	cout << i <<  endl ;

}



	2D Array:-

int NumGrid[rows][columns] = {

							{1, 2},

							{2, 3},

							{3, 4}

							};

=>(here rows = 3, columns = 2)

similarly n-dimensional arrays



	Comments:-

// this text will be ignored(single line)

/* this

text will also be

ignored */



	Pointers:-

they are just the physical memory address of any variable



int Age = 18;

int *pAge = &Age;



cout << pAge;     => cout << &Age;  => displays the physical address of the variable Age



cout << *pAge   => displays the value of variable Age = 18 => called dereferencing a pointer



Age == *&Age



pAge == &Age



	Classes and Objects:-

a class is basically a new datatype

object is the actual variable that use that datatype



class Book{

	public:

		string name;

		string author;

		int pages;

		

		Book(){



		}



		Book(string aname, .. ){   => Constructors

			string name = aname;

		}

		

		bool MorePages(){  => function named MorePages inside class

			if(pages > 500){

				return true;

			}

			return false

		}

		

};  => creates a book datatype which can store its name, author and no. of pages



Constructors are executed each time the object is created

we can create as many constructors as we want



int main(){

	Book book1;

	book1.name = “Harry Potter”;

	book1.author = “JK Rollings”;

	book1.pages = 400;

			

			OR

	

	Book book1(“Harry Potter”, “JK Rollings”, 400);



	Book book2(“Lord of the rings” , “author” , 700);

	

	//book1.name = “Lord of the Rings”;

	cout << book1.name ;

	

	cout << book1.MorePages();  => calling the function

}



above Class = Book

object = book1



example 2- Setters and Getters



class Movie{

	private :  => cmds underneath can only be accessed inside this class

		string rating;

	public :    => cmds underneath can be accessed from anywhere

		string name;

		string director;



		Movie(string aName, string aDirector, string aRating){

			name = aName;

			director = aDirector;

			setRating(aRating);

		}

		void setRating(string aRating){   => Setter

			if (aRating == “A” || aRating == “B” || aRating == “C” || aRating == “D” || aRating == “E”){

				rating = aRating;

			} else {

				rating = “NR”

			}

		}

		

		string getRating(){

			return rating;

		}

};



	Inheritance:-

class Physics : public Book{  =>physics class can do everything the book class can now

	public :  => can do much more

		string difficulty;

		

		bool MorePages(){  => can also overwrite previously declared functions

			if(pages>300){

				return true;

			}

			return false;

		}

};



convert any datatype to string =>

#include <string>

…

	string str = to_string(num);


