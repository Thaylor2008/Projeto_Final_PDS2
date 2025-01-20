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
    /*
    //futuramente vai virar a funçao mostra tabela
    cout << "----------------------------------------------------------" << endl;
    for(size_t i = 0; i < Usuarios.size(); i++){
        cout << Usuarios[i]->getApelido() << " | " << Usuarios[i]->getVitorias() << " | " << Usuarios[i]->getDerrotas() << " | " << Usuarios[i]->getSequencia() << endl;
    cout << "----------------------------------------------------------" << endl;
    }
    */
    while(true){
        string entrada;
        cin >> entrada;
        if(entrada == "FS"){
            for(auto e : Usuarios){
                delete e;
            }
            break;
        }else if(entrada == "EP"){
            char jogo;
            string apelido1, apelido2;
            cin >> jogo >> apelido1 >> apelido2;
            if(jogo == 'V'){
                JogoVelha velha;
                velha.executarPartida(Usuarios[0], Usuarios[1]);
            }
            
        }
    }
    //cout << "Vitorias Carlos: " << Jogador1->getVitorias() << endl;
    return 0;
}
