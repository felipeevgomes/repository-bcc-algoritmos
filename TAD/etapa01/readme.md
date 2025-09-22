# Introdução: O que é um Tipo Abstrato de Dados (TAD)?

Um Tipo Abstrato de Dados (TAD) é um modelo matemático que define um conjunto de dados e as operações fundamentais que podem ser realizadas sobre eles, sem especificar detalhes de implementação. O objetivo principal de um TAD é separar a interface (o que pode ser feito) da implementação (como é feito), promovendo modularidade, reutilização e facilidade de manutenção do código.

Ao trabalhar com TADs, o programador pode manipular estruturas complexas, como listas, filas, pilhas e árvores, utilizando apenas as operações definidas, sem se preocupar com os detalhes internos de armazenamento ou manipulação dos dados. Isso permite que diferentes implementações possam ser trocadas ou otimizadas sem impactar o restante do sistema, desde que a interface permaneça a mesma.

No contexto deste projeto, o TAD estudado é uma lista de números inteiros, com operações para criação, inserção, remoção, substituição, consulta e impressão dos elementos. A implementação apresentada utiliza uma abordagem sequencial, baseada em vetor dinâmico, para armazenar os dados e gerenciar a capacidade da lista conforme necessário.

# TAD Lista

[Implementação do TAD com abordagem sequencial.](TAD-Lista%20Sequencial.md)


## Dados
Uma lista de números inteiros. 

```c++
typedef struct ListaSeq;
```


## Operações

**Ciclo de vida**

- [x] Criar uma lista
```c++
// Protótipo
Lista* lista_criar();
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
```

- [ ] Destruir uma lista (Memória)

```c++
// Protótipo
void lista_destruir(Lista* lista);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]

lista_destruir(l1);

```
  
### **Funcionalidades de Modificação**

- [x] Insere um elemento no final da lista

```c++
// Protótipo
bool lista_anexar(int elemento, Lista* lista);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]

```

- [x] Insere um elemento em qualquer posição da lista

```c++
// Protótipo
bool lista_inserir(int elemento, int pos, Lista* lista);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_inserir(10, 0, l1);  // [10]
lista_inserir(20, 1, l1);  // [10, 20]
lista_inserir(5, 0, l1);   // [5, 10, 20]
lista_inserir(15, 2, l1);  // [5, 10, 15, 20]
lista_print(l1);
```

- [ ] Substitui um elemento da lista

```c++
// Protótipo
bool lista_substituir(int elemento, int pos, Lista* lista);
```  

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  // [10]
lista_anexar(20, l1);  // [10, 20]
lista_anexar(30, l1);  // [10, 20, 30]

lista_substituir(11, 0, l1);
lista_substituir(21, 1, l1);
lista_substituir(31, 2, l1); // [11, 21, 31]
lista_print(l1);
```

- [x] Inicializar uma Lista já criada


```c++
// Protótipo
bool lista_inicializar(Lista* lista);
```  

```c++
// Uso da Função
Lista l1;
lista_inicializar(&l1);
lista_anexar(10, &l1);  // [10]
lista_anexar(20, &l1);  // [10, 20]
lista_anexar(30, &l1);  // [10, 20, 30]

lista_print(&l1);
```


- [ ] Remove um elemento de uma posição da lista

```c++
// Protótipo
int lista_removerPorPosicao1(int pos, Lista* lista);

bool lista_removerPorPosicao2(int pos, Lista* lista, int* endereco);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  
lista_anexar(40, l1);  // [10, 20, 30, 40]

lista_removerPorPosicao1(1, l1);  // [10, 30, 40]
lista_removerPorPosicao1(2, l1);  // [10, 30]
lista_removerPorPosicao1(0, l1);  // [30]
lista_removerPorPosicao1(0, l1);  // []

lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  
lista_anexar(40, l1);  // [10, 20, 30, 40]

int removido;
lista_removerPorPosicao2(1, l1, &removido);  // [10, 30, 40]
lista_removerPorPosicao2(2, l1, &removido);  // [10, 30]
lista_removerPorPosicao2(0, l1, &removido);  // [30]
lista_removerPorPosicao2(0, l1, &removido);  // []
```

- [ ] Remove um elemento da lista

```c++
// Protótipo
int lista_removerPorElemento(int elemento, Lista* lista);
```

```c++
// Uso da Função
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
// Protótipo
void lista_print(Lista* lista);
```


- [ ] Obtém a quantidade de elementos da lista

```c++
// Protótipo
int lista_tamanho(Lista* lista);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  // [10, 20, 30]

printf("Tamanho: %d \n", lista_tamanho(l1)); // 3
```


- [ ] Obtém a posição de um elemento na lista

```c++
// Protótipo
int lista_getPosicao(int elemento, Lista* lista);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  // [10, 20, 30]

printf("Elemento [%d] - posicao [%d] \n", 10, lista_getPosicao(10, l1)); // 0
printf("Elemento [%d] - posicao [%d] \n", 20, lista_getPosicao(20, l1)); // 1
printf("Elemento [%d] - posicao [%d] \n", 30, lista_getPosicao(30, l1)); // 2
```

- [ ] Obtém o elemento que ocupa uma posição da lista

```c++
// Protótipo
int lista_getElemento(int pos, Lista* lista);
```  

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  // [10, 20, 30]

printf("Posicao [%d] - elemento [%d] \n", 0, lista_getElemento(0, l1)); // 10
printf("Posicao [%d] - elemento [%d] \n", 1, lista_getElemento(1, l1)); // 20
printf("Posicao [%d] - elemento [%d] \n", 2, lista_getElemento(2, l1)); // 30

```

### **Funcionalidades Extra**

- [ ] Devolver o conteúdo da lista na forma de string

```c++
// Protótipo
bool lista_toString(char* saida, Lista* lista);
```

```c++
// Uso da Função
Lista* l1 = lista_criar();
lista_anexar(10, l1);  
lista_anexar(20, l1);  
lista_anexar(30, l1);  // [10, 20, 30]

char texto[100];
lista_toString(texto, l1);
printf("%s \n", texto);

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

