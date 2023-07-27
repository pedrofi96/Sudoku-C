#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    int i,j;
    int sudoku_usuario[9][9];

	printf("\nDigite um numero de 1 a 9 para escolher qual linha você quer adicionar um numero:\n");
	scanf ("%d",&i);

	printf("\nDigite um numero de 1 a 9 para escolher qual coluna do jogo você quer adicionar um numero:\n");
	scanf("%d",&j);


	if((i<0)&&(i<=9)&&(0<j)&&(j<=9)){
	printf("\nDigite que um numero de 1 a 9 para adicionar na linha %d e coluna %d:\n", i, j);
	i=i-1;
	j=j-1;
	scanf("%d", &sudoku_usuario[i][j]);
	}else{
		printf("\n\n*******Coluna e/ou linha invalida.*******\n\n");
    }
    return 0;
}
