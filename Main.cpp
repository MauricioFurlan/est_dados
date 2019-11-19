#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>l
#include <fstream>
#include "Cadastro.h"


void add_competidor(std::vector<TAD1>&);
void add_elemento(std::vector<TAD1>&,int);
void add_pokemon(std::vector<TAD1>&, int, int);

void printVector(std::vector<TAD1>&);

void del_pessoa(std::vector<TAD1>& , int);
void del_elemento(std::vector<TAD1>&, int ,int);
void del_pokemon(std::vector<TAD1>& , int , int , int );

void editar_pessoa(std::vector<TAD1>& , int);
void editar_elemento(std::vector<TAD1>&, int, int);
void editar_pokemon(std::vector<TAD1>&, int, int, int);

int menu();
int menu_editar();
int menu_editar_question_ed_or_ed();
int add_or_edit_element();
int add_or_edit_participante();
int add_or_edit_pokemon();

void salvar(std::vector<TAD1>&);
void load(std::vector<TAD1>&);
//void load();

int main() {
	setlocale(LC_ALL, "Portuguese");
	std::vector<TAD1> lista_participantes;
	int op, index , index_element , participante, index_poke, menu_edit, edd_or_edit;

	do {
		op = menu();

		switch (op) {
		case 1:
			system("CLS");
			add_competidor(lista_participantes);
			system("CLS");
			std::cout << "\n\n";
			std::cout << "                                 Lista de Competidores" << "\n";
			std::cout << "\n";
			std::cout <<"+-------------------------------+" <<"\n";
			printVector(lista_participantes);
			std::cout << "+-------------------------------+" << "\n";
			std::cout << "+------------------------------------------------------------------+" << "\n";
			std::cout << "            Digite o index para cadastrar os elementos dos pokemons: ";
			std::cin >> index;
			system("CLS");
			add_elemento(lista_participantes, index);
			system("CLS");
			printVector(lista_participantes);
			std::cout << "\n";
			std::cout << "+------------------------------------------------------------------+" << "\n";
			std::cout << "            Escolha o index do elemento para cadastrar o Pokemon:";
			std::cin >> index_element;
			system("CLS");
			add_pokemon(lista_participantes, index , index_element);
			system("CLS");

			break;
		case 2:
			system("CLS");
			printVector(lista_participantes);
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			std::cout << "\n";
			printVector(lista_participantes);
			std::cout << "\n";
			std::cout << "+------------------------------------------------------------------+" << "\n";
			std::cout << "            Digite o Index do participante que deseja alterar: ";
				std::cin >> participante;

				system("CLS");
				printVector(lista_participantes);

				menu_edit = menu_editar_question_ed_or_ed();
				if (menu_edit == 1) {
				system("CLS");
					printVector(lista_participantes);
					edd_or_edit = add_or_edit_participante();
					if (edd_or_edit == 1) {
						system("CLS");
						printVector(lista_participantes);
						add_competidor(lista_participantes);
					}
					if (edd_or_edit == 2) {
						system("CLS");
						printVector(lista_participantes);
						editar_pessoa(lista_participantes, participante);
					}
					if (edd_or_edit == 3) {
						system("CLS");
						printVector(lista_participantes);
						del_pessoa(lista_participantes, participante);
					}
					else {
						system("CLS");
					}

				}if (menu_edit == 2) {
					edd_or_edit = add_or_edit_element();
					if (edd_or_edit == 1) {
						system("CLS");
						printVector(lista_participantes);
						add_elemento(lista_participantes, participante);
					}
					if (edd_or_edit == 2) {
						system("CLS");
						printVector(lista_participantes);
						std::cout << "                                 Digite o index do elemento:";
						std::cout << "\n";
						std::cin >> index_element;
						editar_elemento(lista_participantes, participante, index_element);
					}
					if (edd_or_edit == 3) {
						system("CLS");
						printVector(lista_participantes);
						std::cout << "                                 Digite o index do elemento:";
						std::cin >> index_element;
						del_elemento(lista_participantes, participante, index_element);
					}
					else {
						system("CLS");
					}
				}if (menu_edit == 3) {
					system("CLS");
					edd_or_edit = add_or_edit_pokemon();
					printVector(lista_participantes);
					if (edd_or_edit == 1) {
						std::cout << "\n";
						std::cout << "                                 Digite o index do elemento:";
						std::cin >> index_element;
						add_pokemon(lista_participantes, participante, index_element);
					}
					if (edd_or_edit == 2) {
					system("CLS");
						printVector(lista_participantes);
						std::cout << "                                 Digite o index do elemento:";
						std::cin >> index_element;
						std::cout << "\n";
						std::cout << "                                 Digite o index do pokemon:";
						std::cin >> index_poke;
						editar_pokemon(lista_participantes, participante, index_element, index_poke);
					}
					if (edd_or_edit == 3) {

						printVector(lista_participantes);
						std::cout << "                                 Digite o index do elemento:";
						std::cin >> index_element;
						std::cout << "\n";
						std::cout << "                                 Digite o index do pokemon:";
						std::cin >> index_poke;
						del_pokemon(lista_participantes, participante, index_element, index_poke);
						system("CLS");
					}
					else {
						system("CLS");
					}

				}
		case 5:
			salvar(lista_participantes);
				break;
		case 6:
			load(lista_participantes);
		}
	} while (op != 0);
	}

