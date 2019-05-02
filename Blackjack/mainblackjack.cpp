#include "blackjack_classes.h"  
#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>
using namespace std; 


int main() {
  srand (time(NULL)); //configuração do rand int
  vector<Jogador> jogadores_ativos; //vector onde ficaram os jogadores
  int objetivo=0; //pontuação alvo (tipo o 21 do blackjack)
  //Pede a quantidade de jogadores e os nomes deles. Enche a lista jogadores_ativos
  int qnt_jogadores;  
  string input_aux;
  cout << "Quantos jogadores jogarão? ";
  cin >> qnt_jogadores;
  for (int i=0;i<qnt_jogadores;i++){
    cout << "Qual é o nome do jogador " << i+1 << "? ";
    cin >> input_aux;
    Jogador player_atual = Jogador(input_aux);
    jogadores_ativos.push_back(player_atual);
  }

  

  bool finalizado = 0; //define o fim do jogo
  while(finalizado == 0){ //inicio do jogo----------------
    while(1){ //escolha de pontuação
    cout << "Escolha a pontuação alvo: \n"
    <<"1 - Padrão - 21\n"
    <<"2 - Curta  - 15\n"
    <<"3 - Moderada - 30\n"
    <<"4 - Longa - 50\n";
    cin >> objetivo;
    if(objetivo==1||objetivo==2||objetivo==3||objetivo==4){
      break;
    }
    else{
      cout << "Escolha inválida!\n";
    }
  }
    if(objetivo==1)
      objetivo=21;
    else if(objetivo==2)
      objetivo=15;
    else if(objetivo==3)
      objetivo=30;
    else if(objetivo==4)
      objetivo=50;

  bool acabou = false; //variável que marca o fim da partida
  //inicio do turno --------------------------------------
  while (acabou == false){  
    char aux_parada='k';
    //opção de cada jogador parar ou continuar
    for (auto i = 0; i < qnt_jogadores; i++){//loop por toda a lista de jogadores
      if (jogadores_ativos[i].perdeu==false){ //se o jogador ainda n tiver parado, da a ele a oportunidade de jogar os dados, ou de parar

        while (!(aux_parada=='S'||aux_parada=='s'||aux_parada=='n'||aux_parada=='N')){
          cout << "É a sua vez, " << jogadores_ativos[i].nome; 
          cout << "\nQuer jogar os dados? S/N ";
          cin >> aux_parada;
          if(!(aux_parada=='S'||aux_parada=='s'||aux_parada=='n'||aux_parada=='N')){
            cout << "Opção inválida!\n";
        }
        }
        //se o jogador escolher parar, ele tá fora e n joga mais os dados
        if (aux_parada=='n'||aux_parada=='N'){ 
          jogadores_ativos[i].fora();
        }
        //se o jogador tiver continuado, ele joga os dados
        else{
          jogar_dados(jogadores_ativos[i],objetivo);
          //se o jogador atingir a pontuação N, o jogo termina
          if (jogadores_ativos[i].pontos == objetivo){
            acabou=true;
            break;
          }
          if (acabou == true){//interrompe a rodada caso alguém esteja com a pontuação alvo
            break;
    }

        }
        aux_parada='k'; //resetando a escolha p/ o próximo
    }
    }



    //verifica se o jogo ainda n acabou(se alguem já ganhou)
    if (acabou == true){
      break;
    }
    acabou = true;
    //verifica se ainda tem algum jogador ativo
    for (auto i = 0; i < qnt_jogadores; i++){
      if(jogadores_ativos[i].perdeu==false){
        acabou = false;
        break;
      }
    }

  }//fim da sequência de turnos -------------------------




  //exibe o vencedor
  //criando uma nova lista com os jogadores que tiverem pontuação abaixo do objetivo
  vector<Jogador> possiveis_vencedores;
  for (auto i = 0; i < qnt_jogadores; i++){
    if (jogadores_ativos[i].pontos <= objetivo){
      possiveis_vencedores.push_back(jogadores_ativos[i]);
    }
  }
  //definindo o vencedor, se houver um
  int vencedor = 0; 
  if(possiveis_vencedores.empty()){
    cout << "Todos perderam! ";
  }
  else{ 
  for(auto i = 0; i < possiveis_vencedores.size(); i++){
    if(possiveis_vencedores[i].pontos > possiveis_vencedores[vencedor].pontos){
      vencedor=i;
    }
  }
  

  cout << "\n\nO grande vencedor é: " << possiveis_vencedores[vencedor].nome << ", com " << possiveis_vencedores[vencedor].pontos << " pontos!"
  << "\n\nPontuação individual: \n\n";
  for (auto i=0; i<qnt_jogadores;i++){
    cout << jogadores_ativos[i].nome << " -- " << jogadores_ativos[i].pontos << " pontos\n";
  }
  }
  //dá a opção jogar de novo
  char aux_parada2 = 'x';
  while (!(aux_parada2=='S'||aux_parada2=='s'||aux_parada2=='n'||aux_parada2=='N')){
    cout << "\nGostaria de jogar novamente? S/N ";
    cin >> aux_parada2;
    if(!(aux_parada2=='S'||aux_parada2=='s'||aux_parada2=='n'||aux_parada2=='N')){
      cout << "Opção inválida!\n";
        }
        }
  if (aux_parada2=='N'||aux_parada2=='n'){
    finalizado=1;
  }
  else{//para um novo jogo, reseta todos os jogadores
    for(auto i=0;i<qnt_jogadores;i++){
      jogadores_ativos[i].pontos=0;
      jogadores_ativos[i].perdeu=false;
    }
  }

  }
  return 0;
}
