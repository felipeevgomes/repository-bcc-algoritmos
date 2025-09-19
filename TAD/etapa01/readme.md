# TAD - O que?

## Dados
Uma lista de números inteiros. 

```c++
typedef struct ListaSeq;
```



## Operações

**Ciclo de vida**

- [x] Criar uma lista
```c++

Lista* lista_criar();

Lista* l1 = lista_criar();

```

- [ ] Destruir uma lista (Memória)
  
### **Funcionalidades de Modificação**

- [x] Insere um elemento no final da lista
```c++

bool lista_anexar(int elemento, Lista* lista);

Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]


```
- [ ] Insere um elemento em qualquer posição da lista
```c++
bool lista_inserir(int elemento, int pos, Lista* lista);

Lista* l1 = lista_criar();
lista_inserir(10, 0, l1);  // [10]
lista_inserir(20, 1, l1);  // [10, 20]
lista_inserir(5, 0, l1);   // [5, 10, 20]
lista_inserir(15, 2, l1);  // [5, 10, 15, 20]
lista_print();
```

- [ ] Substitui um elemento da lista
```c++
bool lista_substituir(int elemento, int pos, Lista* lista);

Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]
lista_anexar(30, l1);  // [10, 20, 30]

lista_substituir(11, 0, l1);
lista_substituir(21, 1, l1);
lista_substituir(31, 2, l1); // [11, 21, 31]
lista_print();
```  

- [ ] Remove um elemento de uma posição da lista
```c++
bool lista_remover(int pos, Lista* lista);

Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  
lista_anexar(40, l1);  // [10, 20, 30, 40]

lista_removerPorPosicao(1, l1);  // [10, 30, 40]
lista_removerPorPosicao(2, l1);  // [10, 30]
lista_removerPorPosicao(0, l1);  // [30]
lista_removerPorPosicao(0, l1);  // []

```

- [ ] Remove um elemento da lista

```c++
bool lista_remover(int pos, Lista* lista);

Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  
lista_anexar(40, l1);  // [10, 20, 30, 40]

lista_removerPorElemento(20, l1);  // [10, 30, 40]
lista_removerPorElemento(40, l1);  // [10, 30]
lista_removerPorElemento(10, l1);  // [30]
lista_removerPorElemento(30, l1);  // []

```
  

### **Funcionalidades de consulta**

- [x] Imprime o conteúdo da lista
```c++
void lista_print(Lista* lista);
```

- [ ] Obtém a quantidade de elementos da lista
```c++

```

- [ ] Obtém a posição de um elemento na lista
```c++

```

- [ ] Obtém o elemento que ocupa uma posição da lista

```c++

Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]
lista_anexar(30, l1);   // [10, 20, 30]

int x = lista_elemento(10, l1);


```  

### **Funcionalidades Extra**

- [ ] Devolver o conteúdo da lista na forma de string

```c++

```



# Implementação usando organização sequencial

A implementação da lista sequencial utiliza um vetor dinâmico para armazenar os elementos inteiros. Os atributos: 
- `dados` é um ponteiro para o início do vetor de inteiros; 
- `qtde` representa a quantidade atual de elementos armazenados na lista, e 
- `tam` indica a capacidade máxima do vetor alocado no momento. 

 
Quando a lista atinge sua capacidade máxima, é necessário realocar o vetor para aumentar o espaço disponível, permitindo a inserção de novos elementos. Todas as operações de inserção, remoção e acesso aos elementos são realizadas por meio do índice, o que garante acesso rápido, porém pode exigir deslocamento dos elementos em operações que não sejam no final da lista.


```c++
struct lista {
  int* dados;
  int qtde;
  int tam;
};
```

