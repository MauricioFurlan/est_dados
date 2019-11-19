#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Cadastro.h"

void AddPerson(std::vector<Tad1>&);
void AddElement(std::vector<Tad1>&,int);
void AddPokemon(std::vector<Tad1>&, int, int);
void PrintList(std::vector<Tad1>&);
void DeletePerson(std::vector<Tad1>& , int);
void DeleteElement(std::vector<Tad1>&, int ,int);
void DeletePokemon(std::vector<Tad1>& , int , int , int );
void EditPerson(std::vector<Tad1>& , int);
void EditElement(std::vector<Tad1>&, int, int);
void EditPokemon(std::vector<Tad1>&, int, int, int);
int Menu();
int EditMenu();
int EditMenuQuestion();
int ChooseElemenet();
int ChoosePerson();
int ChoosePokemon();
void Save(std::vector<Tad1>&);
void load(std::vector<Tad1>&);

int main() {
  setlocale(LC_ALL, "Portuguese");
  std::vector<Tad1> list_person;
  int op, index , index_element , persons, index_poke, menu_edit, edd_or_edit;
  do {
    op = Menu();
	switch (op) {
	  case 1:
	    system("CLS");
	    AddPerson(list_person);
	    system("CLS");
	    std::cout << "\n\n";
	    std::cout << "                                 Lista de Competidores" << "\n";
	    std::cout << "\n";
	    std::cout <<"+-------------------------------+" <<"\n";
	    PrintList(list_person);
	    std::cout << "+-------------------------------+" << "\n";
	    std::cout << "+------------------------------------------------------------------+" << "\n";
	    std::cout << "     Digite o index do treinador para cadastrar os elementos dos pokemons: ";
	    std::cin >> index;
	    system("CLS");
	    AddElement(list_person, index);
	    system("CLS");
	    PrintList(list_person);
	    std::cout << "\n";
	    std::cout << "+------------------------------------------------------------------+" << "\n";
	    std::cout << "            Escolha o index do elemento para cadastrar o Pokemon:";
	    std::cin >> index_element;
	    system("CLS");
	    AddPokemon(list_person, index , index_element);
	    system("CLS");
	    break;
	  case 2:
	    system("CLS");
	    PrintList(list_person);
	    system("PAUSE");
	    system("CLS");
	    break;
	  case 3:
	    system("CLS");
	    std::cout << "\n";
	    PrintList(list_person);
	    std::cout << "\n";
	    std::cout << "+------------------------------------------------------------------+" << "\n";
	    std::cout << "            Digite o Index do treinador que deseja alterar: ";
	    std::cin >> persons;
	    system("CLS");
	    PrintList(list_person);
	    menu_edit = EditMenuQuestion();
	    if (menu_edit == 1) {
	      system("CLS");
	  	  PrintList(list_person);
	  	  edd_or_edit = ChoosePerson();
	  	  if (edd_or_edit == 1) {
	  	    system("CLS");
	  	    PrintList(list_person);
	  	    AddPerson(list_person);
	  	  }
	  	  if (edd_or_edit == 2) {
	  	    system("CLS");
	  	    PrintList(list_person);
	  	    EditPerson(list_person, persons);
	  	  }
	  	  if (edd_or_edit == 3) {
	  	    system("CLS");
	  	    PrintList(list_person);
	  	    DeletePerson(list_person, persons);
	  	  }  
	  	  else {
	  	    system("CLS");
	  	  }
	    }
	    if (menu_edit == 2) {
	      edd_or_edit = ChooseElemenet();
	  	  if (edd_or_edit == 1) {
	        system("CLS");
	        PrintList(list_person);
	        AddElement(list_person, persons);
	  	  }
	  	  if (edd_or_edit == 2) {
	  	    system("CLS");
	  	    PrintList(list_person);
	  	    std::cout << "                                 Digite o index do elemento:";
	  	    std::cin >> index_element;
	  	    EditElement(list_person, persons, index_element);
	  	  }
	  	  if (edd_or_edit == 3) {
	  	    system("CLS");
	  	    PrintList(list_person);
	  	    std::cout << "                                 Digite o index do elemento:";
	  	    std::cin >> index_element;
	  	    DeleteElement(list_person, persons, index_element);
	  	  }
	  	  else {
	  	    system("CLS");
	      }
	    }
	    if (menu_edit == 3) {
	  	  system("CLS");
	  	  edd_or_edit = ChoosePokemon();
	  	  PrintList(list_person);
	  	  if (edd_or_edit == 1) {
	  	    std::cout << "\n";
	  		std::cout << "                                 Digite o index do elemento:";
	  		std::cin >> index_element;
	  		AddPokemon(list_person, persons, index_element);
	  	  }
	  	  if (edd_or_edit == 2) {
	  	    system("CLS");
	  		PrintList(list_person);
	  		std::cout << "                                 Digite o index do elemento:";
	  		std::cin >> index_element;
	  		std::cout << "\n";
	  		std::cout << "                                 Digite o index do pokemon:";
	  		std::cin >> index_poke;
	  		EditPokemon(list_person, persons, index_element, index_poke);
	  	  }
	  	  if (edd_or_edit == 3) {
	  		PrintList(list_person);
	  		std::cout << "                                 Digite o index do elemento:";
	  		std::cin >> index_element;
	  		std::cout << "\n";
	  		std::cout << "                                 Digite o index do pokemon:";
	  		std::cin >> index_poke;
	  		DeletePokemon(list_person, persons, index_element, index_poke);
	  		system("CLS");
	  	  }
	  	  else {
	  	    system("CLS");
	  	  }
	    }
	  case 5:
	    Save(list_person);
		system("CLS");
		std::cout << "\n\n";
		std::cout << "                                 +-------------------------------+" << "\n";
		std::cout << "                                 +----------~~Salvando~~---------+" << "\n";
		std::cout << "                                 +-------------------------------+" << "\n";
		std::cout << "\n\n";
		system("PAUSE");
		system("CLS");
	    break;
	  case 4:
	    load(list_person);
		system("CLS");
		std::cout << "\n\n";
		std::cout << "                                 +--------------------------------+" << "\n";
		std::cout << "                                 +----~~Carregando Registros~~----+" << "\n";
		std::cout << "                                 +--------------------------------+" << "\n";
		std::cout << "\n\n";
		system("PAUSE");
		system("CLS");
	}
  } while (op != 0);
}

