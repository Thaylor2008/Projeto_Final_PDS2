#ifndef REVERSI_H
#define REVERSI_H

#include "JogosTab.hpp"
#include <vector>

class Reversi : public JogosTab {
public:

    Reversi();

    void mostraTabuleiro() const override;

    bool testaJogada(int linha, int coluna, char jogador) override;

    void atualizaTabuleiro(int linha, int coluna, char jogador) override;

    bool verificaVencedor() const override;

    void executarPartida(std::string jogador1, std::string jogador2);

private:
   
    bool posicaoValida(int linha, int coluna) const;

    void inverterPecas(int linha, int coluna, char jogador);
    
    bool verificaDirecao(int linha, int coluna, int dirLinha, int dirColuna, char jogador) const;
};

#endif // REVERSI_H