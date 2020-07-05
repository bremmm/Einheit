#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int f_pre_floresta(void);

enum parte {pre_floresta};

int floresta(void)
{
    system("cls");

    int (*parte[1])(void);
    enum parte estado = pre_floresta;


    parte[pre_floresta] = f_pre_floresta;

    do
    {
        estado = parte[estado]();
    }
    while(parte != 'pre_floresta');
    return 0;
}

int f_pre_floresta(void)
{


    FILE *go;
    char a;
    char state;
    setlocale(LC_ALL, "");
    system("cls");
    go = fopen("historia\\floresta\\Floresta_desc.txt","r");
    while(fscanf(go,"%c",&a) != EOF)
    {
        printf("%c",a);
    }
    getch();

    do
    {
        system("cls");
        vod();
        go = fopen("historia\\floresta\\pre_floresta.txt","r");
        while(fscanf(go,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if (state == '1')
    {
        system("cls");
        printf("O grupo adentra floresta a dentro, nao imaginando os perigos que os aguardam.\n");
        printf("Infelizmente o que acontece a dentro da floresta vai continuar sendo um misterio.\n");
        printf("Deseje sorte a nossos herois.\n");
        printf("FIM DO CAPITULO UM!\n");
        printf("\n\nObrigado por jogar :)\n");
        exit(0);
    }
}


