#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int *p_altitude;
    int *p_engine;
    int *p_velocity;

    p_altitude = malloc(sizeof (int));
    printf("p_altitude = %p\n", (void*)p_altitude);
    puts("setting altitude to 100");
    *p_altitude = 100;
    free(p_altitude);

    p_engine = malloc(sizeof(int));
    printf("p_engine = %p\n", (void*)p_engine);

    free(p_altitude);   // double free --> it's problem

    puts("setting engine to 345");
    *p_engine = 345;        // could crush

    p_velocity=malloc(sizeof(int));
    puts("setting velocity to 876");
    *p_velocity = 876;      // could change engine value

    printf("engine value is: %d\n", *p_engine);
    printf("velocity value is: %d\n", *p_velocity);

    printf("p_altitude = %p\n", (void*)p_altitude);
    printf("p_velocity = %p\n", (void*)p_velocity);

    free(p_engine);
    free(p_velocity);   // could crush 

    puts("END");
    return 0;
}
