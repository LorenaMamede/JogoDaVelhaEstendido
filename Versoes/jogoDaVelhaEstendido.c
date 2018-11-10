#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 9

int verificaVitoriaEstendido(int tabuleiro[N][N], int dimensao){
    int jogador = 0;
    for(int i = 0; i<dimensao;i++){
        int dimAux = dimensao-1;
        int dimAux2 = dimensao-1;
        int somaDiagonalInferior = 0;
        int somaDiagonalSuperior = 0;
        int somaDiagonalBorda = 0;
        int somaDiagonalBorda2 = 0;
        int decresce = i;
        int acresce = 0;
        int decresceJ = i;
        int acresceJ = 0;
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
            }else if(acresce!=(i+1)){
                if((tabuleiro[acresce][j]==tabuleiro[acresce+1][j+1])&&(tabuleiro[acresce][j])){
                    somaDiagonalSuperior++;
                    jogador = tabuleiro[acresce][j];
                }
                acresce++;
            }


            if ((j+i) < (dimensao-1)){//sexto caso
                if((tabuleiro[j][j+i]==tabuleiro[j+1][j+1+i])&&(tabuleiro[j][j+i])){
                     somaDiagonalBorda++;
                     jogador = tabuleiro[j][j+i];
                }                
            }else{
                if((tabuleiro[j][dimAux2]==tabuleiro[j+1][dimAux2-1])&&(tabuleiro[j][dimAux2])){
                    somaDiagonalBorda++;
                    jogador = tabuleiro[j][dimAux2];
                }                
                dimAux2--;
            }

            if(decresceJ){//setimo caso
                if((tabuleiro[j][decresceJ]==tabuleiro[j+1][decresceJ-1])&&(tabuleiro[j][decresceJ])){
                     somaDiagonalBorda2++;
                     jogador = tabuleiro[j][decresceJ];
                     decresceJ--;                     
                }                
            }else if(acresceJ!=(i+1)){
                if((tabuleiro[j][acresceJ]==tabuleiro[j+1][acresceJ+1])&&(tabuleiro[j][acresceJ])){
                    somaDiagonalBorda2++;
                    jogador = tabuleiro[j][acresceJ];
                }                
                acresceJ++;
            }

        }

        if((somaDiagonalBorda2 ==(dimensao-1))||(somaDiagonalInferior==(dimensao-1))||(somaDiagonalSuperior==(dimensao-1))||(somaDiagonalBorda ==(dimensao-1))){//verifica vitoria
            return jogador;
        }
    }
    return 0;
}

int verificaVitoria(int tabuleiro[N][N], int dimensao){//vitorias tradicionais
	int jogador, somaLinha, somaColuna;
	int somaDiagonal = 0;
	int somaOutraDiagonal = 0;
	for(int i = 0; i < dimensao; i++){
		somaLinha = 0;
		somaColuna = 0;
		for(int j=0; j< (dimensao-1);j++){
			if((tabuleiro[i][j] == tabuleiro[i][j+1])&&(tabuleiro[i][j])){//segundo caso
				somaLinha++;
				jogador = tabuleiro[i][j];
			}
			if((tabuleiro[j][i] == tabuleiro[j+1][i])&&(tabuleiro[j][i])){//terceiro caso
				somaColuna++;
				jogador = tabuleiro[j][i];
			}
		}
		if((i+1)!=dimensao){
			if((tabuleiro[i][i] == tabuleiro[i+1][i+1])&&(tabuleiro[i][i])){//primeiro caso
				somaDiagonal++;
				jogador = tabuleiro[i][i];
			}
			if((tabuleiro[i][(dimensao-1)-i] == tabuleiro[i+1][dimensao-i])&&(tabuleiro[i][dimensao-1-i])){//primeiro caso
				somaOutraDiagonal++;
				jogador = tabuleiro[i][dimensao-1-i];
			}
		}
		if((somaLinha == (dimensao-1))||(somaColuna == (dimensao-1))||(somaDiagonal == (dimensao-1))||(somaOutraDiagonal == (dimensao-1))){
			return jogador;			
		}
    }
    return verificaVitoriaEstendido(tabuleiro,dimensao);
}

void verificaGanhador(int jogador){
	if(!jogador){
		printf("Empate \n");
	}else {
		if (jogador==1)
       		printf("X ganhou ");
	    else
	      	printf("O ganhou ");
	}

	printf("\n------FIM DE JOGO------\n");
}

