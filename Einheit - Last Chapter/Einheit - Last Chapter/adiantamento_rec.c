#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int adiantamento (void)
{
    extern int ouro;
    srand(time(NULL));
    int t;
    int x;
    extern int dano;
    extern int ouro;
    extern int vida;
    char state;
// Nesse arquivo é gerado um numero aleatorio, para que a decisão do NPC seja randomica a cada jogo, ele pode dizer sim, ou não.
    x = 1 + rand() % (2 - 1 + 1);

    if(x==1)
    {
       FILE *adiantamento;
    char a;
    char state;
    setlocale(LC_ALL, "");
    dano,ouro += 50, vida;
    do
    {
        system("cls");
        vod();
        adiantamento = fopen("historia\\adiantamento_rec_success.txt","r");
        while(fscanf(adiantamento,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return f_aceitar_quest();
    }
    else if(x==2)
    {
         FILE *adiantamento;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        adiantamento = fopen("historia\\adiantamento_rec_fail.txt","r");
        while(fscanf(adiantamento,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return f_aceitar_quest();
    }
}
