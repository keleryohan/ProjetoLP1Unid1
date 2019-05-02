#include "classes.h"
#include "funcions.h"
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

// Muito foi reaproveitado do add_employee

void fnc_raiseall(vector <Company> empresas,int qnt_empresas) {
  if (qnt_empresas==0){//se n houverem empresas
    cout << "Erro! Sem empresas para aumentar o salário!";
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
    float raise = 0;
    cout << "Quanto % deseja adicionar ao salario dos funcionarios?";
    cin >> raise;
    for(int i=0;i<empresas[choice].employee.size();i++){
     empresas[choice].employee[i].salary += (empresas[choice].employee[i].salary) * (raise/100);
    }
  }
}