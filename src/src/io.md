
# IO

`iostream` is the header file responsible for input and output. `std` is the namespace for `cout` object which is **normally** connected to the screen. `<<` is the _stream insertion operator_. `endl` is equivalent to `"\n" << flush`. What this basically means is that a newline escape character is inserted into the stream and the output that was buffered in the memory was expelled onto the the screen.



> C++ buffers it because printing is an expensive task for memory and CPU. 

