#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int startMonth;
    int endMonth;
    int numOfDependencies;
    int dependency[10];
} Task;

//functions
void print(Task tasks[], int numOfTasks);
void input(Task tasks[], int numOfTasks);
void edit(Task tasks[], int numOfTasks);
void ascii();

int main()
{
    int choice;

    //user input
    printf("Welcome to the Gantt Generator!\nWould you like to use the test example (enter 1) or create your own Gantt from scratch(enter 2)?\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        //predefined gantt with tasks filled in
        Task tasksDefined[10] ={
            {"Find_Bank", 1, 2, 0},
            {"Get_mortgage_approval", 2, 2, 1, {0}},
            {"Draw_Down", 4, 6, 2, {0, 1}},
            {"Build_foundation", 3, 4, 1, {2}},
            {"Build_walls", 4, 5, 0},
            {"Roof_and_Ceiling", 5, 6, 2, {3, 4}},
            {"Plumbing", 7, 7, 1, {5}},
            {"Electrics", 8, 9, 1, {6}},
            {"Inspect_Build", 9, 10, 1, {4}},
            {"Snagging", 9, 10, 2, {7, 8}}
        };

        //function call to print tasks and Gantt bars
        print(tasksDefined, 10);

        //function call to ask what user wants to do with gantt
        input(tasksDefined, 10);
    }

    if(choice == 2)
    {
        int numOfTasks;
        int i, j, k;

        printf("How many tasks would you like to add?(1-10)\n");
        scanf("%d", &numOfTasks);

        if (numOfTasks<1 || numOfTasks>10)
        {
            printf("Invalid number of tasks.\n");
            return 0;
        }

        Task tasksUser[numOfTasks];

        for(i=0; i<numOfTasks; i++)
        {
            printf("Please enter the task name:\n");
            scanf("%s", &tasksUser[i].name);

            printf("Start month(1-12):\n");
            scanf("%d", &tasksUser[i].startMonth);

            if (tasksUser[i].startMonth<1 || tasksUser[i].startMonth>12)
            {
                printf("Invalid start month.\n");
                return 0;
            }

            printf("End month(1-12):\n");
            scanf("%d", &tasksUser[i].endMonth);

            if (tasksUser[i].endMonth<1 || tasksUser[i].endMonth>12)
            {
                printf("Invalid end month.\n");
                return 0;
            }

            if (tasksUser[i].startMonth>tasksUser[i].endMonth)
            {
                printf("Start month must be before end month.\n");
                return 0;
            }

            printf("Enter how many dependencies this task has:\n");
            scanf("%d", &tasksUser[i].numOfDependencies);

            if (tasksUser[i].numOfDependencies>0)
            {
                for (j=0; j<tasksUser[i].numOfDependencies; j++)
                {
                    printf("Enter dependent task:\n");
                    scanf("%d", &tasksUser[i].dependency[j]);
                }
            }
        }

        print(tasksUser, numOfTasks);
        input(tasksUser, numOfTasks);

    }

    ascii();

    return 0;
}

void print(Task tasks[], int numOfTasks)
{
    int i,j,k;

    //print the month headers & aligns
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-22s| January |February | March   |  April  |   May   |   June  |  July   |  August |September| October |November |December |Dependencies\n", "");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

     //print tasks and Gantt bars
    for(i=0; i<numOfTasks; i++)
    {
        //aligns the tasks
        printf("%-22s", tasks[i].name);

        for(j=0; j<12; j++)
        {
            if(j>=tasks[i].startMonth-1 && j<= tasks[i].endMonth-1)
            {
                printf("|   XXX   ");
            }
            else
            {
                printf("|         ");
            }
        }

        printf("|");

        //prints out dependencies
        for(k=0; k<tasks[i].numOfDependencies; k++)
        {
            printf("%d ", tasks[i].dependency[k]);
        }
        printf("\n");
    }

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//function which asks user if they would like to edit, test or quit
void input(Task tasks[], int numOfTasks)
{
    char option[4];
    printf("If you wish to edit the Gantt please type 'edit'/If you wish to run a test, type 'test' or to exit, type 'quit' and then press enter to execute your option.\n");
    scanf("%s", &option);

    if(strcmp(option, "edit") == 0)
    {
        //function call to edit tasks
        edit(tasks, numOfTasks);
    }

    if(strcmp(option, "test") == 0)
    {
        printf("Sorry! This function hasn't been implemented.");
    }

    if(strcmp(option, "quit") == 0)
    {}
}

void edit(Task tasks[], int numOfTasks)
{
    char taskName[50];
    int i, j;

    printf("Please enter the task name you which to change exactly:\n");
    scanf("%s", &taskName);

    //search for task name
    for(i=0; i<numOfTasks; i++)
    {
        if(strcmp(taskName, tasks[i].name) == 0)
        {
            break;
        }
    }

    printf("Please enter the new task name or write its old one:\n");
    scanf("%s", &tasks[i].name);

    printf("Start month(1-12):\n");
    scanf("%d", &tasks[i].startMonth);
    if (tasks[i].startMonth<1 || tasks[i].startMonth>12)
    {
        printf("Invalid start month.\n");
        return 0;
    }

    printf("End month(1-12):\n");
    scanf("%d", &tasks[i].endMonth);
    if (tasks[i].endMonth<1 || tasks[i].endMonth>12)
    {
        printf("Invalid end month.\n");
        return 0;
    }

    if (tasks[i].startMonth>tasks[i].endMonth)
    {
        printf("Start month must be before end month.\n");
        return 0;
    }

    printf("Enter how many dependencies this task has:\n");
    scanf("%d", &tasks[i].numOfDependencies);

    if (tasks[i].numOfDependencies>0)
    {
        for (j=0; j<tasks[i].numOfDependencies; j++)
        {
            printf("Enter dependent task:\n");
            scanf("%d", &tasks[i].dependency[j]);
        }
    }
    //clear screen
    system("cls");

    print(tasks, numOfTasks);
    input(tasks, numOfTasks);
}

void ascii()
{
    printf("\n                     ,,\n");
    printf("  /\\ _,,_/\\         / /\n");
    printf(" /  .   .  \\        | |\n");
    printf(" |  > ^ <  |,,.,_.,/ /\n");
    printf("  \\          \\ \\ \\ \\/\n");
    printf("  |   _    ______   |\n");
    printf("  \\../ \\../   \\..\\../\n\n");
}
