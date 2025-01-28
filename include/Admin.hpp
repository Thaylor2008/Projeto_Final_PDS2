#ifndef ADMIN_H
#define ADMIN_H

#include "Jogador.hpp"
#include <vector>
#include <string>

/**
 * @brief Classe responsável por gerenciar jogadores.
 */
class Admin {
private:
    /**
     * @brief Vetor de ponteiros para os jogadores cadastrados.
     */
    std::vector<Jogador*> Jogadores;

    /**
     * @brief Nome do arquivo usado para persistência de dados dos jogadores.
     */
    std::string arquivo;

public:
    /**
     * @brief Construtor da classe Admin.
     * 
     * @param arquivo Nome do arquivo para persistência de dados.
     */
    Admin(std::string arquivo);

    /**
     * @brief Cria um novo jogador com nome e apelido.
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     * @return Ponteiro para o jogador criado.
     */
    Jogador* createJogador(std::string nome, std::string apelido);

    /**
     * @brief Cria um novo jogador com todos os atributos fornecidos.
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     * @param atributo1 Valor do primeiro atributo.
     * @param atributo2 Valor do segundo atributo.
     * @param atributo3 Valor do terceiro atributo.
     * @param atributo4 Valor do quarto atributo.
     * @param atributo5 Valor do quinto atributo.
     * @param atributo6 Valor do sexto atributo.
     * @param atributo7 Valor do sétimo atributo.
     * @return Ponteiro para o jogador criado.
     */
    Jogador* createJogador(std::string nome, std::string apelido, int atributo1, int atributo2, int atributo3, int atributo4, int atributo5, int atributo6, int atributo7);

    /**
     * @brief Busca um jogador pelo apelido.
     * 
     * @param apelido Apelido do jogador a ser buscado.
     * @return Ponteiro para o jogador encontrado, ou nullptr se não encontrado.
     */
    Jogador* buscaApelido(std::string apelido);

    /**
     * @brief Atualiza os dados dos jogadores no arquivo.
     */
    void uptadeJogadores();

    /**
     * @brief Lista todos os usuários cadastrados.
     */
    void listarUsuarios();

    /**
     * @brief Remove um jogador pelo apelido.
     * 
     * @param apelido Apelido do jogador a ser removido.
     * @return Vetor atualizado de jogadores.
     */
    std::vector<Jogador*> removerJogador(std::string apelido);

    /**
     * @brief Destrutor da classe Admin.
     */
    ~Admin();
};

#endif // ADMIN_H