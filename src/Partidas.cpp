#include "Partidas.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <limits>
#include <cctype>
using namespace std;

/**
 * @brief Executa uma partida entre dois jogadores, dependendo do tipo de jogo escolhido.
 * 
 * Este método permite que dois jogadores joguem diferentes jogos como "Jogo da Velha", "Reversi" ou "Conecta 4", verificando os movimentos e atualizando os dados dos jogadores após o fim da partida.
 * 
 * @param jogo Caracter que define o tipo de jogo a ser jogado ('V' para Jogo da Velha, 'R' para Reversi, 'L' para Conecta 4).
 * @param jogador1 Ponteiro para o jogador 1 da partida.
 * @param jogador2 Ponteiro para o jogador 2 da partida.
 * 
 * @throw "jogador inexistente" Se algum dos jogadores não for válido (nullptr).
 * @throw "dados incorretos" Se o tipo de jogo fornecido não for válido.
 */
void Partidas::executarPartida(char jogo, Jogador* jogador1, Jogador* jogador2) {
    // Verifica se os jogadores são válidos
    if (jogador1 == nullptr || jogador2 == nullptr)
        throw "jogador inexistente";
    
    // Inicia o Jogo da Velha
    if (toupper(jogo) == 'V') {
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
            try {
                cin >> linha >> coluna;
                if (!cin) {
                    throw invalid_argument("formato incorreto");
                }
            } catch (invalid_argument& e) {
                cerr << "ERRO: " << e.what() << endl;
                std::cin.clear(); // Limpa o flag de erro de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                while (!(cin >> linha >> coluna)) {
                    std::cin.clear(); // Limpa o flag de erro de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                    cout << "ERRO: formato incorreto" << endl;
                }
            }

            linha--;
            coluna--;
            if (partida.testaJogada(linha, coluna, ' ')) {
                partida.atualizaTabuleiro(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
                if (partida.verificaVencedor()) {
                    partida.mostraTabuleiro();
                    cout << "Parabens! " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << " venceu!" << endl;
                    if (turnoJogador1) {
                        jogador1->setVitVel(jogador1->getVitVel() + 1);
                        jogador2->setDerVel(jogador2->getDerVel() + 1);
                        jogador1->setSequencia(jogador1->getSequencia() + 1);
                        jogador2->setSequencia(0);
                    } else {
                        jogador2->setVitVel(jogador2->getVitVel() + 1);
                        jogador1->setDerRev(jogador1->getDerRev() + 1);
                        jogador2->setSequencia(jogador2->getSequencia() + 1);
                        jogador1->setSequencia(0);
                    }
                    return;
                }
                turnoJogador1 = !turnoJogador1;
                ++jogadas;
            } else {
                cout << "ERRO: jogada invalida" << endl;
            }
            if (partida.tabuleiroCheio()) {
                partida.mostraTabuleiro();
                cout << "Empate! O jogo terminou sem vencedor." << endl;
                return;
            }
        }
    } 
    // Inicia o jogo Reversi
    else if (toupper(jogo) == 'R') {
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
            try {
                cin >> linha >> coluna;
                if (!cin) {
                    throw invalid_argument("formato incorreto");
                }
            } catch (invalid_argument& e) {
                cerr << "ERRO: " << e.what() << endl;
                std::cin.clear(); // Limpa o flag de erro de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                while (!(cin >> linha >> coluna)) {
                    std::cin.clear(); // Limpa o flag de erro de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                    cout << "ERRO: formato incorreto" << endl;
                }
            }
            linha--;
            coluna--;

            if (partida.testaJogada(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2)) {
                partida.atualizaTabuleiro(linha, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
                turnoJogador1 = !turnoJogador1;
            } else {
                cout << "ERRO: jogada invalida" << endl;
            }
        }

        partida.mostraTabuleiro();
        if (partida.getPontosB() < partida.getPontosP()) {
            jogador1->setVitRev(jogador1->getVitRev() + 1);
            jogador2->setDerRev(jogador2->getDerRev() + 1);
            jogador1->setSequencia(jogador1->getSequencia() + 1);
            jogador2->setSequencia(0);
            cout << "Vitoria: " << jogador1->getApelido();
        } else if (partida.getPontosB() > partida.getPontosP()) {
            jogador2->setVitRev(jogador2->getVitRev() + 1);
            jogador1->setDerRev(jogador1->getDerRev() + 1);
            jogador2->setSequencia(jogador2->getSequencia() + 1);
            jogador1->setSequencia(0);
            cout << "Vitoria: " << jogador2->getApelido();
        } else {
            cout << "Empatou ;-;";
        }
        cout << "Fim de jogo!\n";
    } 
    // Inicia o jogo Conecta 4
    else if (toupper(jogo) == 'L') {
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
            try {
                cin >> coluna;
                if (!cin) {
                    throw invalid_argument("formato incorreto");
                }
            } catch (invalid_argument& e) {
                cerr << "ERRO: " << e.what() << endl;
                std::cin.clear(); // Limpa o flag de erro de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                while (!(cin >> coluna)) {
                    std::cin.clear(); // Limpa o flag de erro de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                    cout << "ERRO: formato incorreto" << endl;
                }
            }

            if (partida.testaJogada(0, coluna, ' ')) {
                partida.atualizaTabuleiro(0, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
                if (partida.verificaVencedor()) {
                    partida.mostraTabuleiro();
                    cout << "Parabens! " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << " venceu!" << endl;
                    if (turnoJogador1) {
                        jogador1->setVitLig(jogador1->getVitVel() + 1);
                        jogador2->setDerLig(jogador2->getDerVel() + 1);
                        jogador1->setSequencia(jogador1->getSequencia() + 1);
                        jogador2->setSequencia(0);
                    } else {
                        jogador2->setVitLig(jogador2->getVitVel() + 1);
                        jogador1->setDerLig(jogador1->getDerRev() + 1);
                        jogador2->setSequencia(jogador2->getSequencia() + 1);
                        jogador1->setSequencia(0);
                    }
                    return;
                }
                turnoJogador1 = !turnoJogador1;
            } else {
                cout << "ERRO: jogada invalida" << endl;
            }
        }
    } 
    // Caso o tipo de jogo seja inválido
    else {
        throw "dados incorretos";
    }
}