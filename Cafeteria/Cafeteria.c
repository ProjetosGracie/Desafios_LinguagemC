#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void comeco(char nome[20], char estudante[5], char bebida[11], char *tamanho, int *quantidade, char aluno[5]){
    printf("Digite o seu nome: ");
    scanf("%s", nome);

    printf("Digite se é estudante(Sim ou Nao): ");
    scanf("%s", estudante);

    printf("Tipo de bebida (Chocolate, Agua ou Cafe): ");
    scanf("%s", bebida);

    printf("Digite o tamanho(P,M ou G): ");
    scanf(" %c", tamanho);

    printf("Digite a quantidade: ");
    scanf("%d", quantidade);

    printf("Digite se é aluno do FIAP(Sim ou Nao): ");
    scanf("%s", aluno);
}

float valorPedido(char bebida[11], char tamanho, int quantidade){
    float preco;
    if(strcmp(bebida,"Chocolate")==0){
        if(tamanho == 'P'){
            preco = 5.5;
        }else if(tamanho == 'M'){
            preco = 7.0;
        }else{
            preco = 8.5;
        }
    }
    else if(strcmp(bebida,"Agua")==0){
        if(tamanho == 'P'){
            preco = 2.0;
        }else if(tamanho == 'M'){
            preco = 5.0;
        }else{
            preco = 8.0;
        }
    }
    else if(strcmp(bebida,"Cafe")==0){
        if(tamanho == 'P'){
            preco = 4.0;
        }else if(tamanho == 'M'){
            preco = 5.5;
        }else{
            preco = 7.0;
        }
    }else{
        printf("Erro no sistema\n");
        return -1;
    }

    float precoUnitario = preco*quantidade;
    return precoUnitario;
}

float desconto(char aluno[5], float precounitario){
    float valorDesconto = 0;
    if(strcmp(aluno,"Sim")==0 && precounitario > 15){
        valorDesconto = 10;
    }
    return valorDesconto;
}

const char* brinde(float precototal){
    if(precototal >= 20){
        return "Voce ganhou um brinde";
    }else{
        return "Voce nao ganhou um brinde";
    }
}

void recibo(char nome[20], char bebida[11], char tamanho, int quantidade, float valorDesconto, float total, const char* mensagemBrinde){
    printf("\n--- Recibo ---\n");
    printf("Nome: %s\n", nome);
    printf("Bebida: %s (%c)\n", bebida, tamanho);
    printf("Quantidade: %d\n", quantidade);
    printf("Desconto: %.0f%%\n", valorDesconto);
    printf("Total: R$ %.2f\n", total);
    printf("Brinde: %s\n", mensagemBrinde);
}

int main(){
    char nome[20], estudante[5], bebida[11], aluno[5];
    char tamanho;
    int quantidade;

    comeco(nome, estudante, bebida, &tamanho, &quantidade, aluno);

    float precoUnitario = valorPedido(bebida, tamanho, quantidade);
    float valorDesconto = desconto(aluno, precoUnitario);
    float total = precoUnitario - (precoUnitario * valorDesconto / 100);
    const char* mensagemBrinde = brinde(total);

    recibo(nome, bebida, tamanho, quantidade, valorDesconto, total, mensagemBrinde);

    return 0;
}