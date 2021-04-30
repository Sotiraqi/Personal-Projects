#include <stdio.h>
#include "selection.h"

#define MAX_ACTIVITIES 10

int main()
{
    int number;

    printf("Activity number: ");
    scanf("%d", &number);

    int start_time[MAX_ACTIVITIES];
    int finish_time[MAX_ACTIVITIES];

    for(int i = 0 ; i < number ; i++)
    {
        printf("Enter start time for Activity [%d] = ", i);
        scanf("%d", &start_time[i]);
        printf("Enter finish time for Activity [%d] = ", i);
        scanf("%d", &finish_time[i]);
    }

    random_max_activities(start_time, finish_time, number); //Enable this function for the algorithm 2
    //select_max_activities(start_time, finish_time, number);

    return 0;
}



