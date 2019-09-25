void liberaMapa();
void leMapa();
void alocaMapa();

void move(char direcao);
int acabou();
void imprimeMapa();

struct mapa {
  char** mapa;
  int linhas, colunas;
};

typedef struct mapa MAPA;
