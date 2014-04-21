/**
 *
 * Trabalho 01 - Programação Orientada a Objetos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#include <iterator>
#include <iostream>
#include <algorithm>

#include <stdlib.h>
#include <time.h>

#include "jogodavelha.h"
#include "jogo.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const std::string cmd = "cls";
#else
static const std::string cmd = "clear";
#endif

using namespace std;

jogo::JogoDaVelha::JogoDaVelha(void) {
  string modo;

  while(1) {
    cout << "Você deseja jogar no modo versus(0) ou contra o computador(1)? ";
    cin  >> modo;

    if(modo != "0" && modo != "1")
      cout << "Opcao invalida..." << endl;
    else
      break;
  }

  if(modo == "0")
    againstIA = false;
  else
    againstIA = true;
  
  cout << "Por favor, entre com o nome do Player 1: ";
  cin  >> player1;

  if(!againstIA) {

    while(1) {
      cout << flush << "Por favor, entre com o nome do Player 2: ";
      cin  >> player2;

      if(player2 != player1)
        break;
      else {
        
        player2 += " 2";
        break;
      }
    }
  }
  else {
    player2 = "Computador";

    IA = new JogadorVirtual(player2, gameLayout);
  }
}

jogo::JogoDaVelha::JogoDaVelha(bool IA) : againstIA(IA) {

  cout << "Por favor, entre com o nome do Player 1: ";
  cin  >> player1;

  if(!IA) {

    while(1) {
      cout << flush << "Por favor, entre com o nome do Player 2: ";
      cin  >> player2;

      if(player2 != player1)
        break;
      else {
        
        player2 += " 2";
        break;
      }
    }
  }
  else {
    player2 = "Computador";

    IA = new JogadorVirtual(player2, gameLayout);
  }
}

void jogo::JogoDaVelha::startGame(void) {
  
  layout = gameLayout;

  string currentPlayer = player1;
  string currentCh     = chPlayer1;

  bool ultJogada = true;
  unsigned int iterations = 0;

  
  srand(time(NULL));

  while(1) { 
   
    system(cmd.c_str());

    printLayout();
    
    string posicao, disclaimer;
    
      disclaimer = currentPlayer + "(" + currentCh + "): ";
   
    if(!ultJogada)
      disclaimer = "(Jogada invalida)" + disclaimer;
   
    if(!againstIA || (currentPlayer != player2)) { 
      cout << disclaimer;
      cin  >> posicao;
    } 
    else 
      posicao = IA->jogadaIA(layout); 

    ultJogada = jogada(currentCh, posicao);

    unsigned int a;
    if(ultJogada) {
      layout[jogo::stdGameMap[posicao].first][jogo::stdGameMap[posicao].second] 
        = currentCh[0];
    }
   
    if(ultJogada && iterations >= 3 && vitoria()){
      system(cmd.c_str());
      printLayout();

      break;
    }
    else if(ultJogada && iterations == 8) {
      system(cmd.c_str());
      printLayout();

      ultJogada = false;

      break;
    }
    
    if(ultJogada && currentPlayer == player1) {
      
      currentCh     = chPlayer2;
      currentPlayer = player2;
    }
    else if(ultJogada) {
      currentCh     = chPlayer1;
      currentPlayer = player1;
    }

    if(ultJogada)
      ++iterations;
  }

  if(ultJogada)
    cout << "O jogador " << currentPlayer << " ganhou!! Parabens!! " << endl;
  else
    cout << "Velha!!!" << endl;
  
  #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
  system("pause");
  #endif
  
  return;
}

bool jogo::JogoDaVelha::jogada(string chPlayer, string posicao) {

  bool success = true;


  if(jogo::stdGameMap.find(posicao) == jogo::stdGameMap.end()) 
    success = false;
  else {
    if(!jaJogadas.empty() && jaJogadas.find(posicao) != jaJogadas.end())
      success = false;
    else
      jaJogadas[posicao] = chPlayer;
  }

  return success;
}

bool jogo::JogoDaVelha::vitoria(void) {
  
  bool victory = false;

  if(jaJogadas.find("1a") != jaJogadas.end() &&
     jaJogadas.find("1b") != jaJogadas.end() &&
     jaJogadas.find("1c") != jaJogadas.end() ) {
    
    if(jaJogadas["1a"] == jaJogadas["1b"] && jaJogadas["1b"] == jaJogadas["1c"])
      victory = true;
  }
  if(jaJogadas.find("2a") != jaJogadas.end() &&
     jaJogadas.find("2b") != jaJogadas.end() &&
     jaJogadas.find("2c") != jaJogadas.end() ) {
    
    if(jaJogadas["2a"] == jaJogadas["2b"] && jaJogadas["2b"] == jaJogadas["2c"])
      victory = true;
  }
  if(jaJogadas.find("3a") != jaJogadas.end() &&
     jaJogadas.find("3b") != jaJogadas.end() &&
     jaJogadas.find("3c") != jaJogadas.end() ) {
    
    if(jaJogadas["3a"] == jaJogadas["3b"] && jaJogadas["3b"] == jaJogadas["3c"])
      victory = true;
  }
  if(jaJogadas.find("1a") != jaJogadas.end() &&
     jaJogadas.find("2a") != jaJogadas.end() &&
     jaJogadas.find("3a") != jaJogadas.end() ) {
    
    if(jaJogadas["1a"] == jaJogadas["2a"] && jaJogadas["2a"] == jaJogadas["3a"])
      victory = true;
  }
  if(jaJogadas.find("1b") != jaJogadas.end() &&
     jaJogadas.find("2b") != jaJogadas.end() &&
     jaJogadas.find("3b") != jaJogadas.end() ) {
    
    if(jaJogadas["1b"] == jaJogadas["2b"] && jaJogadas["2b"] == jaJogadas["3b"])
      victory = true;
  }
  if(jaJogadas.find("1c") != jaJogadas.end() &&
     jaJogadas.find("2c") != jaJogadas.end() &&
     jaJogadas.find("3c") != jaJogadas.end() ) {
    
    if(jaJogadas["1c"] == jaJogadas["2c"] && jaJogadas["2c"] == jaJogadas["3c"])
      victory = true;
  }
  if(jaJogadas.find("1a") != jaJogadas.end() &&
     jaJogadas.find("2b") != jaJogadas.end() &&
     jaJogadas.find("3c") != jaJogadas.end() ) {
    
    if(jaJogadas["1a"] == jaJogadas["2b"] && jaJogadas["2b"] == jaJogadas["3c"])
      victory = true;
  }
  if(jaJogadas.find("3a") != jaJogadas.end() &&
     jaJogadas.find("2b") != jaJogadas.end() &&
     jaJogadas.find("1c") != jaJogadas.end() ) {
    
    if(jaJogadas["3a"] == jaJogadas["2b"] && jaJogadas["2b"] == jaJogadas["1c"])
      victory = true;
  }
  
  return victory;
} 

map<string, pair<unsigned int, unsigned int> > jogo::createMap() {
  
  map<string, pair<unsigned int, unsigned int> > ret;

  ret["1a"] = make_pair(2,7);
  ret["2a"] = make_pair(5,7);
  ret["3a"] = make_pair(8,7);

  ret["1b"] = make_pair(2,13);
  ret["2b"] = make_pair(5,13);
  ret["3b"] = make_pair(8,13);

  ret["1c"] = make_pair(2,19);
  ret["2c"] = make_pair(5,19);
  ret["3c"] = make_pair(8,19);
  
  return ret;
}


void jogo::JogoDaVelha::printLayout(void) {
 
  for(vector<string>::iterator it = layout.begin();
      it != layout.end();
      ++it) {
    cout << *it;
  }
  cout << endl;
}
