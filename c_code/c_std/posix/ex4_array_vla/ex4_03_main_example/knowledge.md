
//             0   1   2   3   4      5
int nums[] = {10, 20, 30, 40, 50}; // X

//      5
const size_t    nums_len    = sizeof nums/sizeof nums[0];
const int       i_nums_len  = sizeof nums/sizeof nums[0];

//print each cell in the array
for (int i = 0; i < nums_len; ++i)
{
	printf("%d ", nums[i]);
}

//print each cell in the array 
//using size_t to ensure we can represent every possible
// index
//
for (size_t i = 0; i < nums_len; ++i)
{
	printf("%d ", nums[i]);
}

//print each cell in the array backwards
for (int i = i_nums_len - 1; i >= 0; --i)
{
	printf("%d ", nums[i]);
}

//BUGGED -> size_t can never be less than zero
//
// for (size_t i = nums_len - 1; i >= 0; --i)
// {
//     printf("%d ", nums[i]);
// }
// puts("");

// FIXED
for (size_t i = 0; i < nums_len; ++i)
{
	printf("%d ", nums[nums_len - 1 - i]);
}


