#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labirinto.h"
#include "../populacao/individuo.h"




Labirinto carregarLabirinto() {
    Labirinto lab;
    FILE *arquivo = fopen("labirinto.txt", "r");
    
    if (arquivo == NULL) {
        printf("ERRO ao abrir o arquivo");
        exit(1);
    }
    
    char linha[MAX_colunas];
    int lin = 0;
    size_t max_colunas = 0; // Para rastrear o comprimento da linha mais longa

    while (fgets(linha, MAX_colunas, arquivo)) {
        // Remove o caractere de nova linha, se presente
        linha[strcspn(linha, "\r\n")] = '\0';
        
        // Calcula o comprimento da linha atual
        size_t tamanho = strlen(linha);
        
        // Atualiza o número máximo de colunas, se necessário
        if (tamanho > max_colunas) {
            max_colunas = tamanho;
        }
        
        // Copia a linha para a matriz do labirinto
        strcpy(lab.Labi[lin], linha);

        // Procura por 'S' e 'E' na linha
        for (size_t col = 0; col < tamanho; col++) {
            if (linha[col] == 'S') {
                lab.inicio[0] = lin;
                lab.inicio[1] = col;
            } else if (linha[col] == 'E') {
                lab.final[0] = lin;
                lab.final[1] = col;
            }
        }
        
        // Verifica se o número de linhas excede o limite
        if (lin >= MAX_linhas) {
            printf("ERRO: labirinto ultrapassa o limite máximo de linhas.\n");
            break;
        }

        lin++;
    }

    // Define o número de linhas e colunas
    lab.linhas = lin;
    lab.colunas = max_colunas; // Usa o comprimento da linha mais longa

    // Preenche linhas mais curtas com espaços, se necessário
    for (int i = 0; i < lab.linhas; i++) {
        size_t len = strlen(lab.Labi[i]);
        for (size_t j = len; j < max_colunas; j++) {
            lab.Labi[i][j] = ' '; // Preenche com espaços
        }
        lab.Labi[i][max_colunas] = '\0'; // Garante terminação da string
    }

    fclose(arquivo);
    while (fgets(linha, MAX_colunas, arquivo)) {
    linha[strcspn(linha, "\r\n")] = '\0';
    size_t tamanho = strlen(linha);
    printf("Linha %d: %s (tamanho: %lu)\n", lin, linha, (unsigned long)tamanho);

    // Resto do código...
}

    printf("Labirinto carregado com sucesso!\n");
    return lab;
}

int movimentoValido(Labirinto lab, int x, int y) {
    return (x >= 0 && x < lab.linhas &&
            y >= 0 && y < lab.colunas &&
            lab.Labi[x][y] != '#');
}

int calcularDistanciaObjetivo(int x, int y, int objetivoX, int objetivoY) {
    return abs(x - objetivoX) + abs(y - objetivoY);
}

int simularIndividuo(Labirinto lab, Individuo *ind) {
    int x = lab.inicio[0];
    int y = lab.inicio[1];
    int colisoes = 0;

    for (int i = 0; i < ind->tamanho; i++) {
        int novoX = x;
        int novoY = y;

        switch (ind->genoma[i]) {
            case 'C': novoX--; break;
            case 'B': novoX++; break;
            case 'E': novoY--; break;
            case 'D': novoY++; break;
        }

        if (movimentoValido(lab, novoX, novoY)) {
            x = novoX;
            y = novoY;
        } else {
            colisoes++;
            // continue; // ou break; depende de como você quer tratar colisões
        }
    }

    ind->posicaoFinal[0] = x;
    ind->posicaoFinal[1] = y;

    int distancia = calcularDistanciaObjetivo(x, y, lab.final[0], lab.final[1]);

    // Fitness: penaliza colisões e distância até o fim
    ind->fitness = 100 - colisoes - distancia;

    return colisoes;
}


void imprimirLabirinto(Labirinto lab) {
    for (int i = 0; i < lab.linhas; i++) {
        for (int j = 0; j < lab.colunas; j++) {
            printf("%c", lab.Labi[i][j]);
            
        }
        printf("\n");
    }
}