void AddPerson(std::vector<Tad1>& list_person) {
  std::string nome;
  std::cout << "\n\n";
  std::cout << "                                 +-------------------------------+" << "\n";
  std::cout << "                                 ---------~~Competidores~~--------" << "\n";
  std::cout << "                                 +-------------------------------+" << "\n";
  std::cout << "\n\n";
  std::cout <<"				Quantidade de treinadores:";
  int tamanhoNome;
  std::cin >> tamanhoNome;
  std::cin.ignore();
  for (int i = 0; i < tamanhoNome; i++) {
	std::cout << "\n";
	std::cout << "                                 Treinador: ";
	getline(std::cin, nome);
	if (nome.length() < 50) {
	  Tad1 novoNome(nome);
	  list_person.push_back(novoNome);
	  std::cout << "\n";
	}
	else {
	  std::cout << "Nome do competidor muito grande para os nossos registros." << "\n";
	  std::cout << "Compeditor nao adicionado" << "\n";
	  system("PAUSE");
	}
  }
  std::cout << "\n";

}
void AddElement(std::vector<Tad1>& list_person,int index) {
  std::string nome_elemento;
  std::vector<Tad2> lista_elemento;
  int qnt_elementos;
  std::cout << "\n\n";
  std::cout << "                                 +-------------------------------+" << "\n";
  std::cout << "                                 -----------~~Elementos~~---------" << "\n";
  std::cout << "                                 +-------------------------------+" << "\n";
  std::cout << "\n\n";
  std::cout << "                                 Quantidade de Elementos:";
  std::cin >> qnt_elementos;
  std::cin.ignore();
  for (int i = 0; i < qnt_elementos; i++) {
    std::cout << "\n";
    std::cout << "                                 Elemento "<<"["<<i<<"]"<<":";
    getline(std::cin, nome_elemento);
    if (nome_elemento.length() < 30) {
	  Tad2 elemento(nome_elemento);
	  lista_elemento.push_back(elemento);
	  //	list_person[index].SetListaElemento(lista_elemento);
	  list_person[index].GetListElement().push_back(elemento);
	  std::cout << "\n";
	}
	else {
	  std::cout << "Nome do elemento muito grande para os nossos registros." << "\n";
	  std::cout << "elemento nao adicionado" << "\n";
	  system("PAUSE");
	}
  }
}

