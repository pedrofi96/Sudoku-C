#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//variaveis globais, estarã\o em todas a funções não sendo necessario incluir elas em cada uma das funções.
int sudoku_resposta[9][9];
int sudoku_jogo[9][9];
int sudoku_usuario[9][9];

int facil(){ //função para iniciar o jogo no fácil atribuindo valores à matriz, apartir de um arquivo .txt
	int i,j; //variaveis para pecorrer a matriz.
	int sudoku_facil[9][9]; //matriz para pegar o jogo no facil
	int sudoku_facil_resolvido[9][9]; //matriz para pegar a resolução do jogo no fácil.
	
	FILE *arq; //ponteiro para abrir o arquivo .txt

    arq=fopen("sudoku_facil.txt", "r"); //comando para abrir o arquivo .txt e le-lo

    for(i=0;i<9;i++){ //os dois for, vão percorrer a matriz dentro do arquivo  .txt e atribuir valores ao "sudoku_facil"
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_facil[i][j]);
        }
    }
    fclose(arq);// fecha arquivo .txt

	for(i=0;i<9;i++){ //função para percorrer a matriz sudoku usuario e igualar os valores dela a sudoku facil
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j]=sudoku_facil[i][j];
        }
	}

    for(i=0;i<9;i++){ //funcao para percorrer a matriz sudoku facil e igualar o valor dela a sudoku jogo
		for(j=0;j<9;j++){
    		sudoku_jogo[i][j]=sudoku_facil[i][j];
        }
	}
    arq=fopen("Sudoku_Facil_Resolvido.txt", "r"); //funçao para abrir o arquivo do sudoku resolvido e lê-lo
    for(i=0;i<9;i++){ //função para percorrer o arquivo de .txt e pegar os valores do arquivo igualando a matriz sudoku facil resolvido
        for(j=0;j<9;j++){
            fscanf(arq,"%d ", &sudoku_facil_resolvido[i][j]);
        }
        printf("\n");
    }
    fclose(arq); //função para fechar o arquivo
    for(i=0;i<9;i++){ //função para igualar os valores de sudoku facil resolvido à sudoku resposta.
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
	int contador=0; 

	for(i=0;i<9;i++){ //função para percorrer a sudoku usuario e compara-lo com sudoku resposta para ver se o usuario respondeu corretamente.
        for(j=0;j<9;j++){
            if(sudoku_usuario[i][j]==sudoku_resposta[i][j]){
               contador++; //todo numero que o usuario colocou corretamente adiciona 1 ao contador
            }
        }
	}
    if (contador==81){ //se o contador for igual a 81 o usuario acertou tudo do jogo.
        printf("\nParabéns você concluiu o Sudoku corretamente.\n");
    }else{
        printf("\nInfelizmente o sudoku não foi concluido corretamente.\n");
    }

}
int check_list(){
    int i,j;
    for(i=0;i<9;i++){
        for (j=0;j<9;j++){
            if((sudoku_jogo[i][j]!=0) && (sudoku_usuario[i][j]!=sudoku_jogo[i][j])){
                sudoku_usuario[i][j]=sudoku_jogo[i][j];
                printf("\n**********Você tentou alterar um dos numeros iniciais do sudoku, este numero não pode ser alterado.***********\n");
            }
        }
    }
}
int main(){
    int opcao,opcao2;
    int i,j;


	setlocale (LC_ALL, "Portuguese"); //Função para adicionar caracteres especiais da lingua portuguesa nos printf.

    printf ("\n\n********************************* SUDOKU *********************************\n\n\n\n");
    printf("Regras do jogo:\n-Cada fileira deve conter 9 numeros de 1 a 9 sem repeti-los.\n-Cada linha deve conter 9 numeros de 1 a 9 sem repeti-los.\n-Cada quadrado com 9 espaços deve conter 9 digitos de 1 a 9 sem repeti-los.\n");
    printf ("\n-Ao final do jogo caso consiga completar o jogo corretamente você vence.\n");
    printf("\nLembre-se que o jogo inicial do sudoku não pode ser alterado, caso tente altera-lo o programa retornara o numero original.\n");

    do{ //comando do-while para o jogador selecionar a dificuldade
	printf ("\n\nDigite um numero para a dificuldade que deseja jogar:\n-Digite:\n-1 para jogar no fácil\n-2 para jogar no medio.\n-3 para jogar no dificil.\n");
	scanf ("%d", &opcao);

	switch(opcao){

	case 1:
        facil();// busca a função facil
        printf("\n-Iniciando jogo no fácil:\n");
		break;
	case 2:
		medio(); //puxa resultado da função medio e iguala ao jogo do usuario
		printf("\n-Iniciando jogo no medio:\n");
		break;
	case 3:
		dificil(); //puxa resultado da função dificil e iguala ao jogo do usuario
		printf("\n-Iniciando jogo no dificil, boa sorte!\n");
		break;
	default:
		printf("\n\nComando invalido.\n\n");
		break;
	}
    }while(opcao>3);

    printf("\n\n\n\n\n");

	do{//comando do-while para o usuario jogar

	printf("+---+---+---+\n");//parte para colocar a matriz de sudoku corretamente na tela
    for (i=0; i<9; i++){
        printf("|");
        	for (j=0; j<9; j++){
                 if(sudoku_usuario[i][j]!=0){
                    printf("%d", sudoku_usuario[i][j]);
                }else{
                    printf(" ");
                } if (j % 3 == 2)//adiciona uma | toda vez que modulo de j tiver resto 2.
                    printf("|");
            }
        if (i % 3 == 2)//adiciona a separaçãod os quadrados do sudoku toda vez que modulo de i tiver resto 2
            printf("\n+---+---+---+");
            printf("\n");
    }

	printf("\nDigite um numero de 1 a 9 para escolher qual linha você quer adicionar um numero:\n");
	scanf ("%d",&i);

	printf("\nDigite um numero de 1 a 9 para escolher qual coluna do jogo você quer adicionar um numero:\n");
	scanf("%d",&j);


	if ((i>0)&&(i<=9)&&(0<j)&&(j<=9)){
	printf("\nDigite que um numero de 1 a 9 para adicionar na linha %d e coluna %d:\n", i, j);
	i=i-1;//reduz em 1 os valores que o usuario escolheu na linha e coluna para coloca-los nos lugares corretos da matriz
	j=j-1;
	scanf("%d", &sudoku_usuario[i][j]);
	}else{
		printf("\n\n*******Coluna e/ou linha invalida.*******\n\n");
	}

    check_list();//puxa a função checklist para garantir que o usuario não tentou alterar um numero que não devia
	
	printf("\n\n****Digite 1 para continuar a jogar****\n****Ou 2 para encerrar o jogo.****\n");
	scanf("%d", &opcao2); //encerra ou continua o do-while
    printf("\n\n\n\n\n\n\n");

	}while(opcao2!=2);

	resultado();

	printf("\n\n\n\nObrigado por ter jogado sudoku com a gente esperamos que tenha se divertido com o jogo, até a próxima.\n\n\n");

	return 0;
}
