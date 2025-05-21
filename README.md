# Projeto Labirinto Genético

## Descrição
Este projeto implementa um algoritmo genético para simular indivíduos percorrendo um labirinto. Cada indivíduo possui um genoma que define seus movimentos dentro do ambiente.

## Como funciona?
1. O labirinto é carregado a partir de um arquivo `labirinto.txt`.
2. Uma população de indivíduos é gerada aleatoriamente.
3. Cada indivíduo tenta percorrer o labirinto com base em seu genoma.
4. O desempenho é avaliado com base em colisões e distância ao objetivo.

## Tecnologias utilizadas
- Linguagem: **C**
- Estruturas de dados: **Lista encadeada**
- Algoritmos: **Algoritmo genético**
- Compilador recomendado: **GCC**

## Como executar?
gcc main.c mapa/labirinto.c populacao/populacao.c populacao/individuo.c -o genetic_lab
./genetic_lab
