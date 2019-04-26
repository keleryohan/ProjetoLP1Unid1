#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>  
using namespace std; 

class Jogador{
  public:
    int pontos;
    bool perdeu;
    string nome;
  //função construtora
  Jogador(string nome_p){
    this->nome = nome_p;
    this->pontos = 0;
    this->perdeu=false;
  }
  void add_pontos(int &pontos_ganhos){
    pontos+=pontos_ganhos;
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


int main() {
  srand (time(NULL)); //configuração do rand int
  vector<Jogador> jogadores_ativos; //vector onde ficaram os jogadores
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



  bool acabou = false; //variável que marca o fim do jogo
  //inicio do turno
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
          jogar_dados(jogadores_ativos[i]);
        }
        aux_parada='k'; //resetando a escolha p/ o próximo
    }
    }



    //verifica se ainda tem algum jogador no jogo
    acabou = true;
    for (auto i = 0; i < qnt_jogadores; i++){
      if(jogadores_ativos[i].perdeu==false){
        acabou=false;
        break;
      }
    }
  }
  
  //exibe o vencedor
  int vencedor = 0;
  for (auto i = 0; i < qnt_jogadores; i++){
    if (jogadores_ativos[i].pontos <= 21 && jogadores_ativos[i].pontos > jogadores_ativos[vencedor].pontos){
      vencedor = i;
    }
  }

  cout << "O grande vencedor é: " << jogadores_ativos[vencedor].nome << ", com " << jogadores_ativos[vencedor].pontos << " pontos!";

  return 0;
}
