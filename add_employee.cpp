#include "classes.h"
#include "funcions.h"
#include <string>
#include <iostream>
using namespace std;

void fnc_add_employee (vector <Company> empresas,int qnt_empresas){
  if (qnt_empresas==0){//se n houverem empresas
    cout << "Erro! Sem empresas para se adicionar empregados! ";
  }
  else{//mostra ao usuário todas as empresas disponíveis 
	cout << "Lista de empresas:";
  int choice;
  for(int i=0;i<=qnt_empresas;i++){
    cout << "\n" << i << " - " << empresas[i].name;
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
    string aux_nome;
    float aux_salario;
    //TO DO: outro while para deixar o usuário colocar quantos funcionários ele quiser
    while(1){ //pedindo as informações sobre o funcionário e verificando se n é repetido
      cout << "Qual é o nome do funcionário? ";
      cin >> aux_nome;
      //verificar se n é repetido ^^^^ usar a string::compare
      cout << "Qual será o salário do " << aux_nome << "?";
      cin >> aux_salario;
      Employee empregado_atual = Employee(aux_nome,aux_salario,"data atual");
      empresas[choice].employee.push_back(empregado_atual); //TO DO: trocar o data_atual por um jeito de se colocar a data de hoje, no tipo Data
    }
  
  }
}