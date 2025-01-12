#include "Ligue4.hpp"
#include <iostream>
using namespace std;

// Construtor que inicializa o tabuleiro com 6 linhas e 7 colunas
Ligue4::Ligue4() : JogosTab(6, 7) {}

// Mostra o estado atual do tabuleiro
void Ligue4::mostraTabuleiro() const {
    for (int i = 0; i < linhas; ++i) {
        cout << "| ";
        for (int j = 0; j < colunas; ++j) {
            cout << (tabuleiro[i][j] == ' ' ? '.' : tabuleiro[i][j]) << " | ";
        }
        cout << endl;
    }
    cout << "  0   1   2   3   4   5   6  " << endl; // Índices das colunas
}

// Testa se a jogada em uma coluna é válida
bool Ligue4::testaJogada(int linha, int coluna) const {
    // Em Lig 4, só precisamos testar a coluna
    return coluna >= 0 && coluna < colunas && tabuleiro[0][coluna] == ' ';
}

// Atualiza o tabuleiro com a jogada do jogador
void Ligue4::atualizaTabuleiro(int linha, int coluna, char jogador) {
    int linhaDisponivel = proximaLinhaDisponivel(coluna);
    if (linhaDisponivel != -1) {
        tabuleiro[linhaDisponivel][coluna] = jogador;
    } else {
        cout << "Erro: a coluna está cheia." << endl;
    }
}

// Verifica se há um vencedor no jogo
bool Ligue4::verificaVencedor() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (tabuleiro[i][j] != ' ' && verificaSequencia(i, j, tabuleiro[i][j])) {
                return true;
            }
        }
    }
    return false;
}

// Executa uma partida de Lig 4 entre dois jogadores
void Ligue4::executarPartida(Usuario* jogador1, Usuario* jogador2) {
    char simboloJogador1 = 'X';
    char simboloJogador2 = 'O';
    bool turnoJogador1 = true;

    while (true) {
        mostraTabuleiro();
        cout << "Turno de " << (turnoJogador1 ? jogador1->nome : jogador2->nome)
             << " (" << (turnoJogador1 ? simboloJogador1 : simboloJogador2) << "):" << endl;

        int coluna;
        cout << "Escolha uma coluna (0-6): ";
        cin >> coluna;

        if (testaJogada(0, coluna)) {
            atualizaTabuleiro(0, coluna, turnoJogador1 ? simboloJogador1 : simboloJogador2);
            if (verificaVencedor()) {
                mostraTabuleiro();
                cout << "Parabéns! " << (turnoJogador1 ? jogador1->nome : jogador2->nome) << " venceu!" << endl;
                if (turnoJogador1) jogador1->vitorias++, jogador2->derrotas++;
                else jogador2->vitorias++, jogador1->derrotas++;
                return;
            }
            turnoJogador1 = !turnoJogador1;
        } else {
            cout << "Jogada inválida. Tente novamente." << endl;
        }
    }
}

// Verifica se uma posição é válida no tabuleiro
bool Ligue4::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

// Verifica se há uma sequência de 4 peças em qualquer direção
bool Ligue4::verificaSequencia(int linha, int coluna, char jogador) const {
    // Verifica todas as direções: horizontal, vertical, e diagonais
    static const int direcoes[4][2] = {
        {0, 1}, {1, 0}, {1, 1}, {1, -1} // Direções: direita, abaixo, diagonal direita, diagonal esquerda
    };

    for (auto& direcao : direcoes) {
        int cont = 1;
        for (int d = 1; d < 4; ++d) { // Verifica na direção positiva
            int novaLinha = linha + d * direcao[0];
            int novaColuna = coluna + d * direcao[1];
            if (posicaoValida(novaLinha, novaColuna) && tabuleiro[novaLinha][novaColuna] == jogador) {
                cont++;
            } else {
                break;
            }
        }
        for (int d = 1; d < 4; ++d) { // Verifica na direção negativa
            int novaLinha = linha - d * direcao[0];
            int novaColuna = coluna - d * direcao[1];
            if (posicaoValida(novaLinha, novaColuna) && tabuleiro[novaLinha][novaColuna] == jogador) {
                cont++;
            } else {
                break;
            }
        }
        if (cont >= 4) return true; // Sequência de 4 encontrada
    }
    return false;
}

// Encontra a próxima linha disponível em uma coluna
int Ligue4::proximaLinhaDisponivel(int coluna) const {
    for (int i = linhas - 1; i >= 0; --i) { // Começa na linha mais baixa
        if (tabuleiro[i][coluna] == ' ') {
            return i;
        }
    }
    return -1; // Coluna está cheia
}
