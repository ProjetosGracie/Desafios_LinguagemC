struct mapa{
// Papel que aponta para uma lista de papels, e cada um desses aponta para um texto
    char** matriz;
// guarda a quantidade de linhas do mapa.
    int linhas;
// guarda a quantidade de colunas.
    int colunas;
};

// Cria um apelido pra struct 
typedef struct mapa MAPA;

struct posicao{
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m,POSICAO* p, char c);
