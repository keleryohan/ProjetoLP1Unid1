#include "classes.h"
#include <string>
#include <iostream>
using namespace std;


Employee::Employee(string n, float s, string d) {
	name = n;
	//cpf = c;
	salary = s;
	date = d;
}

/*
void printall(){
	cout << "\nNome: "<< name << "\n";
	cout << "CPF: " << cpf << "\n";
	cout << "Salário: R$" << salary << "\n";
	cout << "Data: " << date << "\n";
}



void printall(){
	cout << "\nNome: " << name << "\n";
	cout << "CNPJ: " << cnpj << "\n";
}
*/

Company::Company(string n, string c){
	name = n;
	cnpj = c;
}



