#ifndef JOGADOR_H
#define JOGADOR_H
#include "Usuario.hpp"
#include <iostream>
class Jogador : public Usuario{
    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vitorias, int derrotas, int sequencia);
    ~Jogador() override{}
    void mostrarTabela();
};
#endif