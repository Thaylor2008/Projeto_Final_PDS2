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

- Desenvolvedores: **Davi Santos Rodrigues** e **Taylor**
- Orientação: **Luiz Chaimowickz**
---
## 📝 Licença
Este projeto é pedagógico.
