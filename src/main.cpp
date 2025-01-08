#include <iostream>
#include "Ligue4.hpp"
#include "Reversi.hpp"
#include "JogoVelha.hpp"
#include "Jogador.hpp"
#include "Admin.hpp"
using namespace std;
int main(int argc, char const *argv[]){
    Usuario *Jogador1 = new Jogador("Carlos", "Carlao", "Carlos123");
    Usuario *Jogador2 = new Jogador("Sabrina", "Sasa", "sasa123");
    JogoVelha jogo;
    jogo.executarPartida(Jogador1, Jogador2);
    cout << "Vitórias Carlos: " << Jogador1->vitorias << endl;
    return 0;
}
