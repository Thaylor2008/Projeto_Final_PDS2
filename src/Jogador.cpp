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
Jogador::Jogador(string nome, string apelido) : Usuario( nome, apelido), vitVel(0), vitRev(0), vitLig(0),
derVel(0), derRev(0), derLig(0) {}
Jogador::Jogador(std::string nome, std::string apelido, int vitVel, int vitRev, int vitLig, int derVel, 
int derRev, int derLig, int seq) : Usuario(nome, apelido, (vitLig + vitRev + vitVel), (derLig + derRev + derVel),
seq), vitVel(vitVel), vitRev(vitRev), vitLig(vitLig), derVel(derVel), derRev(derRev), derLig(derLig) {}
void Jogador::mostrarTabela(){
    cout << "Tabela!";
}
int Jogador::getVitVel(){
    return vitVel;
}
int Jogador::getVitRev(){
    return vitRev;
}
int Jogador::getVitLig(){
    return vitLig;
}
int Jogador::getDerVel(){
    return derVel;
}
int Jogador::getDerRev(){
    return derRev;
}
int Jogador::getDerLig(){
    return derLig;
}
void Jogador::setVitVel(int vitVel) {
    cout << "entrou! vitorias velha" << endl;
    this->vitVel = vitVel;
}
void Jogador::setVitRev(int vitRev) {
    this->vitRev = vitRev;
}
void Jogador::setVitLig(int vitLig) {
    cout << "entrou vitorias lig" << endl;
    this->vitLig = vitLig;
}
void Jogador::setDerVel(int derVel) {
    
    this->derVel = derVel;
}
void Jogador::setDerRev(int derRev) {
    
    this->derRev = derRev;
}
void Jogador::setDerLig(int derLig) {
    cout << "entrou derrotas lig" << endl;
    this->derLig = derLig;
}