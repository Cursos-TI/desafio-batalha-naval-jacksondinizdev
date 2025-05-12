#include <stdio.h>

// Define constantes usadas no tabuleiro e matrizes

#define TAMANHO 10 // Tamanho do tabuleiro (10x10)
#define NAVIO 3    // Áreas afetadas ou posições ocupadas por navios
#define AGUA 0     // Valor para representar água (posições não afetadas)
#define AFETADO 5  // Valor que indica áreas afetadas pelas habilidades

// Função para imprimir uma matriz 5x5

void imprimirMatriz(int matriz[5][5]) {
  // linhas da matriz
  for (int i = 0; i < 5; i++) {
    // colunas da matriz
    for (int j = 0; j < 5; j++) {
      // Exibe o valor em cada posição
      printf("%d ", matriz[i][j]);
    }

    printf("\n");
  }
}

// Função para gerar a matriz em formato de cone

void gerarMatrizCone(int matriz[5][5]) {
  // Percorre as linhas e colunas para construir o padrão de cone
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      // Define o ponto no topo do cone
      if (i == 0 && j == 2)
        matriz[i][j] = 3;
      // Expande a área na segunda linha
      else if (i == 1 && (j >= 1 && j <= 3))
        matriz[i][j] = 3;
      // Base mais larga na terceira linha
      else if (i == 2)
        matriz[i][j] = 3;
      // Fora da área do cone
      else
        matriz[i][j] = 0;
    }
  }
}

// Função para gerar a matriz em formato de cruz

void gerarMatrizCruz(int matriz[5][5]) {
  // Percorre linhas e colunas para construir o padrão de cruz
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      // Linhas e colunas centrais definem o formato da cruz
      if (i == 2 || j == 2)
        matriz[i][j] = 3;
      // Fora da área da cruz
      else
        matriz[i][j] = 0;
    }
  }
}

// Função para gerar a matriz em formato de octaedro (losango)

void gerarMatrizOctaedro(int matriz[5][5]) {
  // Itera pelas linhas e colunas para construir o padrão de octaedro
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      // Condições que formam o losango (vista frontal do octaedro)
      if ((i + j == 2 || i + j == 6 || i - j == 2 || j - i == 2))
        matriz[i][j] = 3;
      // Fora da área do octaedro
      else
        matriz[i][j] = 0;
    }
  }
}

int main() {
  // Declaração das matrizes para habilidades (cone, cruz e octaedro)
  int cone[5][5], cruz[5][5], octaedro[5][5];

  // Geração dinâmica das matrizes utilizando funções específicas
  gerarMatrizCone(cone);         // Gera matriz do cone
  gerarMatrizCruz(cruz);         // Gera matriz da cruz
  gerarMatrizOctaedro(octaedro); // Gera matriz do octaedro

  // Exibe a matriz do cone
  printf("\nExemplo de saída de habilidade em cone:\n");
  imprimirMatriz(cone);

  // Exibe a matriz da cruz
  printf("\nExemplo de saída de habilidade em cruz:\n");
  imprimirMatriz(cruz);

  // Exibe a matriz do octaedro
  printf("\nExemplo de saída de habilidade em octaedro:\n");
  imprimirMatriz(octaedro);

  // Indica que o programa foi executado com sucesso
  return 0;
}
