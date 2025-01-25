#ifndef REVERSI_H
#define REVERSI_H

#include "JogosTab.hpp"
#include <vector>

class Reversi : public JogosTab {
private:
    int pontosP, pontosB;
public:

    Reversi();

    void mostraTabuleiro() const override;

    bool testaJogada(int linha, int coluna, char jogador) override;

    void atualizaTabuleiro(int linha, int coluna, char jogador) override;

    bool verificaVencedor() override;

    void setPontosB(int num);
    void setPontosP(int num);
    int getPontosB();
    int getPontosP();

private:
   
    bool posicaoValida(int linha, int coluna) const;

    void inverterPecas(int linha, int coluna, char jogador);
    
    bool verificaDirecao(int linha, int coluna, int dirLinha, int dirColuna, char jogador) const;
};

#endif // REVERSI_H