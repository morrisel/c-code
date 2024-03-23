/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_12_pointers.c */
/* gcc ex4_12_pointers.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	//          1000   1004  1008    1012
	int arr[] = {10,    20,   30}; // X

	//arr = arr + 1; //error array is not a pointer by itself

	//int p0 = &arr[0];
	int *p = arr;
	//       ^ array decay into pointer
	*p += 5; // [15, 20, 30]
	//    p0

	//pointer arithmetic:
	p = p + 1; // 15, 20, 30
	//                p0

	//will advance p0 one int size forward in memory
	//it will therefore point to arr[1] address.
	//
	// p0 = p0 + 1;
	// AS IF:
	// p0 = p0 + 1 * 4B
	// (where 4B is 4 bytes. size of int)
	*p += 2;
	// 15, 22, 30
	//         p0

	p = p - 1;
	// 15, 22, 30
	// p0

	//move 4B "left"
	*p += 700;
	//715, 22, 30
	//p0

	p[2] = 333;

	// P[N] --> *(P + N)
	// p[2] -->  *(p + 2) --> *(p + 2 * 4B)
	//
	// p = 1000. p = p + 2 --> 1008
	//
	//a:  1000 1004 1008
	//v:   10   20   30
	//                p

	arr[2] = 331;
	//is the same as
	*(arr + 2) = 331;

	//&*p; --> p;

	//&arr[2];
	//& *(arr + 2)
	//(arr + 2)
	//arr + 2

	return 0;
}
