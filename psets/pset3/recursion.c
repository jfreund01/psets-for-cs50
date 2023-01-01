#include <cs50.h>
#include <stdio.h>

void pyramid (int n, int r);

int main (void) {

    int height = get_int("Enter Height: ") - 1;

    int reference = height;

    pyramid(height, reference);

}

void pyramid (int n, int r){

    if(n <= -1){ return; }

    pyramid(n - 1, r);

    for (int i = 0; i < r - n; i++){

        printf(" ");
    }

    for (int i = 0; i < (2*n) + 1; i++){

        printf("#");
    }

    printf("\n");

}