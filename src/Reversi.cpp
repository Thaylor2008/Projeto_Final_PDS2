#include "Reversi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Reversi::Reversi() : JogosTab(8, 8), pontosP(2), PontosB(2) {
    tabuleiro[3][3] = 'W';
    tabuleiro[3][4] = 'B';
    tabuleiro[4][3] = 'B';
    tabuleiro[4][4] = 'W';
}

void Reversi::mostraTabuleiro() const {
    cout << "  ";
    for (int i = 0; i < colunas; ++i) {
        cout << "   " << (i+1);
    }
    cout << endl;

    for (int i = 0; i < linhas; ++i) {
        cout << (i+1) << " ";
        for (int j = 0; j < colunas; ++j) {
            cout << "   " << tabuleiro[i][j];
        }
        cout << endl;
    }
}

