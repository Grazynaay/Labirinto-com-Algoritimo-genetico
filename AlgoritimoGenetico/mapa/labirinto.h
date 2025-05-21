#ifndef LABIRINTO_H
#define LABIRINTO_H
#include "../populacao/individuo.h"

#define MAX_linhas 100
#define MAX_colunas 100

/**
 * @struct Labirinto
 * Estrutura que representa o labirinto.
 * Contém a matriz do labirinto, dimensões e coordenadas de início e fim.
 */
typedef struct{
    char Labi[MAX_linhas][MAX_colunas];
    int linhas;
    int colunas;
    int inicio[2];
    int final[2];
}Labirinto;

/**
 * Função que vai ler o arquivo labirinto.txt e 
 * carregar os dados na estrutura 
 * @param
 * @return Labirinto*
 */
Labirinto carregarLabirinto();

/**
 * Imprime o labirinto no terminal
 * @param lab Estrutura do labirinto a ser impressa
 */
void imprimirLabirinto(Labirinto lab);

/**
 * Calcula a distância de Manhattan entre dois pontos (posição atual e objetivo)
 * @param x Coordenada X atual.
 * @param y Coordenada Y atual.
 * @param objetivoX Coordenada X do objetivo (ponto E).
 * @param objetivoY Coordenada Y do objetivo (ponto E).
 * @return int A distância de Manhattan entre o ponto atual e o ponto de objetivo.
 */
int calcularDistanciaObjetivo(int x, int y, int objetivoX, int objetivoY);

/**
 * Simula o percurso de um indivíduo no labirinto com base em seu genoma.
 * @param lab Estrutura do labirinto onde o indivíduo será testado.
 * @param ind Ponteiro para o indivíduo a ser simulado.
 * @return int O número total de colisões que o indivíduo teve durante o percurso.
 */
int simularIndividuo(Labirinto lab, Individuo *ind);



#endif 