void add_competidor(std::vector<TAD1>& lista_participantes) {
	std::string nome;
	std::cout << "\n\n";
	std::cout << "                                 +-------------------------------+" << "\n";
	std::cout << "                                 ---------~~Competidores~~--------" << "\n";
	std::cout << "                                 +-------------------------------+" << "\n";
	std::cout << "\n\n";
	std::cout <<"				Quantidade de participantes:";
	int tamanhoNome;
	std::cin >> tamanhoNome;
	std::cin.ignore();
	for (int i = 0; i < tamanhoNome; i++) {
		std::cout << "\n";
		std::cout << "                                 Treinador: ";
		getline(std::cin, nome);
		if (nome.length() < 50) {
			TAD1 novoNome(nome);
			lista_participantes.push_back(novoNome);
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
void add_elemento(std::vector<TAD1>& lista_participantes,int index) {
	std::string nome_elemento;
	std::vector<TAD2> lista_elemento;
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
			TAD2 elemento(nome_elemento);
			lista_elemento.push_back(elemento);
			//	lista_participantes[index].SetListaElemento(lista_elemento);
			lista_participantes[index].GetListaElemento().push_back(elemento);
			std::cout << "\n";
		}
		else {
			std::cout << "Nome do elemento muito grande para os nossos registros." << "\n";
			std::cout << "elemento nao adicionado" << "\n";
			system("PAUSE");
		}
	}
}
void add_pokemon(std::vector<TAD1>& lista_participantes, int index , int index_element) {
	std::string nome_pokemon;

	std::vector<TAD3> lista_pokemon;
	TAD2 tad2;
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
			TAD3 pokemon(nome_pokemon);
			pokemon.SetPokemon(nome_pokemon);
			//tad2.ListaPokemon(pokemon);
			lista_participantes[index].GetListaElemento()[index_element].PegaPokemon().push_back(pokemon);
			//lista_participantes[index].GetListaElemento()[index_element].SetListaPokemon(lista_pokemon);
		}
		else {
			std::cout << "Nome do Pokemon muito grande para os nossos registros." <<"\n";
			std::cout << "pokemon nao adicionado" << "\n";
			system("PAUSE");
			
		}

	}
}
void printVector( std::vector<TAD1>& lista_participantes) {
	size_t size = lista_participantes.size();

	for (size_t i = 0; i < size; i++) {
		std::cout << "\n";
		std::cout << "|" << "Treinador:" << "[" <<i<< "]" << lista_participantes[i].GetName() << "\n";
		for (size_t j = 0; j < lista_participantes[i].GetListaElemento().size(); j++) {
			std::cout <<"       "<< "Elemento:" << "[" << lista_participantes[i].GetName() << "]" << "["<<j<<"]" << lista_participantes[i].GetListaElemento()[j].GetElemento() << "\n";
			std::cout << "-----------------------------------\n";
			for (size_t k = 0; k < lista_participantes[i].GetListaElemento()[j].PegaPokemon().size(); k++) {
				std::cout << "                            "<< "Pokemon:" << "[" << k << "]" << lista_participantes[i].GetListaElemento()[j].PegaPokemon()[k].GetPokemon() <<  "\n";
		}
		}
		std::cout << "\n";
	}
}

