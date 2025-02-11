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

//    printf("%09d)   %-12s %-8s %3d\n",  s->id, s->fn, s->ln, s->grade);

}


int main(void)
{
    Student s1 = {
        123,
        "moshe", "levi",
        95
    };

    Student s2 = {
        124,
        "avi", "cohen",
        85
    };

    print_student(&s1);
    print_student(&s2);

    puts("");
    return 0;
}

