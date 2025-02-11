#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int         id;
    const char  *fn;    // first name
    const char  *ln;    // last name
    int         grade;
} Student;

Student* find_best_student
(
        Student arr[], 
        size_t  len, 
        bool    is_greater (Student*, Student*)     // bool (*is_greater)(Student*, Student*)
);


void print_students_if(const Student *arr, size_t len, bool is_valid(const Student*));
bool validate_grade_gt_50(const Student *s) { return (*s).grade > 50; }

void print_student(const Student *s)
{
    printf("%09d)   %-12s %-8s %3d\n",  (*s).id, (*s).fn, (*s).ln, (*s).grade);
}

// The students saved in DS(data segment) (but not on the heap)
Student students[] =
{
    {100, "moshe", "levi", 94},
    {101, "moshe", "cohen", 80},
    {102, "lea", "levi", 100},
    {103, "david", "azulai", 47},
    {104, "david", "cohen", 30},
    {105, "avi", "levi", 25},
    {106, "avi", "azulay", 84},
};
const size_t students_len = sizeof(students)/ sizeof(students[0]);


int main(void)
{
    puts("list of all students:\n");
    print_students_if(students, students_len, validate_grade_gt_50);

    puts("");
    return 0;
}

void print_students_if(const Student  *arr, size_t len, bool is_valid(const Student*))
{
    //  // compilation error: trying to change the point to --> arr[0]
    //  // arr[0].fn = "fname"; // you are cannot change the pointer beause it defined const

    //  // no erros: tryin to change the pointer: arr = &s1; // NOT RECOMENDED!
    //  Student s1 = {111, "aaa", "bbb", 222};
    //  arr = &s1;
    //  // if we want to make it impossible to change the *arr pointer and not just the point to --> arr[0]
    //  // we need to add the const for the *arr pointer too, "const Student const *arr" 

    const Student *ps=arr;

    for (size_t i=0; i<len; ++i, ps=arr+i)
        if(is_valid( ps))
            print_student(arr+i);

    puts("");
}

