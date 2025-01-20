#ifndef JOGADOR_H
#define JOGADOR_H
#include "Usuario.hpp"
class Jogador : public Usuario{
    public:
    Jogador(std::string nome, std::string apelido, std::string senha);
    void mostrarTabela();
};
#endif