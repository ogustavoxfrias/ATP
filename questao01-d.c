#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int encontraCIA(char s[]){
    int tamanho = strlen(s);
    int contador = 0;

    for(int i = 0; i<tamanho; i++){
        if((s[i] == 'c' || s[i] == 'C') && (s[i + 1] == 'i' || s[i + 1] == 'I')){
            contador = contador + 1;
        }
    }

    return contador;

}

int main(){
    
    char string[MAX] = "A CIA denuncia que a Mafia abastecia o trafico de armas na Bacia do Rio da Prata";
    printf("%s\n", string);

    int frequencia = encontraCIA(string);

    printf("A frequencia de CIA é: %d\n", frequencia);

}