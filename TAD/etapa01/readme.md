# TAD - O que?

## Dados
Uma lista de números inteiros. 

```c++
typedef struct ListaSeq;
```

## Operações

**Ciclo de vida**

- [x] Criar uma lista
- [ ] Destruir uma lista (Memória)
  
**Funcionalidades de Modificação**

- [x] Insere um elemento no final da lista
```c++
bool lista_anexar(int elemento, Lista* lista);
```
- [ ] Insere um elemento em qualquer posição da lista
```c++
bool lista_inserir(int elemento, int pos, Lista* lista);

Lista* l1 = lista_criar();
lista_inserir(10, 0, l1);  // [10]
lista_inserir(20, 1, l1);  // [10, 20]
lista_inserir(5, 0, l1);   // [5, 10, 20]
lista_inserir(15, 2, l1);   // [5, 10, 15, 20]
lista_print();
```

- [ ] Substitui um elemento da lista
```c++
bool lista_substituir(int elemento, int pos, Lista* lista);

Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]
lista_anexar(30, l1);   // [10, 20, 30]

lista_substituir(11, 0, l1);
lista_substituir(21, 1, l1);
lista_substituir(31, 2, l1); // [11, 21, 31]
lista_print();
```  

- [ ] Remove um elemento de uma posição da lista
- [ ] Remove um elemento da lista
  

**Funcionalidades de consulta**

- [x] Imprime o conteúdo da lista
- [ ] Obtém a quantidade de elementos da lista
- [ ] Obtém a posição de um elemento na lista
- [ ] Obtém o elemento que ocupa uma posição da lista
```c++

Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]
lista_anexar(30, l1);   // [10, 20, 30]

int x = lista_elemento(10, l1);


```  

**Funcionalidades Extra**
- [ ] Devolver o conteúdo da lista na forma de string


  