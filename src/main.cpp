#include <iostream>
#include <fstream>
#include <vector>
#include "JogoVelha.hpp"
#include "Ligue4.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
#include "Partidas.hpp"
#include <limits>
using namespace std;

int main(int argc, char const *argv[]) {
    string arquivo;
    int entrada;
    while (std::cout << "Escolha seu arquivo(1-3):" << endl && !(std::cin >> entrada)) {
    std::cin.clear(); //clear bad input flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
    std::cout << "Formato invalido\n";
}
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
        cout << "Arquivo 1 escolhido" << endl;
        arquivo = "database/test1.csv";
    }
    Admin Jogadores(arquivo);
    while(true){
        string entrada;
        cin >> entrada;
        if(entrada == "FS"){
            cout << "PROGRAMA FINALIZADO" << endl;
            Jogadores.uptadeJogadores();
            break;
        }else if(entrada == "EP"){
            char jogo;
            string apelido1, apelido2;
            cin >> jogo >> apelido1 >> apelido2;
            Partidas partida;
            try{
            partida.executarPartida(jogo, Jogadores.buscaApelido(apelido1), Jogadores.buscaApelido(apelido2));
            }catch(const char* Exc){
                cout << "ERRO:" << Exc;
                Jogadores.uptadeJogadores();
            }catch(...){
                cout << "Erro inesperado";
                Jogadores.uptadeJogadores();
            }
            
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
