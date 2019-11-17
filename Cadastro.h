#pragma once
#include <vector>
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_DEPRECATE

class TAD3 {
public:
	//construtor
	TAD3();
	//Overload construtor
	TAD3(std::string);
	// destructor
	~TAD3();
	// acesso a funcao
	std::string& GetPokemon();
	void SetPokemon(std::string&);

private:
	std::string novo_pokemon_;
};

class TAD2 {
public:
	//construtor
	TAD2();
	//Overload construtor
	TAD2(std::string);
	// destructor
	~TAD2();
	// acesso a funcao
	std::string GetElemento();
	void SetElemento(std::string);

	std::vector<TAD3>& PegaPokemon();
	void SetListaPokemon(std::vector<TAD3>&);

	void ListaPokemon(TAD3);
	std::string BuscarPokemon(int);

private:
	std::string poke_elemento_;
	std::vector<TAD3> lista_pokemon_;
};

class TAD1 {
public:
	//construtor
	TAD1();
	//Overload construtor
	TAD1(std::string);
	// destructor
	~TAD1();
	// acesso a funcao
	std::string GetName() const;
	void SetName(std::string);

	std::vector<TAD2>& GetListaElemento();
	void SetListaElemento(std::vector<TAD2>&);
	
private:
	std::string novo_nome_;
	std::vector<TAD2> lista_elemento_;
};




