#include "Reversi.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construtor da classe Reversi.
 * 
 * Este construtor inicializa o tabuleiro com a configuração padrão do jogo Reversi, com as quatro peças iniciais no centro.
 */
Reversi::Reversi() : JogosTab(8, 8) {
    tabuleiro[3][3] = 'O';
    tabuleiro[3][4] = 'X';
    tabuleiro[4][3] = 'X';
    tabuleiro[4][4] = 'O';
}

/**
 * @brief Exibe o estado atual do tabuleiro.
 * 
 * Mostra o tabuleiro com as peças e os números das colunas e linhas para facilitar a visualização.
 */
void Reversi::mostraTabuleiro() const {
    for (int i = 0; i < linhas; ++i) {
        cout << i+1 << "| ";
        for (int j = 0; j < colunas; ++j) {
            cout << (tabuleiro[i][j] == ' ' ? '.' : tabuleiro[i][j]) << " | ";
        }
        cout << endl;
    }
    cout << "   1   2   3   4   5   6   7   8" << endl;
}

/**
 * @brief Testa se uma jogada é válida.
 * 
 * Verifica se a posição onde o jogador deseja colocar sua peça é válida, ou seja, se está livre e se a jogada segue as regras do Reversi.
 * 
 * @param linha Linha onde o jogador deseja jogar.
 * @param coluna Coluna onde o jogador deseja jogar.
 * @param jogador O jogador que está tentando fazer a jogada ('X' ou 'O').
 * 
 * @return true Se a jogada for válida.
 * @return false Se a jogada for inválida.
 */
bool Reversi::testaJogada(int linha, int coluna, char jogador) {
    if (!posicaoValida(linha, coluna) || tabuleiro[linha][coluna] != ' ') {
        return false;
    }

    for (int dirLinha = -1; dirLinha <= 1; ++dirLinha) {
        for (int dirColuna = -1; dirColuna <= 1; ++dirColuna) {
            if (dirLinha != 0 || dirColuna != 0) {
                if (verificaDirecao(linha, coluna, dirLinha, dirColuna, jogador)) {
                    return true;
                }
            }
        }
    }

    return false;
}

/**
 * @brief Atualiza o tabuleiro com a jogada.
 * 
 * Coloca a peça do jogador na posição escolhida e inverte as peças adversárias ao redor da jogada.
 * 
 * @param linha Linha onde o jogador fez a jogada.
 * @param coluna Coluna onde o jogador fez a jogada.
 * @param jogador O jogador que está fazendo a jogada.
 */
void Reversi::atualizaTabuleiro(int linha, int coluna, char jogador) {
    tabuleiro[linha][coluna] = jogador;
    for (int dirLinha = -1; dirLinha <= 1; ++dirLinha) {
        for (int dirColuna = -1; dirColuna <= 1; ++dirColuna) {
            if (dirLinha != 0 || dirColuna != 0) {
                if (verificaDirecao(linha, coluna, dirLinha, dirColuna, jogador)) {
                    inverterPecas(linha, coluna, jogador);
                }
            }
        }
    }
}

/**
 * @brief Verifica se há um vencedor.
 * 
 * Conta as peças de cada jogador e verifica se há um vencedor, ou se o jogo terminou em empate.
 * 
 * @return true Se houve um vencedor (ou o jogo terminou).
 * @return false Se o jogo ainda está em andamento.
 */
bool Reversi::verificaVencedor() {
    int countX = 0, countO = 0;

    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            if (celula == 'X') ++countX;
            if (celula == 'O') ++countO;
        }
    }
    setPontosP(countX);
    setPontosB(countO);
    return countX == 0 || countO == 0 || (countX + countO == linhas * colunas);
}

/**
 * @brief Verifica se uma posição no tabuleiro é válida.
 * 
 * @param linha Linha da posição a ser verificada.
 * @param coluna Coluna da posição a ser verificada.
 * 
 * @return true Se a posição é válida.
 * @return false Se a posição é inválida.
 */
bool Reversi::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

/**
 * @brief Inverte as peças ao redor de uma jogada.
 * 
 * Para cada direção possível, verifica se é necessário inverter as peças adversárias.
 * 
 * @param linha Linha onde a jogada foi realizada.
 * @param coluna Coluna onde a jogada foi realizada.
 * @param jogador O jogador que fez a jogada.
 */
void Reversi::inverterPecas(int linha, int coluna, char jogador) {
    for (int dirLinha = -1; dirLinha <= 1; ++dirLinha) {
        for (int dirColuna = -1; dirColuna <= 1; ++dirColuna) {
            if (verificaDirecao(linha, coluna, dirLinha, dirColuna, jogador)) {
                int i = linha + dirLinha, j = coluna + dirColuna;
                while (posicaoValida(i, j) && tabuleiro[i][j] != jogador) {
                    tabuleiro[i][j] = jogador;
                    i += dirLinha;
                    j += dirColuna;
                }
            }
        }
    }
}

/**
 * @brief Verifica se há peças adversárias para inverter em uma direção.
 * 
 * Verifica se, em uma direção específica, existe uma sequência de peças adversárias seguida de uma peça do jogador.
 * 
 * @param linha Linha da posição onde a jogada foi realizada.
 * @param coluna Coluna da posição onde a jogada foi realizada.
 * @param dirLinha Direção na linha.
 * @param dirColuna Direção na coluna.
 * @param jogador O jogador que fez a jogada.
 * 
 * @return true Se houver peças adversárias para inverter.
 * @return false Se não houver peças adversárias para inverter.
 */
bool Reversi::verificaDirecao(int linha, int coluna, int dirLinha, int dirColuna, char jogador) const {
    int i = linha + dirLinha, j = coluna + dirColuna;

    bool encontrouAdversario = false;

    while (posicaoValida(i, j)) {
        if (tabuleiro[i][j] == ' ') return false;
        if (tabuleiro[i][j] == jogador) return encontrouAdversario;

        encontrouAdversario = true;
        i += dirLinha;
        j += dirColuna;
    }

    return false;
}

/**
 * @brief Define a quantidade de pontos do jogador "P".
 * 
 * @param num Número de pontos do jogador "P".
 */
void Reversi::setPontosP(int num) {
    this->pontosP = num;
}

/**
 * @brief Define a quantidade de pontos do jogador "B".
 * 
 * @param num Número de pontos do jogador "B".
 */
void Reversi::setPontosB(int num) {
    this->pontosB = num;
}

/**
 * @brief Obtém a quantidade de pontos do jogador "B".
 * 
 * @return int Número de pontos do jogador "B".
 */
int Reversi::getPontosB() {
    return pontosB;
}

/**
 * @brief Obtém a quantidade de pontos do jogador "P".
 * 
 * @return int Número de pontos do jogador "P".
 */
int Reversi::getPontosP() {
    return pontosP;
}