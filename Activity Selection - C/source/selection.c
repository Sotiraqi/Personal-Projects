# include <stdio.h>

//First algorithm
void select_max_activities(int start[], int finish[], int number)
{
    int i, j;

    printf("Please select the activities to check if they are mutually compatible:  \n");
    printf("First activity selected: ");
    scanf("%d", &i);
    printf("Second activity selected: ");
    scanf("%d", &j);


    if (start[j] >= finish[i] || start[i] >= finish[j])
    {
        printf("Selected activities are mutually compatible");
        i = j;
    }
    else
    {
        printf("Selected activities are not mutually compatible");
    }

}

//Second algorithm
void random_max_activities(int start[], int finish[], int number)
{
    int i, j, temp;
    temp = 0;

    while (temp != 3)
    {
        i=rand() % number;
        j=rand() % number;

        if(i==j)
        {
            printf("Random selected activities are the same, trying again...");
            temp++;
        }
        else
        {
            printf("The selected activities are choosen: Activity[%d] and Activity[%d]", i, j);
            temp = 3;
        }
    }

    if (start[j] >= finish[i] || start[i] >= finish[j])
    {
        printf("Selected activities are mutually compatible");
        i = j;
    }
    else
    {
        printf("Selected activities are not mutually compatible");
    }
}



