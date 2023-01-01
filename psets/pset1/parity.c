#include <stdio.h>
#include <cs50.h>

int main(){

    int n = get_int("n: ");

    if(n % 2 == 0)
        printf("N is even.\n");

    else
        printf("N is odd.\n");
}