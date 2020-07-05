#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>
typedef struct arma Ferreiro;

struct arma{
int dano;
char nome[50];
int preco;
};
int main (void)
{
    char espada[] = "ola";
    Ferreiro loja[5];

    loja[0].dano = 250;
    loja[0].nome[] = "excalibur";
    loja[0].preco = 1000;

    printf("%d %d %d",loja[0].dano, loja[0].nome,loja[0].preco);
}
