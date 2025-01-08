#ifndef JOGOVELHA_H
#define JOGOVELHA_H
#include "JogosTab.hpp"
#include "Jogador.hpp"
using namespace std;
class JogoVelha : public JogosTab{
    public:
    void executarPartida(Usuario* jogador1, Usuario* jogador2);
};
#endif