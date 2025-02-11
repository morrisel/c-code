/*

(arr+i)  ≡  &arr[i]
*(arr+i)  ≡  arr[i]

 *(*(mat+i)+j)) = mat[i][j]


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_STR 100
                    // 0      1        2
typedef enum status {single,married,divorcee} status_t;

typedef struct worker{
    char first_name[LEN_STR]; 
    char last_name[LEN_STR]; 
    unsigned int id; 
    status_t status; 
    unsigned int age;
    double  salary;
}worker_t;


int chack_worker_exists(worker_t ***workers,int num_of_workers,int id);
void scan_worker(worker_t **workers,int num_of_workers,int index);
int add_worker(worker_t **workers,int* num_of_workers);
void view_all_workers(worker_t **workers,int num_of_workers);
int delete_worker(worker_t **workers,int num_of_workers,int id);
