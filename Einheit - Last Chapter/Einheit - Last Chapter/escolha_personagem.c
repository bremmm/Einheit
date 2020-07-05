#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int f_anao(void);
int f_mago(void);
int f_ladino(void);
int f_escolha_classe(void);

enum escolha {anao, mago, ladino, escolha_classe};

int escolha_personagem(void)
{
    system("cls");

    int (*escolha[4])(void);

    enum escolha estado = escolha_classe;

    escolha[anao] = f_anao;
    escolha[mago] = f_mago;
    escolha[ladino] = f_ladino;
    escolha[escolha_classe] = f_escolha_classe;

    do
    {
        estado = escolha[estado]();
    }
    while(estado != 'escolha_classe');
    return 0;
}

int f_anao(void)
{
     Beep(600,200);
    FILE *anao1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do{
        system("cls");
        anao1 = fopen("imagens\\anao.txt","r");
        while(fscanf(anao1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '2');

    if(state == '1') return anao;
    else if(state == '0') return escolha_classe;
}

int f_mago(void)
{
     Beep(600,200);
    FILE *mago1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        mago1 = fopen("imagens\\mago.txt","r");
        while(fscanf(mago1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '2');

    if(state == '1') return mago;
    else if(state == '0') return escolha_classe;
}

int f_ladino(void)
{
     Beep(600,200);
     FILE *ladino1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        ladino1 = fopen("imagens\\ladino.txt","r");
        while(fscanf(ladino1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '2');

    if(state == '1') return ladino;
    else if(state == '0') return escolha_classe;
}

int f_escolha_classe(void)
{
    static int m=0;
    //MUSICA TOCADA NO COMECO
    if(m == 0)
    {
    Beep(600,200);
    Beep(900,150);
    Beep(1000,150);
    Beep(600,150);
    m++;
    }
    FILE *escolha_classe1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        escolha_classe1 = fopen("imagens\\escolha_personagem.txt","r");
        while(fscanf(escolha_classe1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '4');
    if(state == '1') return anao;
    else if(state == '2') return mago;
    else if(state == '3') return ladino;
    else if(state == '0') return main();
    else if(state == '4') return f_historia();

}





