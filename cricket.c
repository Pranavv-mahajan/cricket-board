#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct cricket
{
    char name[20];
    int age;
    char country[20];
    char category[20];
    float average;
    int odi;
    int t_20;
    int wicket;
};

void displayinfo(int n, struct cricket p[n]);
void BatsmanCountry(int n, struct cricket p[n]);
void avg_score(int n, struct cricket p[n]);
void highest_avg(int n, struct cricket p[n]);
void BowlersCountry(int n, struct cricket p[n]);
void wicket(int n, struct cricket p[n]);
void display_particular(int n, struct cricket p[n]);
void swap(struct cricket *x, struct cricket *y);

int main()
{
    int n, i, key;
    printf("Enter Number of Player :   ");
    scanf("%d", &n);
    printf("\n");
    struct cricket p[n];

    // Collectng information from user
    for (int i = 0; i < n; i++)
    {
        printf("\t  ****** Player : %d ******\n", i + 1);
        printf("\t Enter Name of Player :  ");
        scanf("%s", p[i].name);

        printf("\t Enter age of player: ");
        scanf("%d", &p[i].age);

        printf("\t Enter country of Player :  ");
        scanf("%s", p[i].country);

        printf("\t Enter the role of player : ");
        scanf("%s", p[i].category);

        printf("\t Enter number of ODI's palyed: ");
        scanf("%d", &p[i].odi);

        printf("\t Enter number of 20-20's played: ");
        scanf("%d", &p[i].t_20);

        printf("\t Enter Average score of Player :  ");
        scanf("%f", &p[i].average);

        printf("\t Enter Wickets of Player :  ");
        scanf("%d", &p[i].wicket);
        printf("\n");
    }

    int choice;
    printf("\n");
    do
    {
        printf("\t1.Display all players information \n");
        printf("\t2.Display Number of Batsman of particular country\n");
        printf("\t3.Sort as per the average batting score\n");
        printf("\t4.Display batsman with highest average batting score\n");
        printf("\t5.Display number of Bowlers of particular country\n");
        printf("\t6.Display number Of Bowlers with maximum wickets\n");
        printf("\t7.Display information of particular player\n");
        printf("\n");

        printf("\tEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayinfo(n, p);
            break;
        case 2:
            BatsmanCountry(n, p);
            break;
        case 3:
            avg_score(n, p);
            break;
        case 4:
            highest_avg(n, p);
            break;
        case 5:
            BowlersCountry(n, p);
            break;
        case 6:
            wicket(n, p);
            break;
        case 7:
            display_particular(n, p);
            break;
        case 8:
            break;

        default:
            printf("Invalid Selection");
            break;
        }
    } while (choice != 8);

    return 0;
}
void swap(struct cricket *x, struct cricket *y)
{
    struct cricket temp = *x;
    *x = *y;
    *y = temp;
}

void displayinfo(int n, struct cricket p[n])
{
    printf("\t_______________________________________________________________________________\n");
    printf("\tName\tAge\tCountry\tCategory\tODI\t20-20\tAvgScore\tWickets\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t%d\n", p[i].name, p[i].age, p[i].country, p[i].category, p[i].odi, p[i].t_20, p[i].average, p[i].wicket);
    }
    printf("\t_______________________________________________________________________________\n");
    printf("\n");
}
void BatsmanCountry(int n, struct cricket p[n])
{
    int key = 0;
    char temp[20];

    printf("\tEnter name of country: ");
    scanf("%s", temp);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(temp, p[i].country) == 0 && strcmp(p[i].category, "Batsman") == 0)
        {
            key++;
        }
    }
    printf("\tNumber of batsman from given country is %d\n", key);
    printf("\n");
}
void avg_score(int n, struct cricket p[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].average < p[j + 1].average)
                swap(&p[j], &p[j + 1]);
        }
    }
    printf("\nThe sorted detils of players as per avg batting score:");
    printf("\n____________________________________________\n");
    printf("\nNo\tName\tCategory\tAvg score");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%s\t\t%s\t\t%.2f", i + 1, p[i].name, p[i].country, p[i].average);
    }
    printf("\n____________________________________________\n");
    printf("\n");
}

void highest_avg(int n, struct cricket p[n])
{
    float z = p[0].average;
    int answ = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].average > z)
        {
            z = p[i].average;
            answ = i;
        }
    }
    printf("\n");

    printf("Batsman with highest average score: %s\n", p[answ].name);
}
void BowlersCountry(int n, struct cricket p[n])
{
    int key = 0;
    char temp[20];

    printf("Enter name of country: ");
    scanf("%s", temp);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(temp, p[i].country) == 0 && strcmp(p[i].category, "Bowler") == 0)
        {
            key++;
        }
    }
    printf("\tNumber of Bowlers from given country is %d\n", key);
    printf("\n");
}
void wicket(int n, struct cricket p[n])
{
    float z = p[0].wicket;
    int answ = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].wicket > z)
        {
            z = p[i].wicket;
            answ = i;
        }
    }
    printf("\n");

    printf("\tBowler with highest wicket score: %s\n", p[answ].name);
    printf("\n");
}

void display_particular(int n, struct cricket p[n])
{
    char name1[20];
    int d;

    printf("\tEnter the name of player : ");
    scanf("%s", name1);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(name1, p[i].name) == 0)
        {
            d = i;
            break;
        }
    }
    printf("\n");
    printf("\tName of player: %s\n", p[d].name);
    printf("\tAge of player: %d\n", p[d].age);
    printf("\tCountry of player: %s\n", p[d].country);
    printf("\tCategory of player: %s\n", p[d].category);
    printf("\tNumber of ODI's played: %d\n", p[d].odi);
    printf("\tNumber of 20-20's played: %d\n", p[d].t_20);
    printf("\tAverage score: %f\n", p[d].average);
    printf("\tNumber of wickets taken: %d\n\n", p[d].wicket);
    printf("\n");
}