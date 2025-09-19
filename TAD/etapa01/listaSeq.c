
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

#define TAMANHO 10

struct lista {
  int* dados;
  int qtde;
  int tam;
};

Lista* lista_criar(){    
    Lista* novaLista = (Lista*) malloc(sizeof(Lista));
    lista_inicializar(novaLista);
    return novaLista;
}

bool lista_inicializar(Lista* lista){
    lista->dados = (int*) malloc(TAMANHO * sizeof(int));
    lista->qtde = 0;
    lista->tam = TAMANHO;
    return true;
}


bool lista_anexar(int elemento, Lista* lista){

    lista->dados[lista->qtde] = elemento;
    lista->qtde++;
    return true;
}

void lista_print(Lista* lista){
    printf("[");
    for (int i=0; i < lista->qtde; i++){
        printf("%d", lista->dados[i]);
        if (i < lista->qtde -1) printf(",");
    }
    printf("]");
}

bool lista_inserir(int elemento, int pos, Lista* lista){

    if (pos < 0) return false;
    if (pos > lista->qtde) return false;
    if (lista == NULL) return false;

    // if (lista->qtde == lista->tam) aumentaTamanho();
    

    // Deslocamento
    for (int i=lista->qtde; i > pos; i-- ){
        lista->dados[i] = lista->dados[i-1];
    }

    // memcpy(enderecoDestino, enderecoOrigem, qtdeBytesCopiados)    
    // memcpy(lista->dados+pos+1, lista->dados+pos, (lista->qtde-pos)*sizeof(int));
    

    lista->dados[pos] = elemento;
    lista->qtde++;
    return true;
    
}