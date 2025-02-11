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
    {103, "david", "azulai", 70},
    {104, "david", "cohen", 80},
    {105, "avi", "levi", 65},
};
const size_t students_len = sizeof(students)/ sizeof(students[0]);

Student* best_student_by_grade(Student arr[], size_t len);
Student* first_student_by_ln(Student arr[], size_t len);

int main(void)
{
    puts("list of all students:\n");
    for (size_t i=0; i<students_len; ++i)
    {
        print_student(students+i);      // <--> &students[i]
    }
    puts("");

    Student *p_best = best_student_by_grade(students, students_len);
    printf("the student with the highest grade:\n");
    print_student(p_best);
    puts("");

    p_best = first_student_by_ln(students, students_len);
    printf("the first student by last name:\n");
    print_student(p_best);
    puts("");


    puts("");
    return 0;
}


Student* best_student_by_grade(Student arr[], size_t len)
{
    Student *p_best_student = &arr[0];
    for (size_t i=1; i<len; ++i)
    {
        if (arr[i].grade > (*p_best_student).grade )
        {
            p_best_student = &arr[i];

        }
    }

    return p_best_student;

}

Student* first_student_by_ln(Student arr[], size_t len)
{
    Student *p_best_student = &arr[0];
    for (size_t i=1; i<len; ++i)
    {
        const char *ln1 = (*p_best_student).ln;
        const char *ln2 = arr[i].ln;

        if (strcmp(ln2, ln1) < 0 )
        {
            p_best_student = &arr[i];

        }
    }

    return p_best_student;

}


