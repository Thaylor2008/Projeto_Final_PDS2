#ifndef PARTIDAS_HPP
#define PARTIDAS_HPP

#include "Jogador.hpp"
#include "JogosTab.hpp"
#include "JogoVelha.hpp"
#include "Reversi.hpp"
#include "Ligue4.hpp"
#include <string>
#include <vector>

/**
 * @brief Classe que gerencia partidas entre jogadores.
 */
class Partidas {
private:
    /**
     * @brief Histórico das partidas realizadas.
     * 
     * Cada entrada no vetor representa uma descrição ou resumo de uma partida.
     */
    std::vector<std::string> historico;

public:
    /**
     * @brief Executa uma partida entre dois jogadores em um jogo específico.
     * 
     * @param jogo O tipo de jogo a ser jogado ('V' para Jogo da Velha, 'R' para Reversi, 'L' para Ligue 4).
     * @param jogador1 Ponteiro para o primeiro jogador.
     * @param jogador2 Ponteiro para o segundo jogador.
     */
    void executarPartida(char jogo, Jogador* jogador1, Jogador* jogador2);
};

#endif
