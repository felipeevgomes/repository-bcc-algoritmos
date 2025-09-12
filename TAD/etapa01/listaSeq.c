
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int dados[10];    
    int qtde;
    int tam;
} ListaSeq;

ListaSeq* lista_criar(){
    ListaSeq* novaLista = (ListaSeq*) malloc(sizeof(ListaSeq));
    novaLista->qtde = 0;
    novaLista->tam = 10;
    return novaLista;
}


bool lista_anexar(int elemento, ListaSeq* lista){

    lista->dados[lista->qtde] = elemento;
    lista->qtde++;
    return true;
}

// bool lista_inserir(int elemento, int pos, ListaSeq* lista){

// }

void lista_print(ListaSeq* lista){
    printf("[");
    for (int i=0; i < lista->qtde; i++){
        printf("%d", lista->dados[i]);
        if (i < lista->qtde -1) printf(",");
    }
    printf("]");
}
