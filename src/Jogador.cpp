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
Jogador::Jogador(string nome, string apelido, string senha) : Usuario( nome, apelido, senha){
    cout << "Criou!\n";
}
void Jogador::mostrarTabela(){
    cout << "Tabela!";
}