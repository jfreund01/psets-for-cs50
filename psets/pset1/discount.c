#include <stdio.h>
#include <cs50.h>

float discount(float price, float percentage);

int main(void){

    float regular = get_float("Regular Price: ");
    int percentOff = get_float("Percent Off: ");
    float sale = discount(regular, percentOff);
    printf("Sale Price: %.2f\n", sale);
}


float discount(float price, float percentage){

    return price * (percentage/100);
}