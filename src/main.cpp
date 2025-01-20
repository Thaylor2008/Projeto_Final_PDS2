#include <iostream>
#include "JogoVelha.hpp"
#include "Ligue4.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Usuario* Jogador1 = new Jogador("Carlos", "Carlao", "Carlos123");
    Usuario* Jogador2 = new Jogador("Sabrina", "Sasa", "sasa123");
    JogoVelha jogo1;
    Ligue4 jogo2;
    int escolha;
    cout << "Escolha um jogo para jogar:\n";
    cout << "1 - Jogo da Velha\n";
    cout << "2 - Lig 4\n";
    cout << "Digite sua escolha: ";
    cin >> escolha;
    
    if(escolha == 1){
        jogo1.executarPartida(Jogador1, Jogador2);
        
    }else if(escolha == 2){
        jogo2.executarPartida(Jogador1, Jogador2);
        
    }
    
    cout << "Vitorias Carlos: " << Jogador1->getVitorias() << endl;
    return 0;
}
