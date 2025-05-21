#include <stdio.h>
#include <stdlib.h>
#include "populacao.h"

TNo* criarNo() {
    TNo* novoNo = (TNo*)malloc(sizeof(TNo));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    gerarIndividuo(&novoNo->individuo);
    novoNo->prox = NULL;
    return novoNo;
}

void inserirInicio(TNo **primeNo, int valor) {
    TNo *novoNo = criarNo(valor);
    if (novoNo != NULL) {
        novoNo->prox = *primeNo;
        *primeNo = novoNo;
    }
}

void exibirLista(TNo *primeNo) {
    TNo *temp = primeNo;
    while (temp != NULL) {
        printf("Indivíduo fitness: %d -> ", temp->individuo.fitness);
        temp = temp->prox;
    }
    printf("NULL\n");
}