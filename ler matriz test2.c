#include<stdio.h>
#include<stdlib.h>

int main(){

    int i, j,opcao2, sudoku_facil[9][9];
    int sudoku_facil_resolvido[9][9];
	int sudoku_usuario[9][9];
	int sudoku_resposta[9][9];
    FILE *arq;

    arq=fopen("sudoku_facil.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d", &sudoku_facil[i][j]);
        }
    }
    fclose(arq);

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j]=sudoku_facil[i][j];
        }
	}

    arq=fopen("sudoku_medio_resolvido.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_facil_resolvido[i][j]);
        }
    }
    fclose(arq);
    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j]=sudoku_facil_resolvido[i][j];
        }
	}

	do{
    printf("+---+---+---+\n");
    for (i=0; i<9; i++){
        printf("|");
        	for (j=0; j<9; j++){
                 if(sudoku_usuario[i][j]!=0){
                    printf("%d", sudoku_usuario[i][j]);
                }else{
                    printf(" ");
                } if (j % 3 == 2)
                    printf("|");
            }
        if (i % 3 == 2)
            printf("\n+---+---+---+");
            printf("\n");
    }

    printf("\nDigite um numero de 1 a 9 para escolher qual linha você quer adicionar um numero:\n");
	scanf ("%d", &i);

	printf("\nDigite um numero de 1 a 9 para escolher qual coluna do jogo você quer adicionar um numero:\n");
	scanf("%d", &j);


	if(0< i <= 9 && 0< j <=9){
	printf("\nDigite que um numero de 1 a 9 para adicionar na linha %d e coluna %d:\n", i, j);
	i=i-1;
	j=j-1;
	scanf("%d", &sudoku_usuario[i][j]);
	}else{
		printf("\n\n*******Coluna e/ou linha invalida.*******\n\n");
	}

	printf("\n\n****Digite 1 para continuar a jogar****\n****Ou 2 para encerrar o jogo.****\n");
	scanf("%d", &opcao2);

    for(i=0;i<9;i++){
        for (j=0;j<9;j++){
             if(sudoku_facil[i][j]!=0){
                sudoku_usuario[i][j]=sudoku_facil[i][j];
             }
        }
    }

	}while(opcao2!=2);
    return 0;
}
