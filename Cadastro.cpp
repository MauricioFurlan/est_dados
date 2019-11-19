#include <string>
#include <vector>
#define _CRT_SECURE_NO_DEPRECATE
#include "Cadastro.h"

Tad1::Tad1() {}

Tad1::Tad1(std::string name) {
  new_name_ = name;
}
Tad1::~Tad1() {}
std::string Tad1::GetName() const {
  return new_name_;
}
void Tad1::SetName(std::string name) {
  new_name_ = name;
}

std::vector<Tad2>& Tad1::GetListElement() {
  return list_element_;
}

void Tad1::SetListElemenet(std::vector<Tad2>& element) {
  list_element_ = element;
}

Tad2::Tad2() {}

Tad2::Tad2(std::string element) {
  poke_element_ = element;
}

Tad2::~Tad2() {}
std::string Tad2::GetElement()  {
  return poke_element_;
}

void Tad2::SetElement(std::string element){
  poke_element_ = element;
}

std::vector<Tad3>& Tad2::GetListPokemon(){
  return list_pokemon_;
}

void Tad2::SetListPokemon(std::vector<Tad3>&pokemon) {
  list_pokemon_ = pokemon;
}

void Tad2::ListPokemon(Tad3 pokemon){
  list_pokemon_.push_back(pokemon);
}

std::string Tad2::SearchPokemon(int index) {
  return list_pokemon_[index].GetPokemon();
}

Tad3::Tad3() {}

Tad3::Tad3(std::string pokemon) {
  new_pokemon_ = pokemon;
}

Tad3::~Tad3() {}

std::string& Tad3::GetPokemon()  {
  return new_pokemon_;
}

void Tad3::SetPokemon(std::string& pokemon){
  new_pokemon_ = pokemon;
}
