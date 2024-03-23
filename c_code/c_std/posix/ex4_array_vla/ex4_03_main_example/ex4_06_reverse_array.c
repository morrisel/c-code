/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_06_reverse_array.c */
/* gcc ex4_06_reverse_array.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

//prints an array
void print_ints(int arr[], size_t len);
//reverses an array in place
void reverse_ints(int arr[], size_t len);

int main(void) {
	int nums1[] = {10, 20, 30, 44};
	const size_t nums1_len = sizeof nums1/sizeof nums1[0];

	printf("before swap: ");
	print_ints(nums1, nums1_len);

	reverse_ints(nums1, nums1_len);

	printf("after  swap: ");
	print_ints(nums1, nums1_len);

	return 0;
}

void reverse_ints(int arr[], size_t len) {
	for ( size_t left = 0, right = len-1;
			left < right;
			++left, --right
	    ) {
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
}

void print_ints(int arr[], size_t len) {
	for (size_t i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	puts("");
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
