#ifndef POPULACAO_H
#define POPULACAO_H
#include "individuo.h"

/**
 * @struct TNo
 * Estrutura que representa um nó da lista encadeada de indivíduos.
 * Cada nó contém um indivíduo e um ponteiro para o próximo nó.
 */
typedef struct TNo{
    Individuo individuo; 
    struct TNo*prox;
} TNo;

/**
 * Insere um novo nó no início da lista encadeada.
 * O novo indivíduo criado terá o valor especificado.
 * @param primeNo Ponteiro para o ponteiro do primeiro nó da lista.
 * @param valor Valor que será utilizado para criar o novo indivíduo.
 */
void inserirInicio(TNo **primeNo, int valor);

/**
 * Exibe os indivíduos contidos na lista encadeada no terminal.
 * @param primeNo Ponteiro para o primeiro nó da lista.
 */
void exibirLista(TNo *primeNo);

/**
 * Remove da lista o nó que contém um indivíduo com o valor especificado.
 * @param primeNo Ponteiro para o ponteiro do primeiro nó da lista.
 * @param valor Valor do indivíduo que deve ser removido da lista.
 */
void removerNo(TNo **primeNo, int valor);

#endif