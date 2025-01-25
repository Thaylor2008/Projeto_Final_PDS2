#include <iostream>
#include <fstream>
#include <vector>
#include "JogoVelha.hpp"
#include "Ligue4.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
#include "Partidas.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    string arquivo;
    int entrada;
    cout << "Escolha seu arquivo(1-3):" << endl;
    cin >> entrada;
    switch (entrada){
    case 1:
        arquivo = "database/test1.csv";
        break;
    
    case 2:
        arquivo = "database/test2.csv";
        break;
    case 3:
        arquivo = "database/test3.csv";
        break;
    default:
        arquivo = "database/test1.csv";
    }
    Admin Jogadores(arquivo);
    while(true){
        string entrada;
        cin >> entrada;
        if(entrada == "FS"){
            cout << "PROGRAMA FINALIZADO" << endl;
            Jogadores.uptadeJogadores(arquivo);
            break;
        }else if(entrada == "EP"){
            char jogo;
            string apelido1, apelido2;
            cin >> jogo >> apelido1 >> apelido2;
            Partidas partida;
            partida.executarPartida(jogo, Jogadores.buscaApelido(apelido1), Jogadores.buscaApelido(apelido2));
            
        }else if(entrada == "LJ"){
            cout << "lista de jogadores" << endl;
            Jogadores.listarUsuarios();
        }else if(entrada == "RJ"){
            string apelido;
            cin >> apelido;
            try{
                Jogadores.removerJogador(apelido);
            } catch(const runtime_error& e){
                 cerr << "ERRO: " << e.what() << endl;
            }
            
        }else if(entrada == "CJ"){
            string apelido, nome;
            cin >> apelido >> nome;
            try{
                Jogadores.createJogador(apelido, nome);
            }catch(const runtime_error& e){
                cerr << "ERRO: " << e.what() << endl;
            }
            
        }
    }
    return 0;
}
