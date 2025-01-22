#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nome;
    std::string apelido;
    int vitorias;
    int derrotas;
    int sequencia;

public:
    Usuario(std::string nome, std::string apelido) : nome(nome), apelido(apelido), vitorias(0), derrotas(0), sequencia(0) {}
    Usuario(std::string nome, std::string apelido, int vit, int der, int seq) : nome(nome), apelido(apelido), vitorias(vit), derrotas(der), sequencia(seq) {}
    virtual ~Usuario(){};
    virtual void mostrarTabela() = 0;
    std::string getNome();
    std::string getApelido();
    int getVitorias();
    int getDerrotas();
    int getSequencia();
    void setVitorias(int);
    void setDerrotas(int);
    void setSequencia(int);
};

#endif