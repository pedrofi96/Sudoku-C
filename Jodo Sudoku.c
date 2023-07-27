#include <stdio.h>
#include <string.h> //biblioteca com string sera necessaria para fazer a compara��o do jogo do usuario com o jogo completo para saber se o usuario fez o jgoo certo.
#include <stdlib.h>
#include <locale.h>
//variaveis globais, estar�\o em todas a fun��es n�o sendo necessario incluir elas em cada uma das fun��es.
int sudoku_resposta[9][9];
int sudoku_jogo[9][9];
int sudoku_usuario[9][9];

int facil(){ //fun��o para iniciar o jgoo no f�cil atribuindo valores � matriz, apartir de um arquivo .txt
	int i,j; //variaveis para pecorrer a matriz.
	int sudoku_facil[9][9];
	int sudoku_facil_resolvido[9][9];
	FILE *arq; //ponteiro para abrir o arquivo .txt

    arq=fopen("sudoku_facil.txt", "r"); //comando para abrir o arquivo .txt e le-lo
    for(i=0;i<9;i++){ //os dois for, v�o percorrer a matriz dentro do arquivo  .txt e atribuir valores ao "sudoku_facil"
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

    arq=fopen("Sudoku_Facil_Resolvido.txt", "r");
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

}
int medio(){
	int i,j;
	int sudoku_medio[9][9];

	int sudoku_medio_resolvido[9][9];
	  FILE *arq;

    arq=fopen("sudoku_medio.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_medio[i][j]);
        }
    }
    fclose(arq);

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j]=sudoku_medio[i][j];
        }
	}
	 for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_jogo[i][j]=sudoku_medio[i][j];
        }
	}

    arq=fopen("sudoku_medio_resolvido.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_medio_resolvido[i][j]);
        }
    }
    fclose(arq);
    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j]=sudoku_medio_resolvido[i][j];
        }
	}

}
int dificil(){
	int i,j;
	int sudoku_dificil[9][9];
	int sudoku_dificil_resolvido[9][9];

	FILE *arq;
	arq=fopen("sudoku_dificil.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_dificil[i][j]);
        }
    }
    fclose(arq);

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j]=sudoku_dificil[i][j];
        }
	}

    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_jogo[i][j]=sudoku_dificil[i][j];
        }
	}
    arq=fopen("sudoku_medio_resolvido.txt", "r");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_dificil_resolvido[i][j]);
        }
    }
    fclose(arq);
    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j]=sudoku_dificil_resolvido[i][j];
        }
	}
}
int resultado(){
	int i, j;
	int contador;
	/*if(sudoku_usuario[9][9] == sudoku_resposta[9][9]){
		printf("\nParab�ns, vc concluiu o sudoku corretamente.\n");
	}else{
		printf("\nInfelizmente voc� n�o concluiu o jogo de sudoku corretamente.\n Adicionaremos seu jogoa  um arquivo de texto para voc� poder comparar suas respostas com o gabarito.");
	}*/
	for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(sudoku_usuario[i][j] == sudoku_resposta[i][j]){
               contador++;
            }
        }
	}
    if (contador==81){
        printf("\nParab�ns voc� concluiu o Sudoku corretamente.\n");
    }else{
        printf("\nInfelizmente o sudoku n�o foi concluido corretamente.\n");
    }

}
int check_list(){
    int i,j;
      for(i=0;i<9;i++){
        for (j=0;j<9;j++){
             if(sudoku_jogo[i][j]!=0){
                sudoku_usuario[i][j]=sudoku_jogo[i][j];
             }
        }
    }

}
int main(){
    int opcao,opcao2, sair;
    int i,j;
    char txt[20];

	setlocale (LC_ALL, "Portuguese"); //Fun��o para adicionar caracteres especiais em portug�s nos printf.

    printf ("\n\n********************************* SUDOKU *********************************\n\n\n\n");
    printf("Regras do jogo:\n-Cada fileira deve conter 9 numeros de 1 a 9 sem repeti-los.\n-Cada linha deve conter 9 numeros de 1 a 9 sem repeti-los.\n-Cada quadrado com 9 espa�os deve conter 9 digitos de 1 a 9 sem repeti-los.\n");
    printf ("\n-Ao final do jogo caso consiga completar o jogo corretamente voc� vence.\n");
    printf("\nLembre-se que o jogo inicial do sudoku n�o pode ser alterado, caso tente altera-lo o programa retornara o numero original.\n");

    do{
	printf ("\n\nDigite um numero para a dificuldade que deseja jogar:\n-Digite:\n-1 para jogar no f�cil\n-2 para jogar no medio.\n-3 para jogar no dificil.\n");
	scanf ("%d", &opcao);

	switch(opcao){

	case 1:
        facil();
        printf("\n-Iniciando jogo no f�cil:\n");
		break;
	case 2:
		medio(); //puxa resultado da fun��o medio e iguala ao jogo do usuario
		printf("\n-Iniciando jogo no medio:\n");
		break;
	case 3:
		dificil(); //puxa resultado da fun��o dificil e iguala ao jogo do usuario
		printf("\n-Iniciando jogo no dificil, boa sorte!\n");
		break;
	default:
		printf("\n\nComando invalido.\n\n");
		break;
	}
    }while(opcao>3);

    printf("\n\n\n\n\n\n");

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

	printf("\nDigite um numero de 1 a 9 para escolher qual linha voc� quer adicionar um numero:\n");
	scanf ("%d", &i);

	printf("\nDigite um numero de 1 a 9 para escolher qual coluna do jogo voc� quer adicionar um numero:\n");
	scanf("%d", &j);
	i=i-1;
	j=j-1;

	if(0<= i <9 && 0<= j <9){
	i=i+1;
	j=j+1;
	printf("\nDigite que um numero de 1 a 9 para adicionar na linha %d e coluna %d:\n", i, j);
	i=i-1;
	j=j-1;
	scanf("%d", &sudoku_usuario[i][j]);
	}else{
		printf("\n\n*******Coluna e/ou linha invalida.*******\n\n");
	}

    check_list();

	printf("\n\n****Digite 1 para continuar a jogar****\n****Ou 2 para encerrar o jogo.****\n");
	scanf("%d", &opcao2);
    printf("\n\n\n\n\n\n\n\n");

	}while(opcao2!=2);

	resultado();

	printf("\n\n\n\nObrigado por ter jogado sudoku com a gente esperamos que tenha se divertido com o jogo, at� a pr�xima.\n\n\n");

	return 0;
}
