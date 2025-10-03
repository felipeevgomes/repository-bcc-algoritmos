#include <iostream>

class Data {

  private:
  int dia;
  int mes;
  int ano;

  public:

  Data(){
    std::cout << "Objeto construido" << std::endl;
  }
  
  
  Data(int dia, int mes, int ano) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    std::cout << "Objeto construido" << std::endl;
  }

  ~Data(){
    std::cout << "Objeto destruido" << std::endl;
  }
  
  void preenche(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
  }

  void preenche(int dia, int mes){
    this->dia = dia;
    this->mes = mes;
    this->ano = 2026;
  }



  void print(){
    printf("%d/%d/%d \n", this->dia, this->mes, this->ano);
  }

};

int main() {
  Data* data1 = new Data(10,10, 2024);
  Data* data2 = new Data(10,11, 2024);

  data1->print();
  data2->print();

  delete data1;
  delete data2;

  
  Data d1(5, 10, 2025);

  d1.preenche(10, 1, 2023);
  
  Data d2;
  d2.preenche(15, 10);

  d1.print();
  d2.print();

}

// void preenche2(Data& d, int dia, int mes, int ano){
//   d.dia = dia;
//   d.mes = mes;
//   d.ano = ano;
// }

// void preenche3(Data d, int dia, int mes, int ano){
//   d.dia = dia;
//   d.mes = mes;
//   d.ano = ano;
// }


// int main() {
//   Data d1;
//   preenche(&d1, 3, 10, 2025);
//   preenche2(d1, 10, 10, 2025);
//   preenche3(d1, 20, 10, 2025);
//   print(&d1);
  
//   Data* d2 = new Data;
//   preenche(d2, 3, 10, 2025);
//   preenche2(*d2, 25, 10, 2025);
//   print(d2);

// }