#include "classes.h"
#include "funcions.h"
#include <string>
#include <iostream>
using namespace std;

// Muito foi reaproveitado do add_employee

void fnc_calc_average(vector <Company> empresas,int qnt_empresas) {
  if (qnt_empresas==0){//se n houverem empresas
    cout << "Erro! Sem empresas para calcular a média!";
  }
  else{//mostra ao usuário todas as empresas disponíveis 
	cout << "Lista de empresas:";
  int choice;
  for(int i=0;i<qnt_empresas;i++){
    cout << "\n" << i+1 << " - " << empresas[i].name << "\n";
  }
  while(1){ //verifica se o usuário n escreveu caca
    cout << "Selecione a empresa: ";
    cin >> choice;
    if (choice<0 || choice>qnt_empresas){
      cout << "Escolha inválida! \n";
    }
    else{
      break;
    }
    }
    choice--;
    float aux_sal = 0;
    int aux_counter = 0;
    for(int i=0;i<empresas[choice].employee.size();i++){
     aux_sal += empresas[choice].employee[i].salary;
     aux_counter += 1;
    }
    aux_sal = aux_sal/aux_counter;
    cout << "A média dos salários é : " << aux_sal;
  }
}