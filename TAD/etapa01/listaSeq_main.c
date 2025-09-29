#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"


void testeRemoverPorPosicao1(){
  printf("\n--- Teste Remover Por Posicao 1 ---\n");
  Lista* l1 = lista_criar();  
  lista_anexar(10, l1);
  lista_anexar(20, l1);
  lista_anexar(30, l1);
  lista_anexar(40, l1);

  printf("Excecoes \n");
  printf("[%s] Remocao de uma posicao inexistente (negativa) \n", -999 == lista_removerPorPosicao1(-1, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao de uma posicao inexistente (maior) \n", -999 == lista_removerPorPosicao1(19, l1) ? "PASS" : "FAIL");
  printf("[%s] Tamanho da lista nao deve ser alterado \n", 4 == lista_tamanho(l1) ? "PASS" : "FAIL");
  
  
  printf("Casos de teste \n");
  printf("[%s] Remocao no Meio \n", 20 == lista_removerPorPosicao1(1, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao do primeira \n", 10 == lista_removerPorPosicao1(0, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao do Ultimo \n", 40 == lista_removerPorPosicao1(1, l1) ? "PASS" : "FAIL");
  printf("[%s] Remocao do unico \n", 30 == lista_removerPorPosicao1(0, l1) ? "PASS" : "FAIL");
  printf("[%s] Tamanho da lista apos remocoes \n", 0 == lista_tamanho(l1) ? "PASS" : "FAIL");

  lista_destruir(l1);
}

void testeRemoverPorPosicao2(){
  printf("\n--- Teste Remover Por Posicao 2 ---\n");
  Lista* l1 = lista_criar();  
  lista_anexar(10, l1);
  lista_anexar(20, l1);
  lista_anexar(30, l1);
  lista_anexar(40, l1);

  int elementoRemovido;

  printf("Excecoes \n");
  printf("[%s] Remocao de uma posicao inexistente (negativa) \n", false == lista_removerPorPosicao2(-1, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao de uma posicao inexistente (maior) \n", false == lista_removerPorPosicao2(19, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Tamanho da lista nao deve ser alterado \n", 4 == lista_tamanho(l1) ? "PASS" : "FAIL");
  
  
  printf("Casos de teste \n");
  printf("[%s] Remocao no Meio (retorno) \n", true == lista_removerPorPosicao2(1, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao no Meio (valor) \n", 20 == elementoRemovido ? "PASS" : "FAIL");
  
  printf("[%s] Remocao do primeira (retorno) \n", true == lista_removerPorPosicao2(0, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao do primeira (valor) \n", 10 == elementoRemovido ? "PASS" : "FAIL");
  
  printf("[%s] Remocao do Ultimo (retorno) \n", true == lista_removerPorPosicao2(1, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao do Ultimo (valor) \n", 40 == elementoRemovido ? "PASS" : "FAIL");
  
  printf("[%s] Remocao do unico (retorno) \n", true == lista_removerPorPosicao2(0, l1, &elementoRemovido) ? "PASS" : "FAIL");
  printf("[%s] Remocao do unico (valor) \n", 30 == elementoRemovido ? "PASS" : "FAIL");

  printf("[%s] Tamanho da lista apos remocoes \n", 0 == lista_tamanho(l1) ? "PASS" : "FAIL");

  lista_destruir(l1);
}

void teste_removerPorElemento(){
    printf("\n--- Teste Remover Por Elemento ---\n");
    Lista* l1 = lista_criar();
    lista_anexar(10, l1);
    lista_anexar(20, l1);
    lista_anexar(30, l1);
    lista_anexar(40, l1);

    printf("Casos de teste\n");
    printf("[%s] Remover elemento do meio (retorno) \n", 1 == lista_removerPorElemento(20, l1) ? "PASS" : "FAIL");
    printf("[%s] Tamanho apos remocao \n", 3 == lista_tamanho(l1) ? "PASS" : "FAIL");
    printf("[%s] Remover primeiro elemento (retorno) \n", 0 == lista_removerPorElemento(10, l1) ? "PASS" : "FAIL");
    printf("[%s] Remover ultimo elemento (retorno) \n", 1 == lista_removerPorElemento(40, l1) ? "PASS" : "FAIL");

    char saida[100];
    lista_toString(saida, l1);
    printf("Lista apos remocoes: %s\n", saida);
    printf("[%s] Conteudo da lista \n", strcmp(saida, "[30]") == 0 ? "PASS" : "FAIL");

    printf("Excecoes\n");
    printf("[%s] Remover elemento inexistente \n", -1 == lista_removerPorElemento(99, l1) ? "PASS" : "FAIL");
    printf("[%s] Tamanho da lista inalterado \n", 1 == lista_tamanho(l1) ? "PASS" : "FAIL");

    lista_destruir(l1);
}

void teste_inserir(){
    printf("\n--- Teste Inserir ---\n");
    Lista* l1 = lista_criar();
    lista_anexar(10, l1);
    lista_anexar(30, l1);

    printf("Casos de teste \n");
    printf("[%s] Inserir no meio \n", true == lista_inserir(20, 1, l1) ? "PASS" : "FAIL");
    printf("[%s] Tamanho apos insercao \n", 3 == lista_tamanho(l1) ? "PASS" : "FAIL");
    printf("[%s] Inserir no inicio \n", true == lista_inserir(5, 0, l1) ? "PASS" : "FAIL");
    printf("[%s] Inserir no fim \n", true == lista_inserir(40, 4, l1) ? "PASS" : "FAIL");
    
    char saida[100];
    lista_toString(saida, l1);
    printf("Lista final: %s\n", saida);
    printf("[%s] Conteudo da lista \n", strcmp(saida, "[5,10,20,30,40]") == 0 ? "PASS" : "FAIL");

    printf("Excecoes \n");
    printf("[%s] Inserir em posicao negativa \n", false == lista_inserir(99, -1, l1) ? "PASS" : "FAIL");
    printf("[%s] Inserir em posicao invalida \n", false == lista_inserir(99, 10, l1) ? "PASS" : "FAIL");

    lista_destruir(l1);
}

void teste_substituir(){
    printf("\n--- Teste Substituir ---\n");
    Lista* l1 = lista_criar();
    lista_anexar(10, l1);
    lista_anexar(20, l1);
    lista_anexar(30, l1);

    printf("Casos de teste \n");
    printf("[%s] Substituir no meio \n", true == lista_substituir(25, 1, l1) ? "PASS" : "FAIL");
    printf("[%s] Valor substituido \n", 25 == lista_getElemento(1, l1) ? "PASS" : "FAIL");
    printf("[%s] Tamanho da lista inalterado \n", 3 == lista_tamanho(l1) ? "PASS" : "FAIL");

    printf("Excecoes \n");
    printf("[%s] Substituir em posicao negativa \n", false == lista_substituir(99, -1, l1) ? "PASS" : "FAIL");
    printf("[%s] Substituir em posicao invalida \n", false == lista_substituir(99, 3, l1) ? "PASS" : "FAIL");

    lista_destruir(l1);
}

void teste_getPosicao_e_getElemento(){
    printf("\n--- Teste GetPosicao e GetElemento ---\n");
    Lista* l1 = lista_criar();
    lista_anexar(10, l1);
    lista_anexar(20, l1);
    lista_anexar(30, l1);

    printf("Casos de teste - getElemento\n");
    printf("[%s] Get elemento no meio \n", 20 == lista_getElemento(1, l1) ? "PASS" : "FAIL");
    printf("[%s] Get primeiro elemento \n", 10 == lista_getElemento(0, l1) ? "PASS" : "FAIL");
    printf("[%s] Get ultimo elemento \n", 30 == lista_getElemento(2, l1) ? "PASS" : "FAIL");

    printf("Excecoes - getElemento\n");
    printf("[%s] Get elemento em posicao negativa \n", -999 == lista_getElemento(-1, l1) ? "PASS" : "FAIL");
    printf("[%s] Get elemento em posicao invalida \n", -999 == lista_getElemento(3, l1) ? "PASS" : "FAIL");

    printf("Casos de teste - getPosicao\n");
    printf("[%s] Get posicao do meio \n", 1 == lista_getPosicao(20, l1) ? "PASS" : "FAIL");
    printf("[%s] Get posicao do primeiro \n", 0 == lista_getPosicao(10, l1) ? "PASS" : "FAIL");
    printf("[%s] Get posicao do ultimo \n", 2 == lista_getPosicao(30, l1) ? "PASS" : "FAIL");

    printf("Excecoes - getPosicao\n");
    printf("[%s] Get posicao de elemento inexistente \n", -1 == lista_getPosicao(99, l1) ? "PASS" : "FAIL");
    
    lista_destruir(l1);
}

void teste_toString(){
    printf("\n--- Teste toString ---\n");
    Lista* l1 = lista_criar();
    char saida[100];

    printf("Casos de teste\n");
    lista_toString(saida, l1);
    printf("Lista vazia: %s\n", saida);
    printf("[%s] Lista vazia \n", strcmp(saida, "[]") == 0 ? "PASS" : "FAIL");

    lista_anexar(10, l1);
    lista_toString(saida, l1);
    printf("Lista com 1 elemento: %s\n", saida);
    printf("[%s] Lista com 1 elemento \n", strcmp(saida, "[10]") == 0 ? "PASS" : "FAIL");

    lista_anexar(20, l1);
    lista_anexar(30, l1);
    lista_toString(saida, l1);
    printf("Lista com 3 elementos: %s\n", saida);
    printf("[%s] Lista com 3 elementos \n", strcmp(saida, "[10,20,30]") == 0 ? "PASS" : "FAIL");

    lista_destruir(l1);
}

void teste_redimensionamento(){
    printf("\n--- Teste Redimensionamento (Aumenta/Diminui) ---\n");
    Lista* l1 = lista_criar();
    
    printf("Teste de aumento de capacidade\n");
    // Assumindo TAMANHO inicial = 10
    for(int i=0; i < 10; i++){
        lista_anexar(i*10, l1);
    }
    printf("[%s] Tamanho da lista antes de estourar \n", 10 == lista_tamanho(l1) ? "PASS" : "FAIL");
    
    // O 11º elemento deve forçar o aumento da lista
    lista_anexar(100, l1);
    printf("[%s] Tamanho da lista apos estourar \n", 11 == lista_tamanho(l1) ? "PASS" : "FAIL");
    printf("[%s] Elemento inserido apos aumento \n", 100 == lista_getElemento(10, l1) ? "PASS" : "FAIL");

    printf("\nTeste de diminuicao de capacidade\n");
    // A capacidade dobrou para 20. A diminuicao ocorre quando qtde/tam <= 0.25
    // Com tam=20, a diminuicao ocorre quando qtde <= 5.
    // Removendo até 5 elementos.
    while(lista_tamanho(l1) > 5){
        lista_removerPorPosicao1(0, l1);
    }
    printf("[%s] Tamanho da lista antes de diminuir \n", 5 == lista_tamanho(l1) ? "PASS" : "FAIL");

    // A proxima remocao deve acionar a diminuicao
    lista_removerPorPosicao1(0, l1);
    printf("[%s] Tamanho da lista apos diminuir \n", 4 == lista_tamanho(l1) ? "PASS" : "FAIL");
    
    // Esvaziar a lista
    while(lista_tamanho(l1) > 0){
        lista_removerPorPosicao1(0, l1);
    }
    printf("[%s] Tamanho final da lista \n", 0 == lista_tamanho(l1) ? "PASS" : "FAIL");

    lista_destruir(l1);
}


int main() {
  printf("INICIO DOS TESTES\n");

  testeRemoverPorPosicao1();
  testeRemoverPorPosicao2();
  teste_removerPorElemento();
  teste_inserir();
  teste_substituir();
  teste_getPosicao_e_getElemento();
  teste_toString();
  teste_redimensionamento();

  printf("\nFIM DOS TESTES\n");
  return 0;
}