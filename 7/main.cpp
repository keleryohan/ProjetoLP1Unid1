// COMM : Exemplo base da documentação do doxygen.
// TODO : Descobrir como fazer o 'sa'.
// TODO: printall() do Employee e de Company não funcionando
// TODO: fazer as funções alterarem resultado (passagem por referencia)
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
#include <ostream>
#include "classes.h"
#include "funcions.h"


// COMM : Para nunca precisar usar 'std::'
using namespace std;



// COMM : Área para declarar funções.
// SEP : Funções utilitárias
void fnc_clr();  // DBG : Desativar ela para melhorar o debug


// COMM : Função main onde está text menu.
// TODO : implementar funções do text menu: 
// '-> func. adicionar empresa ; 
// '-> func. adicionar funcionario a empresa (um por vez) ; 
// '-> func. N OBRIG. de listar empresas/funcionario para debug ; 
// '-> func. listar dados de todos os funcionarios 'sobrecarregando o operador de inserção em stream (<<)' ; 
// '-> func. aumentar todos salarios de empresa em x% ; 
// '-> func. listar dados de funcionarios com menos de 90 dias da data atual ; 
// '-> func. exibir/calcular media dos atributos dos funcionarios de uma empresa ; 
vector <Company> empresas;
int qnt_empresas = 1;
//criando uma empresa para teste
int main () {
  Company google = Company("google","123643");
  empresas.push_back(google);
  vector <Employee> empregados;
  Employee keler = Employee("Keler Yohan",1500,"01/05/2019");
  Employee italo = Employee("Italo",1999,"9/10/2010");
  empregados.push_back(keler);
  empregados.push_back(italo);
  empresas[0].employee = empregados;
  cout << empresas[0].employee[0].salary;
	fnc_clr();
  int choice = 0;
  while(choice!=7){ 
    cout << "Menu Inicial:\n\n\n"
    <<"Opções:\n\n"
    <<"1-) Adicionar empresa\n"
    <<"2-) Adicionar funcionários\n"
    <<"3-) Listar dados dos funcionários de uma empresa\n"
    <<"4-) Listar dados dos funcionários em período de experiência\n"
    <<"5-) Calcular média do salário dos funcionários\n"
    <<"6-) Encerrar\n";


    cout << "\n->";
    cin >> choice;
    fnc_clr();

    if (choice == 1) {
      cout << "\nOpção 1 selecionada:\n\n";
      fnc_add_company(empresas,qnt_empresas);
    }
    else if (choice == 2) {
      cout << "\nOpção 2 selecionada:\n\n";
      fnc_add_employee(empresas,qnt_empresas);
      //TESTE
    }
    else if (choice == 3) {
      cout << "\nOpção 3 selecionada:\n\n";
      fnc_list_emp(empresas,qnt_empresas);
    }
    else if (choice == 4) {
      cout << "\nOpção 4 selecionada:\n\n";
      fnc_list_exp_emp();
    }
    else if (choice == 5) {
      cout << "\nOpção 5 selecionada:\n\n";
      fnc_calc_average(empresas,qnt_empresas);
    }
    else if (choice == 6) {
      cout << "\nOpção 6 selecionada:\n\n";
      fnc_raiseall(empresas,qnt_empresas);
    }
    else if(choice == 7){
      cout << "Encerrando...";
    }
    else {
      cout << "\nERROR\n\nOpção inválida selecionada!\n\n";
	}


  }
	return 0;
}



// COMM : Área para implementar funções.

// SEP : Funções utilitárias :
// TODO : Melhorar essa função (?)
void fnc_clr ()
{
  cout << "\n--------------------------------------------\n";
	//cout << string( 20, '\n' );
  //cout << "---------------------------------------\n";
}

// SEP : Funções práticas :
// TODO : Ajustar tipos e parâmetros das funções.


void fnc_list_exp_emp ()
{}






