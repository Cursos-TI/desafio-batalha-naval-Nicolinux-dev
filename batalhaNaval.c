#include <stdio.h>

int main()
{

    // Declarando variáveis
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Cria a coluna horizontal do tabuleiro
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                      // Cria a linha vertical do tabuleiro
    int tabuleiro[10][10] = {0};                                           // Cria uma matriz 10x10 e preenche com zeros

    int navio1_pos_linha = 1, navio2_pos_linha = 1;   // Posição em y do navio
    int navio1_pos_coluna = 0, navio2_pos_coluna = 3; // Posição em x do navio

    int valor_navio = 3;        // Tamanho do navio

    // Apresentando o jogo
    printf("==================================\n");
    printf("     || BATALHA NAVAL EM C ||\n");
    printf("==================================\n\n");
    printf(" #"); // Espaço necessário para alinhar corretamente no terminal


// =====================================================================================================================================
    // Navio horizontal
    int colisao_horizontal = 0; // Alerta de colisão
    if (navio1_pos_coluna + valor_navio > 10)
    {
        printf("Fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[navio1_pos_linha][navio1_pos_coluna + i] != 0)
            {
                colisao_horizontal = 1;
                break;
            }
        }
    }

    if (colisao_horizontal)
    {
        printf("Colisao horizontal!");
    }
    else
    {

        for (int i = 0; i < 3; i++)
        {
            tabuleiro[navio1_pos_linha][navio1_pos_coluna + i] = valor_navio;
        }
    }

// =====================================================================================================================================
    //  Navio Vertical
    int colisao_vertical = 0;   // Alerta de colisão
    if (navio2_pos_linha + valor_navio > 10)
    {
        printf("Fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[navio2_pos_linha + i][navio2_pos_coluna] != 0)
            {
                colisao_vertical = 1;
                break;
            }
        }
    }

    if (colisao_vertical)
    {
        printf("Colisao vertical!");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[navio2_pos_linha + i][navio2_pos_coluna] = valor_navio;
        }
    }

// =====================================================================================================================================
    // Inicia criando o cabeçalho (Colunas)
    for (int i = 0; i < 10; i++)
    {
        printf(" %c", colunas[i]);
    }
    // Após criar as colunas, o programa irá pular uma linha e criará as linhas verticais, e em seguida o tabuleiro preenchido com os zeros
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d", linhas[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("%2d", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}