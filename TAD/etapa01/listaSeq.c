
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

#define TAMANHO 3
#define DEBUG 1

/********************************************
 * Especificação dos dados
 *******************************************/
struct lista {
  int* dados;
  int qtde;
  int tam;
};

/********************************************
 * Funções Auxiliares
 *******************************************/
void verificaAumenta(Lista* lista) {
    if (lista->qtde < lista->tam) return;
    
    int novoTamanho = lista->tam * 2;

    int* novo = (int*) calloc(novoTamanho, sizeof(int));
    // copia
    for (int i=0; i < lista->qtde; i++) {
        novo[i] = lista->dados[i];
    }

    free(lista->dados);
    lista->dados = novo;
    lista->tam = novoTamanho;
}

void verificaDiminui(Lista* lista) {
    
    if ((double)lista->qtde / lista->tam > 0.25) return;
    
    int novoTamanho = lista->tam / 2;

    int* novo = (int*) calloc(novoTamanho, sizeof(int));
    // copia
    for (int i=0; i < lista->qtde; i++) {
        novo[i] = lista->dados[i];
    }

    free(lista->dados);
    lista->dados = novo;
    lista->tam = novoTamanho;
}

/********************************************
 * IMPLEMENTAÇÃO DAS OPERAÇÕES
 *******************************************/
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
    verificaAumenta(lista);
    if (DEBUG) printf("Ocupação %d/%d (%.2f)\n", lista->qtde, lista->tam, (double)lista->qtde / lista->tam );

    lista->dados[lista->qtde] = elemento;
    lista->qtde++;
    return true;
}

bool lista_inserir(int elemento, int pos, Lista* lista){

    if (pos < 0) return false;
    if (pos > lista->qtde) return false;
    if (lista == NULL) return false;

    verificaAumenta(lista);
    
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

void lista_print(Lista* lista){
    printf("[");
    for (int i=0; i < lista->qtde; i++){
        printf("%d", lista->dados[i]);
        if (i < lista->qtde -1) printf(",");
    }
    printf("]");
}

int lista_tamanho(Lista* lista){
    if (lista == NULL) return -1;

    return lista->qtde;
}

int lista_removerPorPosicao1(int pos, Lista* lista){
    if (pos < 0) return -999;
    if (pos >= lista->qtde) return -999;
    if (lista == NULL) return -999;

    int elementoRemovido = lista->dados[pos];
    // deslocamento
    for (int i = pos; i < lista->qtde-1; i++) {
        lista->dados[i] = lista->dados[i+1];
    }
    lista->qtde--;

    verificaDiminui(lista);
    if (DEBUG) printf("Ocupação %d/%d (%.2f)\n", lista->qtde, lista->tam, (double)lista->qtde / lista->tam );    

    return elementoRemovido;
}

bool lista_removerPorPosicao2(int pos, Lista* lista, int* endereco){
    if (pos < 0) return false;
    if (pos >= lista->qtde) return false;
    if (lista == NULL) return false;

    int elementoRemovido = lista->dados[pos];
    // deslocamento
    for (int i = pos; i < lista->qtde; i++) {
        lista->dados[i] = lista->dados[i+1];
    }
    lista->qtde--;

    verificaDiminui(lista);

    *endereco = elementoRemovido;
    return true;
}

int lista_removerPorElemento(int elemento, Lista* lista){
    if (lista == NULL) return -1;
    
    int pos = -1;
    for (int i=0; i < lista->qtde; i++) {
        if (elemento == lista->dados[i]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return -1;

    lista_removerPorPosicao1(pos, lista);
    return pos;
}