# file_descriptors

On \*nix systems, file descriptors are a number that are given to files that have a stream attached to them. C can directly read and write from file descriptors using the `read()` command that takes a file descriptor, a buffer and a length to be read.

There are different file descriptors for every process. To get the file descriptors for the current process, run `ls -l /proc/$$/fd`.

> `$$` is a substitute for the current process ID. Run `ps` and `echo $$` to compare.

By standard, 0 is standard input, 1 is standard output, and 2 is standard error.
