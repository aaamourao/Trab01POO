#
#	Makefile 
#	Jogo da Velha 
#	Trabalho de Programacao Orientada a Objetos
#
#	Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
#	Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
#

all: jogodavelha

jogodavelha: main.o jogodavelha.o jogadorvirtual.o
	g++ jogadorvirtual.o jogodavelha.o main.o -o jogodavelha 

main.o: main.cpp
	g++ -c main.cpp

jogodavelha.o: jogodavelha.cpp 
	g++ -c jogodavelha.cpp

jogodorvirtual.o: jogadorvirtual.cpp
	g++ -c jogodorvirtual.cpp

clean: 
	rm -rf *o .*.swp jogodavelha  