void AddPokemon(std::vector<Tad1>& list_person, int index , int index_element) {
  std::string nome_pokemon;
  std::vector<Tad3> lista_pokemon;
  Tad2 Tad2;
  int qntpoke;
  std::cout << "\n\n";
  std::cout << "                                 +-------------------------------+" << "\n";
  std::cout << "                                 -----------~~Pokemon~~-----------" << "\n";
  std::cout << "                                 +-------------------------------+" << "\n";
  std::cout << "\n\n";
  std::cout << "                                 Quantidade de pokemons:";
  std::cin >> qntpoke;
  for (int i = 0; i < qntpoke; i++) {
	std::cout << "\n";
	std::cout << "                                 Pokemon: ";
	std::cin >> nome_pokemon;
	if (nome_pokemon.length() <= 10) {
	  std::cout << "\n";
	  Tad3 pokemon(nome_pokemon);
	  pokemon.SetPokemon(nome_pokemon);
	  list_person[index].GetListElement()[index_element].GetListPokemon().push_back(pokemon);
	}
	else {
	  std::cout << "Nome do Pokemon muito grande para os nossos registros." <<"\n";
	  std::cout << "pokemon nao adicionado" << "\n";
	  system("PAUSE");	
	}
  }
}

void PrintList( std::vector<Tad1>& list_person) {
  size_t size = list_person.size();
  for (size_t i = 0; i < size; i++) {
	std::cout << "\n";
	std::cout << "|" << "Treinador:" << "[" <<i<< "]" << list_person[i].GetName() << "\n";
	for (size_t j = 0; j < list_person[i].GetListElement().size(); j++) {
	  std::cout <<"       "<< "Elemento:" << "[" << list_person[i].GetName() << "]" << "["<<j<<"]" << list_person[i].GetListElement()[j].GetElement() << "\n";
	  std::cout << "-----------------------------------\n";
	  for (size_t k = 0; k < list_person[i].GetListElement()[j].GetListPokemon().size(); k++) {
		std::cout << "                            "<< "Pokemon:" << "[" << k << "]" << list_person[i].GetListElement()[j].GetListPokemon()[k].GetPokemon() <<  "\n";
	  }
	}
  std::cout << "\n";
  }
}

void DeletePerson(std::vector<Tad1>& list_person , int persons) {
  list_person.erase(list_person.begin()+ persons);
}

void DeleteElement(std::vector<Tad1>& list_person , int index, int index_element) {
  list_person[index].GetListElement().erase(list_person[index].GetListElement().begin() + index_element);
}

void DeletePokemon(std::vector<Tad1>& list_person, int index, int index_element, int index_poke) {
  list_person[index].GetListElement()[index_element].GetListPokemon().erase(list_person[index].GetListElement()[index_element].GetListPokemon().begin() + index_poke);
}

void EditPerson(std::vector<Tad1>& list_person , int index) {
  std::string novoEdit;
  std::cout << "                                 Digite o novo nome: ";
  std::cin >> novoEdit;
  list_person.at(index).SetName(novoEdit);
}

void EditElement(std::vector<Tad1>& list_person , int index , int index_element) {
  std::string novoEdit;
  std::cout << "                                 Digite o novo elemento: ";
  std::cin >> novoEdit;
  list_person[index].GetListElement().at(index_element).SetElement(novoEdit);
}

void EditPokemon(std::vector<Tad1>& list_person , int index , int index_element, int index_poke) {
  std::string novoEdit;
  std::cout << "                                 Digite o novo pokemon: ";
  std::cin >> novoEdit;
  list_person[index].GetListElement()[index_element].GetListPokemon().at(index_poke).SetPokemon(novoEdit);
}

