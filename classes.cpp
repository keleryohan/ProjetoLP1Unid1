#include "classes.h"
#include <string>
#include <ostream>
#include <iostream>
using namespace std;


Employee::Employee(string n, float s, string d) {
	name = n;
	//cpf = c;
	salary = s;
	date = d;
}

void Employee::printall(){
	cout << "\nNome: "<< name << "\n";
	cout << "CPF: " << cpf << "\n";
	cout << "Salário: R$" << salary << "\n";
	cout << "Data: " << date << "\n";
}

std::ostream& operator<< (std::ostream &o, Employee const e) {
  o << e.name;
  return o;
}


Company::Company(string n, string c){
	name = n;
	cnpj = c;
}



