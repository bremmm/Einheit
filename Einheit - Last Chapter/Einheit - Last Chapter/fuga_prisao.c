#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int f_fuga(void);
int f_aceitar_quest (void);
int f_foragido(void);

enum parte {fuga, aceitar_quest, foragido};

int fuga_prisao(void)
{
      system("cls");

    int (*parte[3])(void);

    enum parte estado = fuga;

    parte[fuga] = f_fuga;
    parte[aceitar_quest] = f_aceitar_quest;
    parte[foragido] = f_foragido;

    do
    {
        estado = parte[estado]();
    }
    while(parte != 'fuga');
    return 0;
}

int f_fuga (void)
{
     extern int dano;
    FILE *fuga;
    char a;
    char state;
    setlocale(LC_ALL, "");
    dano+=50;
    do
    {
        system("cls");
        vod();
        fuga = fopen("historia\\fuga_prisao.txt","r");
        while(fscanf(fuga,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '2');

    if(state == '1') return aceitar_quest;
    else if(state == '2') return foragido;
}

int f_aceitar_quest (void)
{
    FILE *fuga;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        fuga = fopen("historia\\aceitar_quest.txt","r");
        while(fscanf(fuga,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return  cidade() ;
}

int f_foragido(void)

{
    FILE *fuga;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        fuga = fopen("historia\\foragido.txt","r");
        while(fscanf(fuga,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') exit(0);

}
