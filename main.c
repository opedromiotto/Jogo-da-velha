/*faça um programa para jogar o jogo da velha. ao final imprima o resultado do jogo e pergunte se deseja jogar novamente*/
/*while (getchar() != '\n'); // descartar caracteres até encontrar uma nova linha*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*
  1 - iniciar a estrutura vazia 
  2 - montar o tabuleiro
  3 - ler as coordenadas
  4 - validar as coordenadas
  5 - verificar se alguém ganhou por uma linha, coluna, diagonal principal ou secundaria
  6 - perguntar se deseja jogar novamente
*/
/*global*/
char matriz[3][3];

int venceuLinha(char matriz[3][3], char simbolo, char nome[10]){
    int venceu = 0;
    if (matriz[0][0] == simbolo && matriz[0][1] == simbolo && matriz[0][2] == simbolo ||
        matriz[1][0] == simbolo && matriz[1][1] == simbolo && matriz[1][2] == simbolo ||
        matriz[2][0] == simbolo && matriz[2][1] == simbolo && matriz[2][2] == simbolo){
            venceu = 1;
            printf("\n ------ FIM DE JOGO ------ \n");
            printf("%s venceu por linha", nome);
            return venceu;
    }
    return venceu;
}

int venceuColuna(char matriz[3][3], char simbolo, char nome[10]){
    int venceu = 0;
    if (matriz[0][0] == simbolo && matriz[1][0] == simbolo && matriz[2][0] == simbolo ||
        matriz[0][1] == simbolo && matriz[1][1] == simbolo && matriz[2][1] == simbolo ||
        matriz[0][2] == simbolo && matriz[1][2] == simbolo && matriz[2][2] == simbolo){
            venceu = 1;
            printf("\n ------ FIM DE JOGO ------ \n");
            printf("%s venceu por coluna", nome);
            return venceu;
    }
    return venceu;
}

int venceuDiagonalPrincipal(char matriz[3][3], char simbolo, char nome[10]){
    int venceu = 0;
    if (matriz[0][0] == simbolo && matriz[1][1] == simbolo && matriz[2][2] == simbolo){
            venceu = 1;
            printf("\n ------ FIM DE JOGO ------ \n");
            printf("%s venceu por diagonal principal", nome);
            return venceu;
    }
    return venceu;
}

int venceuDiagonalSecundaria(char matriz[3][3], char simbolo, char nome[10]){
    int venceu = 0;
    if (matriz[0][2] == simbolo && matriz[1][1] == simbolo && matriz[2][0] == simbolo){
            venceu = 1;
            printf("\n ------ FIM DE JOGO ------ \n");
            printf("%s venceu por diagonal secundaria", nome);
            return venceu;
    }
    return venceu;
}

void leValidaCoordenadas(char matriz[3][3], char nome[10], char simbolo){
    setlocale(LC_ALL, "Portuguese");
    int linha, coluna;

    do{
        do{
            printf("%s, em qual linha deseja jogar?: ", nome);
            scanf("%d", &linha);
            if (linha < 0 || linha > 2){
                printf("Linha inválida, escolha uma posição entre 0 e 2\n");
            }
        }while(linha < 0 || linha > 2);
        do{
            printf("%s, em qual coluna deseja jogar?: ", nome);
            scanf("%d", &coluna);
            if (coluna < 0 || coluna > 2){
                printf("Coluna inválida, escolha uma posição entre 0 e 2\n");
            }    
        }while(coluna < 0 || coluna > 2);
            
            if (matriz[linha][coluna] != ' '){
                printf("Índices válidos, mas essa posição já está ocupada\n");
            }
    }while(matriz[linha][coluna] != ' ');
    matriz[linha][coluna] = simbolo;
}

int main(int argc, char const *argv[]){
    char nome_j1[10], nome_j2[10], simbolo;
    int l, c, jogadas_j1 = 0, jogadas_j2 = 0, jogador = 1, ganhou = 0, pergunta;
    int pontosj1 = 0, pontosj2 = 0;

    /*nome dos jogadores*/
    printf("Informe o nome do 1.o jogador: ");
    scanf("%s", nome_j1);
    printf("Informe o nome do 2.o jogador: ");
    scanf("%s", nome_j2);

    do{
        /*iniciando a estrutura vazia*/
        for (l = 0; l < 3; l++){
            for (c = 0; c < 3; c++){
                matriz[l][c] = ' ';
            }
        }

        do{
            /*montando o tabuleiro*/
            printf("0   1   2\n\n");
            for (l = 0; l < 3; l++){
                for (c = 0; c < 3; c++){
                    printf("%c", matriz[l][c]);

                    if (c == 2){
                        printf("  %d", l);
                    }

                    if (c < 2){
                        printf(" | ");
                    }
                }
                printf("\n");
            }
            
            /*chamando a função que lê e valida as coordenadas*/
            if (jogador == 1){
                simbolo = 'X';
                jogadas_j1++;
                jogador++;
                leValidaCoordenadas(matriz, nome_j1, simbolo);
                if (jogadas_j1 > 2){
                    for (c = 1; c < 5; c++){
                        ganhou = venceuLinha(matriz, simbolo, nome_j1);
                        if (ganhou){
                            pontosj1 += 1;
                            break;
                        }
                        ganhou = venceuColuna(matriz, simbolo, nome_j1);
                        if (ganhou){
                            pontosj1 += 1;
                            break;
                        }
                        ganhou = venceuDiagonalPrincipal(matriz, simbolo, nome_j1);
                        if (ganhou){
                            pontosj1 += 1;
                            break;
                        }
                        ganhou = venceuDiagonalSecundaria(matriz, simbolo, nome_j1);
                        if (ganhou){
                            pontosj1 += 1;
                            break;
                        }
                    }
                }
            }
            else{
                simbolo = 'O';
                jogadas_j2++;
                jogador = 1;
                leValidaCoordenadas(matriz, nome_j2, simbolo);
                if (jogadas_j2 > 2){
                    ganhou = venceuLinha(matriz, simbolo, nome_j2);
                    if (ganhou){
                        pontosj2++;
                        break;
                    }
                    ganhou = venceuColuna(matriz, simbolo, nome_j2);
                    if (ganhou){
                        pontosj2 += 1;
                        break;
                    }
                    ganhou = venceuDiagonalPrincipal(matriz, simbolo, nome_j2);
                    if (ganhou){
                        pontosj2 += 1;
                        break;
                    }
                    ganhou =  venceuDiagonalSecundaria(matriz, simbolo, nome_j2);
                    if (ganhou){
                        pontosj2 += 1;
                        break;
                    }
                }
            }
        }while(ganhou == 0);
        printf("\n--------------------------\n");
        do{
            printf("\nDigite 1 para jogar novamente\nDigite 0 para encerrar o programa\nInforme sua resposta: ");
            scanf("%d", &pergunta);
            if (pergunta != 1 && pergunta != 0){
                printf("Por favor, digite apenas 0 ou 1\n");
                while (getchar() != '\n'); // Limpar o buffer de entrada para evitar problemas com múltiplas entradas
            }
        }while(pergunta != 1 && pergunta != 0);
    }while(pergunta == 1);

    printf("\n ------ PLACAR FINAL ------ \n");
    printf("%s %dX%d %s", nome_j1, pontosj1, pontosj2, nome_j2);
    printf("\nObrigado por ter jogado :) \n");
}
