#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // vector data
    int *arr        = NULL;
    size_t arr_len  = 0; 

    int  option;
    bool is_running = true;

    while ( is_running)
    {
        printf(
                "Options:\n"
                "1) add a number \n"
                "2) remove the last number \n"
                "0) show results and exit \n"
              );

        printf("option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                {
                    int num;
                    printf("enter number to add: ");
                    scanf("%d", &num);
                                                                    //    if (arr == NULL)
                    ++arr_len;                                      //    {
                    arr = realloc(arr, sizeof(int) * arr_len);      //        arr = malloc(sizeof (int) * 1);
                    // TODO: check realloc result
                    arr[arr_len-1] = num;                           //        arr_len = 1;
                                                                    //    }
                                                                    //    else
                                                                    //    {
                                                                    //        ++arr_len;
                                                                    //        arr = realloc(arr, arr_len);
                                                                    //    }
                }
                break;
                
            case 2:
                {
                    if (arr_len == 0)
                    {
                        puts("Error: array is empty");
                        break;
                    }

                    printf("removed the value %d\n", arr[arr_len-1]);

                    --arr_len;

                    if (arr_len > 0)
                    {
                        arr = realloc(arr, arr_len * sizeof (*arr));    // sizeof (int)  <-->  sizeof (*arr)
                    }
                    else
                    {
                        free(arr);
                        arr = NULL;
                    }


                }
                break;

            case 0:
                {
                    is_running = false;
                }
                break;

            default:
                {
                    puts("error: invalid option\n");
                }
                break;


        } // end_switch

    } // end_while


    puts("Result:");
    printf("[");
    for (size_t i = 0; i<arr_len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("]");
    puts("");


    return 0;
}
