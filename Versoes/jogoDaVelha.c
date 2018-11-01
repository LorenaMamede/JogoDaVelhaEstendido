#include <stdio.h>
#define N 4

int main(void){
	int tabuleiro[N][N];
	puts("Entre com o tabuleiro final 4x4:");
	for(int i = 0; i<N; i++){
		for(int j=0; j<N;j++){
			scanf("%d", &tabuleiro[i][j]);
		}
	}
	for(int i = 0; i<N; i++){
		for(int j=0; j<N;j++){
			printf("%d ", tabuleiro[i][j]);
		}
		printf("\n");
	}
	verificaVitoria(tabuleiro,N);
	return 0;
}



