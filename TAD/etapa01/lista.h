
#include <stdbool.h>


typedef struct lista Lista;


Lista* lista_criar();
bool lista_inicializar(Lista* lista);
bool lista_anexar(int elemento, Lista* lista);
bool lista_inserir(int elemento, int pos, Lista* lista);
void lista_print(Lista* lista);