#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int valor;
    char campo1[100];
    char campo2[100];
    int RRN;
    int qnt;
}Entrada;

typedef struct{
    char campo1[100];
    char campo2[100];
}dados;


Entrada ler_entrada(){
    Entrada entrada;
    char inicio[256];
    char delim[] = " ";
    char* token;
    int c = 0,i;
    printf("entrada\n");
    scanf("%s", inicio);
    for (token = strtok(inicio, delim); token; token = strtok(NULL, delim))
    {
        printf("token=%s\n", token);
    }

};

int main(){
    ler_entrada();
    return 0;
}
