/**
 *
 * Trabalho 01 - Programação Orientada a Objetos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#ifndef JOGADORVIRTUAL_H
#define JOGADORVIRTUAL_H

#include <string>
#include <vector>

namespace jogo {

  class JogadorVirtual {
    
    private:
      std::string name;

      std::vector<std::string> layout;

    public:
      JogadorVirtual(std::string, std::vector<std::string>);

      std::string jogadaIA(std::vector<std::string>);
  };
}

#endif
