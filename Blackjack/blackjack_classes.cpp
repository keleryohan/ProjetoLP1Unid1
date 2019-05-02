#include "blackjack_classes.h"  
#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>
using namespace std; 

  //função construtora
Jogador::Jogador(string nome_p){
  nome = nome_p;
  pontos = 0;
  perdeu=false;
}
void Jogador::add_pontos(int &pontos_ganhos,int N){
  pontos+=pontos_ganhos;
  //21 apto a mudança. substituir por variável
  if (pontos>N){
    cout << " O jogador " << this->nome << " está fora! ";
    this->fora();
  } 
};
void Jogador::fora(){
  perdeu=true;
}


//chama a função que aumenta os pontos do jogador atual e printa quanto ele tirou
void jogar_dados(Jogador &jogador,int N){
  auto x = rand() % 6 + 1;
  auto y = rand() % 6 + 1;
  cout << "O jogador " << jogador.nome << " tirou " << x << " e " << y<< "!";
  int soma = x+y;
  jogador.add_pontos(soma,N);
  cout << " E possui agora " <<jogador.pontos<<"!\n";
};