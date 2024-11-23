#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void rotate_left_array(int arr[], size_t len);

int main(void)
{
    /* Enter code here */
    int arr[] = {10, 20, 33, 50};
    size_t len_arr = 4 ;

    for (size_t i=0; i<len_arr; ++i) printf("%d ", arr[i]);
    puts("");

    rotate_left_array(arr, len_arr);
    for (size_t i=0; i<len_arr; ++i) printf("%d ", arr[i]);
    puts("");

    return 0;
}


/* Note: we don't need to use dynamic allocation
 *       to solve this program (and it's less
 *       efficient). this just an example
 */
void rotate_left_array(int arr[], size_t len)
{
    // create an auxillery array with the same size
    // as the original arry (arr)
    // int aux[len];   // VLA (Variable Length Array) - old style and some problems

    int *aux = malloc(sizeof (int) * len);
    // TODO: check malloc didn't fail
    //

    // copy from second elemnt in arr (0..N-1)
    // into aux from first element (0..N-2)
    for (size_t i=1; i<len; ++i)
    {
        aux[i-1] = arr[i];
    }

    // copy first of arr into last of aux
    aux[len-1] = arr[0];

    // copy aux entirely into arr
    memcpy(arr, aux, sizeof(int)*len);

    free(aux);
    aux = NULL;     // not needed, but for safety

}
