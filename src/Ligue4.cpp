#include "Ligue4.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construtor da classe Ligue4.
 * 
 * Inicializa o tabuleiro com 6 linhas e 7 colunas chamando o construtor da classe base JogosTab.
 */
Ligue4::Ligue4() : JogosTab(6, 7) {}

/**
 * @brief Exibe o tabuleiro no console.
 * 
 * Mostra o estado atual do tabuleiro no console, com '.' representando espaços vazios e as peças dos jogadores nas células.
 */
void Ligue4::mostraTabuleiro() const {
    for (int i = 0; i < linhas; ++i) {
        cout << "| ";
        for (int j = 0; j < colunas; ++j) {
            cout << (tabuleiro[i][j] == ' ' ? '.' : tabuleiro[i][j]) << " | ";
        }
        cout << endl;
    }
    cout << "  0   1   2   3   4   5   6  " << endl;
}

/**
 * @brief Verifica se a jogada é válida.
 * 
 * @param linha A linha em que a jogada será feita (não utilizada diretamente aqui).
 * @param coluna A coluna em que a jogada será feita.
 * @param jogador O jogador que está fazendo a jogada (não utilizado diretamente aqui).
 * @return Retorna true se a jogada é válida (a coluna está dentro do intervalo e a célula superior da coluna está vazia), caso contrário, false.
 */
bool Ligue4::testaJogada(int linha, int coluna, char jogador) {
    return coluna >= 0 && coluna < colunas && tabuleiro[0][coluna] == ' ';
}

/**
 * @brief Atualiza o tabuleiro com a jogada do jogador.
 * 
 * @param linha A linha em que a jogada será feita (não utilizada diretamente aqui).
 * @param coluna A coluna em que a jogada será feita.
 * @param jogador O jogador que está fazendo a jogada.
 */
void Ligue4::atualizaTabuleiro(int linha, int coluna, char jogador) {
    int linhaDisponivel = proximaLinhaDisponivel(coluna);
    if (linhaDisponivel != -1) {
        tabuleiro[linhaDisponivel][coluna] = jogador;
    } else {
        cout << "Erro: a coluna está cheia." << endl;
    }
}

/**
 * @brief Verifica se há um vencedor no jogo.
 * 
 * Percorre o tabuleiro e verifica se existe alguma sequência de 4 peças do mesmo jogador em linha, coluna ou diagonal.
 * 
 * @return Retorna true se há um vencedor, caso contrário, false.
 */
bool Ligue4::verificaVencedor() {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (tabuleiro[i][j] != ' ' && verificaSequencia(i, j, tabuleiro[i][j])) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Verifica se a posição (linha, coluna) é válida dentro do tabuleiro.
 * 
 * @param linha A linha da posição a ser verificada.
 * @param coluna A coluna da posição a ser verificada.
 * @return Retorna true se a posição é válida (dentro dos limites do tabuleiro), caso contrário, false.
 */
bool Ligue4::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

/**
 * @brief Verifica se existe uma sequência de 4 peças do mesmo jogador em uma direção específica.
 * 
 * @param linha A linha da posição inicial da sequência.
 * @param coluna A coluna da posição inicial da sequência.
 * @param jogador O jogador que está fazendo a sequência (representado por 'X' ou 'O').
 * @return Retorna true se uma sequência de 4 peças do jogador for encontrada, caso contrário, false.
 */
bool Ligue4::verificaSequencia(int linha, int coluna, char jogador) const {
    static const int direcoes[4][2] = {
        {0, 1}, {1, 0}, {1, 1}, {1, -1} 
    };

    for (auto& direcao : direcoes) {
        int cont = 1;
        for (int d = 1; d < 4; ++d) {
            int novaLinha = linha + d * direcao[0];
            int novaColuna = coluna + d * direcao[1];
            if (posicaoValida(novaLinha, novaColuna) && tabuleiro[novaLinha][novaColuna] == jogador) {
                cont++;
            } else {
                break;
            }
        }
        for (int d = 1; d < 4; ++d) {
            int novaLinha = linha - d * direcao[0];
            int novaColuna = coluna - d * direcao[1];
            if (posicaoValida(novaLinha, novaColuna) && tabuleiro[novaLinha][novaColuna] == jogador) {
                cont++;
            } else {
                break;
            }
        }
        if (cont >= 4) return true;
    }
    return false;
}

/**
 * @brief Encontra a próxima linha disponível em uma coluna.
 * 
 * Verifica qual é a próxima linha vazia em uma coluna para que a peça do jogador seja colocada lá.
 * 
 * @param coluna A coluna a ser verificada.
 * @return Retorna o índice da linha onde a peça pode ser colocada ou -1 se a coluna estiver cheia.
 */
int Ligue4::proximaLinhaDisponivel(int coluna) const {
    for (int i = linhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            return i;
        }
    }
    return -1;
}