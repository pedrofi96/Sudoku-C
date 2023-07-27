#include<stdio.h>
#include<stdlib.h>

int main(){

    int i, j, sudoku_facil[9][9];
    int sudoku_facil_resolvido[9][9];
	int sudoku_usuario[9][9];
	int sudoku_resposta[9][9];
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
        }
	}

    arq=fopen("Sudoku_Facil_Resolvido.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_facil_resolvido[i][j]);
            printf("%d", sudoku_facil_resolvido[i][j]);//testar se a impressão esta correta
    }
    printf("\n");
    }
    fclose(arq);
    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j]=sudoku_facil_resolvido[i][j];
        }
	}




    return 0;
}
