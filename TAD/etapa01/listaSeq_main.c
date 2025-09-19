#include "lista.h"

int main() {

Lista* l1 = lista_criar();
lista_inserir(10, 0, l1);  // [10]
lista_inserir(20, 1, l1);  // [10, 20]
lista_inserir(5, 0, l1);   // [5, 10, 20]
lista_inserir(15, 2, l1);  // [5, 10, 15, 20]
lista_print(l1);

Lista* l2 = lista_criar();
lista_inserir(10, 0, l2);  // [10]
lista_inserir(20, 1, l2);  // [10, 20]
lista_inserir(5, 4, l2);   
lista_inserir(15, -2, l2);  
lista_print(l2);

}