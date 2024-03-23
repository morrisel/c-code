
#include "mul.h"

#include "add.h"
//int add(int a, int b);

int mul(int a, int b)
{
	int result = 0;
	int i;
	for (i = 0; i < b; ++i)
	{
		result = add(result, a);
	}

	return result;
}
