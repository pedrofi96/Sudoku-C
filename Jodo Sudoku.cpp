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
    return 0;
}

int medio(){
	int i,j;
	int sudoku_medio[9][9] ={{ 0, 0, 0, 7, 1, 0, 0, 0, 0},
                          { 0, 2, 0, 0, 0, 3, 0, 0, 0},
                          { 0, 9, 0, 5, 0, 2, 0, 7, 3},
                          { 0, 0, 0, 0, 0, 0, 0, 6, 0},
                          { 6, 8, 0, 0, 5, 9, 0, 0, 0},
                          { 2, 5, 4, 0, 3, 6, 1, 0, 0},
                          { 0, 3, 0, 0, 0, 7, 0, 0, 9},
                          { 1, 6, 0, 0, 0, 5, 0, 0, 0},
                          { 4, 7, 0, 0, 0, 0, 6, 8, 0}};

	int sudoku_medio_resolvido[9][9] ={{ 3, 4, 5, 7, 1, 8, 9, 2, 6},
                                    { 7, 2, 6, 4, 9, 3, 8, 5, 1},
                                    { 8, 9, 1, 5, 6, 2, 4, 7, 3},
                                    { 9, 1, 3, 2, 7, 4, 5, 6, 8},
                                    { 6, 8, 7, 1, 5, 9, 3, 4, 2},
                                    { 2, 5, 4, 0, 3, 6, 1, 0, 0},
                                    { 5, 3, 8, 6, 4, 7, 2, 1, 9},
                                    { 1, 6, 2, 9, 8, 5, 7, 3, 4},
                                    { 4, 7, 9, 3, 2, 1, 6, 8, 5}};
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j] = sudoku_medio[i][j];
		}
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j] = sudoku_medio_resolvido[i][j];
		}
	}

    return 0;
}

int dificil(){
	int i,j;
	int sudoku_dificil[9][9] = {{ 0, 0, 0, 0, 0, 0, 0, 7, 0},
                             { 0, 6, 0, 3, 0, 0, 1, 0, 5},
                             { 3, 0, 4, 0, 0, 0, 2, 0, 0},
                             { 0, 5, 0, 0, 9, 6, 0, 2, 0},
                             { 0, 0, 8, 0, 0, 5, 0, 0, 0},
                             { 4, 0, 0, 8, 0, 0, 0, 0, 7},
                             { 5, 3, 1, 9, 0, 0, 0, 0, 0},
                             { 0, 0, 9, 0, 0, 0, 0, 8, 0},
                             { 8, 2, 0, 6, 0, 0, 4, 5, 0}};
	int sudoku_dificil_resolvido[9][9] = {{ 1, 8, 5, 4, 2, 9, 6, 7, 3},
                                        { 9, 6, 2, 3, 7, 8, 1, 4, 5},
                                        { 3, 7, 4, 5, 6, 1, 2, 9, 8},
                                        { 7, 5, 3, 1, 9, 6, 8, 2, 4},
                                        { 2, 1, 8, 7, 4, 5, 9, 3, 6},
                                        { 4, 9, 6, 8, 3, 2, 5, 1, 7},
                                        { 5, 3, 1, 9, 8, 4, 7, 6, 2},
                                        { 6, 4, 9, 2, 5, 7, 3, 8, 1},
                                        { 8, 2, 7, 6, 1, 3, 4, 5, 9}};
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_usuario[i][j] = sudoku_dificil[i][j];
		}
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
    		sudoku_resposta[i][j] = sudoku_dificil_resolvido[i][j];
		}
	}

    return 0;
}
int resultado(){
    int i,j;
	if (for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                sudoku_usuario[i][j] = sudoku_resposta[i][j];
            }}
	)
		printf("\nParabéns por ter completado o jogo de sudoku corretamente.\n");
	}else{
		printf("\nInfelizmente o jogo não foi concluido corretamente. salvaremos ele em uma arquivo de texto apra que vc possa comparar com a resposta do jogo.");
	}
	return 0;
}
int main(){
    int opcao,opcao2;
    int i,j, k,n;
    char txt[20];
	char sair[4];
	setlocale (LC_ALL, "Portuguese"); //Função para adicionar caracteres especiais em portugês nos printf.

    printf ("\n\n********************************* SUDOKU *********************************\n\n\n\n");
    printf("Regras do jogo:\n-Cada fileira deve conter 9 numeros de 1 a 9 sem repeti-los. \n-Cada linha deve conter 9 numeros de 1 a 9 sem repeti-los. \n-Cada quadrado com 9 espaços deve conter 9 digitos de 1 a 9 sem repeti-los \n");
    printf ("-Ao final do jogo caso consiga completar o jogo você vence.\n");

   do{ //comando para repetir a pergunta sobre a dificuldade para caso o usuario de um comando invalido.

	printf ("\nDigite um numero para a dificuldade que deseja jogar\nDigite 1 para jogar no fácil, 2 para jogar no medio ou 3 para jogar no dificil.\n");
	scanf ("%d", opcao);
	switch(opcao){

	case 1:
		sudoku_usuario = facil(); //puxa resultado da função fácil e iguala ao jogo do usuario
		break;
	case 2:
		sudoku_usuario =medio(); //puxa resultado da função medio e iguala ao jogo do usuario
		break;
	case 3:
		sudoku_usuario= dificil(); //puxa resultado da função dificil e iguala ao jogo do usuario
		break;
	default:
		printf("\n\nComando invalido.\n\n");
		break;
	}
	}while(opcao>3);


		//comando necessario para imprimir a matriz do sudoku na tela do usuário na tela:
		//comando para o usuario adicionar novos numeros na matriz esses comandos devem ficar em loop até o usuario decidir quer não quer continuar.
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

	printf("\nDigite um numero de 1 a 9 para escolher qual coluna você quer adicionar um numero:\n");
	scanf ("%d", &k);
	printf("\nDigite um numero de 1 a 9 para escolher qual linha do jogo você quer adicionar um numero:\n");
	scanf("%d", &n);
	k=k-1;
	n=n-1;

	if(0<= k < 9 && 0<= n <9){
	k=k+1;
	n=n+1;
	printf("\nDigite que um numero de 1 a 9 para adicionar na coluna %d e linha %d:\n", k ,n);
	k=k-1;
	n=n-1;
	scanf("%d", &sudoku_usuario[k][n]);

	} else{
		printf("\nColuna e/ou linha invalida.\n");
	}
	printf("digite c para continuar ou s para encerrar o jogo.");
	scanf("%s", &sair);
	strcmp

	opcao2=8705987654;
	}while(opcao2!= );

	//comando para o usuario adicionar novos numeros na matriz esses comandos devem ficar em loop até o usuario decidir quer não quer continuar.


	// e depois seria bom um if else para mostrar o resultado : "parabens você concluiu o jogo perfeitamente" ou
	//"infelizmente jogador não conseguiu completar todo o sudoku corretamente" gostaria de tente novamente.

	//não permitir que o usuario altere os numeros iniciais e coloca-los em negrito.

	resultado(); //traz a função resultado para
	printf("\nObrigado por ter jogado sudoku com a gente esperamos que tenha se divertido com o jogo, até a próxima.");

	return 0;
}
