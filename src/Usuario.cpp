#include "Usuario.hpp"
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
 * @brief Obtém o nome do usuário.
 * 
 * Retorna o nome associado ao usuário.
 * 
 * @return string Nome do usuário.
 */
string Usuario::getNome() {
    return nome;
}

/**
 * @brief Obtém o apelido do usuário.
 * 
 * Retorna o apelido associado ao usuário.
 * 
 * @return string Apelido do usuário.
 */
string Usuario::getApelido() {
    return apelido;
}

/**
 * @brief Obtém o número de vitórias do usuário.
 * 
 * Retorna a quantidade de vitórias acumuladas pelo usuário.
 * 
 * @return int Número de vitórias do usuário.
 */
int Usuario::getVitorias() {
    return vitorias;
}

/**
 * @brief Obtém o número de derrotas do usuário.
 * 
 * Retorna a quantidade de derrotas acumuladas pelo usuário.
 * 
 * @return int Número de derrotas do usuário.
 */
int Usuario::getDerrotas() {
    return derrotas;
}

/**
 * @brief Obtém a sequência de vitórias do usuário.
 * 
 * Retorna a sequência atual de vitórias consecutivas do usuário.
 * 
 * @return int Sequência de vitórias.
 */
int Usuario::getSequencia() {
    return sequencia;
}

/**
 * @brief Define o número de vitórias do usuário.
 * 
 * Atualiza o número de vitórias acumuladas pelo usuário.
 * 
 * @param vit Número de vitórias a ser definido.
 */
void Usuario::setVitorias(int vit) {
    this->vitorias = vit;
}

/**
 * @brief Define o número de derrotas do usuário.
 * 
 * Atualiza o número de derrotas acumuladas pelo usuário.
 * 
 * @param der Número de derrotas a ser definido.
 */
void Usuario::setDerrotas(int der) {
    this->derrotas = der;
}

/**
 * @brief Define a sequência de vitórias do usuário.
 * 
 * Atualiza a sequência atual de vitórias consecutivas do usuário.
 * 
 * @param seq Sequência de vitórias a ser definida.
 */
void Usuario::setSequencia(int seq) {
    this->sequencia = seq;
}