/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_05_is_plaindrome.c */
/* gcc ex4_05_is_plaindrome.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

bool is_palindrome   (int arr[], size_t len);
bool is_palindrome_v2(int arr[], size_t len);

int main(void) {
	int nums1[] = {10, 20, 30, 40, 30, 20, 10};
	const size_t nums1_len = sizeof nums1 / sizeof nums1[0];

	int nums2[] = {10, 20, 30, 40, 35, 20, 10};
	const size_t nums2_len = sizeof nums2 / sizeof nums2[0];

	if (is_palindrome(nums1, nums1_len)) {
		puts("nums1 is a palindrome");
	}
	else {
		puts("nums1 is not a palindrome");
	}

	if (is_palindrome(nums2, nums2_len)) {
		puts("nums2 is a palindrome");
	}
	else {
		puts("nums2 is not a palindrome");
	}

	return 0;
}

bool is_palindrome(int arr[], size_t len) {
	bool result = true;

	for ( size_t left = 0, right = len-1;
			left < right;
			++left, --right 
	    ) {
		if (arr[left] != arr[right])  {
			result = false;
			break;
		}
	}

	return result;
}

bool is_palindrome_v2(int arr[], size_t len) {
	bool result = true;

	for ( size_t    left = 0;
			left < len/2;
			++left
	    ) {
		if (arr[left] != arr[len-1 - left])  {
			result = false;
			break;
		}
	}

	return result;
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
 * =================================================================================== */
