
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

#define DEBUG 0

/********************************************
 * Especificação dos dados
 *******************************************/
#define TAMANHO 10

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
    if (DEBUG) printf("Ocupacao %d/%d (%.2f)\n", lista->qtde, lista->tam, (double)lista->qtde / lista->tam );

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
    if (DEBUG) printf("Ocupacao %d/%d (%.2f)\n", lista->qtde, lista->tam, (double)lista->qtde / lista->tam );    

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


/************************************************
 * lista_destruir
 *
 * Libera a memória alocada para a lista.
 *
 * @param lista Ponteiro para a lista a ser destruída.
 ************************************************/
void lista_destruir(Lista* lista){
    if (lista == NULL) return;
    free(lista->dados);
    free(lista);
}

/************************************************
 * lista_substituir
 *
 * Substitui um elemento em uma determinada posição da lista.
 *
 * @param elemento O novo elemento a ser inserido.
 * @param pos A posição do elemento a ser substituído.
 * @param lista Ponteiro para a lista.
 * @return true se a substituição for bem-sucedida, false caso contrário.
 ************************************************/
bool lista_substituir(int elemento, int pos, Lista* lista){
    if (lista == NULL) return false;
    if (pos < 0) return false;
    if (pos >= lista->qtde) return false;

    lista->dados[pos] = elemento;
    return true;
}

/************************************************
 * lista_getPosicao
 *
 * Retorna a posição da primeira ocorrência de um elemento na lista.
 *
 * @param elemento O elemento a ser buscado.
 * @param lista Ponteiro para a lista.
 * @return A posição do elemento ou -1 se não for encontrado.
 ************************************************/
int lista_getPosicao(int elemento, Lista* lista){
    if (lista == NULL) return -1;
    
    for (int i=0; i < lista->qtde; i++) {
        if (elemento == lista->dados[i]) {
            return i;
        }
    }
    return -1;
}

/************************************************
 * lista_getElemento
 *
 * Retorna o elemento em uma determinada posição da lista.
 *
 * @param pos A posição do elemento desejado.
 * @param lista Ponteiro para a lista.
 * @return O elemento na posição especificada ou -999 se a posição for inválida.
 ************************************************/
int lista_getElemento(int pos, Lista* lista){
    if (lista == NULL) return -999;
    if (pos < 0) return -999;
    if (pos >= lista->qtde) return -999;

    return lista->dados[pos];
}

/************************************************
 * lista_toString
 *
 * Converte a lista para uma representação em string.
 * Formato: "[elem1,elem2,...,elemN]"
 *
 * @param saida Ponteiro para a string de saída.
 * @param lista Ponteiro para a lista.
 * @return true se a conversão for bem-sucedida, false caso contrário.
 ************************************************/
bool lista_toString(char* saida, Lista* lista){
    if (lista == NULL) return false;

    int offset = 0;
    offset += sprintf(saida + offset, "[");
    for (int i=0; i < lista->qtde; i++){
        offset += sprintf(saida + offset, "%d", lista->dados[i]);
        if (i < lista->qtde -1) {
            offset += sprintf(saida + offset, ",");
        }
    }
    sprintf(saida + offset, "]");
    return true;
}