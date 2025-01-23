#ifndef PARITDAS_HPP
#define PARTIDAS_HPP
#include "Jogador.hpp"
#include "JogosTab.hpp"
#include "JogoVelha.hpp"
#include "Reversi.hpp"
#include "Ligue4.hpp"
#include <string>
#include <vector>
class Partidas{
    private:
    std::vector<std::string> historico;
    public:
    void executarPartida(char jogo, Jogador*, Jogador*);
};
#endif