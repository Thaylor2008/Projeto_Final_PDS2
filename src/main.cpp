#include <iostream>
#include <fstream>
#include <vector>
#include "JogoVelha.hpp"
#include "Ligue4.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    string arquivo;
    int entrada;
    cout << "Escolha seu arquivo(1-3):" << endl;
    cin >> entrada;
    switch (entrada){
    case 1:
        arquivo = "tests/test1.csv";
        break;
    
    case 2:
        arquivo = "tests/test2.csv";
        break;
    case 3:
        arquivo = "tests/test3.csv";
        break;
    default:
        arquivo = "tests/test1.csv";
    }
    Admin Jogadores(arquivo);
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
    return 0;
}
