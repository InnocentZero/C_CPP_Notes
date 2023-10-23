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










> TODO: add references and lvalue, rvalue, xvalue etc.






## Compiler Process

gcc
: GNU C Compiler


    c => preprocessed file => IR => Assembly Language(.s) => .o => Machine Code (0&1)



    $gcc -E file.c #This gives the preprocessed file

    $gcc -S file.c #This produces the assembly file

    $gcc -c file.c #This gives the machine code



`gcc hello.c` compiles the code.

`a.out` or `./a.out` executes the code.











