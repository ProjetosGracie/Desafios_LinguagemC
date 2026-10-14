#include <stdio.h>
#include <stdlib.h>

// Papel que aponta para uma lista de papels, e cada um desses aponta para um texto
char** mapa;
// guarda a quantidade de linhas do mapa.
int linhas;
// guarda a quantidade de colunas.
int colunas;

void liberamapa(){
 // Libera da alocacao na memoria 
 for(int i =0; i <linhas; i++){
    free(mapa[i]);
 }
 free(mapa);
}

void alocamapa(){
 // Alocação dinamica na memoria 
 // reserve um espaço para linhas, devolve o endereço e guarda isso em mapa
 mapa = malloc(sizeof(char*)*linhas);
 // para cada linha, reserva espaço para o texto
 for(int i = 0; i<linhas;i++){ 
    mapa[i] = malloc(sizeof(char)*(colunas+1));  // +1 é para o caractere especial 
 }
}

void lemapa(){
     // Abre o arquivo "mapa.txt" para leitura
 FILE *f;
 f = fopen("mapa.txt", "r");
 if (f ==0){
     printf("Erro ao abrir o arquivo\n");
     exit(1);
 }

 fscanf(f,"%d %d", &linhas, &colunas);

  alocamapa();
  
 // Passar lendo cada linha
 for(int i = 0; i<5; i++){
  fscanf(f,"%s",mapa[i]);
 }
  fclose(f);
}

int main(){
      
 lemapa();
 
 //imprime o mapa
 for (int i = 0; i<5;i++){
    printf("%s\n",mapa[i]);
 }

 liberamapa();
}   