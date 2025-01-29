# Projeto Final - Jogos de Tabuleiro 🎲

**Valor**: 20 pontos  
**Data de entrega**: 28/JAN/2025  
---
## 📋 Informações Importantes

1. **Permissões no Linux**:  
   Certifique-se de permitir a leitura dos arquivos `.csv` ao compilar em um sistema Linux. Por exemplo, use o comando:  
```bash
   chmod +r tests/test1.csv
```
2. **Limpeza de arquivos gerados pelo Make**:  
   Execute o comando `make clean` adequado ao seu sistema operacional para evitar conflitos:  
    - **Windows**:  
```bash
     mingw32-make clean
```
   - **Linux**:  
```bash
     make clean
```

---
## 🌟 Desafios

### Organização dos Arquivos e Criação do Makefile
*"Makefile se mostra uma ferramenta poderosa, mas um pouco trabalhosa de criar. Após me re-familiarizar com a sua sintaxe, passei boa parte do tempo ajustando comandos no terminal. Achei que teria que reinstalar o MinGW, mas, na realidade, era só usar `MinGW32-make` ao invés de `make`. Viva ao Windows!"*  
— *Davi Santos Rodrigues*  

### Encapsulamento e Responsabilidades
*"Algumas vezes dá um nó na cabeça: 'Como diabos eu vou acessar esse método privado da classe abstrata dentro da classe que está referenciando uma das classes filhas!'. Mas, com debugging e paciência, o trem anda."*  
— *Davi Santos Rodrigues*  

### Tratamento de Exceções
*"Tentar abordar todos os erros possíveis se mostra um dos maiores desafios de toda a implementação. Acredito que fomos competentes e que conseguimos deixar o código bem robusto no final."*
— *Davi Santos Rodrigues*  

### Desafio em criar os Jogos 
### jogo da velha
*"Os desafios que enfrentei na hora de implementar os jogos de tabuleiro, começando com o “Jogo da Velha”, foram na criação de um tabuleiro 3x3 gerenciado de forma eficiente, além de também ter dificuldades na hora de testar as jogadas e validar se estão dentro dos limites do tabuleiro e em células vazias. Outro desafio foi a verificação da condição de vitória, que exigia a identificação de combinações vencedoras em linhas, colunas ou diagonais. Além disso, era preciso implementar uma lógica para detectar empates, caso o tabuleiro estivesse cheio e nenhum jogador tivesse vencido."*  

### ligue4
*"No "Lig 4", os desafios se tornam mais complexos devido ao tabuleiro maior, de 6x7, e ao fato de as peças precisarem "cair" para a posição mais baixa disponível na coluna selecionada. Também foi necessário conferir as jogadas para garantir que o jogador escolhesse colunas dentro dos limites e que ainda houvesse espaço disponível. Determinar a condição de vitória também é um desafio significativo, pois é necessário verificar combinações de 4 peças consecutivas na horizontal, vertical e diagonais."*  

### reversi 
*"Já no "Reversi" (Othello), o maior desafio está na complexidade das regras. A validação de jogadas requer verificar se a peça colocada pelo jogador irá cercar peças adversárias em pelo menos uma direção, o que envolve analisar linhas, colunas e diagonais simultaneamente. Também é necessária a implementação de uma lógica para inverter as peças cercadas, o que exige percorrer múltiplas direções a partir da jogada realizada. Outro obstáculo é determinar o fim do jogo, que depende de o tabuleiro estar cheio ou de nenhum jogador poder realizar jogadas válidas."*

— *Thaylor Weslei Dias G. Verteiro* 

---
## 💡 Escolhas de Implementação

### Arquivo `.csv`
*"Optei por utilizar um arquivo `.csv` ao invés de um arquivo `.txt` puro pelos seguintes motivos:*  
- É mais legível e fácil de interpretar os dados.  
- Facilita a integração com outras linguagens.  
- Permite uma futura integração com ferramentas de análise de dados, como Google Sheets ou Power BI.  
*No fim, é simplesmente uma opção melhor."*  
— *Davi Santos Rodrigues*

