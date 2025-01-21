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
Jogador* Admin::createJogador(string nome, string apelido){
    Jogadores.push_back(new Jogador(nome, apelido));
    return Jogadores.back();
}
Jogador* Admin:: createJogador(string nome, string apelido, int vitorias, int derrotas, int sequencia){
    Jogadores.push_back(new Jogador(nome, apelido, vitorias, derrotas, sequencia));
    return Jogadores.back();
}
void Admin::listarUsuarios(){
    cout << "----------------------------------------------------------" << endl;
    for(size_t i = 0; i < Jogadores.size(); i++){
        cout << Jogadores[i]->getApelido() << " | " << Jogadores[i]->getVitorias() << " | " << Jogadores[i]->getDerrotas() << " | " << Jogadores[i]->getSequencia() << endl;
    cout << "----------------------------------------------------------" << endl;
    }
}
Jogador* Admin::buscaApelido(string apelido){
    cout << "BUSCOU!" << endl;
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
    if (i != Jogadores.end()) {
        cout << "Jogador " << (*i)->getApelido() << " removido com sucesso" << endl;
        delete *i;
        Jogadores.erase(i);
    }
        return Jogadores;
}
void Admin::uptadeJogadores(string arquivo){
    std::ofstream FILE;
    FILE.open(arquivo);
    FILE << "nome,apelido,vitorias,derrotas,sequencia" << endl;
    for(size_t i = 0; i < Jogadores.size(); i++){
        FILE << Jogadores[i]->getNome() << ","<< Jogadores[i]->getApelido() << ","<< Jogadores[i]->getVitorias() << ","<< Jogadores[i]->getDerrotas() << "," << Jogadores[i]->getSequencia();
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