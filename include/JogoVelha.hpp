#ifndef JOGOVELHA_H
#define JOGOVELHA_H

#include "JogosTab.hpp"
#include "Jogador.hpp"
#include <vector>
#include <iostream>

/**
 * @brief Classe que implementa o jogo da velha, derivada de JogosTab.
 */
class JogoVelha : public JogosTab {
public:
    /**
     * @brief Construtor da classe JogoVelha.
     * 
     * Inicializa o tabuleiro do jogo da velha com 3x3.
     */
    JogoVelha();

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
     * @brief Verifica se o tabuleiro está completamente preenchido.
     * 
     * @return true se o tabuleiro estiver cheio, false caso contrário.
     */
    bool tabuleiroCheio() const;
};

#endif // JOGOVELHA_H