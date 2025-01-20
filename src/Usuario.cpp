#include "Usuario.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

string Usuario::getNome() {
    return nome;
}

string Usuario::getApelido() {
    return apelido;
}

int Usuario::getVitorias() {
    return vitorias;
}

int Usuario::getDerrotas() {
    return derrotas;
}

int Usuario::getSequencia() {
    return sequencia;
}

void Usuario::setVitorias(int vit) {
    this->vitorias = vit;
}

void Usuario::setDerrotas(int der) {
    this->derrotas = der;
}

void Usuario::setSequencia(int seq) {
    this->sequencia = seq;
}