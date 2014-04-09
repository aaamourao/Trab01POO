/**
 *
 * Trabalho 01 - Programação Orientada a Objetos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#include "jogodavelha.h"

using namespace std;

jogo::velha::velha(bool IA) : againstIA(IA) {

  // TODO : load players
  //
  // TODO : call another constructor

}

jogo::velha::velha(std::string player1, 
    std::string player2) : againstIA(false) {
  
  // TODO : initialize data structure
  
  // TODO : load players 
}

jogo::velha::velha(std::string player) : againstIA(true) {

  // TODO : initialize data structure

  // TODO : load players
}

bool jogo::velha::jogada(string player, unsigned int x, unsigned int y) {

  bool success = true;

  // TODO: Test and execute 

  return success;
}
