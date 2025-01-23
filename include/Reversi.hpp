#ifndef REVERSI_H
#define REVERSI_H
#include "Jogador.hpp"
#include "JogosTab.hpp"
class Reversi : public JogosTab{
    private:
    int pontosP, PontosB;
    public:
    Reversi();
    void mostraTabuleiro() const override;
    bool testaJogada(int linha, int coluna) const override{return true;}
    void atualizaTabuleiro(int linha, int coluna, char jogador) override{}
    bool verificaVencedor() const override{return true;}
    
};
#endif