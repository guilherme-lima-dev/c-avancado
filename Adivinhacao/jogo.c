#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	int valorChute = 0;
	int tentativa = 0;
	float pontos = 1000.0;
	float pontosPerdidos = 0.0;
	int nivel;
	int numeroTentativas;
	int i;
	int acertou = 0;
	
	
	printf("",setlocale(LC_ALL,""));
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
    while(1){
    	int segundos = time(0);
		srand(segundos);
		int numeroSecreto = rand() % 100;
    	printf("Aperte Ctrl + C para sair!");
		printf("\n\n\n");
		printf("Qual o nível de dificuldade?\n");
	    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	    printf("Escolha um nível e pressione ENTER: ");
	    scanf("%d", &nivel);
	    
	    switch(nivel) {
	        case 1: 
	            numeroTentativas = 20;
	            break;
	        case 2:
	            numeroTentativas = 15;
	            break;
	        default:
	            numeroTentativas = 6;
	            break;
	    }
	    
	  	for(i = 0; i < numeroTentativas; i++){
			printf("Chute um numero e pressione ENTER:");
			scanf("%d", &valorChute);
			
			if(valorChute < 0){
				printf("Não coloque numeros negativos!\n");
				i --;
				
				continue;
			}
			
			if(valorChute == numeroSecreto){
				acertou = 1;		
				break;
			}else if(valorChute > numeroSecreto){
						printf("Você errou!\n");
						printf("Tente um numero menor!\n");
						pontosPerdidos = (valorChute - numeroSecreto) / 2.0;
					}else{
						printf("Você errou!\n");
						printf("Tente um numero maior!\n");
						pontosPerdidos = (numeroSecreto - valorChute) / 2.0;
					}		
				pontos = pontos - pontosPerdidos;
			}
			if(acertou == 1){
				
				printf("\n\n\n");
				
				printf("			      	        | |       | |     | | (_)                			\n");
				printf("	  ___ ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___ 			\n");
				printf("	 / __/ _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __|		\n");
				printf("	| (_| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\			\n");
				printf("	 \\___\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/	\n");
				printf("	                  __/ |                                                  			\n");
				printf("	                 |___/ 																\n");
				printf("\n\n\n");
				
				printf("Parabéns, você ganhou!!\n\n");
	
			}else{
				pontos = 0;
		        printf("\n\n\n");			
				printf("       \\|/ ____ \\|/    \n");   
		        printf("        @~/ ,. \\~@      \n");   
		        printf("       /_( \\__/ )_\\    \n");   
		        printf("          \\__U_/        \n");
		        printf("\n\n\n");
				printf("Você perdeu! Tente novamete!!\n\n");
	
				
			}
			printf("Você fez %.2f pontos!\n\n\n\n", pontos);
	}
}
