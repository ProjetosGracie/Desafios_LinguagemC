#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void liberamapa(MAPA* m){
 // Libera da alo cacao na memoria 
 for(int i =0; i <m->linhas; i++){
    free(m->matriz[i]);
 }
 free(m->matriz);
}

void alocamapa(MAPA* m){
 // Alocação dinamica na memoria 
 // reserve um espaço para linhas, devolve o endereço e guarda isso em mapa
 m->matriz = malloc(sizeof(char*)*m->linhas);
 // para cada linha, reserva espaço para o texto
 for(int i = 0; i<m->linhas;i++){ 
    m->matriz[i] = malloc(sizeof(char)*(m->colunas+1));  // +1 é para o caractere especial 
 }
}

void lemapa(MAPA* m){
     // Abre o arquivo "mapa.txt" para leitura
 FILE *f;
 f = fopen("mapa.txt", "r");
 if (f ==0){
     printf("Erro ao abrir o arquivo\n");
     exit(1);
 }

 // coloca os dois primeiros numeros do "f" aqui
 fscanf(f,"%d %d", &(m->linhas), &(m->colunas));

  alocamapa(m);

 // Passar lendo cada linha
 for(int i = 0; i<5; i++){
  fscanf(f,"%s",m->matriz[i]);
 }
  fclose(f);
}


void imprimemapa(MAPA* m){
    //imprime o mapa
 for (int i = 0; i<m->linhas;i++){
    printf("%s\n",m->matriz[i]);
 }
}