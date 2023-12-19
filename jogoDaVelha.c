#include <stdio.h>

int main(){
	
	int l, c, linha, coluna, jogador, cont, vitoria, vitoriaX=0, vitoriaO=0, resposta;
	char jogo[3][3];
	
	do{
		jogador = 1;
		vitoria = 0;
		cont = 0;
		
		for(l = 0; l < 3; l++){
	        for(c = 0; c < 3; c++){
	        	jogo[l][c] = ' ';
	        }
	    }
		
		do{
			printf("\nJogador 1 [X] | Jogador 2 [O]\n");
			
			printf ("\n   0   1   2\n");
			printf ("\n");
			printf ("0  %c | %c | %c \n", jogo[0][0], jogo[0][1], jogo[0][2]);
			printf ("   ----------\n");
			printf ("1  %c | %c | %c \n", jogo[1][0], jogo[1][1], jogo[1][2]);
			printf ("   ----------\n");
			printf ("2  %c | %c | %c \n", jogo[2][0], jogo[2][1], jogo[2][2]);
	            
			printf("\nJogador [%d] Digite a linha que deseja jogar: ", jogador);
			scanf("%d", &linha);
			printf("\nJogador [%d] Digite a coluna que deseja jogar: ", jogador);
			scanf("%d", &coluna);
			
			if(linha > 2 || linha < 0 || coluna > 2 || coluna < 0){
				
				do{
					printf("\nOpcao invalida! Tente novamente\n");
					printf("\nJogador [%d] Digite a linha que deseja jogar: ", jogador);
					scanf("%d", &linha);
					printf("\nJogador [%d] Digite a coluna que deseja jogar: ", jogador);
					scanf("%d", &coluna);
				}while(linha > 2 || linha < 0 || coluna > 2 || coluna < 0);
			}
	
			if(jogo[linha][coluna]=='X' || jogo[linha][coluna]=='O'){
				do{
					printf("\nLocal ocupado! Tente novamente\n");
					printf("\nJogador [%d] Digite a linha que deseja jogar: ", jogador);
					scanf("%d", &linha);
					printf("\nJogador [%d] Digite a coluna que deseja jogar: ", jogador);
					scanf("%d", &coluna);
				}while(jogo[linha][coluna]=='X' || jogo[linha][coluna] == 'O');
			}
			
			printf("\n-----------------------------------------------\n");
			
			cont++;
			
			if(jogador == 1){
				jogo[linha][coluna] = 'X';
				jogador= 2;
			}else{
				jogo[linha][coluna] = 'O';
				jogador= 1;
			}
			
			if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
		       jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
		       jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
		        printf("\nO jogador [1] venceu por linha!!\n");
		        vitoriaX++;
		        vitoria++;
		    }
		
		    if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
		       jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
		       jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O'){
		    	printf("\nO jogador [2] venceu por linha!!\n");
		    	vitoriaO++;
		    	vitoria++;
		    }
		
		 	if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
		       jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
		       jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
		        printf("\nO jogador [1] venceu por coluna!!\n");
		        vitoriaX++;
				vitoria++;   
		    }
		
		    if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
		       jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
		       jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O'){
		        printf("\nO jogador [2] venceu por coluna!!\n");
		        vitoriaO++;
				vitoria++;        
		    }
		
			if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
		        printf("\nO jogador [1] venceu na diagonal!!\n");
		        vitoriaX++;
				vitoria++;      
		    }
		
		    if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O'){
		        printf("\nO jogador [2] venceu na diagonal!!\n");
		        vitoriaO++;
		        vitoria++;
		    }
		
		    if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
		        printf("\nO jogador [1] venceu na diagonal!!\n");
		        vitoriaX++;
		        vitoria++;
		    }
			
			if(jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O'){
		        printf("\nO jogador [2] venceu na diagonal!!\n");
		        vitoriaO++;
		        vitoria++;
		    } 
		}while(cont < 9 && vitoria == 0);
		
		if(vitoria == 0){
			printf("\nA partida nao teve ganhadores, deu velha!!\n");
		}
		
		printf("\n");
		printf ("  %c | %c | %c \n", jogo[0][0], jogo[0][1], jogo[0][2]);
		printf ("  ----------\n");
		printf ("  %c | %c | %c \n", jogo[1][0], jogo[1][1], jogo[1][2]);
		printf ("  ----------\n");
		printf ("  %c | %c | %c \n", jogo[2][0], jogo[2][1], jogo[2][2]);
		
		printf("\n------------------\n");
		printf("|     Placar     |\n");
		printf("------------------\n");
		printf("|JOGADOR [1] | %d |\n", vitoriaX);
		printf("------------------ \n");
		printf("|JOGADOR [2] | %d |\n", vitoriaO);
		printf("------------------\n");
		
		printf("\nDeseja jogar novamente?\n \nDigite [1] Para Sim | [0] Para Nao \n");
		scanf("%d", &resposta);
	}while(resposta == 1);
	
	return 0;
	
}
