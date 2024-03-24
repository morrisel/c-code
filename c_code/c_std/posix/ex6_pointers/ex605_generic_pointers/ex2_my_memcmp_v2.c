/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_my_memcmp_v2.c */
/* gcc ex2_my_memcmp_v2.o -o program -lm */
#include <stdio.h>
#include <string.h>

int my_memcmp_v2(const void *left, const void *right, size_t sz);

int main(void)
{
	int arr1[] = {10,20,30,40};
	int arr2[] = {10,20,30,40};
	int arr3[] = {55,10,20,30,40,66};
	int arr4[] = {10,20,30,11};

	printf("arr1 <=> arr2: %d\n", my_memcmp_v2(arr1, arr2, 4));
	printf("arr1 <=> arr2: %d\n", my_memcmp_v2(arr1, arr2, sizeof(arr1)));
	printf("arr1 <=> arr3: %d\n", my_memcmp_v2(arr1, arr3, sizeof(arr1)));
	printf("arr1 <=> arr4: %d\n", my_memcmp_v2(arr1, arr4, sizeof(arr1)));
	printf("arr2 <=> arr3: %d\n", my_memcmp_v2(arr2, arr3, sizeof(arr1)));
	printf("arr2 <=> arr4: %d\n", my_memcmp_v2(arr2, arr4, sizeof(arr1)));
	printf("arr3 <=> arr4: %d\n", my_memcmp_v2(arr3, arr4, sizeof(arr3)));

	return 0;
}

int my_memcmp_v2(const void *left, const void *right, size_t sz)
{
	const char *c1 = (const char *)left;
	const char *c2 = (const char *)right;

	size_t i;
	for (i=0; i<sz; ++i)
	{
		if (c1[i] < c2[i])
			return -1;

		if (c1[i] > c2[i])
			return +1;
	}

	return 0;
}

/*
 * :%s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :%s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :%17s#// \(.*\)#/ * \1 * /
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * =================================================================================== */
