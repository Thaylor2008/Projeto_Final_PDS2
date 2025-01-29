#include "JogoVelha.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construtor da classe JogoVelha.
 * 
 * Inicializa o tabuleiro 3x3 chamando o construtor da classe base JogosTab.
 */
JogoVelha::JogoVelha() : JogosTab(3, 3) {}

/**
 * @brief Exibe o tabuleiro no console.
 * 
 * Mostra o estado atual do tabuleiro no console, com ' ' representando espaços vazios.
 */
void JogoVelha::mostraTabuleiro() const {
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << (tabuleiro[i][j] == ' ' ? ' ' : tabuleiro[i][j]) << " | ";
        }
        cout << endl;
        if (i < 2) {
            cout << "|---|---|---|" << endl;
        }
    }
}

/**
 * @brief Verifica se a jogada é válida.
 * 
 * @param linha A linha em que a jogada foi feita.
 * @param coluna A coluna em que a jogada foi feita.
 * @param jogador O jogador que está fazendo a jogada.
 * @return Retorna true se a jogada é válida (posição dentro do tabuleiro e célula vazia), caso contrário, false.
 */
bool JogoVelha::testaJogada(int linha, int coluna, char jogador) {
    return linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ';
}

/**
 * @brief Atualiza o tabuleiro com a jogada do jogador.
 * 
 * @param linha A linha em que a jogada será feita.
 * @param coluna A coluna em que a jogada será feita.
 * @param jogador O jogador que está fazendo a jogada.
 */
void JogoVelha::atualizaTabuleiro(int linha, int coluna, char jogador) {
    if (testaJogada(linha, coluna, ' ')) {
        tabuleiro[linha][coluna] = jogador;
    } else {
        cout << "Erro: tentativa de atualizar com jogada invalida." << endl;
    }
}

/**
 * @brief Verifica se há um vencedor no jogo.
 * 
 * Verifica se há uma linha, coluna ou diagonal com todas as células preenchidas pelo mesmo jogador.
 * 
 * @return Retorna true se há um vencedor, caso contrário, false.
 */
bool JogoVelha::verificaVencedor() {
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return true; 
        }
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return true;
        }
    }

    // Verifica diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return true; 
    }
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return true; 
    }
    return false;
}

/**
 * @brief Verifica se o tabuleiro está cheio.
 * 
 * @return Retorna true se o tabuleiro está cheio (sem espaços vazios), caso contrário, false.
 */
bool JogoVelha::tabuleiroCheio() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == ' ') {
                return false; // Encontrou um espaço vazio
            }
        }
    }
    return true; // Tabuleiro cheio
}
