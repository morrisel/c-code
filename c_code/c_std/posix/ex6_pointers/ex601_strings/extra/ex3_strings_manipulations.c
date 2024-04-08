/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_strings_manipulations.c */
/* gcc ex3_strings_manipulations.o -o program -lm */
#include <stdio.h>
#include <string.h>

char *truncate_string_from_start_memmove(char *str, size_t n) {
	size_t length = strlen(str);
	size_t newLength = (length > n) ? (length - n) : 0;

	/* Trim the string from the beginning at the n-th value */
	memmove(str, str + n, newLength + 1); /* +1 для включения символа '\0' */

	return str;
}

char *truncate_string_from_start_memcpy(char *str, size_t n) {
	size_t length = strlen(str);
	size_t newLength = (length > n) ? (length - n) : 0;

	/* Trim the string from the beginning at the n-th value */
	memcpy(str, str + n, newLength + 1);

	return str;
}

char *truncate_string_from_start_strncpy(char *str, size_t n) {
	size_t length = strlen(str);
	size_t newLength = (length > n) ? (length - n) : 0;

	/* Trim the string from the beginning at the n-th value */
	strncpy(str, str + n, newLength);

	str[newLength] = '\0';

	return str;
}

char *truncate_string_from_end_memmove(char *str, size_t n) {
	size_t length = strlen(str);
	size_t newLength = (length > n) ? (length - n) : 0;

	/* Trim the string from the beginning at the n-th value */
	memmove(str + newLength, str + length, 1);

	return str;
}

char *truncate_string_from_end_memcpy(char *str, size_t n) {
	size_t length = strlen(str);
	size_t newLength = (length > n) ? (length - n) : 0;

	/* Trim the string from the beginning at the n-th value */
	memcpy(str + newLength, str + length, 1);

	return str;
}

char *truncate_string_from_end_strncpy(char *str, size_t n) {
	size_t length = strlen(str);
	size_t newLength = (length > n) ? (length - n) : 0;

	/* Trim the string from the beginning at the n-th value */
	strncpy(str + newLength, str + length, 1);

	str[newLength] = '\0';

	return str;
}

int main() 
{
	char target[] = "Hello, World!";
	char source[] = "iThis_is_my_name_in_the_d1234bvasdf";
	size_t n = 3;

	printf("target lenght is:  %zu\n", sizeof(target)/sizeof(target[0]));
	printf("source lenght is:  %zu\n", sizeof(source)/sizeof(source[0]));
	printf("n = %ld\n", n);

	puts("");
	puts("Before copying:");
	printf("target is:  %s\n", target);
	printf("source is:  %s\n", source);

	n = 10;
	/* char *src_res = truncate_string_from_end_memmove(source, n); */
	/* char *src_res = truncate_string_from_end_memcpy(source, n); */
	char *src_res = truncate_string_from_end_strncpy(source, n);
	printf("%s\n", src_res);

	puts("");
	puts("After copying:");
	printf("target is:  %s\n", target);
	printf("source is:  %s\n", source);

	puts("");
	return 0;
}
