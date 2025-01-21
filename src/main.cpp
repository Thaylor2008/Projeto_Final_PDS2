#include <iostream>
#include <fstream>
#include <vector>
#include "JogoVelha.hpp"
#include "Ligue4.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Admin Jogadores;
    string arquivo = "tests/test1.csv";
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
         (nome.empty() || apelido.empty() || vitorias.empty() || derrotas.empty() || sequencia.empty()) {
            continue;
        }
        Jogadores.createJogador(nome, apelido, stoi(vitorias), stoi(derrotas), stoi(sequencia));
    }
    ip.close();
    while(true){
        string entrada;
        cin >> entrada;
        if(entrada == "FS"){
            Jogadores.uptadeJogadores(arquivo);
            break;
        }else if(entrada == "EP"){
            char jogo;
            string apelido1, apelido2;
            cin >> jogo >> apelido1 >> apelido2;
            if(jogo == 'V'){
                JogoVelha velha;
                velha.executarPartida(Jogadores.buscaApelido(apelido1), Jogadores.buscaApelido(apelido2));
            }
            
        }else if(entrada == "LJ"){
            Jogadores.listarUsuarios();
        }else if(entrada == "RJ"){
            string apelido;
            cin >> apelido;
            Jogadores.removerJogador(apelido);
        }
    }
    //cout << "Vitorias Carlos: " << Jogador1->getVitorias() << endl;
    return 0;
}