void del_pessoa(std::vector<TAD1>& lista_participantes , int participante) {

	lista_participantes.erase(lista_participantes.begin()+ participante);
}
void del_elemento(std::vector<TAD1>& lista_participantes , int index, int index_element) {
	lista_participantes[index].GetListaElemento().erase(lista_participantes[index].GetListaElemento().begin() + index_element);
}
void del_pokemon(std::vector<TAD1>& lista_participantes, int index, int index_element, int index_poke) {
	lista_participantes[index].GetListaElemento()[index_element].PegaPokemon().erase(lista_participantes[index].GetListaElemento()[index_element].PegaPokemon().begin() + index_poke);
}

void editar_pessoa(std::vector<TAD1>& lista_participantes , int index) {
	std::string novoEdit;
	std::cout << "                                 Digite o novo nome: ";
	std::cin >> novoEdit;
	lista_participantes.at(index).SetName(novoEdit);
}
void editar_elemento(std::vector<TAD1>& lista_participantes , int index , int index_element) {
	std::string novoEdit;
	std::cout << "                                 Digite o novo elemento: ";
	std::cin >> novoEdit;
	lista_participantes[index].GetListaElemento().at(index_element).SetElemento(novoEdit);
}
void editar_pokemon(std::vector<TAD1>& lista_participantes , int index , int index_element, int index_poke) {
	std::string novoEdit;
	std::cout << "                                 Digite o novo pokemon: ";
	std::cin >> novoEdit;
	lista_participantes[index].GetListaElemento()[index_element].PegaPokemon().at(index_poke).SetPokemon(novoEdit);
}

int menu() {
	unsigned int op;
	printf("\n\n");
	printf("                                .::LIGA POKEMON::.  \n\n");
	printf("                 Veja todas as funcoes disponiveis no menu   \n");
	printf("                 use os números para selecionar a opção desejada.  \n");
	printf("\n\n");
	printf("\n                                 MENU PRINCIPAL:");
	printf("\n                        +-------------------------------+");
	printf("\n                        | [1] - Adicionar Compeditor    |");
	printf("\n                        | [2] - Listar Competidores     |");
	printf("\n                        | [3] - Editar Competidores     |");
	printf("\n                        | [4] - Listar dados em memória |");
	printf("\n                        | [5] - Salvar                  |");
	printf("\n                        | [0] - Sair                    |");
	printf("\n                        +-------------------------------+ ");
	printf("\n\n                          Selecione a opção desejada: ");
	std::cin >> op;
	return op;
}
int menu_editar() {
	unsigned int op_edit;
	std::cout << "[1] Editar" << "\n";
	std::cout << "[0] Voltar" << "\n";
	std::cout << "Op:";
	std::cin >> op_edit;
	return op_edit;
}

