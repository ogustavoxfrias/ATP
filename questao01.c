#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool eh_algarismo(char c){

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            return false;
        }
        else {
            return true;
        }
}

bool eh_maiscula(char c){
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    else {
        return false;
    }
}

bool eh_minuscula(char c){
    if(c >= 'a' && c <= 'z'){
        return true;
    }
    else {
        return false;
    }
}

bool eh_letra(char c){

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            return true;
        }
        else {
            return false;
        }
}

char minusculo(char c, char n){
    if(eh_letra(c) == true){
        return n = tolower(c);
    }
}

int main(){
    
    char algarismo_lido;

    printf("Informe um caracter:\n");
    scanf("%c", &algarismo_lido);

//Algarismo
    if(eh_algarismo(algarismo_lido) == true){
        printf("É um algarismo\n");
    }

//Maiuscula
    if(eh_maiscula(algarismo_lido) == true){
        printf("O caracter é maiúsculo\n");
    }

//Minusculo
    if(eh_minuscula(algarismo_lido) == true){
        printf("O caracter é minúsculo\n");
    }


//Letra
    if(eh_letra(algarismo_lido) == true){
        printf("O caracter é uma letra\n");
    }

//Letra minuscula
    char n, letra;
    letra = minusculo(algarismo_lido, n);
    printf("%c\n", letra);

}