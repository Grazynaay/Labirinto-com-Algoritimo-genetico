#ifndef INDIVIDUO_H
#define INDIVIDUO_H


#define tamanho_genoma 80

/**
 * @struct Individuo
 * Estrutura que representa um indivíduo da população.
 * Contém um genoma com instruções de movimento, seu tamanho real,
 * a pontuação de fitness (adequação ao objetivo) e a posição final após simulação.
 */
typedef struct {
    char genoma[tamanho_genoma];  // ainda pode ser o tamanho máximo
    int tamanho;                  // tamanho real usado
    int fitness;
    int posicaoFinal[2];          // se for simular caminho
} Individuo;

/**
 * Gera um indivíduo aleatório com um genoma de movimentos válidos.
 * 
 * @param ind Ponteiro para o indivíduo a ser gerado.
 */
void gerarIndividuo(Individuo *ind);

/**
 * Imprime no terminal os dados do indivíduo, como genoma, fitness e posição final.
 * 
 * @param ind Ponteiro para o indivíduo a ser exibido.
 */
void imprimirindividuo(Individuo *ind);

#endif