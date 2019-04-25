// COMM : Exemplo base da documentação do doxygen.
// TODO : Descobrir como fazer o 'sa'.

/**
* @file atv1lp1.cpp
* @author Italo Nardy
* @author Keler Yohan
* @since 25/04/2019
* @date 25/04/2019
* @version 0.02
* @sa ?????
*/



/*
Changelog: 
V0.03 : 
- Começo da função de adicionar 
V0.02 :
- Add funcões do menu
- Add texto do menu
- Add fnc_clr para uma melhor experiência (desativar ela para melhorar debug)
- Add toda a organização e formatação dos comentários normais (não-doxygen)
V0.01 :
- Add a função main, uhuuu!
- Add includes
*/



// DICT : Dicionário de termos usados nos comentários
// DICT -> Dicionário
// COMM -> 'Comment' -> Comentários sobre o código abaixo
// GENERAL -> Área geral para comentários sopre o codigo como um todo
// TODO -> 'To do' -> Coisa(s) que ainda devem ser feitas
// FIXME -> 'Fix me' -> Coisa(s) que estão com preblemas e devem ser consertadas
// WARNING -> Avisos sobre possíveis problemas futuros
// SEP -> 'Separation' -> Separação de um grupo em alguma categoria



// GENERAL : 
// TODO : 
//'-> Melhorar fnc_clr (?)
//'-> Criar comentários do doxygen



// COMM : Includes para o programa funcionar.
#include <iostream>
#include <string>
#include <vector>



// COMM : Para nunca precisar usar 'std::'
using namespace std;



// COMM : Área para declarar funções.
// SEP : Funções utilitárias
void fnc_clr();  // DBG : Desativar ela para melhorar o debug

// SEP : Funções práticas
// TODO : Ajustar tipos e parâmetros das funções.
void fnc_add_company();
void fnc_add_employee();
void fnc_list_emp();
void fnc_list_exp_emp();
void fnc_calc_average();
void fnc_back();



// COMM : Definição das classes usadas no programa
class Employee {
public:
	string name;
	string cpf;
	float salary;
	string date;
	
	Employee(string n, string c, float s, string d);
	void printall(){
		cout << "\nNome: "<< name << "\n";
		cout << "CPF: " << cpf << "\n";
		cout << "Salário: R$" << salary << "\n";
		cout << "Data: " << date << "\n";
	}
};

Employee::Employee(string n, string c, float s, string d) {
	name = n;
	cpf = c;
	salary = s;
	date = d;

}


class Company {
public:
	string name;
	string cnpj;
	//TEST : 
	vector<Employee> employee; // Vector of employees

	Company(string n, string c);
	void printall(){
		cout << "\nNome: " << name << "\n";
		cout << "CNPJ: " << cnpj << "\n";
	}
};

Company::Company(string n, string c){
	name = n;
	cnpj = c;
}



// COMM : Função main onde está text menu.
// TODO : implementar funções do text menu: 
// '-> func. adicionar empresa ; 
// '-> func. adicionar funcionario a empresa (um por vez) ; 
// '-> func. N OBRIG. de listar empresas/funcionario para debug ; 
// '-> func. listar dados de todos os funcionarios 'sobrecarregando o operador de inserção em stream (<<)' ; 
// '-> func. aumentar todos salarios de empresa em x% ; 
// '-> func. listar dados de funcionarios com menos de 90 dias da data atual ; 
// '-> func. exibir/calcular media dos atributos dos funcionarios de uma empresa ; 
// WARNING : testar se tem empresas antes de permitir adicionar funcionarios.
int main () {
	fnc_clr();

	cout << "Menu Inicial:\n\n\n"
	<<"Opções:\n\n"
	<<"1-) Adicionar empresa\n"
	<<"2-) Adicionar funcionários\n"
	<<"3-) Listar dados dos funcionários\n"
	<<"4-) Listar dados dos funcionários em período de experiência\n"
	<<"5-) Calcular média dos atributos dos funcionários\n";

	int choice = 0;
	cout << "\n->";
	cin >> choice;
	fnc_clr();

	if (choice == 1) {
		cout << "\nOpção 1 selecionada:\n\n";
		fnc_add_company();
	}
	else if (choice == 2) {
		cout << "\nOpção 2 selecionada:\n\n";
		fnc_add_employee();
	}
	else if (choice == 3) {
		cout << "\nOpção 3 selecionada:\n\n";
		fnc_list_emp();
	}
	else if (choice == 4) {
		cout << "\nOpção 4 selecionada:\n\n";
		fnc_list_exp_emp();
	}
	else if (choice == 5) {
		cout << "\nOpção 5 selecionada:\n\n";
		fnc_calc_average();
	}
	else {
		cout << "\nERROR\n\nOpção inválida selecionada!\n\n";
		fnc_back();
	}



	return 0;
}



// COMM : Área para implementar funções.

// SEP : Funções utilitárias :
// TODO : Melhorar essa função (?)
void fnc_clr ()
{
	cout << string( 100, '\n' );
}

// SEP : Funções práticas :
// TODO : Ajustar tipos e parâmetros das funções.
void fnc_add_company ()
{}

void fnc_add_employee ()
{
	//TEST :
	Employee employee("joão", "45454", 999.99, "12/12/12");
	employee.printall();
	Company company("IMC", "456686485");
	company.printall();
}

void fnc_list_emp ()
{}

void fnc_list_exp_emp ()
{}

void fnc_calc_average ()
{}

void fnc_back ()
{}

void fnc_raiseall ()
{}








