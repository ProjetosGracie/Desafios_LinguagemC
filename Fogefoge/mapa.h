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

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);

