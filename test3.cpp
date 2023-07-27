#include<stdio.h>
#include<stdlib.h>

int main(){

    int i, j, sudoku_facil[9][9];
	int sudoku_usuario[9][9];
    FILE *arq;
	
    arq=fopen("sudoku_facil.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_facil[i][j]);
            printf("%d", sudoku_facil[i][j]);//testar se a impressão esta correta
    }
    printf("\n");
    }
    fclose(arq);//fechar arquivo
    
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j]=sudoku_facil[i][j];
    		printf("%d", sudoku_facil[i][j]);
        }
        printf("\n");
	}
   
	printf("+---+---+---+\n");
    for (i=0; i<9; i++){
        printf("|");
        	for (j=0; j<9; j++){
                 if(sudoku_facil[i][j]!=0){
                    printf("%d", sudoku_facil[i][j]);
                }else{
                    printf(" ");
                } if (j % 3 == 2)
                    printf("|");
            }
        if (i % 3 == 2)
            printf("\n+---+---+---+");
            printf("\n");
	}
    
    return 0;
}
