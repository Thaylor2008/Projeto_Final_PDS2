#ifndef JOGADOR_H
#define JOGADOR_H
#include "Usuario.hpp"
class Jogador : public Usuario{
    public:
    Jogador(string nome, string apelido, string senha);
    void mostrarTabela();
};
#endif