### `std::vector` para Usuários
*"Utilizei `std::vector` para armazenar os usuários devido ao seu tamanho dinâmico. É um trade-off válido entre consumo de memória e performance."*  
— *Davi Santos Rodrigues*

### Admin como Gerenciador de Usuários
*"Decidi implementar a classe `Admin` como responsável pela gestão de `Jogadores` e `Usuários`, respeitando os princípios de encapsulamento e responsabilidade. Inicialmente, planejava adicionar funcionalidades exclusivas para administradores (como permissões avançadas), mas, devido ao tempo, priorizamos outras features."*  
— *Davi Santos Rodrigues*  

### Usuario como classe abstrata
*"Decidi implementar `Usuario` como uma classe abstrata porque inicialmete teríamos diferentes tipos de usuario, mas optamos por não continuar essa feature. Usuario segue como abstrata pois futuramente podem existir diferentes tipos de usuários para a aplicação"*
- *Davi Santos Rodrigues*
---
## CRC's
*"Os CRC's são uma ótima ferramenta de documentação, então não poderiam ficar de fora deste arquivo. Foi uma boa escolha manter a versão original dos CRC's, pois pode ser interessante comparar o que haviamos planejado no início com o que se tornou no final."*
### CRC's iniciais
![CRC Usuários](https://raw.githubusercontent.com/Thaylor2008/Projeto_Final_PDS2/main/imagens/CRCUSUARIOSTPPDS2%20(1)_page-0001.jpg)
![CRC 2](https://raw.githubusercontent.com/Thaylor2008/Projeto_Final_PDS2/main/imagens/CRC2%20(1)_page-0001.jpg)
*"Queriamos ter a feature de admin e inicialmente planejamos as partidas em cada jogo."*
### CRC's finais

![CRC Maker 4](https://raw.githubusercontent.com/Thaylor2008/Projeto_Final_PDS2/main/imagens/CRC%20Maker4_page-0001.jpg)
![CRC Maker 3](https://raw.githubusercontent.com/Thaylor2008/Projeto_Final_PDS2/main/imagens/CRC%20Maker3_page-0001.jpg)

*"Queríamos que os diferentes usuários pudessem ver diferentes listagens de todos os usuários, mantemos o dado Sequência, pois o conceito de streak é atrativo para jogadores, mas não fizemos nada com ele no final."*
---
## 🗂️ Estrutura do Projeto

```plaintext
.
├── src/             # Código-fonte do projeto
├── include/         # Arquivos de cabeçalho (.hpp)
├── obj/             # Arquivos objeto (.o)
├── bin/             # Binários gerados pelo compilador
├── tests/           # Arquivos de teste (.csv e outros)
└── Makefile         # Automação de build
```

---
## 🚀 Como Executar

1. **Compilação**:
   - No **Windows**, use:  
```bash
     mingw32-make
```
   - No **Linux**, use:  
```bash
     make
```

2. **Executando o binário**:
   - **Windows**:  
```bash
     .\bin\main.exe
```
   - **Linux**:  
```bash
     ./bin/main
```

3. **Limpeza de Arquivos**:
   - Windows:  
```bash
     mingw32-make clean
```
   - Linux:  
```bash
     make clean
```
4. **DOCTEST**:
   - Windows:
```bash
   minGW32-make run-tests
```
   - Linux:
```bash
   make run-tests
```
---
## 🛠️ Tecnologias Utilizadas

- Linguagem: **C++ (C++11)**
- Build System: **Makefile**
- Editor: **Visual Studio Code**
- Sistema Operacional: **Windows e Linux (WSL)**
## 🤝 Contribuições

- Desenvolvedores: **Davi Santos Rodrigues** e **Thaylor Weslei Dias G. Verteiro**
- Orientação: **Luiz Chaimowickz**
---
## 📝 Licença
Este projeto é pedagógico.
