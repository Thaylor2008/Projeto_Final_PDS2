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
    if(jogador1 == nullptr || jogador2 == nullptr)
    throw "jogador inexistente";
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
            cout << "Jogada invalida. Tente novamente." << endl;
        }
        if (partida.tabuleiroCheio()) {
            partida.mostraTabuleiro();
            cout << "Empate! O jogo terminou sem vencedor." << endl;
            return;
        }
    }
    }else if(toupper(jogo) == 'R'){
        Reversi partida;
        char simboloJogador1 = 'X';
        char simboloJogador2 = 'O';
        bool turnoJogador1 = true;
        while (!partida.verificaVencedor()) {
            partida.mostraTabuleiro();
            cout << "Turno de " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido())
                << " (" << (turnoJogador1 ? simboloJogador1 : simboloJogador2) << "):" << endl;

            int linha, coluna;
            cout << "Digite linha e coluna (1-8): ";
            cin >> linha >> coluna;
            linha--;
            coluna--;

            if (partida.testaJogada(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2)) {
                partida.atualizaTabuleiro(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
                turnoJogador1 = !turnoJogador1;
            } else {
                cout << "Jogada invalida. Tente novamente." << endl;
            }
    }
    partida.mostraTabuleiro();
    if(partida.getPontosB() < partida.getPontosP()){
        jogador1->setVitRev(jogador1->getVitRev() + 1);
        jogador2->setDerRev(jogador2->getDerRev() + 1);
        cout << "Vitoria: " << jogador1->getApelido();
    }else if(partida.getPontosB() > partida.getPontosP()){
        jogador2->setVitRev(jogador2->getVitRev() + 1);
        jogador1->setDerRev(jogador1->getDerRev() + 1);
        cout << "Vitoria: " << jogador2->getApelido();
    }else{
        cout << "Empatou ;-;";
    }
    cout << "Fim de jogo!\n";
    }else if(toupper(jogo) == 'L'){
        Ligue4 partida;
        char simboloJogador1 = 'X';
        char simboloJogador2 = 'O';
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
                    cout << "Parabens! " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << " venceu!" << endl;
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
                cout << "Jogada invalida. Tente novamente." << endl;
            }
        }
    }else{
        throw "dados incorretos";
    }
}