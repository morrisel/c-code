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


void print_students_if(const Student arr[], size_t len, bool is_valid(const Student*));

bool validate_grade_gt_50(const Student *s) { return s->grade > 50; }

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
    {106, "avi", "azulay", 65},
};
const size_t students_len = sizeof(students)/ sizeof(students[0]);


int main(void)
{
    puts("list of all students:\n");
    print_students_if(students, students_len, validate_grade_gt_50);

    puts("");
    return 0;
}

void print_students_if(const Student *const arr, size_t len, bool is_valid(const Student*))
{
    const Student *ps=arr;      // pointer to constant data

    for (size_t i=0; i<len; ++i, ps=arr+i)
    {
        if(is_valid(ps))
            print_student((Student *)ps);
    }
    puts("");
}

