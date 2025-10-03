#include <iostream>

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

void preenche(Data* d, int dia, int mes, int ano){
  d->dia = dia;
  // (*d).dia = dia;
  d->mes = mes;
  d->ano = ano;
}

void preenche2(Data& d, int dia, int mes, int ano){
  d.dia = dia;
  d.mes = mes;
  d.ano = ano;
}

void preenche3(Data d, int dia, int mes, int ano){
  d.dia = dia;
  d.mes = mes;
  d.ano = ano;
}

void print(Data* d){
  printf("%d/%d/%d \n", d->dia, d->mes, d->ano);
}

int main() {
  Data d1;
  preenche(&d1, 3, 10, 2025);
  preenche2(d1, 10, 10, 2025);
  preenche3(d1, 20, 10, 2025);
  print(&d1);
  
  Data* d2 = new Data;
  preenche(d2, 3, 10, 2025);
  preenche2(*d2, 25, 10, 2025);
  print(d2);

}