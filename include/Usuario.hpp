#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
class Usuario{
    public:
    string nome;
    string apelido;
    string senha;
    int vitorias;
    int derrotas;
    int sequencia;
    Usuario(string nome, string apelido, string senha) {
        this->nome = nome;
        this->apelido = apelido;
        this->senha = senha;
        this->vitorias = 0;
        this->derrotas = 0;
    }
    virtual void mostrarTabela() = 0;
};
#endif