#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

typedef struct bolsa itens;

struct bolsa{
int ouro;
int pocoes;
};

int main (void)
{
    itens loja;
printf("Você recebeu 50 de ouro, e duas pocoes de vida");

    loja.ouro = 50;
    loja.pocoes = 2;

    printf("%d , %d", loja.ouro, loja.pocoes);
}



