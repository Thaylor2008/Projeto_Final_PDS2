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
        cout << "Erro: tentativa de atualizar com jogada inválida." << endl;
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

// Executa uma partida de Jogo da Velha entre dois jogadores
void JogoVelha::executarPartida(Usuario* jogador1, Usuario* jogador2) {
    char simboloJogador1 = 'X';
    char simboloJogador2 = 'O';
    bool turnoJogador1 = true;
    int jogadas = 0;

    while (jogadas < 9) {
        mostraTabuleiro();
        cout << "Turno de " << (turnoJogador1 ? jogador1->nome : jogador2->nome)
             << " (" << (turnoJogador1 ? simboloJogador1 : simboloJogador2) << "):" << endl;

        int linha, coluna;
        cout << "Digite linha e coluna (0-2): ";
        cin >> linha >> coluna;

        if (testaJogada(linha, coluna)) {
            atualizaTabuleiro(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
            if (verificaVencedor()) {
                mostraTabuleiro();
                cout << "Parabéns! " << (turnoJogador1 ? jogador1->nome : jogador2->nome) << " venceu!" << endl;
                if (turnoJogador1) {
                    jogador1->vitorias++;
                    jogador2->derrotas++;
                } else {
                    jogador2->vitorias++;
                    jogador1->derrotas++;
                }
                return;
            }
            turnoJogador1 = !turnoJogador1;
            ++jogadas;
        } else {
            cout << "Jogada inválida. Tente novamente." << endl;
        }

        // Empate ao encher o tabuleiro sem vencedor
        if (tabuleiroCheio()) {
            mostraTabuleiro();
            cout << "Empate! O jogo terminou sem vencedor." << endl;
            return;
        }
    }
}
