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


                                                   // bool (*is_greater)(Student*, Student*)
Student* find_best_student(Student arr[], size_t len, bool   is_greater (Student*, Student*));

void print_students_if(Student arr[], size_t len, bool is_valid(Student*));

bool by_grade(Student* s1, Student* s2);
bool by_last_name(Student* s1, Student* s2);
bool by_name(Student* s1, Student* s2);
bool validate_grade_gt_50(Student *s) { return s->grade > 50; }

Student* best_student_by_grade(Student arr[], size_t len);
Student* first_student_by_ln(Student arr[], size_t len);
Student* first_student_by_name(Student arr[], size_t len);


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
    for (size_t i=0; i<students_len; ++i)
    {
        print_student(students+i);      // <--> &students[i]
    }
    puts("");

//    Student *p_best = best_student_by_grade(students, students_len);
    Student *p_best = find_best_student(students, students_len, by_grade);
    printf("the student with the highest grade:\n");
    print_student(p_best);
    puts("");

//    p_best = first_student_by_ln(students, students_len);
    p_best = find_best_student(students, students_len, by_last_name);
    printf("the first student by last name:\n");
    print_student(p_best);
    puts("");

    p_best = find_best_student(students, students_len, by_name);
    printf("the first student by full name:\n");
    print_student(p_best);
    puts("");


    print_students_if(students, students_len, validate_grade_gt_50);


    puts("");
    return 0;
}


Student* find_best_student(Student arr[], size_t len, bool   is_greater (Student*, Student*))
{
    Student *p_stud = &arr[0];

    for (size_t i=1; i<len; ++i)
    {
        //if (arr[i].grade > (*p_stud).grade )
        if (is_greater(&arr[i], p_stud) )
        {
            p_stud = &arr[i];

        }
    }

    return p_stud;
}

void print_students_if(Student arr[], size_t len, bool is_valid(Student*))
{
    Student *ps=arr+1;

    for (size_t i=0; i<len; ++i, ps=arr+i)
    {
        if(is_valid(ps))
            print_student(arr+i);
    }
    puts("");
}

bool by_grade(Student* s1, Student* s2)
{
    return s1->grade > s2->grade;
}


bool by_last_name(Student* s1, Student* s2)
{
    return strcmp(s1->ln, s2->ln) < 0;
}

bool by_name(Student* s1, Student* s2)
{
    int ln_cmp = strcmp(s1->ln, s2->ln);

    if (ln_cmp < 0) return true;

    if (ln_cmp > 0) return false;

    // ln_cmp == 0
    return strcmp(s1->ln, s2->ln) < 0;

}

//
//
//Student* first_student_by_ln(Student arr[], size_t len)
//{
//    Student *p_best_student = &arr[0];
//    for (size_t i=1; i<len; ++i)
//    {
//        const char *ln1 = (*p_best_student).ln;
//        const char *ln2 = arr[i].ln;
//
//        if (strcmp(ln2, ln1) < 0 )
//        {
//            p_best_student = &arr[i];
//
//        }
//    }
//
//    return p_best_student;
//
//}
//
