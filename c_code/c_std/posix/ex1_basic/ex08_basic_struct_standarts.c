/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex08_basic_struct_standarts.c */
/* gcc ex08_basic_struct_standarts.o -o program -lm */
#include <stdio.h>

struct Student
{
	int id;       //field
	double score;    //field
};

int main(void)
{
	struct Student stud1 = {
		1000,
		91.5
	};

	//C99 initialization
	struct Student stud2 = {
		.score = 85.4,
		.id = 1001
	};

	struct Student stud3 = {
		1002 //id  (score will be 0.0)
	};

	//C99 
	struct Student stud4 = {
		.score = 45.7 // (id will 0)
	};

	struct Student stud5 =  { 0 };

	//C23
	// struct Student stud6 =  { }; //<-- better (safer)

	stud1.id = 1000;
	stud1.score = 75;

	stud2.id = 1001;
	stud2.score = 81;


	return 0;
}
