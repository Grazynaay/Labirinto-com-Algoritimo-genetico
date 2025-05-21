#include <stdio.h>
#include <stdlib.h>
#include "individuo.h"

void gerarIndividuo(Individuo *ind){
    char caminhos[]= {'D','E','B','C'};
    int mov=tamanho_genoma;
    for(int i=0; i < mov; i++){
        ind->genoma[i] = caminhos[rand()%4];
    }
    ind->fitness = 0;
    ind->tamanho = tamanho_genoma;
}

void imprimirindividuo(Individuo *ind) {
    for (int i = 0; i < ind->tamanho; i++) {
        printf("%c ", ind->genoma[i]);
    }
    printf("\n");
}