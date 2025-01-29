#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

/**
 * @brief Construtor para criar um jogador com nome e apelido. Inicializa as vitórias e derrotas como 0.
 * 
 * @param nome Nome do jogador.
 * @param apelido Apelido do jogador.
 */
Jogador::Jogador(string nome, string apelido) : Usuario(nome, apelido), vitVel(0), vitRev(0), vitLig(0),
derVel(0), derRev(0), derLig(0) {}

/**
 * @brief Construtor para criar um jogador com todas as informações (vitórias e derrotas).
 * 
 * @param nome Nome do jogador.
 * @param apelido Apelido do jogador.
 * @param vitVel Vitórias no jogo Velha.
 * @param vitRev Vitórias no jogo Reversi.
 * @param vitLig Vitórias no jogo Lig4.
 * @param derVel Derrotas no jogo Velha.
 * @param derRev Derrotas no jogo Reversi.
 * @param derLig Derrotas no jogo Lig4.
 * @param seq Sequência de vitórias.
 */
Jogador::Jogador(std::string nome, std::string apelido, int vitVel, int vitRev, int vitLig, int derVel, 
int derRev, int derLig, int seq) : Usuario(nome, apelido, (vitLig + vitRev + vitVel), (derLig + derRev + derVel),
seq), vitVel(vitVel), vitRev(vitRev), vitLig(vitLig), derVel(derVel), derRev(derRev), derLig(derLig) {}

/**
 * @brief Exibe uma tabela. Função placeholder para ser implementada ou substituída.
 */
void Jogador::mostrarTabela() {
    cout << "Tabela!";
}

/**
 * @brief Retorna o número de vitórias no jogo Velha.
 * 
 * @return Número de vitórias no jogo Velha.
 */
int Jogador::getVitVel() {
    return vitVel;
}

/**
 * @brief Retorna o número de vitórias no jogo Reversi.
 * 
 * @return Número de vitórias no jogo Reversi.
 */
int Jogador::getVitRev() {
    return vitRev;
}

/**
 * @brief Retorna o número de vitórias no jogo Lig4.
 * 
 * @return Número de vitórias no jogo Lig4.
 */
int Jogador::getVitLig() {
    return vitLig;
}

/**
 * @brief Retorna o número de derrotas no jogo Velha.
 * 
 * @return Número de derrotas no jogo Velha.
 */
int Jogador::getDerVel() {
    return derVel;
}

/**
 * @brief Retorna o número de derrotas no jogo Reversi.
 * 
 * @return Número de derrotas no jogo Reversi.
 */
int Jogador::getDerRev() {
    return derRev;
}

/**
 * @brief Retorna o número de derrotas no jogo Lig4.
 * 
 * @return Número de derrotas no jogo Lig4.
 */
int Jogador::getDerLig() {
    return derLig;
}

/**
 * @brief Define o número de vitórias no jogo Velha.
 * 
 * @param vitVel Número de vitórias no jogo Velha.
 */
void Jogador::setVitVel(int vitVel) {
    this->vitVel = vitVel;
}

/**
 * @brief Define o número de vitórias no jogo Reversi.
 * 
 * @param vitRev Número de vitórias no jogo Reversi.
 */
void Jogador::setVitRev(int vitRev) {
    this->vitRev = vitRev;
}

/**
 * @brief Define o número de vitórias no jogo Lig4.
 * 
 * @param vitLig Número de vitórias no jogo Lig4.
 */
void Jogador::setVitLig(int vitLig) {
    this->vitLig = vitLig;
}

/**
 * @brief Define o número de derrotas no jogo Velha.
 * 
 * @param derVel Número de derrotas no jogo Velha.
 */
void Jogador::setDerVel(int derVel) {
    this->derVel = derVel;
}

/**
 * @brief Define o número de derrotas no jogo Reversi.
 * 
 * @param derRev Número de derrotas no jogo Reversi.
 */
void Jogador::setDerRev(int derRev) {
    this->derRev = derRev;
}

/**
 * @brief Define o número de derrotas no jogo Lig4.
 * 
 * @param derLig Número de derrotas no jogo Lig4.
 */
void Jogador::setDerLig(int derLig) {
    this->derLig = derLig;
}

/**
 * @brief Construtor de cópia, cria um novo jogador com os dados de outro jogador.
 * 
 * @param outro Jogador a ser copiado.
 */
Jogador::Jogador(const Jogador& outro)
    : Usuario(outro), vitVel(outro.vitVel), vitRev(outro.vitRev), vitLig(outro.vitLig),
      derVel(outro.derVel), derRev(outro.derRev), derLig(outro.derLig) {}

/**
 * @brief Operador de atribuição para copiar as informações de um jogador para outro.
 * 
 * @param outro Jogador a ser copiado.
 * @return Referência para o jogador atual.
 */
Jogador& Jogador::operator=(const Jogador& outro) {
    if (this != &outro) {
        Usuario::operator=(outro);  // Copia os dados da classe base
        vitVel = outro.vitVel;
        vitRev = outro.vitRev;
        vitLig = outro.vitLig;
        derVel = outro.derVel;
        derRev = outro.derRev;
        derLig = outro.derLig;
    }
    return *this;
}
