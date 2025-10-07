#include <iostream>

using namespace std;

const bool DEBUG = false;
const int TAMANHO = 10;

class Lista{
  private:
  int* dados;
  int qtde;
  int tam;

  void verificaAumenta() {
    if (qtde < tam) return;
    
    int novoTamanho = tam * 2;

    int* novo = new int[novoTamanho];

    for (int i=0; i < qtde; i++) {
        novo[i] = dados[i];
    }

    delete[] dados;

    dados = novo;
    tam = novoTamanho;
  }

  void verificaDiminui() {
    if ((double)qtde / tam > 0.25) return;

    int novoTamanho = tam / 2;
    int* novo = new int[novoTamanho];

    for (int i=0; i < qtde; i++) {
          novo[i] = dados[i];
      }

    delete[] dados;
    dados = novo;
    tam = novoTamanho;
  }

  public:
  
  Lista(){
    dados = new int[TAMANHO];
    qtde =0;
    tam = TAMANHO;
  }

  ~Lista(){
    delete[] dados;
  }

  bool anexar(int elemento) {
    verificaAumenta();
    if (DEBUG) printf("Ocupacao %d/%d (%.2f)\n", qtde, tam, (double)qtde / tam);

    dados[qtde] = elemento;
    qtde++;
    return true;
  }

  bool inserir(int elemento, int pos) {
    if (pos < 0 || pos > qtde) return false;

    verificaAumenta();

    for (int i = qtde; i > pos; i--) {
      dados[i] = dados[i - 1];
    }

    dados[pos] = elemento;
    qtde++;
    return true;
  }

  void print() const {
    cout << "[";
    for (int i = 0; i < qtde; i++) {
      cout << dados[i];
      if (i < qtde - 1) cout << ",";
    }
    cout << "]" << endl;
  }

  int tamanho() const {
      return qtde;
  }

  int removerPorPosicao(int pos) {
    if (pos < 0 || pos >= qtde) return -999;

    int elementoRemovido = dados[pos];
    for (int i = pos; i < qtde - 1; i++) {
      dados[i] = dados[i + 1];
    }
    qtde--;

    verificaDiminui();
    if (DEBUG) printf("Ocupacao %d/%d (%.2f)\n", qtde, tam, (double)qtde / tam);

    return elementoRemovido;
  }

  bool removerPorPosicao(int pos, int* endereco) {
    if (pos < 0 || pos >= qtde) return false;

    *endereco = dados[pos];
    for (int i = pos; i < qtde - 1; i++) {
      dados[i] = dados[i + 1];
    }
    qtde--;

    verificaDiminui();
    return true;
  }

  int removerPorElemento(int elemento) {
    int pos = getPosicao(elemento);
    if (pos == -1) return -1;
    removerPorPosicao(pos);
    return pos;
  }

  bool substituir(int elemento, int pos) {
    if (pos < 0 || pos >= qtde) return false;
    dados[pos] = elemento;
    return true;
  }

  int getPosicao(int elemento) const {
    for (int i = 0; i < qtde; i++) {
      if (dados[i] == elemento) return i;
    }
    return -1;
  }

  int getElemento(int pos) const {
    if (pos < 0 || pos >= qtde) return -999;
    return dados[pos];
  }

  string toString() const {
    string str = "[";
    for (int i = 0; i < qtde; i++) {
      str.append(to_string(dados[i]));
      if (i < qtde - 1) str.append(",");
    }
    str.append("]");
    return str;
  }
};


int main() {
  Lista lista;

  lista.anexar(10);
  lista.anexar(20);
  lista.anexar(30);
  lista.print(); // [10,20,30]

  lista.inserir(15, 1);
  lista.print(); // [10,15,20,30]

  lista.removerPorPosicao(2);
  lista.print(); // [10,15,30]

  cout << "Tamanho: " << lista.tamanho() << endl; // 3
  cout << "Elemento na pos 1: " << lista.getElemento(1) << endl; // 15
  cout << "String: " << lista.toString() << endl;

  return 0;
}
