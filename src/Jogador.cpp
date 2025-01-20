#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
Jogador::Jogador(string nome, string apelido) : Usuario( nome, apelido){
    cout << "Criou!\n";
}
Jogador::Jogador(std::string nome, std::string apelido, int vitorias, int derrotas, int sequencia) : Usuario(nome, apelido, vitorias, derrotas, sequencia){}
void Jogador::mostrarTabela(){
    cout << "Tabela!";
}