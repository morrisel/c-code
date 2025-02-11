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

                                                       // predicate(Student*)
void print_students_if(Student arr[], size_t len, bool is_valid(Student*));
bool validate_grade_gt_50(Student *s) { return (*s).grade > 50; }

void print_student(Student *s)
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


Student* find_best_student(Student arr[], size_t len, bool   is_greater (Student*, Student*))
{
    Student *p_stud = &arr[0];

    for (size_t i=0; i<len; ++i)
        if (is_greater(&arr[i], p_stud) )       //if (arr[i].grade > (*p_stud).grade )
            p_stud = &arr[i];

    return p_stud;
}

void print_students_if(Student arr[], size_t len, bool is_valid(Student*))
{
    Student *ps=arr+1;

    for (size_t i=0; i<len; ++i, ps=arr+i)
        if(is_valid(ps))
            print_student(arr+i);

    puts("");
}

