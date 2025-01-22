#ifndef LIGUE4_H
#define LIGUE4_H

#include "JogosTab.hpp"
#include "Jogador.hpp"

//Classe para o jogo Lig 4, derivada de JogosTab.
 
class Ligue4 : public JogosTab {
public:
    //Construtor que inicializa o tabuleiro com o tamanho padrão de 6x7.
    Ligue4();

    void mostraTabuleiro() const override;
    
    bool testaJogada(int linha, int coluna) const override;

    void atualizaTabuleiro(int linha, int coluna, char jogador) override;

    bool verificaVencedor() const override;

    void executarPartida(Jogador* jogador1, Jogador* jogador2);

private:
  
    bool posicaoValida(int linha, int coluna) const;

    bool verificaSequencia(int linha, int coluna, char jogador) const;

    int proximaLinhaDisponivel(int coluna) const;
};

#endif
