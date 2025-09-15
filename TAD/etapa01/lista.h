
#include <stdbool.h>


typedef struct lista Lista;


Lista* lista_criar();
bool lista_anexar(int elemento, Lista* lista);
void lista_print(Lista* lista);