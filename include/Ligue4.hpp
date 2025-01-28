#ifndef LIGUE4_H
#define LIGUE4_H

#include "JogosTab.hpp"
#include "Jogador.hpp"

/**
 * @brief Classe que implementa o jogo Lig 4, derivada de JogosTab.
 */
class Ligue4 : public JogosTab {
public:
    /**
     * @brief Construtor que inicializa o tabuleiro com o tamanho padrão de 6x7.
     */
    Ligue4();

    /**
     * @brief Exibe o tabuleiro do jogo no console.
     */
    void mostraTabuleiro() const override;
    
    /**
     * @brief Verifica se uma jogada é válida.
     * 
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param jogador Símbolo do jogador que está fazendo a jogada.
     * @return true se a jogada for válida, false caso contrário.
     */
    bool testaJogada(int linha, int coluna, char jogador) override;

    /**
     * @brief Atualiza o tabuleiro com a jogada do jogador.
     * 
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param jogador Símbolo do jogador que está fazendo a jogada.
     */
    void atualizaTabuleiro(int linha, int coluna, char jogador) override;

    /**
     * @brief Verifica se há um vencedor no jogo.
     * 
     * @return true se houver um vencedor, false caso contrário.
     */
    bool verificaVencedor() override;
  
    /**
     * @brief Verifica se a posição é válida no tabuleiro.
     * 
     * @param linha Linha a ser verificada.
     * @param coluna Coluna a ser verificada.
     * @return true se a posição for válida, false caso contrário.
     */
    bool posicaoValida(int linha, int coluna) const;

    /**
     * @brief Verifica se há uma sequência vencedora a partir de uma posição.
     * 
     * @param linha Linha inicial da verificação.
     * @param coluna Coluna inicial da verificação.
     * @param jogador Símbolo do jogador a ser verificado.
     * @return true se houver uma sequência vencedora, false caso contrário.
     */
    bool verificaSequencia(int linha, int coluna, char jogador) const;

    /**
     * @brief Retorna a próxima linha disponível em uma coluna.
     * 
     * @param coluna Coluna a ser verificada.
     * @return Índice da próxima linha disponível ou -1 se a coluna estiver cheia.
     */
    int proximaLinhaDisponivel(int coluna) const;
};

#endif