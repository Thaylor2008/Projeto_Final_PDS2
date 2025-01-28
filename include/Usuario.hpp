#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/**
 * @brief Classe que representa um usuário de um jogo.
 * 
 * A classe contém informações sobre o nome, apelido, vitórias, derrotas e sequência de vitórias
 * do usuário, além de métodos para acessar e modificar essas informações.
 */
class Usuario {
private:
    std::string nome; /**< Nome do usuário. */
    std::string apelido; /**< Apelido do usuário. */
    int vitorias; /**< Número de vitórias do usuário. */
    int derrotas; /**< Número de derrotas do usuário. */
    int sequencia; /**< Sequência de vitórias do usuário. */

public:
    /**
     * @brief Construtor da classe Usuario.
     * 
     * @param nome Nome do usuário.
     * @param apelido Apelido do usuário.
     * Inicializa o número de vitórias, derrotas e sequência com zero.
     */
    Usuario(std::string nome, std::string apelido) : nome(nome), apelido(apelido), vitorias(0), derrotas(0), sequencia(0) {}

    /**
     * @brief Construtor da classe Usuario com valores personalizados para vitórias, derrotas e sequência.
     * 
     * @param nome Nome do usuário.
     * @param apelido Apelido do usuário.
     * @param vit Número de vitórias.
     * @param der Número de derrotas.
     * @param seq Sequência de vitórias.
     */
    Usuario(std::string nome, std::string apelido, int vit, int der, int seq) : nome(nome), apelido(apelido), vitorias(vit), derrotas(der), sequencia(seq) {}

    /**
     * @brief Destruidor da classe Usuario.
     * 
     * O destruidor é virtual para permitir a destruição correta em hierarquias de classes derivadas.
     */
    virtual ~Usuario(){};

    /**
     * @brief Método virtual para mostrar as informações do usuário.
     * 
     * Este método é puramente virtual, sendo implementado pelas classes derivadas.
     */
    virtual void mostrarTabela() = 0;

    /**
     * @brief Retorna o nome do usuário.
     * 
     * @return O nome do usuário.
     */
    std::string getNome();

    /**
     * @brief Retorna o apelido do usuário.
     * 
     * @return O apelido do usuário.
     */
    std::string getApelido();

    /**
     * @brief Retorna o número de vitórias do usuário.
     * 
     * @return O número de vitórias.
     */
    int getVitorias();

    /**
     * @brief Retorna o número de derrotas do usuário.
     * 
     * @return O número de derrotas.
     */
    int getDerrotas();

    /**
     * @brief Retorna a sequência de vitórias do usuário.
     * 
     * @return A sequência de vitórias.
     */
    int getSequencia();

    /**
     * @brief Define o número de vitórias do usuário.
     * 
     * @param vit Novo número de vitórias.
     */
    void setVitorias(int vit);

    /**
     * @brief Define o número de derrotas do usuário.
     * 
     * @param der Novo número de derrotas.
     */
    void setDerrotas(int der);

    /**
     * @brief Define a sequência de vitórias do usuário.
     * 
     * @param seq Nova sequência de vitórias.
     */
    void setSequencia(int seq);
};

#endif
