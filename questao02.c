#include <stdio.h>
#include <string.h>

#define MAX 100

char trocaPalavra(char s[]){

    int tamanho = strlen(s);
    int aux;
    char new_string[MAX];

    for(int i = 0; i < tamanho; i++){
        new_string[i] = s[i];
        if(s[i] == 'U'){
            if(s[i + 1] == 'S'){
                if(s[i + 2] == 'U'){
                    if(s[i + 3] == 'A'){
                        if(s[i + 4] == 'R'){
                            if(s[i + 5] == 'I'){
                                if(s[i + 6] == 'O'){
                                    new_string[i] = 'P';
                                    aux = i;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
                
        new_string[aux + 1] = 'a';
        new_string[aux + 2] = 't';
        new_string[aux + 3] = 'r';
        new_string[aux + 4] = 'i';
        new_string[aux + 5] = 'c';
        new_string[aux + 6] = 'i';
        new_string[aux + 7] = 'a';
        
        printf("%s\n", new_string);
        int novo_tamanho = strlen(new_string) + 1;

    return new_string[novo_tamanho];

}

int main(){
    char string[MAX] = "Ola, USUARIO, atualize a senha e o nome do seu usuario.";
    printf("%s\n", string);

    printf("%c", trocaPalavra(string));

}