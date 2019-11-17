#include <string>
#include <vector>
#define _CRT_SECURE_NO_DEPRECATE
#include "Cadastro.h"

TAD1::TAD1() {

}
TAD1::TAD1(std::string nome) {
	novo_nome_ = nome;
}
TAD1::~TAD1() {

}
std::string TAD1::GetName() const {
	return novo_nome_;
}
void TAD1::SetName(std::string nome) {
	novo_nome_ = nome;
}

std::vector<TAD2>& TAD1::GetListaElemento() {
	return lista_elemento_;
}

void TAD1::SetListaElemento(std::vector<TAD2>& elemento) {
	lista_elemento_ = elemento;
}



TAD2::TAD2()  {
	
}
TAD2::TAD2(std::string elemento) {
	poke_elemento_ = elemento;
}
TAD2::~TAD2() {

}
std::string TAD2::GetElemento()  {
	return poke_elemento_;
}

void TAD2::SetElemento(std::string elemento){
	poke_elemento_ = elemento;
}

std::vector<TAD3>& TAD2::PegaPokemon()
{
	return lista_pokemon_;
}

void TAD2::SetListaPokemon(std::vector<TAD3>&pokemon) {
	lista_pokemon_ = pokemon;
}

void TAD2::ListaPokemon(TAD3 pokemon){
	lista_pokemon_.push_back(pokemon);
}

std::string TAD2::BuscarPokemon(int index) {
	return lista_pokemon_[index].GetPokemon();
}


TAD3::TAD3() {

}
TAD3::TAD3(std::string pokemon) {
	novo_pokemon_ = pokemon;
}
TAD3::~TAD3() {

}
std::string& TAD3::GetPokemon()  {
	return novo_pokemon_;
}

void TAD3::SetPokemon(std::string& pokemon){
	novo_pokemon_ = pokemon;
}
