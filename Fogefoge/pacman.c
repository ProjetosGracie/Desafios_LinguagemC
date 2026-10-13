#include <stdio.h>
#include <stdlib.h>

int main(){
 char mapa[5][10+1];
 // Abre o arquivo "mapa.txt" para leitura
 FILE *f;
 f = fopen("mapa.txt", "r");
 if (f ==0){
     printf("Erro ao abrir o arquivo\n");
     exit(1);
 }

 // Passar lendo cada linha
 for(int i = 0; i<5; i++){
  fscanf(f,"%s",mapa[i]);
 }
 
 //imprime o mapa
 for (int i = 0; i<5;i++){
    printf("%s\n",mapa[i]);
 }
}   