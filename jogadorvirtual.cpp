/**
 *
 * Trabalho 01 - Programação Orientada a Objetos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#include <time.h>
#include <stdlib.h>

#include "jogadorvirtual.h"

using namespace std;

jogo::JogadorVirtual::JogadorVirtual(string newName, vector<string> layoutInicial) {
 
  name = name; 
  layout = layoutInicial;
}

string jogo::JogadorVirtual::jogadaIA(vector<string> currentLayout) {

  layout = currentLayout;

  string linha;

  switch(rand()%3 + 1) {
    case 1:
      linha = "1";
      break;
    case 2:
      linha = "2";
      break;
    case 3:
      linha = "3";
      break;
  }

  string coluna;

  switch(rand()%3) {
    case 0:
      coluna = "a";
      break;
    case 1:
      coluna = "b";
      break;
    case 2:
      coluna = "c";
      break;
  }

  string posicao;
  posicao = linha + coluna;

  return posicao;
}
