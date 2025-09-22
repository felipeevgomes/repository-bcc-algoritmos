#include "lista.h"


void testeRemoverPorPosicao1(){
  Lista* l1 = lista_criar();  
  lista_anexar(10, l1);
  lista_anexar(20, l1);
  lista_anexar(30, l1);
  lista_anexar(40, l1);

  printf("Excecoes \n");
  printf("[%s] Remocao de uma posicao inexistente \n", -999 == lista_removerPorPosicao1(-1, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao de uma posicao inexistente \n", -999 == lista_removerPorPosicao1(19, l1) ? "PASS" : "FAIL");
  printf("[%s] Tamanho da lista \n", 4 == lista_tamanho(l1) ? "PASS" : "FAIL");
  
  
  printf("Casos de teste \n");
  printf("[%s] Remocao no Meio \n", 20 == lista_removerPorPosicao1(1, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao do primeira \n", 10 == lista_removerPorPosicao1(0, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao do Ultimo \n", 40 == lista_removerPorPosicao1(1, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao do unico \n", 30 == lista_removerPorPosicao1(0, l1) ? "PASS" : "FAIL");
  printf("[%s] Tamanho da lista \n", 0 == lista_tamanho(l1) ? "PASS" : "FAIL");

}
void testeRemoverPorPosicao2(){
  Lista* l1 = lista_criar();  
  lista_anexar(10, l1);
  lista_anexar(20, l1);
  lista_anexar(30, l1);
  lista_anexar(40, l1);

  int elementoRemovido;

  printf("Excecoes \n");
  printf("[%s] Remocao de uma posicao inexistente \n", false == lista_removerPorPosicao2(-1, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao de uma posicao inexistente \n", false == lista_removerPorPosicao2(19, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Tamanho da lista \n", 4 == lista_tamanho(l1) ? "PASS" : "FAIL");
  
  
  printf("Casos de teste \n");
  printf("[%s] Remocao no Meio \n", true == lista_removerPorPosicao2(1, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao no Meio \n", 20 == elementoRemovido ? "PASS" : "FAIL");
  
  printf("[%s] Remocao do primeira \n", true == lista_removerPorPosicao2(0, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao do primeira \n", 10 == elementoRemovido ? "PASS" : "FAIL");
  
  printf("[%s] Remocao do Ultimo \n", true == lista_removerPorPosicao2(1, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao do Último \n", 40 == elementoRemovido ? "PASS" : "FAIL");
  
  printf("[%s] Remocao do unico \n", true == lista_removerPorPosicao2(0, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao do unico \n", 30 == elementoRemovido ? "PASS" : "FAIL");

  printf("[%s] Tamanho da lista \n", 0 == lista_tamanho(l1) ? "PASS" : "FAIL");

}

void testeAumenta() {
  Lista* l1 = lista_criar();  
  lista_anexar(10, l1);
  lista_anexar(20, l1);
  lista_anexar(30, l1);
  lista_anexar(40, l1); // Aumentar a capacidade 
  lista_anexar(50, l1);
  lista_anexar(60, l1);
  lista_anexar(70, l1); // Aumenta a capacidade

  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
  lista_removerPorPosicao1(0, l1);
}

int main() {

  // testeRemoverPorPosicao1();
  // testeRemoverPorPosicao2();
  testeAumenta();

}