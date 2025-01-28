#ifndef JOGADOR_H
#define JOGADOR_H

#include "Usuario.hpp"
#include <iostream>

/**
 * @brief Classe que representa um jogador, derivada de Usuario.
 */
class Jogador : public Usuario {
private:
    /**
     * @brief Número de vitórias em partidas de velocidade.
     */
    int vitVel;

    /**
     * @brief Número de vitórias em partidas de reversão.
     */
    int vitRev;

    /**
     * @brief Número de vitórias em partidas de ligação.
     */
    int vitLig;

    /**
     * @brief Número de derrotas em partidas de velocidade.
     */
    int derVel;

    /**
     * @brief Número de derrotas em partidas de reversão.
     */
    int derRev;

    /**
     * @brief Número de derrotas em partidas de ligação.
     */
    int derLig;

public:
    /**
     * @brief Construtor para inicializar um jogador com nome e apelido.
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     */
    Jogador(std::string nome, std::string apelido);

    /**
     * @brief Construtor para inicializar um jogador com todos os atributos.
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     * @param vitVel Número de vitórias em velocidade.
     * @param vitRev Número de vitórias em reversão.
     * @param vitLig Número de vitórias em ligação.
     * @param derVel Número de derrotas em velocidade.
     * @param derRev Número de derrotas em reversão.
     * @param derLig Número de derrotas em ligação.
     */
    Jogador(std::string nome, std::string apelido, int vitVel, int vitRev, int vitLig, int derVel, int derRev, int derLig);

    /**
     * @brief Construtor de cópia.
     * 
     * @param outro Referência para outro objeto Jogador a ser copiado.
     */
    Jogador(const Jogador& outro);

    /**
     * @brief Operador de atribuição.
     * 
     * @param outro Referência para outro objeto Jogador a ser atribuído.
     * @return Referência para o objeto atual após a atribuição.
     */
    Jogador& operator=(const Jogador& outro);

    /**
     * @brief Obtém o número de vitórias em partidas de velocidade.
     * 
     * @return Número de vitórias em velocidade.
     */
    int getVitVel();

    /**
     * @brief Obtém o número de vitórias em partidas de reversão.
     * 
     * @return Número de vitórias em reversão.
     */
    int getVitRev();

    /**
     * @brief Obtém o número de vitórias em partidas de ligação.
     * 
     * @return Número de vitórias em ligação.
     */
    int getVitLig();

    /**
     * @brief Obtém o número de derrotas em partidas de velocidade.
     * 
     * @return Número de derrotas em velocidade.
     */
    int getDerVel();

    /**
     * @brief Obtém o número de derrotas em partidas de reversão.
     * 
     * @return Número de derrotas em reversão.
     */
    int getDerRev();

    /**
     * @brief Obtém o número de derrotas em partidas de ligação.
     * 
     * @return Número de derrotas em ligação.
     */
    int getDerLig();

    /**
     * @brief Define o número de vitórias em partidas de velocidade.
     * 
     * @param vitVel Número de vitórias em velocidade.
     */
    void setVitVel(int vitVel);

    /**
     * @brief Define o número de vitórias em partidas de reversão.
     * 
     * @param vitRev Número de vitórias em reversão.
     */
    void setVitRev(int vitRev);

    /**
     * @brief Define o número de vitórias em partidas de ligação.
     * 
     * @param vitLig Número de vitórias em ligação.
     */
    void setVitLig(int vitLig);

    /**
     * @brief Define o número de derrotas em partidas de velocidade.
     * 
     * @param derVel Número de derrotas em velocidade.
     */
    void setDerVel(int derVel);

    /**
     * @brief Define o número de derrotas em partidas de reversão.
     * 
     * @param derRev Número de derrotas em reversão.
     */
    void setDerRev(int derRev);

    /**
     * @brief Define o número de derrotas em partidas de ligação.
     * 
     * @param derLig Número de derrotas em ligação.
     */
    void setDerLig(int derLig);

    /**
     * @brief Destrutor da classe Jogador.
     */
    ~Jogador() override {}

    /**
     * @brief Exibe uma tabela com as estatísticas do jogador.
     */
    void mostrarTabela();
};

#endif // JOGADOR_H