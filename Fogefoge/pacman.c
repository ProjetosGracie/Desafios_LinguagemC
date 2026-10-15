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

 // coloca os dois primeiros numeros do "f" aqui
 fscanf(f,"%d %d", &linhas, &colunas);

  alocamapa();

 // Passar lendo cada linha
 for(int i = 0; i<5; i++){
  fscanf(f,"%s",mapa[i]);
 }
  fclose(f);
}


void imprimemapa(){
    //imprime o mapa
 for (int i = 0; i<linhas;i++){
    printf("%s\n",mapa[i]);
 }
}


int acabou(){
   return 0;
}

void move(char direcao){
   int x;
   int y;

   // ache a posicao do fogefoge
   for(int i =0; i <linhas; i++){
      for(int j = 0; j <colunas; j++){
         if(mapa[i][j] == '@'){
            x =i;
            y = j;
            break;

         }
      }
   }
   // comandos para o pacman andar 
   switch(direcao){
      case 'a':
       mapa[x][y-1] = '@';
       break;
      case 'w':
       mapa[x-1][y] = '@';
       break;
      case 's':
       mapa[x+1][y] = '@';
       break;
      case 'd':
       mapa[x][y+1] = '@';
       break;
   }
   // nao deixa ter dois pacmans no jogo
   mapa[x][y] = '.';
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