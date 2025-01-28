#ifndef JOGOSTAB_H
#define JOGOSTAB_H

#include <vector>
#include <string>

/**
 * @brief Classe base abstrata para jogos de tabuleiro.
 */
class JogosTab {
protected:
    /**
     * @brief Representa o tabuleiro do jogo como uma matriz de caracteres.
     */
    std::vector<std::vector<char>> tabuleiro;

    /**
     * @brief Número de linhas do tabuleiro.
     */
    int linhas;

    /**
     * @brief Número de colunas do tabuleiro.
     */
    int colunas;

public:
    /**
     * @brief Construtor da classe JogosTab.
     * 
     * @param linhas Número de linhas do tabuleiro.
     * @param colunas Número de colunas do tabuleiro.
     */
    JogosTab(int linhas, int colunas) : tabuleiro(std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '))), linhas(linhas), colunas(colunas) {}

    /**
     * @brief Destrutor virtual da classe JogosTab.
     */
    virtual ~JogosTab() = default;

    /**
     * @brief Exibe o tabuleiro atual.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas.
     */
    virtual void mostraTabuleiro() const = 0;

    /**
     * @brief Testa a validade de uma jogada.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas.
     * 
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param jogador Identificador do jogador (caractere).
     * @return true se a jogada for válida, false caso contrário.
     */
    virtual bool testaJogada(int linha, int coluna, char jogador) = 0;

    /**
     * @brief Atualiza o tabuleiro com a jogada de um jogador.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas.
     * 
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param jogador Identificador do jogador (caractere).
     */
    virtual void atualizaTabuleiro(int linha, int coluna, char jogador) = 0;

    /**
     * @brief Verifica se há um vencedor no jogo.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas.
     * 
     * @return true se houver um vencedor, false caso contrário.
     */
    virtual bool verificaVencedor() = 0;

    /**
     * @brief Reseta o tabuleiro para o estado inicial.
     */
    virtual void resetaTabuleiro() {
        for (auto& linha : tabuleiro) {
            std::fill(linha.begin(), linha.end(), ' ');
        }
    }

    /**
     * @brief Obtém o tabuleiro atual.
     * 
     * @return Referência constante para o tabuleiro.
     */
    const std::vector<std::vector<char>>& getTabuleiro() const { return tabuleiro;}

    /**
     * @brief Obtém o número de linhas do tabuleiro.
     * 
     * @return Número de linhas.
     */
    int getLinhas() const { return linhas;}

    /**
     * @brief Obtém o número de colunas do tabuleiro.
     * 
     * @return Número de colunas.
     */
    int getColunas() const { return colunas;}
};

#endif // JOGOSTAB_H