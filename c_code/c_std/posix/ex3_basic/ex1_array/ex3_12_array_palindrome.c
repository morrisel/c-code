/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_12_array_palindrome.c */
/* gcc ex3_12_array_palindrome.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>		  /* size_t (less lib) */

typedef unsigned long ul;

bool is_array_palindrome(int arr[], size_t len)
{
	bool result = true;
	for (size_t left=0, right=len-1; left<right; ++left, --right)
	{
		if (arr[left] != arr[right])
		{
			return false;
			break;
		}
	}

	return result;
}

int main(void)
{
	int nums1[] = {10, 20, 30, 40, 30, 20, 10};
	int nums2[] = {10, 20, 30, 40, 35, 20, 10};

	const size_t nums1_len = sizeof(nums1) / sizeof(nums1[0]);
	const size_t nums2_len = sizeof(nums2) / sizeof(nums2[0]);

	if(is_array_palindrome(nums1,nums1_len))
	{
		puts("nums1 is a palindrome");
	}
	else
	{
		puts("nums1 is not a palindrome");
	}

	if(is_array_palindrome(nums2,nums2_len))
	{
		puts("nums2 is a palindrome");
	}
	else
	{
		puts("nums2 is not a palindrome");
	}


	puts("");
	return 0;
}


/* Compilation processes:
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
 * ================================================================================================ */
