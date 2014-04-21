/**
 *
 * Trabalho 01 - Programação Orientada a Objetos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include <vector>
#include <string>
#include <map>
#include <vector>

#include "jogadorvirtual.h"

namespace jogo {
  
  class JogoDaVelha {
    private:
      std::vector< std::vector<unsigned int> > mJogo;

      std::string player1;
      std::string player2;

      std::vector<std::string> layout;
      void printLayout(void);

      bool againstIA;
      JogadorVirtual *IA;

      std::map<std::string, std::string> jaJogadas;

      bool vitoria(void); 
      bool jogada(std::string, std::string);

    public:
      JogoDaVelha(void);
      JogoDaVelha(bool IA);

      void startGame(void);
  };
}

#endif 
