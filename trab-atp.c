#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char a_principal[50];
    char a_secundario[50];
    int dificuldade;
    char s_verdadeira[256];
    char s_falsa[256];
}QUESTAO;

typedef struct{
    int id;
    char questoes[256];
}PROVA;

typedef struct{
    int id;
    char a_principal[64];
    char a_secundario[64];
    int dificuldade;
    char resposta;
}GABARITO;

QUESTAO questao[50];
QUESTAO teste[50];
QUESTAO gerando_prova[50];

void Inserir(){
            
        int dif;
        char ap[20];
        char as[20];
        char sv[256];
        char sf[256];

        int op;
        int i = 0;
        int contador = 0;
            
        getchar();

        do{

            printf("Qual o assunto principal?\n");
            fgets(ap,sizeof(ap),stdin);
            setbuf(stdin, NULL);
            strcpy(questao[i].a_principal, ap);

            setbuf(stdin, NULL);

            printf("Qual o assunto secundario?\n");
            fgets(as,sizeof(as), stdin);
            setbuf(stdin, NULL);
            strcpy(questao[i].a_secundario, as);

            setbuf(stdin, NULL);

            printf("Sentença verdadeira:\n");
            fgets(sv,sizeof(sv), stdin);
            setbuf(stdin, NULL);
            strcpy(questao[i].s_verdadeira, sv);

            setbuf(stdin, NULL);

            printf("Sentença falsa:\n");
            fgets(sf,sizeof(sf), stdin);
            setbuf(stdin, NULL);
            strcpy(questao[i].s_falsa, sf);

            setbuf(stdin, NULL);

            printf("Qual a dificuldade?\n");
            printf("1 - fácil / 2 - médio / 3 - dificil\n");
            scanf("%d", &dif);

            questao[i].dificuldade = dif;

            //setbuf(stdin, NULL);

            i++;
            contador++;

            printf("Deseja inserir mais questões?\n");
            printf("1 - sim\n");
            printf("0 - não\n");
            scanf("%d", &op);

            getchar();

        }while(op != 0);

        printf("quant de questoes: %d\n", contador);
        gravar(contador);

        printf("\n");

}

void gravar(int contador){
    FILE * arq;
    arq = fopen("questoes.txt", "ab");

    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
    }
    else{
        fwrite(&questao, sizeof(QUESTAO), contador, arq);

        if(ferror(arq)){
            printf("erro na gravação do arquivo\n");
        }
        else{
            printf("gravado em arquivo com sucesso!\n");
            printf("\n");
        }
    }

    fclose(arq);
}

void Imprimir(){
    FILE *arq;
    arq = fopen("questoes.txt", "rb");

    fread(&teste, sizeof(QUESTAO), 50, arq);

    int i = 0;

    do{
        i++;
    }while(teste[i].dificuldade != NULL);

    for(int j = 0; j < i; j++){
        printf("\n");
        printf("Assunto principal: %s", teste[j].a_principal);
        printf("Assunto secundário: %s", teste[j].a_secundario);
        printf("Dificuldade: %d\n", teste[j].dificuldade);
        printf("Sentença verdadeira: %s", teste[j].s_verdadeira);
        printf("Sentença falsa: %s", teste[j].s_falsa);
        printf("\n");
    }

    printf("Dados recuperados do arquvio: %d\n", i);

    fclose(arq);
}

void gerar_prova(){
    FILE *arq;
    arq = fopen("questoes.txt", "rb");

    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
    }
    else{
        fread(&gerando_prova, sizeof(QUESTAO), 50, arq);
        
        int n;
        srand(time(NULL));

        n = rand()%9;

        if(n < 3 || n > 8){
            while(n < 3 || n > 8){
                n = rand()%9;
            }
        }

        printf("O n: %d\n", n);

        int id[n], i, j;

        for(i = 0; i < n; i++){
            id[i] = rand()%26;
            if(i > 0)
                for(j = i-1; j>=0; j--){
                    if(id[i] == id[j]){
                        while(id[i] == id[j]){
                            id[i] = rand()%26;
                        }
                    }
                }
            }

        QUESTAO prova_questoes[n];

        for(int i = 0; i < n; i++){
          // printf("%d\n", id[i]);
          // printf("%s\n", gerando_prova[id[i]].a_principal);
          prova_questoes[i] = gerando_prova[id[i]];
          //printf("%s\n", prova_questoes[i].a_principal);
        }

        PROVA prova[n];
        GABARITO gabarito[n];

        int verdadeiro_falsa[n];
        int aux = 1;

        do{
            for(int i = 0; i < n; i++){
                verdadeiro_falsa[i] = rand() % 2;
            }
            for(int i = 0; i < n; i++){
                if(verdadeiro_falsa[i] == verdadeiro_falsa[i + 1]){
                    aux = 1;
                }
                else{
                    aux = 0;
                    break;
                }
            }
        }while(aux == 1);

        for(int i = 0; i < n; i++){
            if(verdadeiro_falsa[i] == 1){
                strcpy(prova[i].questoes, prova_questoes[i].s_verdadeira);
                gabarito[i].resposta = 'V';
            }
            else{
                strcpy(prova[i].questoes, prova_questoes[i].s_falsa);
                gabarito[i].resposta = 'F';
            }
            prova[i].id = i+1;
            printf("Sentenças: %s\n", prova[i].questoes);

            gabarito[i].id = i+1;
            strcpy(gabarito[i].a_principal, prova_questoes[i].a_principal);
            strcpy(gabarito[i].a_secundario, prova_questoes[i].a_secundario);
            gabarito[i].dificuldade = prova_questoes[i].dificuldade;

        }

        FILE *arq2;
        arq2 = fopen("prova.txt", "wb");

        for(int i = 0; i < n; i++){
            fprintf(arq2, " Questao %d - A sentença abaixo é verdadeira ou falsa?\n", prova[i].id);
            fprintf(arq2, " ( ) %s \n", prova[i].questoes);
        }

        printf("Arquivo de prova gerado!\n");

        FILE *arq3;
        arq3 = fopen("gabarito.txt", "wb");

        for(int i = 0; i < n; i++){
            fprintf(arq3, "Q%d\n", gabarito[i].id);
            fprintf(arq3, "Assunto principal: %s\n", gabarito[i].a_principal);
            fprintf(arq3, "Assunto secundário: %s\n", gabarito[i].a_secundario);
            if(gabarito[i].dificuldade == 1){
                fprintf(arq3, "Dificuldade: fácil\n", gabarito[i].dificuldade);
            }
            else if(gabarito[i].dificuldade == 2){
                fprintf(arq3, "Dificuldade: médio\n", gabarito[i].dificuldade);
            }
            else{
                fprintf(arq3, "Dificuldade: difícil\n", gabarito[i].dificuldade);
            }
            fprintf(arq3, "Respostas: %c\n", gabarito[i].resposta);
        }

        printf("Arquivo de gabarito gerado!\n");

        fclose(arq);
        fclose(arq2);
        fclose(arq3);
    }
}

int main(){
    int op;
    do{
        printf("=============================\n");
        printf("SISTEMA DE GERAÇÂO DE PROVAS\n");
        printf("=============================\n");
        printf("\n");

        printf("O que deseja fazer?\n");
        printf("\n");
        printf("1 - Inserir novas setenças\n");
        printf("2 - Mostrar questões\n");
        printf("3 - Gerar uma prova\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                Inserir();
            break;
            case 2:
                Imprimir();
            break;
            case 3:
                gerar_prova();
            break;
        }

    }while(op != 0);
    
}