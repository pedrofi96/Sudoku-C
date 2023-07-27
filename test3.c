#include <stdio.h>
#include <string.h> //biblioteca com string sera necessaria para fazer a comparação do jogo do usuario com o jogo completo para saber se o usuario fez o jgoo certo.
#include <stdlib.h>
#include <locale.h>
//variaveis globais, estarã\o em todas a funções não sendo necessario incluir elas em cada uma das funções.
int sudoku_resposta[9][9];
int sudoku_jogo[9][9];  
int sudoku_usuario[9][9];
int facil(){
	
	int i,j;
	int sudoku_facil[9][9] ={{ 5, 4, 0, 0, 2, 0, 8, 0, 6},
                         { 0, 1, 9, 0, 0, 7, 0, 0, 3},
                         { 0, 0, 0, 3, 0, 0, 2, 1, 0},
                         { 9, 0, 0, 4, 0, 5, 0, 2, 0},
                         { 0, 0, 1, 0, 0, 0, 6, 0, 4},
                         { 6, 0, 4, 0, 3, 2, 0, 8, 0},
                         { 0, 6, 0, 0, 0, 0, 1, 9, 0},
                         { 4, 0, 2, 0, 0, 9, 0, 0, 5},
                         { 0, 9, 0, 0, 7, 0, 4, 0,2}};
	int sudoku_facil_resolvido[9][9] = {{ 5, 4, 3, 9, 2, 1, 8, 7, 6},
                                        { 2, 1, 9, 6, 8, 7, 5, 4, 3},
                                     	{ 8, 7, 6, 3, 5, 4, 2, 1, 9},
                                     	{ 9, 8, 7, 4, 6, 5, 3, 2, 1},
                                   	 	{ 3, 2, 1, 7, 9, 8, 6, 5, 4},
                                     	{ 6, 5, 4, 1, 3, 2, 9, 8, 7},
                                    	{ 7, 6, 5, 2, 4, 3, 1, 9, 8},
                                     	{ 4, 3, 2, 8, 1, 9, 7, 6, 5},
                                    	{ 1, 9, 8, 5, 7, 6, 4, 3, 2}};
	for(i=0;i<9;i++){ 
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j] = sudoku_facil[i][j];
		}
	}
	for(i=0;i<9;i++){ 
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j] = sudoku_facil_resolvido[i][j];
		}
	}
}
int main(){
    int opcao,opcao2;
    int i,j,k,n;
    char txt[20];
	char sair[1];
	setlocale (LC_ALL, "Portuguese"); //Função para adicionar caracteres especiais em portugês nos printf.

    printf ("\n\n********************************* SUDOKU *********************************\n\n\n\n");
    printf("Regras do jogo:\n-Cada fileira deve conter 9 numeros de 1 a 9 sem repeti-los. \n-Cada linha deve conter 9 numeros de 1 a 9 sem repeti-los. \n-Cada quadrado com 9 espaços deve conter 9 digitos de 1 a 9 sem repeti-los \n");
    printf ("-Ao final do jogo caso consiga completar o jogo você vence.\n");

    //comando para repetir a pergunta sobre a dificuldade para caso o usuario de um comando invalido.
    opcao=1;
	while(opcao<3){
	
	printf ("\nDigite um numero para a dificuldade que deseja jogar\nDigite 1 para jogar no fácil, 2 para jogar no medio ou 3 para jogar no dificil.\n");
	scanf ("%d", opcao);
	switch(opcao){

	case 1:
		facil(); //puxa resultado da função fácil e iguala ao jogo do usuario
		break;
		
	default:
		printf("\n\nComando invalido.\n\n");
		break;
	}
	}

	
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
    return 0;
}		
