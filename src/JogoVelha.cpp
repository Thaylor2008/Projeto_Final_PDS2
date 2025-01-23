#include "JogoVelha.hpp"
#include <iostream>
using namespace std;

// Construtor
JogoVelha::JogoVelha() : JogosTab(3, 3) {}

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

bool JogoVelha::testaJogada(int linha, int coluna) const {
    return linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ';
}

// Atualiza o tabuleiro com a jogada do jogador
void JogoVelha::atualizaTabuleiro(int linha, int coluna, char jogador) {
    if (testaJogada(linha, coluna)) {
        tabuleiro[linha][coluna] = jogador;
    } else {
        cout << "Erro: tentativa de atualizar com jogada invalida." << endl;
    }
}

// Verifica se há um vencedor
bool JogoVelha::verificaVencedor() const {
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

// Método auxiliar para verificar se o tabuleiro está cheio
bool JogoVelha::tabuleiroCheio() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}