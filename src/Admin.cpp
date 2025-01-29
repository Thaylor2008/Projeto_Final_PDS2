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

/**
 * @brief Função para comparar jogadores por apelido (ordem alfabética).
 * 
 * @param a Ponteiro para o jogador A.
 * @param b Ponteiro para o jogador B.
 * @return true se o apelido de A for menor que o de B.
 */
bool compareByORDEMFEALODERIT(Jogador* a, Jogador *b) {
    return a->getApelido() < b->getApelido();
}

/**
 * @brief Construtor da classe Admin. Carrega os jogadores a partir de um arquivo CSV.
 * 
 * @param arquivo Caminho do arquivo CSV contendo as informações dos jogadores.
 */
Admin::Admin(string arquivo) : arquivo(arquivo) {
    ifstream ip(arquivo);
    if (!ip.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << arquivo << endl;
        return;
    }
    string cabecalho;
    getline(ip, cabecalho);  // Lê o cabeçalho do arquivo
    
    // Lê e cria jogadores a partir do arquivo
    while (ip.good()) {
        string nome, apelido, vitVel, vitRev, vitLig, derVel, derRev, derLig, sequencia;
        getline(ip, nome, ',');
        getline(ip, apelido, ',');
        getline(ip, vitVel, ','); getline(ip, vitRev, ','); getline(ip, vitLig, ',');
        getline(ip, derVel, ','); getline(ip, derRev, ','); getline(ip, derLig, ',');
        getline(ip, sequencia, '\n');
        
        // Verifica se os dados são válidos
        if (nome.empty() || apelido.empty() || vitVel.empty() || vitRev.empty() || vitLig.empty() ||
            derVel.empty() || derRev.empty() || derLig.empty() || sequencia.empty()) {
            continue;
        }
        // Cria o jogador com os dados lidos
        createJogador(nome, apelido, stoi(vitVel), stoi(vitRev), stoi(vitLig), stoi(derVel), stoi(derRev), stoi(derLig), stoi(sequencia));
    }
    ip.close();
}

/**
 * @brief Cria um novo jogador com nome e apelido.
 * 
 * @param apelido Apelido do jogador.
 * @param nome Nome do jogador.
 * @return Ponteiro para o jogador criado.
 */
Jogador* Admin::createJogador(string apelido, string nome) {
    if (buscaApelido(apelido) != nullptr) {
        throw runtime_error("jogador repetido");
    }
    Jogadores.push_back(new Jogador(nome, apelido));
    return Jogadores.back();
}

/**
 * @brief Cria um novo jogador com todas as informações detalhadas.
 * 
 * @param nome Nome do jogador.
 * @param apelido Apelido do jogador.
 * @param vitVel Vitórias no jogo Velha.
 * @param vitRev Vitórias no jogo Reversi.
 * @param vitLig Vitórias no jogo Lig4.
 * @param derVel Derrotas no jogo Velha.
 * @param derRev Derrotas no jogo Reversi.
 * @param derLig Derrotas no jogo Lig4.
 * @param seq Sequência de vitórias.
 * @return Ponteiro para o jogador criado.
 */
Jogador* Admin::createJogador(string nome, string apelido, int vitVel, int vitRev, int vitLig, int derVel, int derRev,
int derLig, int seq){
    Jogadores.push_back(new Jogador(nome, apelido, vitVel, vitRev, vitLig, derVel, derRev, derLig, seq));
    return Jogadores.back();
}

/**
 * @brief Lista todos os usuários (jogadores), ordenados por apelido.
 */
void Admin::listarUsuarios() {
    sort(Jogadores.begin(), Jogadores.end(), compareByORDEMFEALODERIT);
    for (size_t i = 0; i < Jogadores.size(); i++) {
        cout << Jogadores[i]->getApelido() << " " << Jogadores[i]->getNome() << endl;
        cout << "REVERSI -V: " << Jogadores[i]->getVitRev() << " D: " << Jogadores[i]->getDerRev() << endl;
        cout << "Lig4    -V: " << Jogadores[i]->getVitLig() << " D: " << Jogadores[i]->getDerLig() << endl;
        cout << "VELHA   -V: " << Jogadores[i]->getVitVel() << " D: " << Jogadores[i]->getDerVel() << endl;
    }
}

/**
 * @brief Busca um jogador pelo apelido.
 * 
 * @param apelido Apelido do jogador.
 * @return Ponteiro para o jogador encontrado ou nullptr se não encontrado.
 */
Jogador* Admin::buscaApelido(string apelido) {
    for (size_t j = 0; j < Jogadores.size(); j++) {
        if (Jogadores[j]->getApelido() == apelido) {
            return Jogadores[j];
        }
    }
    return nullptr;
}

/**
 * @brief Remove um jogador pelo apelido.
 * 
 * @param apelido Apelido do jogador a ser removido.
 * @return Vetor atualizado de jogadores.
 * @throws runtime_error Se o jogador não for encontrado.
 */
vector<Jogador*> Admin::removerJogador(string apelido) {
    auto i = find_if(Jogadores.begin(), Jogadores.end(), [&](Jogador* jogador) {
        return jogador->getApelido() == apelido;
    });
    if (i == Jogadores.end()) {
        throw runtime_error("jogador inexistente");
    }
    cout << "Jogador " << (*i)->getApelido() << " removido com sucesso" << endl;
    delete *i;
    Jogadores.erase(i);
    return Jogadores;
}

/**
 * @brief Atualiza os jogadores no arquivo CSV.
 */
void Admin::uptadeJogadores() {
    std::ofstream FILE;
    FILE.open(arquivo);
    FILE << "nome,apelido,vitVel,vitRev,vitLig,derVel,derRev,derLig,sequencia" << endl;
    for (size_t i = 0; i < Jogadores.size(); i++) {
        FILE << Jogadores[i]->getNome() << "," << Jogadores[i]->getApelido() << "," << Jogadores[i]->getVitVel() << ","
             << Jogadores[i]->getVitRev() << "," << Jogadores[i]->getVitLig() << "," << Jogadores[i]->getDerVel() << ","
             << Jogadores[i]->getDerRev() << "," << Jogadores[i]->getDerLig() << "," << Jogadores[i]->getSequencia();
        if (i != Jogadores.size() - 1) {
            FILE << endl;
        }
    }
    FILE.close();
}

/**
 * @brief Destruidor da classe Admin. Libera a memória dos jogadores.
 */
Admin::~Admin() {
    for (Jogador* jogador : Jogadores) {
        delete jogador;
    }
}