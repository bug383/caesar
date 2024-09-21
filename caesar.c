#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LIMIT 100

int caesar(int ascii[], int argument, int length);

int main(int argc, char *argv[]){
    
    char plaintext[MAX_LIMIT];    
    int ascii[MAX_LIMIT];
    char ciphertext[MAX_LIMIT];
    
    if(argc == 2){
        
        printf("plaintext:");
        fgets(plaintext, MAX_LIMIT, stdin);
        int length = strlen(plaintext);
        int argument = atoi(argv[1]);

        for(int i = 0; i < length - 1; i++){
            ascii[i] = plaintext[i];
        }

        caesar(ascii, argument, length - 1);    
   
   } else{
        printf("Usage: ./caeser {argument}\n");
    }
}


int caesar(int ascii[], int argument, int length){
    
    printf("ciphertext:");
    
    for(int i = 0 ; i < length ; i++){
        if(ascii[i] >= 'A' && ascii[i] <= 'Z'){
            ascii[i] = ((ascii[i] - 'A' + argument) % 26) + 'A';
        } else if(ascii[i] >= 'a' && ascii[i] <= 'z'){
            ascii[i] = ((ascii[i] - 'a' + argument) % 26) + 'a';
        }

        printf("%c", ascii[i]);
    }
    printf("\n");
}
