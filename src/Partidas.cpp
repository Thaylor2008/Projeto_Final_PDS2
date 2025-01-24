#include "Partidas.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cctype>
using namespace std;
void Partidas::executarPartida(char jogo, Jogador* jogador1, Jogador* jogador2){
    if(toupper(jogo) == 'V'){
        JogoVelha partida;
        char simboloJogador1 = 'X';
        char simboloJogador2 = 'O';
        bool turnoJogador1 = true;
        int jogadas = 0;
        while (jogadas < 9) {
        partida.mostraTabuleiro();
        cout << "Turno de " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido())
             << " (" << (turnoJogador1 ? simboloJogador1 : simboloJogador2) << "):" << endl;

        int linha, coluna;
        cout << "Digite linha e coluna (1-3): ";
        cin >> linha >> coluna;
        linha--;
        coluna--;
        if (partida.testaJogada(linha, coluna,' ')) {
            partida.atualizaTabuleiro(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
            if (partida.verificaVencedor()) {
                partida.mostraTabuleiro();
                cout << "Parabens! " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << " venceu!" << endl;
                if (turnoJogador1) {
                    jogador1->setVitVel(jogador1->getVitVel() + 1);
                    jogador2->setDerVel(jogador2->getDerVel() + 1);
                } else {
                    jogador2->setVitVel(jogador2->getVitVel() + 1);
                    jogador1->setDerRev(jogador1->getDerRev() + 1);
                }
                return;
            }
            turnoJogador1 = !turnoJogador1;
            ++jogadas;
        } else {
            cout << "Jogada inválida. Tente novamente." << endl;
        }
        if (partida.tabuleiroCheio()) {
            partida.mostraTabuleiro();
            cout << "Empate! O jogo terminou sem vencedor." << endl;
            return;
        }
    }
    }else if(toupper(jogo) == 'R'){
    Reversi partida;
    partida.mostraTabuleiro();
    }else if(toupper(jogo) == 'L'){
        Ligue4 partida;
        char simboloJogador1 = 'B';
        char simboloJogador2 = 'R';
        bool turnoJogador1 = true;

        while (true) {
            partida.mostraTabuleiro();
            cout << "Turno de " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido())
                << " (" << (turnoJogador1 ? simboloJogador1 : simboloJogador2) << "):" << endl;

            int coluna;
            cout << "Escolha uma coluna (0-6): ";
            cin >> coluna;

            if (partida.testaJogada(0, coluna, ' ')) {
                partida.atualizaTabuleiro(0, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
                if (partida.verificaVencedor()) {
                    partida.mostraTabuleiro();
                    cout << "Parabéns! " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << " venceu!" << endl;
                    if (turnoJogador1) {
                        jogador1->setVitLig(jogador1->getVitVel() + 1);
                        jogador2->setDerLig(jogador2->getDerVel() + 1);
                    } else {
                        jogador2->setVitLig(jogador2->getVitVel() + 1);
                        jogador1->setDerLig(jogador1->getDerRev() + 1);
                    }
                    return;
                }
                turnoJogador1 = !turnoJogador1;
            } else {
                cout << "Jogada inválida. Tente novamente." << endl;
            }
        }
    }
}