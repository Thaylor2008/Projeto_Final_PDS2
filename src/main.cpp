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

/**
 * @brief Função principal do programa.
 * 
 * Este é o ponto de entrada do programa. Ele permite ao usuário escolher um arquivo de dados, interagir com o sistema para executar partidas, adicionar/remover jogadores, e exibir informações sobre jogadores. O programa executa em um loop até que o comando de finalização seja dado.
 * 
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de argumentos passados para o programa.
 * @return Retorna 0 se o programa terminar corretamente.
 */
int main(int argc, char const *argv[]) {
    string arquivo;
    int entrada;

    // Solicita ao usuário escolher um arquivo e garante que a entrada seja válida.
    while (std::cout << "Escolha seu arquivo(1-3):" << endl && !(std::cin >> entrada)) {
        std::cin.clear(); // Limpa o flag de erro de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
        std::cout << "Formato invalido\n";
    }

    // Define o arquivo de dados baseado na escolha do usuário
    switch (entrada) {
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

    // Cria um objeto Admin para gerenciar os jogadores, utilizando o arquivo escolhido
    Admin Jogadores(arquivo);

    // Loop principal para interagir com o sistema
    while (true) {
        string entrada;
        cin >> entrada;

        // Comando para finalizar o programa
        if (entrada == "FS") {
            cout << "PROGRAMA FINALIZADO" << endl;
            Jogadores.uptadeJogadores(); // Atualiza os dados dos jogadores antes de finalizar
            break;
        }
        // Comando para iniciar uma partida entre dois jogadores
        else if (entrada == "EP") {
            char jogo;
            string apelido1, apelido2;
            cin >> jogo >> apelido1 >> apelido2;
            Partidas partida;
            try {
                partida.executarPartida(jogo, Jogadores.buscaApelido(apelido1), Jogadores.buscaApelido(apelido2));
            } catch (const char* Exc) {
                cout << "ERRO:" << Exc;
                Jogadores.uptadeJogadores(); // Atualiza após erro
            } catch (...) {
                cout << "Erro inesperado";
                Jogadores.uptadeJogadores(); // Atualiza após erro
            }
        }
        // Comando para listar todos os jogadores
        else if (entrada == "LJ") {
            string ajn;
            cin >> ajn;
            cout << "lista de jogadores" << endl;
            Jogadores.listarUsuarios();
        }
        // Comando para remover um jogador
        else if (entrada == "RJ") {
            string apelido;
            cin >> apelido;
            try {
                Jogadores.removerJogador(apelido);
            } catch (const runtime_error& e) {
                cerr << "ERRO: " << e.what() << endl;
            }
        }
        // Comando para criar um novo jogador
        else if (entrada == "CJ") {
            string apelido, nome;
            cin >> apelido >> nome;
            try {
                Jogadores.createJogador(apelido, nome);
            } catch (const runtime_error& e) {
                cerr << "ERRO: " << e.what() << endl;
            }
        }
    }

    return 0;
}