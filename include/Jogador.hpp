#ifndef JOGADOR_H
#define JOGADOR_H
#include "Usuario.hpp"
class Jogador : public Usuario{
    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vitorias, int derrotas, int sequencia);
    void mostrarTabela();
};
#endif