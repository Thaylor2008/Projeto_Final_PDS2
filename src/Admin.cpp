#include "Admin.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
bool compareByORDEMFEALODERIT( Jogador* a,  Jogador *b)
{
    return a->getApelido() < b->getApelido();
}
Admin::Admin(string arquivo) : arquivo("tests/" + arquivo) {
    ifstream ip(arquivo);
    if (!ip.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << arquivo << endl;
        return;
    }
    string cabecalho;
    getline(ip, cabecalho);
    
    while (ip.good()) {
        string nome, apelido, vitVel, vitRev, vitLig, derVel, derRev, derLig, sequencia;
        getline(ip, nome, ',');
        getline(ip, apelido, ',');
        getline(ip, vitVel, ',');getline(ip, vitRev, ',');getline(ip, vitLig, ',');
        getline(ip, derVel, ',');getline(ip, derRev, ',');getline(ip, derLig, ',');
        getline(ip, sequencia, '\n');
        if (nome.empty() || apelido.empty() || vitVel.empty() || vitRev.empty() || vitLig.empty() ||
        derVel.empty() || derRev.empty() || derLig.empty() || sequencia.empty()) {
            continue;
        }
        createJogador(nome, apelido, stoi(vitVel), stoi(vitRev), stoi(vitLig), stoi(derVel), stoi(derRev), stoi(derLig), stoi(sequencia));
    }
    ip.close();
}
Jogador* Admin::createJogador(string apelido, string nome) {
    if (buscaApelido(apelido) != nullptr) {
        throw runtime_error("jogador repetido");
    }
    Jogadores.push_back(new Jogador(nome, apelido));
    return Jogadores.back();
}
Jogador* Admin:: createJogador(string nome, string apelido, int vitVel, int vitRev, int vitLig, int derVel, int derRev,
int derLig, int seq){
    Jogadores.push_back(new Jogador(nome, apelido, vitVel, vitRev, vitLig, derVel, derRev, derLig, seq));
    return Jogadores.back();
}
void Admin::listarUsuarios(){
    sort(Jogadores.begin(), Jogadores.end(), compareByORDEMFEALODERIT);
    for(size_t i = 0; i < Jogadores.size(); i++){
        cout << Jogadores[i]->getApelido() << " " << Jogadores[i]->getNome() << endl;
        cout << "REVERSI -V: " << Jogadores[i]->getVitRev() << " D: " << Jogadores[i]->getDerRev() << endl;
        cout << "Lig4    -V: " << Jogadores[i]->getVitLig() << " D: " << Jogadores[i]->getDerLig() << endl;
        cout << "VELHA   -V: " << Jogadores[i]->getVitVel() << " D: " << Jogadores[i]->getDerVel() << endl;
    }
}
Jogador* Admin::buscaApelido(string apelido){
    for(size_t j = 0; j < Jogadores.size(); j++){
        if(Jogadores[j]->getApelido() == apelido){
            return Jogadores[j];
        }
    }
    return nullptr;
}
vector<Jogador*> Admin::removerJogador(string apelido){
        auto i = find_if(Jogadores.begin(), Jogadores.end(), [&](Jogador* jogador) {
        return jogador->getApelido() == apelido;
    });
    if (i == Jogadores.end()) {
        throw runtime_error("jogador inexistente");
    }
        cout << "Jogador " << (*i)->getApelido() << " removido com sucesso" << endl;
        delete *i;
        Jogadores.erase(i);
    
        return Jogadores;
}
void Admin::uptadeJogadores(string arquivo){
    std::ofstream FILE;
    FILE.open(arquivo);
    FILE << "nome,apelido,vitVel,vitRev,vitLig,derVel,derRev,derLig,sequencia" << endl;
    for(size_t i = 0; i < Jogadores.size(); i++){
        FILE << Jogadores[i]->getNome() << ","<< Jogadores[i]->getApelido() << ","<< Jogadores[i]->getVitVel() << ","<< Jogadores[i]->getVitRev() << "," << Jogadores[i]->getVitLig() << ","<< Jogadores[i]->getDerVel() << ","<< Jogadores[i]->getDerRev() << "," << Jogadores[i]->getDerLig() << "," << Jogadores[i]->getSequencia();
        if (i != Jogadores.size() - 1) {
            FILE << endl;
        }
    }
    FILE.close();
}
Admin::~Admin() {
    for (Jogador* jogador : Jogadores) {
        delete jogador;
    }
}