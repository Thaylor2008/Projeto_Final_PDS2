#ifndef ADMIN_H
#define ADMIN_H
#include "Jogador.hpp"
#include <vector>
#include <string>
class Admin{
    private:
    std::vector<Jogador*> Jogadores;
    public:
    Jogador* createJogador(std::string, std::string);
    Jogador* createJogador(std::string, std::string, int, int, int);
    Jogador* buscaApelido(std::string);
    void uptadeJogadores(std::string);
    void listarUsuarios();
    std::vector<Jogador*> removerJogador(std::string);
    ~Admin();


};
#endif