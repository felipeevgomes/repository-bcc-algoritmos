
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista.h"
              
struct lista {
  int* dados;
  int qtde;
  int tam;
};

Lista* lista_criar(){
    int tamanho = 10;
    Lista* novaLista = (Lista*) malloc(sizeof(Lista));
    novaLista->dados = (int*) malloc(tamanho * sizeof(int));
    novaLista->qtde = 0;
    novaLista->tam = tamanho;
    return novaLista;
}


bool lista_anexar(int elemento, Lista* lista){

    lista->dados[lista->qtde] = elemento;
    lista->qtde++;
    return true;
}

// bool lista_inserir(int elemento, int pos, Lista* lista){

// }

void lista_print(Lista* lista){
    printf("[");
    for (int i=0; i < lista->qtde; i++){
        printf("%d", lista->dados[i]);
        if (i < lista->qtde -1) printf(",");
    }
    printf("]");
}
