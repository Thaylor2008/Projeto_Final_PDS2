#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Admin.hpp"
#include "Partidas.hpp"

TEST_CASE("Teste Remove Jogador"){
    
    Admin Jogadores("database/testbase.csv");
    CHECK(Jogadores.createJogador("apelido1", "Jogador1"));
    Jogadores.removerJogador("apelido1");
    CHECK(Jogadores.buscaApelido("apelido1") == nullptr);
}
TEST_CASE("Teste cria jogador"){
    std::cout << "Cadastrar Jogador";
    Admin Jogadores("database/testbase.csv");
    CHECK(Jogadores.createJogador("apelido1", "Jogador1"));
    Jogador *jogad;
    jogad = Jogadores.buscaApelido("apelido1");
    CHECK(jogad->getApelido() == "apelido1");
}