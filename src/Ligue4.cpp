#include "Ligue4.hpp"
#include <iostream>
using namespace std;

// Construtor que inicializa o tabuleiro com 6 linhas e 7 colunas
Ligue4::Ligue4() : JogosTab(6, 7) {}

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


bool Ligue4::testaJogada(int linha, int coluna) const {
    return coluna >= 0 && coluna < colunas && tabuleiro[0][coluna] == ' ';
}

void Ligue4::atualizaTabuleiro(int linha, int coluna, char jogador) {
    int linhaDisponivel = proximaLinhaDisponivel(coluna);
    if (linhaDisponivel != -1) {
        tabuleiro[linhaDisponivel][coluna] = jogador;
    } else {
        cout << "Erro: a coluna está cheia." << endl;
    }
}

bool Ligue4::verificaVencedor() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (tabuleiro[i][j] != ' ' && verificaSequencia(i, j, tabuleiro[i][j])) {
                return true;
            }
        }
    }
    return false;
}

void Ligue4::executarPartida(Usuario* jogador1, Usuario* jogador2) {
    char simboloJogador1 = 'X';
    char simboloJogador2 = 'O';
    bool turnoJogador1 = true;

    while (true) {
        mostraTabuleiro();
        cout << "Turno de " << (turnoJogador1 ? jogador1->nome : jogador2->nome)
             << " (" << (turnoJogador1 ? simboloJogador1 : simboloJogador2) << "):" << endl;

        int coluna;
        cout << "Escolha uma coluna (0-6): ";
        cin >> coluna;

        if (testaJogada(0, coluna)) {
            atualizaTabuleiro(0, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
            if (verificaVencedor()) {
                mostraTabuleiro();
                cout << "Parabéns! " << (turnoJogador1 ? jogador1->nome : jogador2->nome) << " venceu!" << endl;
                if (turnoJogador1) jogador1->vitorias++, jogador2->derrotas++;
                else jogador2->vitorias++, jogador1->derrotas++;
                return;
            }
            turnoJogador1 = !turnoJogador1;
        } else {
            cout << "Jogada inválida. Tente novamente." << endl;
        }
    }
}

bool Ligue4::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

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

int Ligue4::proximaLinhaDisponivel(int coluna) const {
    for (int i = linhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            return i;
        }
    }
    return -1;
}
