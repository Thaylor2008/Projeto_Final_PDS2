#include <iostream>
#include <fstream>
#include <vector>
#include "JogoVelha.hpp"
#include "Ligue4.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    vector<Usuario*> Usuarios;
    ifstream ip("tests/test1.csv");
    string cabecalho;
    getline(ip, cabecalho);
    while(ip.good()){
        string nome, apelido, vitorias, derrotas, sequencia;
        getline(ip, nome, ',');
        getline(ip, apelido, ',');
        getline(ip, vitorias, ',');
        getline(ip, derrotas, ',');
        getline(ip, sequencia, '\n');
        Usuarios.push_back(new Jogador(nome, apelido, stoi(vitorias), stoi(derrotas), stoi(sequencia)));
    }
    ip.close();
    //futuramente vai virar a funçao mostra tabela
    cout << "----------------------------------------------------------" << endl;
    for(size_t i = 0; i < Usuarios.size(); i++){
        cout << Usuarios[i]->getApelido() << " | " << Usuarios[i]->getVitorias() << " | " << Usuarios[i]->getDerrotas() << " | " << Usuarios[i]->getSequencia() << endl;
    cout << "----------------------------------------------------------" << endl;
    }
    
    JogoVelha jogo1;
    Ligue4 jogo2;
    int escolha;
    cout << "Escolha um jogo para jogar:\n";
    cout << "1 - Jogo da Velha\n";
    cout << "2 - Lig 4\n";
    cout << "Digite sua escolha: ";
    cin >> escolha;
    //cout << "Vitorias Carlos: " << Jogador1->getVitorias() << endl;
    return 0;
}
