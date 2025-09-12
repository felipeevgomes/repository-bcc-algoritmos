#include "listaSeq.c"

int main() {

int i;
ListaSeq* l1 = lista_criar();

lista_anexar(1, l1);  // [1]
lista_anexar(2, l1);  // [1,2]
lista_anexar(3, l1);  // [1,2,3]
lista_print(l1); 

// inserir(50, 0, l1);  // [50,1,2,3]
// inserir(100, 2, l1); // [50,1,100,2,3]
// inserir(0, 5, l1); // [50,1,100,2,3]
// print(l1); 


}