void exibeTabuleiro(int tabuleiro[N][N], int dimensao){
	
	for(int a = 0; a < dimensao; a++){
		printf("  %d ",a);
	}
	printf("\n");
	for(int i = 0; i<dimensao; i++){
		printf("%d", i );
		for(int j=0; j<dimensao;j++){
			if(tabuleiro[i][j]==1)
				printf(" X ");
			else if(tabuleiro[i][j]==2)
				printf(" O ");
			else
				printf("   ");
			if(j!= (dimensao-1))
				printf("|");
		}
		printf("\n");
	}
}

int menu(int *modo, int *dimensao){
	int opcao;

	puts("\n------------ MENU ------------");
	

	printf("1.Jogar\n0.Sair\n\n:");
	scanf("%d",&opcao);

	while((opcao > 1)||(opcao < 0)){
		printf("\nOpcao invalida!\n");
		printf("1.Jogar\n0.Sair\n\n:");
		scanf("%d",&opcao);
	}
	
	if(!opcao)
		return 0;
	else{
		printf("\nEscolha o modo de jogo: \n1.Um jogador\n2.Dois jogadores\n\n:");
		scanf("%d",modo);
		
		while((*modo > 2)||(*modo < 1)){
			printf("\nOpcao invalida!\n");
			printf("\nEscolha o modo de jogo: \n1.Um jogador\n2.Dois jogadores\n\n:");
			scanf("%d",modo);
		}

		printf("\nEscolha as dimensoes do tabuleiro:\n4. 4x4\n5. 5x5\n6. 6x6\n7. 7x7\n8. 8x8\n9. 9x9\n\n:");
		scanf("%d",dimensao);
		
		while((*dimensao > 9)||(*dimensao < 4)){
			printf("\nOpcao invalida!\n");
			printf("\nEscolha as dimensoes do tabuleiro:\n4. 4x4\n5. 5x5\n6. 6x6\n7. 7x7\n8. 8x8\n9. 9x9\n\n:");
			scanf("%d",dimensao);
		}

		system("clear");
		
		return 1;
	}
}


void zeraTabuleiro(int tabuleiro[N][N], int dimensao){

	for(int linha = 0; linha < dimensao; linha++){
		for(int coluna = 0; coluna < dimensao; coluna++){
			tabuleiro[linha][coluna]=0;
		}		
	}
}

int jogo(int dimensao, int *ganhador, int modo){
	int vez = 0 ;
	char jogador;
	int tabuleiro[N][N];
	int linha;
	int coluna;

	zeraTabuleiro(tabuleiro, dimensao);
	puts("----- A partida comecou!! -----\n");
	exibeTabuleiro(tabuleiro,dimensao);
	do{		
		if(vez%2)
			jogador = 'X';
		else
			jogador = 'O';
		printf("\n--------- Vez de %c ---------\n", jogador);

		if((modo == 1)&&(vez%2)){
			srand (time(NULL));
			printf("\nJogada do Computador\n");
			do{
				linha = rand() % dimensao;
				coluna = rand() % dimensao;
			}while(tabuleiro[linha][coluna]);

		}else{
			do{
				printf("Linha: ");
				scanf("%d", &linha);

				printf("Coluna: ");
				scanf("%d", &coluna);

				if((tabuleiro[linha][coluna])||(linha>=dimensao)||(coluna>=dimensao)){
					puts("\nEntrada invalida! Tente outra!");
				}
			}while((tabuleiro[linha][coluna])||(linha>=dimensao)||(coluna>=dimensao));
			
		}		

		printf("\n");

		if(vez%2)
			tabuleiro[linha][coluna] = 1;
		else
			tabuleiro[linha][coluna] = 2;

		system("clear");

		exibeTabuleiro(tabuleiro,dimensao);

		if (vez>4){
			*ganhador = verificaVitoria(tabuleiro, dimensao);
			if(*ganhador)
				return *ganhador;
		}
		vez++;

	}while(vez<(dimensao*dimensao));
	return 0;
}

int main(void){
	int dimensao;
	int modo;
	int jogador;
	
	while(menu(&modo,&dimensao)){		
		jogador = 0;

		jogo(dimensao,&jogador, modo);	
		
		verificaGanhador(jogador);
	}
	
	return 0;	
}

