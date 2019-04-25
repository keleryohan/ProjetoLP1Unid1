/*Duvidas:
Como usar uma quantidade indefinida de jogadores, e os colocar num vector/list
*/

#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>  
using namespace std; 

class Jogador{
  public:
    int pontos=0;
    bool perdeu=false;
    string nome="convidado";

  void add_pontos(int &pontos_ganhos){
    this->pontos+=pontos_ganhos;
    //21 apto a mudança. substituir por variável
    if (pontos>21){
      this->fora();
    } 
  };
  void fora(){
    perdeu=true;
  }
};

//chama a função que aumenta os pontos do jogador atual e printa quanto ele tirou
void jogar_dados(Jogador &jogador){
  auto x = rand() % 6 + 1;
  auto y = rand() % 6 + 1;
  cout << "O jogador " << jogador.nome << " tirou " << x << " e " << y<< "!";
  int soma = x+y;
  jogador.add_pontos(soma);
  cout << " E possui agora " <<jogador.pontos<<"!\n";
};


//list<int> first;
int main() {
  
  vector<Jogador> jogadores;
  int qnt_jogadores=4;
  /*
  //Pede a quantidade de jogadores e os nomes deles.
  cout << "Quantos jogadores jogarão?";
  cin >> qnt_jogadores;
  for (int i=0;i<qnt_jogadores;i++){
    cout << "Qual é o nome do jogador " << i+1 << "? ";
    string input_aux;
    cin >> input_aux;
    jogadores.push_back(Jogador);
    jogador1.nome = input_aux;
  }*/
  Jogador jogador1;
  Jogador jogador2;
  Jogador jogador3;
  Jogador jogador4;
  jogador1.nome = "nome1";
  jogador2.nome = "nome2";
  jogador3.nome = "nome3";
  jogador4.nome = "nome4";
  //jogador1.perdeu = true;
  //lista com todos os jogadores que ainda estão jogando
  vector<Jogador> jogadores_ativos= {jogador1,jogador2,jogador3,jogador4};


  bool acabou = false;
  int contador=0;
  //inicio do turno
  while (acabou == false){  
    char aux_parada='k';
    //opção de cada jogador parar ou continuar
    for (auto i = jogadores_ativos.begin(); i != jogadores_ativos.end(); ++i){//loop por toda a lista de jogadores
      if (i->perdeu==false){ //se o jogador ainda n tiver parado, da a ele a oportunidade de jogar os dados, ou de parar
      
        while (!(aux_parada=='S'||aux_parada=='s'||aux_parada=='n'||aux_parada=='N')){
          cout << "É a sua vez, " << i->nome; 
          cout << "\nQuer jogar os dados? S/N ";
          cin >> aux_parada;
          if(!(aux_parada=='S'||aux_parada=='s'||aux_parada=='n'||aux_parada=='N')){
            cout << "Opção inválida!\n";
        }
        }
        //se o jogador escolher parar, ele tá fora e n joga mais os dados
        if (aux_parada=='n'||aux_parada=='N'){ 
          i->fora();
        }
        //se o jogador tiver continuado, ele joga os dados
        else{
          jogar_dados(*i);
        }
        aux_parada='k'; //resetando a escolha p/ o próximo
    }
    else{
      break;
    }
    }




    cout << "\n\n";
    //verifica se ainda tem algum jogador no jogo
    acabou = true;
    for (auto i = jogadores_ativos.begin(); i != jogadores_ativos.end(); ++i){
      if(i->perdeu==false){
        acabou=false;
        break;
      }
    }
  }
  
  //exibe o vencedor
  int vencedor_pts = jogadores_ativos[2].pontos;
  string vencedor_nome = jogadores_ativos[2].nome;
  for (auto i = jogadores_ativos.begin(); i != jogadores_ativos.end(); ++i){
    if (i->pontos <= 21 && i->pontos > vencedor_pts){
      vencedor_pts = i->pontos;
      vencedor_nome = i->nome;
    }
  }

  cout << "O grande vencedor é: " << vencedor_nome << ", com " << vencedor_pts << " pontos!";

  return 0;
}
