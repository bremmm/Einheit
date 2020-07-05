#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>
#define ANSI_COLOR_LIGHT_YELLOW "\033[1;33m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define ANSI_COLOR_RED   "\x1b[31m"

int f_centauro(void);
int f_dragao(void);
int f_driade(void);
int f_globin(void);
int f_elfo(void);
int f_gazela(void);
int f_grifo(void);


// define valores inteiros, começando em zero, para cada variavel do conjunto.
enum bestiario {centauro, dragao, driade, globin, elfo, gazela, grifo};

int bestiario_automato(void)
{
    // limpando a tela
    system("cls");
    // adaptando caracteres brasileiros
    setlocale(LC_ALL, "");

    // criando vetor de funçoes
    int (*bestiario[7])(void);

    // criando variavel do conjunto e definindo estado inicial
    enum bestiario estado = gazela;

    // definindo funçoes para cada comodo
    bestiario[gazela] = f_gazela;
    bestiario[centauro] = f_centauro;
    bestiario[dragao] = f_dragao;
    bestiario[driade] = f_driade;
    bestiario[globin] = f_globin;
    bestiario[elfo] = f_elfo;
    bestiario[grifo] = f_grifo;

    do
    {
        estado = bestiario[estado]();
    }
    while(estado != 'gazela');

    return 0;
}

int f_gazela(void)
{
    FILE *gazela1, *gazela2;
    char e, f;
    int i=0,j=80;
    char state;
    do
    {
        system("cls");
        gazela1 = fopen("imagens\\bestiario.txt","r");
        while(fscanf(gazela1,"%c",&e) != EOF)
        {
            printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,e);
        }
        gazela2 = fopen("imagens\\pergaminho.txt","r");
        while(fscanf(gazela2,"%c",&f) != EOF)
        {
            if((f == '\n')||( f == '10')||(f == '\r'))
            {
                j = 80;
                i++;
            }
            //VAI PEGAR AS COORDENADAS PEDIDAS E IMPRIMIR A IMAGEM NESSAS COORDENADAS
            //SEMPRE QUE FOR \N, 10 OU \R (QUEBRAS DE LINHA) ELE VAI INCREMENTAR A LINHA, QUANDO SAIR DA FUNÇÃO VAI IMPRIMIR
            //A PROXIMA COLUNA COM O j++;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){j,i});
            j++;

            printf(BOLD ANSI_COLOR_LIGHT_YELLOW "%c" ANSI_COLOR_RESET, f);
        }
        state = getch();
    }
    while(state < '0' || state > '6');

    if(state == '1') return centauro;
    else if(state == '2') return dragao;
    else if(state == '3') return driade;
    else if(state == '4') return globin;
    else if(state == '5') return elfo;
    else if(state == '6') return grifo;
    else if(state == '0') return main();
}

int f_centauro(void)
{
    FILE *centauro1;
    char state;
    char f;
    do
    {
        Beep(600,200);
        system ("cls");
        centauro1 = fopen("imagens\\centauro.txt","r");
        while(fscanf(centauro1, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }
        state = getch();
    }
    while(state <= '0' || state > '1');

    if(state == '1')
    {
        return gazela;
    }
}


int f_dragao(void)
{
    FILE *dragao1;
    char g;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        Beep(600,200);
        system("cls");
        dragao1 = fopen("imagens\\dragao.txt","r");
        while(fscanf(dragao1, "%c", &g) != EOF)
        {
            printf("%c", g);
        }
        state = getch();
    }
    while(state <= '0' || state > '1');

    if(state == '1')
    {
        return gazela;
    }
}

int f_driade(void)
{
    FILE *driade1;
    char h;
    char state;

    do
    {
        Beep(600,200);
        system("cls");
        driade1 = fopen("imagens\\driade.txt","r");
        while(fscanf(driade1, "%c", &h) != EOF)
        {
            printf("%c", h);
        }
        state = getch();
    }
    while(state <= '0' || state > '1');

    if(state == '1')
    {
        return gazela;
    }
}


int f_globin(void)
{
    FILE *globin1;
    char state;
    char i;
    do
    {
        Beep(600,200);
        system("cls");
        globin1 = fopen("imagens\\globin.txt","r");
        while(fscanf(globin1, "%c", &i) != EOF)
        {
            printf("%c", i);
        }
        state = getch();
    }
    while(state <= '0' || state > '1');

    if(state == '1')
    {
        return gazela;
    }
}

int f_elfo(void)
{
    FILE *elfo1;
    char state;
    char j;
    do
    {
        Beep(600,200);
        system("cls");
        elfo1 = fopen("imagens\\elfo.txt","r");
        while(fscanf(elfo1, "%c", &j) != EOF)
        {
            printf("%c", j);
        }
        state = getch();
    }
    while(state <= '0' || state > '1');

    if(state == '1')
    {
        return gazela;
    }
}

int f_grifo(void)
{
    setlocale(LC_ALL, "");
    FILE *grifo1;
    char state;
    char j;
    do
    {
        Beep(600,200);
        system("cls");
        grifo1 = fopen("imagens\\grifo.txt","r");
        while(fscanf(grifo1, "%c", &j) != EOF)
        {
            printf("%c", j);
        }
        state = getch();
    }
    while(state <= '0' || state > '1');

    if(state == '1')
    {
        return gazela;
    }
}


