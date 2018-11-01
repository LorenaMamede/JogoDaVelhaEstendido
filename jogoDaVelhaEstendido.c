#include <stdio.h>
#define N 9



void verificaVitoriaEstendido(int tabuleiro[N][N], int dimensao){
    int jogador = 0;
    for(int i = 0; i<dimensao;i++){
        int dimAux = dimensao-1;
        int dimAux2 = dimensao-1;
        int somaDiagonalInferior = 0;
        int somaDiagonalSuperior = 0;
        int somaDiagonalBorda = 0;
        int decresce = i;
        int acresce = 0;
        for(int j = 0; j<dimensao;j++){
            if ((j+i) < (dimensao-1)){//quarto caso
                if((tabuleiro[j+i][j]==tabuleiro[j+1+i][j+1])&&(tabuleiro[j+i][j])){
                     somaDiagonalInferior++;
                     jogador = tabuleiro[j+i][j];
                }
            
            }else{
                if((tabuleiro[dimAux][j]==tabuleiro[dimAux-1][j+1])&&(tabuleiro[dimAux][j])){
                    somaDiagonalInferior++;
                    jogador = tabuleiro[dimAux][j];
                }                
                dimAux--;
            }



            if(decresce){//quinto caso
                if((tabuleiro[decresce][j]==tabuleiro[decresce-1][j+1])&&(tabuleiro[decresce][j])){
                    somaDiagonalSuperior++;
                    jogador = tabuleiro[decresce][j];
                }
                decresce--;
            }else if(acresce!=i){
                if((tabuleiro[acresce][j]==tabuleiro[acresce+1][j+1])&&(tabuleiro[acresce][j])){
                    somaDiagonalSuperior++;
                    jogador = tabuleiro[acresce][j];
                }
                acresce++;
            }


            if ((j+i) < (dimensao-1)){//sexto caso
                if((tabuleiro[j][j+1]==tabuleiro[j+1][j+1+i])&&(tabuleiro[j][j+i])){
                     somaDiagonalBorda++;
                     jogador = tabuleiro[j][j+1];
                }                
            }else{
                if((tabuleiro[j][dimAux2]==tabuleiro[j+1][dimAux2-1])&&(tabuleiro[j][dimAux2])){
                    somaDiagonalBorda++;
                    jogador = tabuleiro[j][dimAux2];
                }                
                dimAux2--;
            }
        }

        if((somaDiagonalInferior==(dimensao-1))||(somaDiagonalSuperior==(dimensao-1))||(somaDiagonalBorda ==(dimensao-1))){//verifica vitoria
            printf("Ganhou %d \n", jogador);
            break;
        }else if(i==(dimensao-1)){
			printf("empate");
			break;
		}
    }
}

void verificaVitoria(int tabuleiro[N][N], int dimensao){//vitorias tradicionais
	int jogador, somaLinha, somaColuna;
	int somaDiagonal = 0;
	int somaOutraDiagonal = 0;
	for(int i = 0; i < dimensao; i++){
		somaLinha = 0;
		somaColuna = 0;
		for(int j=0; j< dimensao;j++){
			if((tabuleiro[i][j] == tabuleiro[i][j+1])&&(tabuleiro[i][j])){//segundo caso
				somaLinha++;
				jogador = tabuleiro[i][j];
			}
			if((tabuleiro[j][i] == tabuleiro[j+1][i])&&(tabuleiro[j][i])){//terceiro caso
				somaColuna++;
				jogador = tabuleiro[j][i];
			}
		}
		if((tabuleiro[i][i] == tabuleiro[i+1][i+1])&&(tabuleiro[i][i])){//primeiro caso
			somaDiagonal++;
			jogador = tabuleiro[i][i];
		}
		if((tabuleiro[i][(dimensao-1)-i] == tabuleiro[i+1][dimensao-i])&&(tabuleiro[i][dimensao-1-i])){//primeiro caso
			somaOutraDiagonal++;
			jogador = tabuleiro[i][dimensao-1-i];
		}
		if((somaLinha == (dimensao-1))||(somaColuna == (dimensao-1))||(somaDiagonal == (dimensao-1))||(somaOutraDiagonal == (dimensao-1))){
			if (jogador == 1){
				printf("X ganhou \n");
				break;
            }else{
				printf("O ganhou \n");
				break;
			}
		}else if(i==(dimensao-1)){
			verificaVitoriaEstendido(tabuleiro,dimensao);
		}
    }
}
int main(void){
	int tabuleiro[N][N];
	int dimensao;

	puts("Informe um valor entre 3 e 10 para as dimensoe do tabuleiro: ");
	scanf("%d", &dimensao);

	puts("Entre com o tabuleiro final:");
	for(int i = 0; i<dimensao; i++){
		for(int j=0; j<dimensao;j++){
			scanf("%d", &tabuleiro[i][j]);
		}
	}
	for(int i = 0; i<dimensao; i++){
		for(int j=0; j<dimensao;j++){
			printf("%d ", tabuleiro[i][j]);
		}
		printf("\n");
	}
	verificaVitoria(tabuleiro, dimensao);
	return 0;
}