int add_or_edit_pokemon() {
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


int menu_editar_question_ed_or_ed() {
	unsigned int ed;
	printf("\n                                 MENU EDITAR:");
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
int add_or_edit_element() {
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
int add_or_edit_participante() {
	unsigned int ed;
	printf("\n                                 MENU PARTICIPANTE:");
	printf("\n                        +-----------------------------------+");
	printf("\n                        | [1] - Adicionar Participante      |");
	printf("\n                        | [2] - Editar Participante         |");
	printf("\n                        | [3] - Excluir Participante        |");
	printf("\n                        | [0] - Voltar                      |");
	printf("\n                        +-----------------------------------+ ");
	printf("\n\n                          Selecione a opção desejada: ");
	std::cin >> ed;
	system("CLS");
	return ed;

}
void salvar(std::vector<TAD1>& lista_participantes) {
	int len_elemento = 0;
	int len_pokemon = 0;
	int aff = 0;
	int len_vet = lista_participantes.size();
	for (int i = 0; i < len_vet; i++) {
		aff++;
		for (int j = 0; j < lista_participantes[i].GetListaElemento().size(); j++) {
			len_elemento++;
			for (int k = 0; k < lista_participantes[i].GetListaElemento()[j].PegaPokemon().size(); k++) {
				len_pokemon++;
			}
		}
	}
	
	std::ifstream in;
	std::ofstream out1;
	std::ofstream out2;
	std::ofstream out3;
	std::string arquivo;

	
	out1.open("competidores.txt");
	out2.open("elementos.txt");
	out3.open("pokemon.txt");
	out1 << len_vet << std::endl;
	out2 << len_elemento << std::endl;
	out3 << len_pokemon << std::endl;
	for (int i = 0; i < len_vet; i++) {
		out1 << i << "|" << lista_participantes[i].GetName() << std::endl;
		//out2 << lista_participantes[i].GetListaElemento().size() << std::endl;
		for (int j = 0; j < lista_participantes[i].GetListaElemento().size(); j++) {
			out2 << i << "|" << lista_participantes[i].GetListaElemento()[j].GetElemento() << std::endl;
		//	out3 << lista_participantes[i].GetListaElemento()[j].PegaPokemon().size() << std::endl;
			for (int k = 0; k < lista_participantes[i].GetListaElemento()[j].PegaPokemon().size(); k++) {
				out3 << i << "|" << j << "|" << lista_participantes[i].GetListaElemento()[j].PegaPokemon()[k].GetPokemon() << std::endl;
			}
		}
	}
	out1.close();
	out2.close();
	out3.close();
}

void load(std::vector<TAD1>& lista_participantes) {
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
		lista_participantes.push_back(competidor);
		for (int i = 0; i < tame ; i++) {
			int id_competidor;
			std::string index_competidor;
			std::getline(in2, index_competidor, '|');
			id_competidor = atoi(index_competidor.c_str());
			std::string elemento;
			std::getline(in2, elemento);
			lista_participantes[id_competidor].GetListaElemento().push_back(elemento);
			if (tamp != 0) {
				for (int i = 0; i < tamp; i++) {
					int id_competidor, id_elemento;
					std::string index_competidor;
					std::getline(in3, index_competidor, '|');
					id_competidor = atoi(index_competidor.c_str());
					std::string index_elemento;
					std::getline(in3, index_elemento, '|');
					id_elemento = atoi(index_elemento.c_str());
					std::string pokemon;
					std::getline(in3, pokemon);
					TAD3 pokemon1(pokemon);
					pokemon1.SetPokemon(pokemon);
					lista_participantes[id_competidor].GetListaElemento()[id_elemento].PegaPokemon().push_back(pokemon1);
				}
			}
		}

	}
	in1.close();
	in2.close();
	in3.close();
	
}






	//int i;

	//int len_vet = lista_participantes.size();
	//char vetor[100];
	//FILE* arq;
	//// abre o arquivo para escrita no modo append (adiciona ao final)
	//arq = fopen("dados.bin", "wt");
	//if (arq != NULL)
	//{
	//	for (i = 0; i < len_vet; i++)
	//		// escreve cada elemento do vetor no arquivo
	//		fwrite(&lista_participantes[i], sizeof(TAD1), 1, arq);
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
//	size_t size = lista_participantes.size();
//	if (arq != NULL) {
//		for (size_t i = 0; i < size; i++) {
//			fwrite(&lista_participantes, sizeof(TAD1), 1, arq);
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


