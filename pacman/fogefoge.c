#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

MAPA m;

void liberaMapa(){
  for (int i = 0; i < m.linhas; i++) {
      free(m.mapa[i]);
  }
  free(m.mapa);
}

void alocaMapa(){

  m.mapa = malloc(sizeof(char*) * m.linhas);
  for (int i = 0; i < m.linhas; i++) {
      m.mapa[i] = malloc(sizeof(char) * (m.colunas+1));
  }
}

void leMapa(){

  FILE* f;

  f = fopen("mapa.txt", "r");

  if (f == 0) {
    printf("Erro na leitura do mapa parceiro.\n");
    exit(1);
  }
  fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

  alocaMapa();

  for (int i = 0; i < 5; i++) {

      fscanf(f, "%s", m.mapa[i]);
  }
  fclose(f);
}
void imprimeMapa(){
  for (int i = 0; i < 5; i++) {

    printf("%s\n", m.mapa[i]);

  }
}
int acabou(){
  return 0;
}
void move(char direcao){
  int x,y;

  for (int i = 0; i < m.linhas; i++) {
      for (int j = 0; j < m.colunas; j++) {
          if (m.mapa[i][j] == '@') {
            x = i;
            y = j;
            break;
          }
      }
  }

  switch (direcao) {
    case 'w':
      m.mapa[x-1][y] = '@';
      break;
    case 'a':
      m.mapa[x][y-1] = '@';
      break;
    case 's':
      m.mapa[x+1][y] = '@';
      break;
    case 'd':
      m.mapa[x][y+1] = '@';
      break;
  }
  m.mapa[x][y] = '.';
}
int main() {

  int i=0, j=0;

  leMapa();
  do {
    imprimeMapa();
    char comando;
    scanf(" %c", &comando);
    move(comando);
  } while(!acabou());

  liberaMapa();

  return 0;
}
