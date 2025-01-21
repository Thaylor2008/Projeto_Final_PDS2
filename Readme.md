Projeto Final - Jogos de Tabuleiro
Valor: 20 pontos
Data de entrega: 23/JAN/2025

# Desafios:
    - Organização dos Arquivos nas pastas e criação do Makefile:
        "Makefile se mostra uma ferramenta poderosa, mas um pouco trabalhosa de criar. Após re-familiarizar 
        com a sua sintaxe, passei a maior parte do tempo tentando realizar os comandos no terminal. Achei 
        que teria que instalar o Ming de novo, mas na realidade era só usar "MinGW32-make" ao invés de "make"
        - um viva ao Windows!"
    Davi
    - Encapsulamento e responsabilidades:
        "Algumas vezes dá um nó na cabeça: 'Como diabos eu vou acessar esse método private da classe abstrata 
        dentro da classe que está referenciando uma das classes filhas!'. Mas, basta debuggar e, mesmo que
        lentamente, o trem anda."
    Davi
# Escolhas de Implementação:
    - Arquivo .csv:
        "Optei por um arquivo .csv, ao invés de um arquivo txt puro, por vários motivos:
            - É mais fácil de ler e entender os dados
            - Fácil integração com outras linguagens
            - Futura possível integração com ferramentas de leitura e manipulação de dados, como Sheets, PowerBi
        No fim, é só uma opção melhor mesmo."
    Davi
    - Vector de Usuários:
        "Optei pelo vector para criar os usuários por causa do tamanho dinâmico do container. Acho que é um 
        trade-off válido de memória e velocidade."
    Davi
    - Admin como UserManagement:
        "Achei melhor segundo os fundamentos de encapsulamento e de responsabilidade deixar a classe Admin 
        como a gerenciadora de Jogadores e Usuarios. Inicialmente, teríamos a feature de admin, que conseguiria 
        alterar e ter permissões acima de Usuarios comuns, mas acho que não vai dar tempo."
    Davi
