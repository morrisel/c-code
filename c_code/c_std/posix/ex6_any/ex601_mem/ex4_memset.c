/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_memset.c */
/* gcc ex4_memset.o -o program -lm */
/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_memset_v2.c */
/* gcc ex4_memset_v2.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>	/*original signature: void *memset(void *s, int c, size_t n); */

#define NEW_LINE puts("");
#define new_line puts("");

/** MEMSET(3)                    Linux Programmer's Manual                    MEMSET(3)
 * 
 * NAME
 *        memset - fill memory with a constant byte
 * 
 * SYNOPSIS
 *        #include <string.h>
 * 
 *        void *memset(void *s, int c, size_t n);
 * 
 * DESCRIPTION
 *        The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
 * 
 * RETURN VALUE
 *        The memset() function returns a pointer to the memory area s.
 * 
 * ATTRIBUTES
 *        For an explanation of the terms used in this section, see attributes(7).
 * 
 *        ┌──────────┬───────────────┬─────────┐
 *        │Interface │ Attribute     │ Value   │
 *        ├──────────┼───────────────┼─────────┤
 *        │memset()  │ Thread safety │ MT-Safe │
 *        └──────────┴───────────────┴─────────┘
 * CONFORMING TO
 *        POSIX.1-2001, POSIX.1-2008, C89, C99, SVr4, 4.3BSD.
 * 
 * SEE ALSO
 *        bstring(3), bzero(3), swab(3), wmemset(3)
 * 
 * COLOPHON
 *        This  page  is  part  of  release  5.05  of  the  Linux  man-pages  project.
 *        A  description  of  the  project, information  about  reporting  bugs,
 *        and  the  latest  version  of  this  page,  can  be  found  at
 *        https://www.kernel.org/doc/man-pages/. */

/* kinds of implementations of my_memset functions adapted on original signature */
void *my_memset_v1(void *ptr, int value, size_t num)
{
	unsigned char *p = ptr;
	for (size_t i=0; i<num; i++)
	{
		*p++ = (unsigned char)value;
	}

	return ptr;
}

void *my_memset_v2(void *ptr, int value, size_t num)
{
	if (ptr == NULL)	// check if ptr not point to NULL
		return NULL;

	unsigned char *p = ptr;
	for (size_t i=0; i<num; i++)
	{
		*p++ = (unsigned char)value;
	}

	return ptr;
}

void *my_memset_v3(void *ptr, int value, size_t num)
{
	if (ptr == NULL)	// check if ptr not point to NULL
		return NULL;

	int  *int_ptr  = (int *)ptr;

	for (size_t i=0; i<num; ++i)
	{
		*int_ptr++ = value;
	}
	
	return ptr;
}

void *my_memset_v4(void *buf, int ch, size_t n)
{
	unsigned char *p = (unsigned char *)buf;
	while (n--)
	{
		*p++ = (unsigned char)ch;
	}

	return buf;
}

/* helper functions */
void print_ints(int arr[], int len)
{
	for (int i=0; i<len; i++)
		printf("%d ", arr[i]);
	puts("");
}

void copy_array(int dest[], int src[], size_t len)
{
	for (size_t i=0; i<len; i++)
		dest[i] = src[i];
}

int main(void)
{
	int arr[5]       = {1,2,3,44,15};
	int value        = 0;
	size_t len       = sizeof(arr)/sizeof(arr[0]);

	int temp_arr[5];

	// test memset
	copy_array(temp_arr, arr, len);
	puts("array before use memset:");
	puts("------------------------");
	print_ints(temp_arr, len);

	puts("array after use memset:");
	puts("-----------------------");
	memset(temp_arr, value, len*sizeof(int));
	print_ints(temp_arr, len);
	NEW_LINE 

	// test my_memset_v1
	copy_array(temp_arr, arr, len);
	puts("array before use my_memset_v1:");
	puts("------------------------------");
	print_ints(temp_arr, len);

	puts("array after use my_memset_v1:");
	puts("-----------------------------");
	my_memset_v1(temp_arr, value, len*sizeof(int));
	print_ints(temp_arr, len);
	NEW_LINE 

	// test my_memset_v2
	copy_array(temp_arr, arr, len);
	puts("array before use my_memset_v2:");
	puts("------------------------------");
	print_ints(temp_arr, len);

	puts("array after use my_memset_v2:");
	puts("-----------------------------");
	my_memset_v2(temp_arr, value, len*sizeof(int));
	print_ints(temp_arr, len);
	NEW_LINE 

	// knowledge:
	// ----------
	// 	We don't need to increase the 'len' of each element in this example
	// 	because dereferencing the pointer in 'my_memset_v3' treats it as an integer pointer,
	// 	not an unsigned char pointer like in other examples.
	// 	
	// 	Explanation:
	// 	 	* "bit in element" refers to the individual bits that make up an integer value.
	// 	 	* 'sizeof(arr)' returns the total size of the array in bytes.
	// 	 	* 'sizeof(arr)/sizeof(arr[0])' returns the number of elements in the array.
	// 	 	* 'sizeof(int)' returns the size of the integer type in bytes, and the size of an int depends
	//  	          on your system architecture (32-bit, 64-bit, and so on).
	// 	
	// 	When using 'my_memset_v3' to fill an array with integer values, you should use 'sizeof(arr)'
	// 	to ensure that the entire array is filled. Using 'sizeof(arr)/sizeof(arr[0])' will only fill
	// 	the first element of the array.
	copy_array(temp_arr, arr, len);
	puts("array before use my_memset_v3:");
	puts("------------------------------");
	print_ints(temp_arr, len);

	puts("array after use my_memset_v3:");
	puts("-----------------------------");
	my_memset_v3(temp_arr, 775, len);
	print_ints(temp_arr, len);
	NEW_LINE 

	// test my_memset_v3
	copy_array(temp_arr, arr, len);
	puts("array before use my_memset_v3:");
	puts("------------------------------");
	print_ints(temp_arr, len);

	puts("array after use my_memset_v3:");
	puts("-----------------------------");
	my_memset_v3(temp_arr, -1, len);
	print_ints(temp_arr, len);
	NEW_LINE 

	// test my_memset_v4
	copy_array(temp_arr, arr, len);
	puts("array before use my_memset_v4:");
	puts("------------------------------");
	print_ints(temp_arr, len);

	puts("array after use my_memset_v4:");
	puts("-----------------------------");
	my_memset_v4(temp_arr, value, len*sizeof(int));
	print_ints(temp_arr, len);
	NEW_LINE 


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
