#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int myPoints = 2;

    int points = get_int("How many points did you lose? ");
    if (points < myPoints){
        printf("You lost fewer points that me.\n");
    }
    else if (points > myPoints){
        printf("You lost more points that me.\n");
    }
    else{
        printf("You lost the same number of points as me.\n");
    }


}