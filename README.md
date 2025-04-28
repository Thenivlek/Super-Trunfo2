# Super Trunfo 2 – Comparações Avançadas em C

## Descrição

Este projeto implementa o desafio “nível mestre” do jogo Super Trunfo em C.  
Cada carta representa um estado brasileiro com dados reais de população, área e PIB (IBGE 2022), além de:

- Pontos turísticos (valor fixo para comparação),
- Densidade demográfica (calculada em hab/km²),
- PIB per capita (calculado em R$/hab).

O programa permite ao jogador escolher **dois** atributos diferentes, compara cada atributo individualmente (usando regra invertida só para densidade demográfica) e soma os valores para determinar o vencedor ou empate.

---

## Funcionalidades

- Cadastro de **duas** cartas pré-definidas com dados reais.
- Cálculo automático de **densidade demográfica** e **PIB per capita**.
- **Menu dinâmico** de seleção de atributos (impede escolha duplicada).
- Comparação com **dois atributos**:
  - Para atributos 1–4 e 6, **maior valor vence**.
  - Para atributo 5 (densidade), **menor valor vence**.
- Soma dos dois valores e decisão final com **operador ternário**.
- Tratamento de **empate**.
- Pausa no final para leitura do resultado.

---

## Atributos Disponíveis

1. População
2. Área (km²)
3. PIB (R$ bilhões)
4. Pontos Turísticos
5. Densidade Demográfica (hab/km²)
6. PIB per Capita (R$/hab)

---

## Como Compilar e Executar

1. Abra o terminal na pasta do projeto.
2. Compile com GCC (ou equivalente):

```bash
  gcc super-trunfo2.c -o super-trunfo2
```

3. Execute:

```bash
  ./super-trunfo2
```

## Estrutura do Código

- Carta: struct com todos os campos (estado, código, cidade, populacao, area, pib, pontosTur, densidadeDemog, pibPerCapita).
- pegarValor(): retorna o valor de um atributo numérico.
- exibirCarta(): printa todos os dados de uma carta.
- mostrarMenu(): mostra opções de atributos, ocultando a já selecionada.
- main():

1. Inicializa cartas com dados reais.
2. Calcula densidade e PIB per capita.
3. Exibe cartas.
4. Recebe duas escolhas de atributo, garantindo não repetição.
5. Compara cada atributo, soma valores e decide o vencedor.
6. Aguarda ENTER antes de encerrar.

## Dados das Cartas

São Paulo (SP)

- População: 44 411 238
- Área: 248 219,485 km²
- PIB: R$ 3 130 bilhões
- Pontos Turísticos: 12

Rio de Janeiro (RJ)

- População: 16 055 174
- Área: 43 750,425 km²
- PIB: R$ 1 150 bilhões
- Pontos Turísticos: 8

## Autor

Kelvin – desafio “Super Trunfo 2” nível mestre em C.
