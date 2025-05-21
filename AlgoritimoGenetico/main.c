#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mapa/labirinto.h"
#include "populacao/populacao.h"

#define TAM_POPULACAO 10  // número de indivíduos

int main() {


    srand(time(NULL)); // inicializa gerador de números aleatórios

    // 1. Carrega o labirinto
    Labirinto lab = carregarLabirinto();
    printf("\n--- LABIRINTO ---\n");
    imprimirLabirinto(lab);

    // 2. Cria população (lista encadeada)
    TNo *populacao = NULL;

    // 3. Insere indivíduos
    for (int i = 0; i < TAM_POPULACAO; i++) {
        inserirInicio(&populacao, i);  // valor "i" é só para diferenciar
    }

    // 4. Simula cada indivíduo
    TNo *temp = populacao;
    int contador = 1;
    while (temp != NULL) {
    int colisoes = simularIndividuo(lab, &temp->individuo); 

    printf("\nIndivíduo %d:\n", contador++);
    printf("Genoma: ");
    imprimirindividuo(&temp->individuo);

    printf("Posição final: (%d, %d)\n",
           temp->individuo.posicaoFinal[0],
           temp->individuo.posicaoFinal[1]);

    printf("Número de colisões: %d\n", colisoes); 
    printf("Fitness: %d\n", temp->individuo.fitness); 

    temp = temp->prox;
}


    return 0;
}
