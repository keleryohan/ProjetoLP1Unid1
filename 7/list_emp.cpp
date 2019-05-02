#include "classes.h"
#include "funcions.h"
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

// Muito foi reaproveitado do add_employee

void fnc_list_emp(vector <Company> empresas,int qnt_empresas) {
  if (qnt_empresas==0){//se n houverem empresas
    cout << "Erro! Sem empresas para listar empregados!";
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
    for(int i=0;i<empresas[choice].employee.size();i++){
      cout << "\n-----------------------------------------\n";
      cout << "Nome: " << empresas[choice].employee[i].name <<"\nSalário: R$" << empresas[choice].employee[i].salary << "\nData de admissão: " << empresas[choice].employee[i].date; //printa os dados de cada funcionario[i] do vetor de funcionarios da empresa escolhida
    }
    cout << "\n-----------------------------------------\n";
  }
}