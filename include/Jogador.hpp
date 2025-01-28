#ifndef JOGADOR_H
#define JOGADOR_H
#include "Usuario.hpp"
#include <iostream>
class Jogador : public Usuario{
    private:
    int vitVel, vitRev, vitLig, derVel, derRev, derLig;
    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int, int, int, int, int, int, int);
    Jogador(const Jogador& outro);
    Jogador& operator=(const Jogador& outro);
    int getVitVel();
    int getVitRev();
    int getVitLig();
    int getDerVel();
    int getDerRev();
    int getDerLig();
    void setVitVel(int vitVel);
    void setVitRev(int vitRev);
    void setVitLig(int vitLig);
    void setDerVel(int derVel);
    void setDerRev(int derRev);
    void setDerLig(int derLig);
    ~Jogador() override{}
    void mostrarTabela();
};
#endif