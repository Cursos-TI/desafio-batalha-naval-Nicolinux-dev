#include <stdio.h>

int main()
{
    // Declarando variáveis
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Cria a coluna horizontal do tabuleiro
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                      // Cria a linha vertical do tabuleiro
    int tabuleiro[10][10] = {0};                                           // Cria uma matriz 10x10 e preenche com zeros

    int navio1_pos_linha = 1, navio2_pos_linha = 1, navio3_pos_linha = 1, navio4_pos_linha = 5;   // Posição em y do navio
    int navio1_pos_coluna = 0, navio2_pos_coluna = 4, navio3_pos_coluna = 6, navio4_pos_coluna = 3; // Posição em x do navio

    int valor_navio = 3;        // Tamanho do navio
    int colisao_horizontal = 0; // Alerta de colisão
    int colisao_vertical = 0;   // Alerta de colisão
    int colisao_diagonal_p = 0;   // Alerta de colisão na diagonal primária
    int colisao_diagonal_s = 0;   // Alerta de colisão na diagonal secundária

    // Apresentando o jogo
    printf("==================================\n");
    printf("     || BATALHA NAVAL EM C ||\n");
    printf("==================================\n\n");
    printf(" #"); // Espaço necessário para alinhar corretamente no terminal

// =====================================================================================================================================
    // Navio horizontal
    if (navio1_pos_coluna + valor_navio > 10)
    {
        printf("Navio horizontal esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
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

        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio1_pos_linha][navio1_pos_coluna + i] = 3;
        }
    }

// =====================================================================================================================================
    //  Navio Vertical
    if (navio2_pos_linha + valor_navio > 10)
    {
        printf("Navio vertical esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
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
        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio2_pos_linha + i][navio2_pos_coluna] = 3;
        }
    }

// =====================================================================================================================================
    //  Navio Diagonal Primário
    if (navio3_pos_linha + valor_navio > 10 || navio3_pos_coluna + valor_navio > 10)
    {
        printf("Navio diagonal primario esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            if (tabuleiro[navio3_pos_linha + i][navio3_pos_coluna + i] != 0)
            {
                colisao_diagonal_p = 1;
                break;
            }
        }
    }

    if (colisao_diagonal_p)
    {
        printf("Colisao diagonal primaria!");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio3_pos_linha + i][navio3_pos_coluna + i] = 3;
        }
    }

// =====================================================================================================================================
    //  Navio Diagonal Secundário
    if (navio4_pos_linha + valor_navio > 10 || navio4_pos_coluna - (valor_navio - 1) < 0)
    {
        printf("Navio diagonal secundario esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            if (tabuleiro[navio4_pos_linha + i][navio4_pos_coluna - i] != 0)
            {
                colisao_diagonal_s = 1;
                break;
            }
        }
    }

    if (colisao_diagonal_s)
    {
        printf("Colisao diagonal secundario!");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio4_pos_linha + i][navio4_pos_coluna - i] = 3;  
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
    printf("\n");
    return 0;
}