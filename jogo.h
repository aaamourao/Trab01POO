/**
 *
 * Trabalho 01 - Programação Orientada a Objetos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#ifndef JOGO_H
#define JOGO_H

#include <utility>

namespace jogo {
  
  std::map<std::string, std::pair<unsigned int, unsigned int> > createMap();

  const char *layoutStrings[]  = { "           _____          \n",
                                   "          |     |         \n",
                                   "1         |     |         \n",
                                   "     _____|_____|_____    \n",
                                   "    |     |     |     |   \n",
                                   "2   |     |     |     |   \n",
                                   "    |_____|_____|_____|   \n",
                                   "          |     |         \n",
                                   "3         |     |         \n",
                                   "          |_____|         \n",
                                   "                          \n",
                                   "      a      b      c     \n"};

  const std::string chPlayer1 = "X";
  const std::string chPlayer2 = "O";

  // Nao pode ser constante para ser acessada do modo T[]
  std::map<std::string, std::pair<unsigned int, unsigned int> > stdGameMap 
    = createMap();                                                               
                                                                                
  std::vector<std::string> gameLayout(layoutStrings, layoutStrings+12);
}
#endif
