#include "classes.h"
#include "funcions.h"
#include <string>
#include <iostream>
using namespace std;

void fnc_add_company(vector <Company> &empresas,int &qnt_empresas){
  string aux_nome;
  string aux_cnpj;
  cout << "Qual é o nome da impresa? ";
  cin >> aux_nome;
  cout << "Qual é o cnpj da impresa? ";
  cin >> aux_cnpj;
  Company empresa = Company(aux_nome,aux_cnpj); 
  empresas.push_back(empresa);
  vector <Employee> funcionarios; //criando vector vazio de funcionarios
  empresas[qnt_empresas].employee = funcionarios; //colocando o vector no objeto
  qnt_empresas++;
}