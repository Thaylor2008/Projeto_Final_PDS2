#include "JogoVelha.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
void JogoVelha::executarPartida(Usuario* jogador1, Usuario* jogador2){
    cout << jogador1->nome << " versus " << jogador2->nome << endl;
    cout << "Vencedor: " << jogador1->nome << endl;
    jogador1 -> vitorias +=1;
    jogador2 -> derrotas +=1;
}