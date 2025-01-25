#include "Reversi.hpp"
#include <iostream>
using namespace std;

// Construtor que inicializa o tabuleiro com a configuração inicial do Reversi
Reversi::Reversi() : JogosTab(8, 8) {
    tabuleiro[3][3] = 'O';
    tabuleiro[3][4] = 'X';
    tabuleiro[4][3] = 'X';
    tabuleiro[4][4] = 'O';
}

// Mostra o estado atual do tabuleiro
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

// Testa se uma jogada é válida
bool Reversi::testaJogada(int linha, int coluna,char jogador) {
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

// Atualiza o tabuleiro com a jogada
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

// Verifica se há um vencedor
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
// Verifica se uma posição no tabuleiro é válida
bool Reversi::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

// Realiza a inversão das peças ao redor de uma jogada
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

// Verifica se há peças para inverter em uma direção
bool Reversi::verificaDirecao(int linha, int coluna, int dirLinha, int dirColuna, char jogador) const {
    //char adversario = (jogador == 'X') ? 'O' : 'X';
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
void Reversi::setPontosB(int num){
    this->pontosB = num;
}
void Reversi::setPontosP(int num){
    this->pontosP = num;
}
int Reversi::getPontosB(){
    return pontosB;
}
int Reversi::getPontosP(){
    return pontosP;
}