#ifndef JOGOSTAB_H
#define JOGOSTAB_H

#include <vector>
#include <string>

//Classe base abstrata para jogos de tabuleiro.

class JogosTab {
protected:
    std::vector<std::vector<char>> tabuleiro;
    int linhas;   
    int colunas;   

public:
    
    JogosTab(int linhas, int colunas) : tabuleiro(std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '))), linhas(linhas), colunas(colunas) {}

    virtual ~JogosTab() = default;
    virtual void mostraTabuleiro() const = 0;
    virtual bool testaJogada(int linha, int coluna, char jogador) = 0;
    virtual void atualizaTabuleiro(int linha, int coluna, char jogador) = 0;
    virtual bool verificaVencedor() const = 0;
    
    virtual void resetaTabuleiro() {
        for (auto& linha : tabuleiro) {
            std::fill(linha.begin(), linha.end(), ' ');
        }
    }
    const std::vector<std::vector<char>>& getTabuleiro() const { return tabuleiro;}
    int getLinhas() const { return linhas;}
    int getColunas() const { return colunas;}
};
#endif // JOGOSTAB_H