int Menu() {
  unsigned int op;
  printf("\n\n");
  printf("                                .::LIGA POKEMON::.  \n\n");
  printf("                 Veja todas as funcoes disponiveis no Menu   \n");
  printf("                 use os n�meros para selecionar a op��o desejada.  \n");
  printf("\n\n");
  printf("\n                                 MENU PRINCIPAL:");
  printf("\n                        +-------------------------------+");
  printf("\n                        | [1] - Adicionar Compeditor    |");
  printf("\n                        | [2] - Listar Competidores     |");
  printf("\n                        | [3] - Editar Competidores     |");
  printf("\n                        | [4] - Carregar                |");
  printf("\n                        | [5] - Salvar                  |");
  printf("\n                        | [0] - Sair                    |");
  printf("\n                        +-------------------------------+ ");
  printf("\n\n                          Selecione a opção desejada: ");
  std::cin >> op;
  return op;
}

int EditMenu() {
  unsigned int op_edit;
  std::cout << "[1] Editar" << "\n";
  std::cout << "[0] Voltar" << "\n";
  std::cout << "Op:";
  std::cin >> op_edit;
  return op_edit;
}

int ChoosePokemon() {
  unsigned int ed;
  printf("\n                                 MENU POKEMON:");
  printf("\n                        +-------------------------------+");
  printf("\n                        | [1] - Adicionar Pokemon       |");
  printf("\n                        | [2] - Editar Pokemon          |");
  printf("\n                        | [3] - Excluir Pokemon         |");
  printf("\n                        | [0] - Voltar                  |");
  printf("\n                        +-------------------------------+ ");
  printf("\n\n                          Selecione a opção desejada: ");
  std::cin >> ed;
  system("CLS");
  return ed;
}

int EditMenuQuestion() {
  unsigned int ed;
  printf("\n                                 Menu EDITAR:");
  printf("\n                        +-------------------------------+");
  printf("\n                        | [1] - Competidor              |");
  printf("\n                        | [2] - Elemento                |");
  printf("\n                        | [3] - Pokemon                 |");
  printf("\n                        | [0] - Voltar                  |");
  printf("\n                        +-------------------------------+ ");
  printf("\n\n                          Selecione a opção desejada: ");
  std::cin >> ed;
  system("CLS");
  return ed;
}

int ChooseElemenet() {
  unsigned int ed;
  printf("\n                                 MENU ELEMENTO:");
  printf("\n                        +-------------------------------+");
  printf("\n                        | [1] - Adicionar Elemento      |");
  printf("\n                        | [2] - Editar Elemento         |");
  printf("\n                        | [3] - Excluir Elemento        |");
  printf("\n                        | [0] - Voltar                  |");
  printf("\n                        +-------------------------------+ ");
  printf("\n\n                          Selecione a opção desejada: ");
  std::cin >> ed;
  system("CLS");
  return ed;
}

int ChoosePerson() {
  unsigned int ed;
  printf("\n                                 MENU COMPETIDOR:");
  printf("\n                        +-----------------------------------+");
  printf("\n                        | [1] - Adicionar Competidor        |");
  printf("\n                        | [2] - Editar Competidore          |");
  printf("\n                        | [3] - Excluir Competidor          |");
  printf("\n                        | [0] - Voltar                      |");
  printf("\n                        +-----------------------------------+ ");
  printf("\n\n                          Selecione a opção desejada: ");
  std::cin >> ed;
  system("CLS");
  return ed;
}

