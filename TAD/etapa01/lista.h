
#include <stdbool.h>
#include <stdio.h>


typedef struct lista Lista;


Lista* lista_criar();
bool lista_inicializar(Lista* lista);
bool lista_anexar(int elemento, Lista* lista);
bool lista_inserir(int elemento, int pos, Lista* lista);
void lista_print(Lista* lista);

void lista_destruir(Lista* lista);
bool lista_substituir(int elemento, int pos, Lista* lista);
int lista_removerPorPosicao1(int pos, Lista* lista);
bool lista_removerPorPosicao2(int pos, Lista* lista, int* endereco);

int lista_removerPorElemento(int elemento, Lista* lista);
int lista_tamanho(Lista* lista);
int lista_getPosicao(int elemento, Lista* lista);
int lista_getElemento(int pos, Lista* lista);
bool lista_toString(char* saida, Lista* lista);