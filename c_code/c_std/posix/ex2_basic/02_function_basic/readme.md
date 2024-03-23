## How to check the symbol table after compilation in C:

1. Compilation:
---------------
	Compile each file separately with the -c flag to create object files:

	gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow main.c add.c mul.c

2. Checking the symbol table:
-----------------------------
	Use the nm command to display the symbol table of each object file:

	nm main.o
	nm add.o
	nm mul.o

3. Interpretation:
------------------
	T - global variables and functions
	U - functions not defined in this file
	D - static variables

Example:
--------
	$ nm main.o

		U add
		U mul
		...
		T main

4. References:
--------------
	man nm: https://linux.die.net/man/1/nm



## Checking the symbol table

After compiling the files `main.c`, `add.c` and `mul.c` with the `-c` flag, 
you can check the symbol table of each object file 
using the `nm` command.

**Commands:**

nm main.o
nm add.o
nm mul.o


**Interpretation:**

* `T` - global variables and functions
* `U` - functions not defined in this file
* `D` - static variables

**Additional information:**

* [man nm](https://linux.die.net/man/1/nm)

**Link to this file:**

* [README.md](https://github.com/morrisel/c-code/tree/main/c_code/c_std/posix/ex2_basic/02_function_basic/readme.md)
