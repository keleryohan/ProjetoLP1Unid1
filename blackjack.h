#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>  
using namespace std; 
#ifndef CLASSE_H
#define CLASSE_H


class Jogador{
  public:
    int pontos;
    bool perdeu;
    string nome;
  //função construtora
    Jogador(string nome_p);
    void fora();
    void add_pontos(int &pontos_ganhos,int N);
};
void jogar_dados(Jogador &jogador,int N);

#endif