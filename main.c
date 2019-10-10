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

int split (const char *str, char c, char ***arr){
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;
    p = str;
    while (*p != '\0'){
        if (*p == c){
            count++;
        }
        p++;
    }

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0'){
        if (*p == c){
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL){
                    exit(1);
            }
            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL){
            exit(1);
    }
    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0'){
        if (*p != c && *p != '\0'){
            *t = *p;
            t++;
        }else{
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }
    return count;
}


Entrada ler_entrada(){
    Entrada entrada;
    char *inicio;
    inicio = malloc(256*sizeof(char));
    int c = 0,i;
    char **arr = NULL;
    printf("entrada\n");
    scanf("%s", inicio);
    c = split(inicio, ' ', &arr);
    for (i = 0; i < c; i++)
        printf("string #%d: %s\n", i, arr[i]);

};

int main(){
    ler_entrada();
    return 0;
}
