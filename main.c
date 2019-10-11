#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    //armazena a funcionalidade a ser executada
    char valor[1];
    //armazena o nome dos arquivos a serem executados e no caso da funcionalidade 4, o valor a ser pesquisado
    char campos[3][100];
    //armazena (caso exista, o RRN)
    int RRN;
    //armazena (caso necessário) a lista de valores a serem utilizados na funcionalidade 5, 6 e 7
    int *inicio_lista;
    //caso exista a lista, armazena quantas valores existem na lista
    int qnt;
}Entrada;


typedef struct{
    char campo1[100];
    char campo2[100];
}dados;
//1 arquivoEntrada.csv arquivoGerado.bin
//2 arquivoGerado.bin
//3 arquivoGerado.bin NomeDoCampo valor
//4 arquivoGerado.bin 6
//8 arquivoGeradoEntrada.bin arquivoGerado.bin
/*
Função que lê a entrada de um arquivo e retorna uma struct com os valores da entrada
*/
Entrada ler_entrada(){
    Entrada entrada;
    char inicio[256];
    int c = 0;
    printf("entrada\n");
    //usar o scanf não funciona :(
    gets(inicio);
    char* p = strtok(inicio, " ");
    strcpy(entrada.valor, inicio);
    if(entrada.valor[0] == '1'||entrada.valor[0] == '2'||entrada.valor[0] == '3'||entrada.valor[0] == '8'){
        int i = 0;
        while((p = strtok(NULL, " ")) != NULL){
            strcpy(entrada.campos[i], p);
            i++;
        }
        for(i=0; i<3;i++){
            printf("%s\n", entrada.campos[i]);
        }
    }else if(entrada.valor[0] == '4'){
        int i = 0;
        while((p = strtok(NULL, " ")) != NULL){
            if(i == 0){
                strcpy(entrada.campos[0], p);
                i++;
            }else{
                char rrn[1];
                strcpy(rrn, p);
                entrada.RRN = atoi(rrn);
                printf("%d", entrada.RRN);
            }
        }
    }
};

int main(){
    ler_entrada();
    return 0;
}
