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

namespace jogo {

  class velha {
    private:
      std::vector< std::vector<unsigned int> > mJogo;

      std::string player1;
      std::string player2;

      const bool againstIA;

    public:
      velha(bool IA);
      velha(std::string player1, std::string player2);
      velha(std::player);

      bool jogada(std::string player, unsigned int x, unsigned int y);
  };
}

#endif 
