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


int main(void)
{
    Student s1 = {
        123,
        "moshe", "levi",
        95
    };

    print_student(&s1);
    //            | <--- we need to add & for refer to address of the memory of the struct of the Student,
    //                   if the struct of the Student, for example in the 5000 address in DS of the
    //                   memory, then the & (umpersand) points to the 5000 address in the Data Segment.

    puts("");
    return 0;
}

