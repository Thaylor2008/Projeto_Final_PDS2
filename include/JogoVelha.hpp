#ifndef JOGOVELHA_H
#define JOGOVELHA_H

#include "JogosTab.hpp"
#include "Jogador.hpp"
#include <vector>
#include <iostream>

//Classe para o jogo da velha, derivada de JogosTab.
 
class JogoVelha : public JogosTab {
public:
    JogoVelha();

    void mostraTabuleiro() const override;

    bool testaJogada(int linha, int coluna, char jogador) override;

    void atualizaTabuleiro(int linha, int coluna, char jogador) override;

    bool verificaVencedor() const override;

    bool tabuleiroCheio() const;
};

#endif // JOGOVELHA_H
