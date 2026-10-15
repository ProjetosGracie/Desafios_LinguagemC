void liberamapa();
void lemapa();
void alocamapa();

void imprimemapa();
int acabou();
void move(char direcao);


struct mapa{
// Papel que aponta para uma lista de papels, e cada um desses aponta para um texto
    char** matriz;
// guarda a quantidade de linhas do mapa.
    int linhas;
// guarda a quantidade de colunas.
    int colunas;
};