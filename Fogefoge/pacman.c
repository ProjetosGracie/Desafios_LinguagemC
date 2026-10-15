#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

struct mapa m;

void liberamapa(){
 // Libera da alo cacao na memoria 
 for(int i =0; i <m.linhas; i++){
    free(m.matriz[i]);
 }
 free(m.matriz);
}

void alocamapa(){
 // Alocação dinamica na memoria 
 // reserve um espaço para linhas, devolve o endereço e guarda isso em mapa
 m.matriz = malloc(sizeof(char*)*m.linhas);
 // para cada linha, reserva espaço para o texto
 for(int i = 0; i<m.linhas;i++){ 
    m.matriz[i] = malloc(sizeof(char)*(m.colunas+1));  // +1 é para o caractere especial 
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

 // coloca os dois primeiros numeros do "f" aqui
 fscanf(f,"%d %d", &(m.linhas), &(m.colunas));

  alocamapa();

 // Passar lendo cada linha
 for(int i = 0; i<5; i++){
  fscanf(f,"%s",m.matriz[i]);
 }
  fclose(f);
}


void imprimemapa(){
    //imprime o mapa
 for (int i = 0; i<m.linhas;i++){
    printf("%s\n",m.matriz[i]);
 }
}


int acabou(){
   return 0;
}

void move(char direcao){
   int x;
   int y;

   // ache a posicao do fogefoge
   for(int i =0; i <m.linhas; i++){
      for(int j = 0; j <m.colunas; j++){
         if(m.matriz[i][j] == '@'){
            x =i;
            y = j;
            break;

         }
      }
   }
   // comandos para o pacman andar 
   switch(direcao){
      case 'a':
       m.matriz[x][y-1] = '@';
       break;
      case 'w':
       m.matriz[x-1][y] = '@';
       break;
      case 's':
       m.matriz[x+1][y] = '@';
       break;
      case 'd':
       m.matriz[x][y+1] = '@';
       break;
   }
   // nao deixa ter dois pacmans no jogo
   m.matriz[x][y] = '.';
}

int main(){
      
 lemapa();
 
 do{
  imprimemapa();

  char comando;
  scanf(" %c",&comando);
  move(comando);
  
 }while(!acabou());
 liberamapa();
}   