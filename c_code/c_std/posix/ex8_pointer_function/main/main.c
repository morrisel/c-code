
/*

(arr+i)  ≡  &arr[i]
*(arr+i)  ≡  arr[i]
 *(*(mat+i)+j)) = mat[i][j]
*/

#include "main.h"


int main(int argc,char** argv){

    worker_t *workers =     NULL;
    int num_of_workers =    0;
    int choice = 0;
    int index = 0;
    int id_del = 0;
                       

    while (1)
    {
        choice = -1;
        index = -3;
        printf("1) add worker\n");
        printf("2) delete worker\n");
        printf("3) view all workers\n");
        printf("4) exit\n");
        printf("your choice: ");
        scanf("%d",&choice);

        if (choice == 1)
        {
            index = add_worker(&workers,&num_of_workers);
            if (index == -1){
                printf("error: malloc failed\n");
                break;
            }
            scan_worker(&workers,num_of_workers,index);
        }
        else if (choice == 2)
        {
            printf("ID delete = ");
            scanf("%d",&id_del);
            index = delete_worker(&workers, num_of_workers,id_del);
            if(index){
                printf("worker deleted\n");
            }
            else{
                printf("worker not found\n");
            }
            
        }
        else if (choice == 3)
        {
            view_all_workers(&workers, num_of_workers);
        }
        else if (choice == 4)
        {
            printf("Goodbye!\n");
            free(workers);
            workers = NULL;
            break;
        }


    }
    return 0;
}

int chack_worker_exists(worker_t ***workers,int num_of_workers,int id){
    for (int i = 0; i < num_of_workers; i++)
        if(((**workers)+i)->id == id || id <= 0)
            return 0;
    return 1;
}

void scan_worker(worker_t **workers,int num_of_workers,int index){
    //(*workers+index)->id=e;// not used workers[index]->id
    int e;
    int id;
    printf("add worker\n");
    while(1){
        printf("worker id: ");
        scanf("%d",&id);
        if(!chack_worker_exists(&(workers),num_of_workers,id)){
            printf("error id or id exists \n");
        }
        else{
            (*workers+index)->id = id;  
            break;
        }
    }
    printf("worker age: ");
    scanf("%d",&(*workers+index)->age);  
    printf("worker first name: ");
    scanf("%s",(*workers+index)->first_name);  
    printf("worker last name: ");
    scanf("%s",(*workers+index)->last_name);  
    printf("worker salary: ");
    scanf("%lf",&(*workers+index)->salary);  
    printf("worker status[0 = single, 1 = married,2 = divorcee: ");
    scanf("%d",&e);  
    (*workers+index)->status = e;

    // printf("[id , age ,first name , last name , salary , status[0 = single, 1 = married,2 = divorcee]\n");

    // scanf("%d %d %s %s %lf %d",&(*workers+index)->id
    //                     ,&(*workers+index)->age
    //                     ,(*workers+index)->first_name
    //                     ,(*workers+index)->last_name
    //                     ,&(*workers+index)->salary
    //                     ,&e
    //                     );

}

int add_worker(worker_t **workers,int* num_of_workers){
    if(*num_of_workers == 0){
        (*num_of_workers)++;
        *workers = (worker_t*)malloc((*num_of_workers)*sizeof(worker_t));
        if(*workers == NULL)
            return -1;

        return 0;
    }
    else{

        // check if id  == 0
        for(int i=0;i<*num_of_workers;i++){
            if((*workers+i)->id == 0){
                return i;
            }
        }

        // else arr is full
        (*num_of_workers)++;
        printf("num_of_workers = %d\n",(*num_of_workers));
        printf("re num_of_workers = %d\n",(*num_of_workers)-1);
        *workers = (worker_t*)realloc(*workers,(*num_of_workers)*sizeof(worker_t));

        if(workers == NULL)
            return -1;
       
        return (*num_of_workers)-1;


    }

    return 0;
}
void view_all_workers(worker_t **workers,int num_of_workers){
    if (num_of_workers != 0){
        for (int i = 0; i < num_of_workers; i++)
        {
            if((*workers+i)->id != 0){
                printf("id   = %15d\n",(*workers+i)->id);
                printf("age  = %15d\n",(*workers+i)->age);
                printf("sal  = %13.2lf\n",(*workers+i)->salary);
                printf("LN   = %s\n",(*workers+i)->last_name);
                printf("FN   = %s\n",(*workers+i)->first_name);
                if ((*workers+i)->status == 0)
                    printf("status = single\n");
                else if ((*workers+i)->status == 1)
                    printf("status = married\n");
                else if ((*workers+i)->status == 2)
                    printf("status = divorcee\n");
                printf("----------------------------------------------------\n");
            }
        }
    }
    else{
        printf("Add worker to list \n");
    }

}

int delete_worker(worker_t **workers,int num_of_workers,int id){


    for (int i=0;i<num_of_workers;i++)
    {
        if ((*workers+i)->id == id){
            (*workers+i)->id  = 0;
            return 1;
        }
    }
    return 0;
}
