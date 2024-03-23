/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_memcmp.c */
/* gcc ex5_memcmp.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int my_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *c1=(const char *)s1;
	const char *c2=(const char *)s2;
	for (size_t i=0; i < n; ++i)
	{
		if (c1[i] < c2[i]) return -1;
		if (c1[i] > c2[i]) return +1;
	}

	return 0;
}

const char * int_to_sign(int sign_number)
{
	if (sign_number == 0)
	{
		return "==";
	}
	else if (sign_number > 0)
	{
		return ">";
	}
	else
	{
		return "<";
	}
}

int main(void)
{
	int arr1[] = {10, 20, 30, 40};
	int arr2[] = {10, 20, 30, 40};
	int arr3[] = {55, 10, 20, 30, 40, 66};
	int arr4[] = {10, 20, 30, 11};

	printf("arr1 <=> arr2: %d\n", my_memcmp(arr1, arr2, sizeof(arr1)));
	printf("arr1 <=> arr4: %d\n", my_memcmp(arr1, arr4, sizeof(arr1)));
	printf("arr1 <=> arr4: %d\n", my_memcmp(arr1, arr4, sizeof(arr1)));
	printf("arr1 <=> arr3 from index 1 to index 4:\n");
	printf("arr1 <=> arr3: %d\n", my_memcmp(arr1, arr3 + 1, sizeof(arr1)));

	if (my_memcmp(arr1, arr2, sizeof(arr1)) == 0)
	{
		puts("arr1 equals arr2");
	}
	else
	{
		puts("arr1 not equals arr2");
	}

	int sign;
	sign = my_memcmp(arr1, arr4, sizeof(arr1));
	printf("arr1 %s arr2\n", int_to_sign(sign));

	puts("");
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
