#pragma once
#include <vector>
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_DEPRECATE

class Tad3 {
 public:
  Tad3();
  Tad3(std::string);
  ~Tad3();
  std::string &GetPokemon();
  void SetPokemon(std::string &);

 private:
  std::string new_pokemon_;
};

class Tad2{
 public:
  Tad2();
  Tad2(std::string);
  ~Tad2();
  std::string GetElement();
  void SetElement(std::string);
  std::vector<Tad3> &GetListPokemon();
  void SetListPokemon(std::vector<Tad3>&);
  void ListPokemon(Tad3);
  std::string SearchPokemon(int);

 private:
  std::string poke_element_;
  std::vector<Tad3> list_pokemon_;
};

class Tad1 {
 public:
	Tad1();
	Tad1(std::string);
	~Tad1();
	std::string GetName() const;
	void SetName(std::string);
	std::vector<Tad2> &GetListElement();
	void SetListElemenet(std::vector<Tad2> &);

 private:
  std::string new_name_;
  std::vector<Tad2> list_element_;
};
