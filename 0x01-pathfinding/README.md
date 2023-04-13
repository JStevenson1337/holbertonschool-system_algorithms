# 0x01. C - Pathfinding


## Resources
### Read or watch:

- Pathfinding
- Backtracking
- Dijkstra’s Algorithm
- Dijkstra’s Algorithm - Computerphile
- A Star algorithm
- A Star Search Algorithm - Computerphile
- Learning Objectives
- At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

+ General
+ What is pathfinding
+ What are the most common applications of pathfinding
+ What is backtracking, and why you should never use it
+ What is Dijkstra’s algorithm, and what is its main weakness
+ What is A star algorithm, and how it is better than Dijkstra’s
+ Requirements
+ General
+ Allowed editors: vi, vim, emacs
+ All your files will be compiled on Ubuntu 14.04 LTS
+ Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
+ All your files should end with a new line
+ A README.md file, at the root of the folder of the project, is mandatory
+ Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
+ You are not allowed to use global variables
+ No more than 5 functions per file
+ You are allowed to use the standard library
+ In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
+ The prototypes of all your functions should be included in your header file called pathfinding.h
+ Don’t forget to push your header file
All your header files should be include guarded


### Building .a or Static Library

> For this illustration to work, we will need gcc to compile our source code. Suppose we have a bunch of C programming source files — we’ll need to compile the source files into object code. We can achieve that by issuing the gcc command with the -Wall option:
``` gcc -Wall -c *.c ```

> We need to make sure that we’re at the root of the source directory. The -Wall option tells the compiler to print all the warnings it encounters. The asterisk in the *.c argument tells the compiler to compile all the *.c source files. Upon issuing the command above, the compiler will compile the *.c files into corresponding object files. Thus, we get all the required *.o files that we will need to build a library from.

>Next up, we’re going to create a library file from the object code using the ar utility, which is included with [GNU Binutils](https://man7.org/linux/man-pages/man1/ar.1.html):

``` ar -t libfile.a ```

 > The -c option suppresses the errors, the -v option is provided for verbose ..output, and the -q option is for quickly appending the specified files to the archive. If the archive does not exist, then a new archive is created instead. When the ar command executes successfully, we should get a static library file libfile.a. Let’s see what is included inside the libfile.a file:

``` ar -cvq libfile.a *.o ```
> This will list all the object files that are archived into the libfile.a. Later on, when we want to include the library in our programs, we can simply reference the library in the compilation command:

``` gcc -o MyProgram *.o -L path/to/libdir -lfile.a ```
> The -L option is used to specify the library directory. Mind the library filename in the command. We substituted the lib prefix with -l. The MyProgram executable will include the object code of the libfile.a library.

Additional Resources:

## [ranlib(1) — Linux manual page](https://man7.org/linux/man-pages/man1/ranlib.1.html) 

## [ar(1) - Linux man page](https://linux.die.net/man/1/ar)