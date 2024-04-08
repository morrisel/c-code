/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow t5_strcpy_with_intervals.c */
/* gcc t5_strcpy_with_intervals.o -o program -lm */
#include <stdio.h>
#include <string.h>

// copy a string from src to dest
char *strcpy_with_n_spaces_v1(char *dest, const char *src, size_t n)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}

	size_t i, j, counter = 0;
	for (i = 0, j=0; src[i] != '\0'; i++, j++)
	{
		if (counter < n)
		{
			dest[j] = src[i];
			dest[++j] = ' ';
			counter++;
		}
		else
		{
			dest[j+i] = src[i];
		}
	}

	dest[i] = '\0';
	return dest;
}

// copy a string from src to dest with n spaces between characters
char *strcpy_with_n_spaces(char *dest, const char *src, size_t n)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}

	size_t i, j, k;

	for (i = 0, j = 0, k = 0; src[i] != '\0'; i++)
	{
		dest[j++] = src[i];

		if (src[i + 1] != '\0' && k < n)
		{
			dest[j++] = ' ';
			k++;
		}
	}

	dest[j] = '\0';
	return dest;
}


int main(void)
{
	char target[128]= "HWorld!";
	char source[128]= "z2HellbA";
	size_t n=3;

	puts("Before:");
	printf("target: %s\n", target);
	printf("source: %s\n", source);
	puts("");

	strcpy_with_n_spaces(target, source, n);

	puts("After:");
	printf("target: %s\n", target);
	printf("source: %s\n", source);
	puts("");

	return 0;
}

//void convert_to_lower(void)
//{
//	int count=0;
//	int ch;
//	while((ch=getchar())!='\n')
//	{
//		if (ch >= 'A' && ch <='Z')
//		{
//			ch+=32;
//		}
//		putchar(ch);
//	}
//	//puts("");
//}
//
//void convert_to_upper(char *destEs)
//{
//	int count=0;
//	int ch;
//	while((ch=getchar())!='\n')
//	{
//		if (ch >= 'a' && ch <='z')
//		{
//			ch-=32;
//		}
//		putchar(ch);
//	}
//	//puts("");
//}
//void str_cpy_B (char *first,char *sec)
//{
//	int i;
//
//	for (i=0;;i++)
//	{
//		if (*(sec+i) == '\0')
//		{
//			*(first+i)=*(sec+i) ;
//			break;
//		}
//		else
//		{
//			if (*(sec+i) >='a' && *(sec+i) <='z')
//			{
//				*(first+i)=*(sec+i)-32 ;
//			}
//			else
//			{
//				*(first+i)=*(sec+i);
//			}
//		}
//	}
//}

char *put_str_to_middle(char *dest, const char *src)
{
	size_t dest_len = strlen(dest);
	size_t src_len = strlen(src);
	size_t middle = dest_len / 2; // finding middle of dest

	// move part of dest from middle to src+1 distance with '\0'
	memmove(dest + middle + src_len, dest + middle, dest_len - middle + 1);

	// copying src to the middle of dest
	memcpy(dest + middle, src, src_len);

	dest[dest_len+src_len]='\0';

	return dest;
}

char *strncpy_reverse(char *dest, const char *src, size_t n)
{
	char *temp = dest;

	strncpy(dest, src, n);
	for (size_t i = 0; i<n; i++)
	{
		temp[i] = src[n -i -1];
	}
	return temp;
}

char *strncpy_reverse_v1(char *dest, const char *src, size_t n)
{
	char *temp = dest;

	strncpy(dest, src, n);
	for (size_t i = 0; i<n; i++)
	{
		temp[i] = src[n -i -1];
	}
	return temp;
}

char *my_strncpy_reverse_v1(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t src_len, dest_len;

	for (src_len=0; src_len!=n; src_len++);
	// length of dest
	for (dest_len=0; dest[dest_len]!='\0'; dest_len++);

	// copy from the end of src to dest
	for (i=0; src[i] != '\0'; i++)
	{
		dest[i]=src[src_len -i -1];
	}

	// continue to fill the dest with the dest's characters if there are
	while (n < dest_len)
	{
		dest[n] = dest[n+1];
		n++;
	}

	// copy from dest
	dest[dest_len] = '\0';

	return dest;
}

// copy a string with an n characters
char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return dest;
}

// concatenate string to the end
char *my_strcat(char *dest, const char *src)
{
	// src is longer, just concatenate
	size_t i, j;

	// set the i variable to the end of the destination
	for (i=0; dest[i] != '\0'; i++);

	// add second arr to the tail of the first array
	for (j=0; src[j]!='\0'; j++)
		dest[i++] = src[j];

	// add the null terminator at the end
	dest[i] = '\0';

	return dest;
}


// copy a string from src to dest
char *my_strcpy(char *dest, const char *src)
{
	size_t i;
	for (i=0; src[i]!='\0'; i++)
	{
		dest[i]=src[i];
	}

	dest[i] = '\0';
	return dest;
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
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * ================================================================================================ */
