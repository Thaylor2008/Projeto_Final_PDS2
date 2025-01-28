#ifndef REVERSI_H
#define REVERSI_H

#include "JogosTab.hpp"
#include <vector>

/**
 * @brief Classe que representa o jogo Reversi, herda de JogosTab.
 * 
 * A classe contém métodos para mostrar o tabuleiro, testar jogadas,
 * atualizar o tabuleiro, verificar o vencedor e manipular os pontos dos jogadores.
 */
class Reversi : public JogosTab {
private:
    int pontosP; /**< Pontuação do jogador P (Preto). */
    int pontosB; /**< Pontuação do jogador B (Branco). */
public:

    /**
     * @brief Construtor da classe Reversi.
     * Inicializa os pontos dos jogadores.
     */
    Reversi();

    /**
     * @brief Mostra o tabuleiro do jogo.
     * 
     * Este método sobrescreve o método da classe base para exibir o tabuleiro.
     */
    void mostraTabuleiro() const override;

    /**
     * @brief Testa se uma jogada é válida.
     * 
     * @param linha Linha onde o jogador deseja jogar.
     * @param coluna Coluna onde o jogador deseja jogar.
     * @param jogador O jogador que está fazendo a jogada (P ou B).
     * @return true se a jogada for válida, false caso contrário.
     */
    bool testaJogada(int linha, int coluna, char jogador) override;

    /**
     * @brief Atualiza o tabuleiro após uma jogada.
     * 
     * @param linha Linha onde o jogador jogou.
     * @param coluna Coluna onde o jogador jogou.
     * @param jogador O jogador que fez a jogada.
     */
    void atualizaTabuleiro(int linha, int coluna, char jogador) override;

    /**
     * @brief Verifica se existe um vencedor no jogo.
     * 
     * @return true se houver um vencedor, false caso contrário.
     */
    bool verificaVencedor() override;

    /**
     * @brief Define a pontuação do jogador B.
     * 
     * @param num Nova pontuação para o jogador B.
     */
    void setPontosB(int num);

    /**
     * @brief Define a pontuação do jogador P.
     * 
     * @param num Nova pontuação para o jogador P.
     */
    void setPontosP(int num);

    /**
     * @brief Retorna a pontuação do jogador B.
     * 
     * @return Pontuação do jogador B.
     */
    int getPontosB();

    /**
     * @brief Retorna a pontuação do jogador P.
     * 
     * @return Pontuação do jogador P.
     */
    int getPontosP();

private:
   
    /**
     * @brief Verifica se a posição indicada é válida no tabuleiro.
     * 
     * @param linha Linha da posição.
     * @param coluna Coluna da posição.
     * @return true se a posição for válida, false caso contrário.
     */
    bool posicaoValida(int linha, int coluna) const;

    /**
     * @brief Inverte as peças ao redor da jogada feita.
     * 
     * @param linha Linha onde a jogada foi realizada.
     * @param coluna Coluna onde a jogada foi realizada.
     * @param jogador O jogador que fez a jogada.
     */
    void inverterPecas(int linha, int coluna, char jogador);
    
    /**
     * @brief Verifica se há peças do jogador adversário em uma direção.
     * 
     * @param linha Linha da posição inicial.
     * @param coluna Coluna da posição inicial.
     * @param dirLinha Direção da linha.
     * @param dirColuna Direção da coluna.
     * @param jogador O jogador que está realizando a verificação.
     * @return true se houver peças do adversário na direção, false caso contrário.
     */
    bool verificaDirecao(int linha, int coluna, int dirLinha, int dirColuna, char jogador) const;
};

#endif // REVERSI_H