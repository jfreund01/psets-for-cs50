#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]){

    string key = argv[1];

    if (strlen(key) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (argv[2] != NULL || argv[1] == NULL){
        printf("Usage: ./substitution key\n");
        return 1;
    }


    string plaintext = get_string("plaintext: ");
    string cyphertext = plaintext;
    int plaintextLength = strlen(plaintext);




    for (int i = 0; i < plaintextLength; i++){
        if(isalpha(plaintext[i])){
            if (islower(plaintext[i])){

                cyphertext[i] = tolower(key[(int) plaintext[i] - 97]);
            }
            if (isupper(plaintext[i])){

                cyphertext[i] = toupper(key[(int) plaintext[i] - 65]);
            }

        }


    }
    printf("%s\n", cyphertext);

}