void Save(std::vector<Tad1>& list_person) {
  std::ifstream in;
  std::ofstream out1;
  std::ofstream out2;
  std::ofstream out3;
  std::string arquivo;
  int len_elemento = 0;
  int len_pokemon = 0;
  int num = 0;
  int len_vet = list_person.size();
  for (int i = 0; i < len_vet; i++) {
    num++;
	for (int j = 0; j < list_person[i].GetListElement().size(); j++) {
	  len_elemento++;
	  for (int k = 0; k < list_person[i].GetListElement()[j].GetListPokemon().size(); k++) {
		len_pokemon++;
	  }
	}
  }
  out1.open("competidores.txt");
  out2.open("elementos.txt");
  out3.open("pokemon.txt");
  out1 << len_vet << std::endl;
  out2 << len_elemento << std::endl;
  out3 << len_pokemon << std::endl;
  for (int i = 0; i < len_vet; i++) {
    out1 << i << "|" << list_person[i].GetName() << std::endl;
	for (int j = 0; j < list_person[i].GetListElement().size(); j++) {
	  out2 << i << "|" << list_person[i].GetListElement()[j].GetElement() << std::endl;
	  for (int k = 0; k < list_person[i].GetListElement()[j].GetListPokemon().size(); k++) {
		out3 << i << "|" << j << "|" << list_person[i].GetListElement()[j].GetListPokemon()[k].GetPokemon() << std::endl;
	  }
	}
  }
  out1.close();
  out2.close();
  out3.close();
}

void load(std::vector<Tad1>& list_person) {
  std::ifstream in1("competidores.txt");
  std::ifstream in2("elementos.txt");
  std::ifstream in3("pokemon.txt");
  int tamc, tame, tamp;
  std::string tam_line, tam_line_elemento, tam_line_pokemon;
  std::getline(in3, tam_line_pokemon);
  tamp = atoi(tam_line_pokemon.c_str());
  std::getline(in2, tam_line_elemento);
  tame = atoi(tam_line_elemento.c_str());
  std::getline(in1, tam_line);
  tamc = atoi(tam_line.c_str());
  for (int i = 0; i < tamc; i++) {
    std::string index;
    std::getline(in1, index, '|');
    std::string competidor;
    std::getline(in1, competidor);
    list_person.push_back(competidor);
  }
  for (int j = 0; j < tame; j++) {
    int id_competidor;
    std::string index_competidor;
    std::getline(in2, index_competidor, '|');
    id_competidor = atoi(index_competidor.c_str());
    std::string elemento;
    std::getline(in2, elemento);
    list_person[id_competidor].GetListElement().push_back(elemento);
  }
  if (tamp != 0) {
	for (int k = 0; k < tamp; k++) {
	  int id_competidor, id_elemento;
	  std::string index_competidor;
	  std::getline(in3, index_competidor, '|');
	  id_competidor = atoi(index_competidor.c_str());
	  std::string index_elemento;
	  std::getline(in3, index_elemento, '|');
	  id_elemento = atoi(index_elemento.c_str());
	  std::string pokemon;
	  std::getline(in3, pokemon);
	  Tad3 pokemon1(pokemon);
	  pokemon1.SetPokemon(pokemon);
	  list_person[id_competidor].GetListElement()[id_elemento].GetListPokemon().push_back(pokemon1);
	}
  }
  in1.close();
  in2.close();
  in3.close();	
}






	//int i;

	//int len_vet = list_person.size();
	//char vetor[100];
	//FILE* arq;
	//// abre o arquivo para escrita no modo append (adiciona ao final)
	//arq = fopen("dados.bin", "wt");
	//if (arq != NULL)
	//{
	//	for (i = 0; i < len_vet; i++)
	//		// escreve cada elemento do vetor no arquivo
	//		fwrite(&list_person[i], sizeof(Tad1), 1, arq);
	//	fclose(arq);
	//}
	//system("CLS");

	//arq = fopen("dados.bin", "rb");
	//while (!feof(arq)){ // to read file
	//	// fucntion used to read the contents of file
	//	fread(&vetor, sizeof(char), 100, arq);
	//	std::cout << vetor;
	//}
	//else
	//{
	//	std::cout << "\nErro ao abrir o arquivo para leitura!" << "\n";
	//	exit(1); // aborta o programa
	//}
//}
//	std::vector<std::string> vetor;
//	FILE* arq;
//	arq = fopen("dados.txt", "wt");
//	size_t size = list_person.size();
//	if (arq != NULL) {
//		for (size_t i = 0; i < size; i++) {
//			fwrite(&list_person, sizeof(Tad1), 1, arq);
//		}
//		fclose(arq);
//		system("CLS");
//
//		arq = fopen("dados.txt", "rt");
//		if (arq != NULL) {
//			fscanf(arq, "%s", &vetor);
//			printf("%s", vetor);
//		}
//	}
//}


