#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int validacao(char telefone[]){
    if(telefone[0] == '+'){
        if((strlen(telefone) == 16) || (strlen(telefone) == 17)){
            if(isdigit(telefone[7])){
                if(isdigit(telefone[8])){
                    if(isdigit(telefone[9])){
                        if(isdigit(telefone[10])){
                            if((isdigit(telefone[11])) || telefone[11] == '-'){
                                if((isdigit(telefone[12])) || telefone[12] == '-'){
                                    if(isdigit(telefone[13])){
                                        if(isdigit(telefone[14])){
                                            if(isdigit(telefone[15])){
                                                if((telefone[0] == '+') || (telefone[0] == 0)){
                                                    if((isdigit(telefone[3])) || (telefone[3] == '(')){
                                                        if((isdigit(telefone[6])) || (telefone[6] == ')')){
                                                            return 1;
                                                        }
                                                    }
                                                }
                                                else{
                                                    return 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        else{
            return 0;
        }
    }

    if(isdigit(telefone[0])){
        if(strlen(telefone) == 12){
            if(isdigit(telefone[2])){
                if(isdigit(telefone[3])){
                    if(isdigit(telefone[4])){
                        if(isdigit(telefone[5])){
                            if((isdigit(telefone[6])) || telefone[6] == '-'){
                                if((isdigit(telefone[7])) || telefone[7] == '-'){
                                    if(isdigit(telefone[8])){
                                        if(isdigit(telefone[9])){
                                            if(isdigit(telefone[10])){
                                                return 1;
                                            }
                                            else{
                                                return 0;
                                            }
                                        }   
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else{
            return 0;
        }
    }

    if(telefone[0] == '('){
        if(strlen(telefone) == 14){
            if(isdigit(telefone[4])){
                if(isdigit(telefone[5])){
                    if(isdigit(telefone[6])){
                        if(isdigit(telefone[7])){
                            if((isdigit(telefone[8])) || telefone[8] == '-'){
                                if((isdigit(telefone[9])) || telefone[9] == '-'){
                                    if(isdigit(telefone[10])){
                                        if(isdigit(telefone[11])){
                                            if(isdigit(telefone[12])){
                                                return 1;
                                            }else{
                                                return 0;
                                            }
                                        }   
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

int main() {

    char telefone[MAX];

    //Supondo que o usuário coloque o número corretamente
    printf("Informe um telefone:\n");
    scanf("%s", telefone);

    printf("O telefone é: %s\n", telefone);
    
    if(validacao(telefone) == 1){
        printf("O telefone é válido\n");
    }
    else{
        printf("Telefone inválido\n");
    }

}