#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main(){
	int i,j; //variaveis para pecorrer a matriz.
	int sudoku_facil[9][9];
	int sudoku_facil_resolvido[9][9];
	int sudoku_resposta[9][9];
    int sudoku_jogo[9][9];
    int sudoku_usuario[9][9];
	FILE *arq; //ponteiro para abrir o arquivo .txt

    arq=fopen("sudoku_facil.txt", "r"); //comando para abrir o arquivo .txt e le-lo

    for(i=0;i<9;i++){ //os dois for, vão percorrer a matriz dentro do arquivo  .txt e atribuir valores ao "sudoku_facil"
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_facil[i][j]);
        }
    }
    fclose(arq);

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j]=sudoku_facil[i][j];
        }
	}

    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_jogo[i][j]=sudoku_facil[i][j];
        }
    }
	printf("+---+---+---+\n");
    for (i=0; i<9; i++){
        printf("|");
        	for (j=0; j<9; j++){
                 if((sudoku_usuario[i][j]==sudoku_jogo[i][j])&&(sudoku_jogo!=0)){
                    printf("%d'",sudoku_usuario);
                 }else if(sudoku_usuario[i][j]!=0){
                    printf("%d", sudoku_usuario[i][j]);
                }else{
                    printf(" ");
                }
                if (j % 3 == 2)
                    printf("|");

            }
        if (i % 3 == 2)
            printf("\n+---+---+---+");
            printf("\n");
    }
    return 0;
}
