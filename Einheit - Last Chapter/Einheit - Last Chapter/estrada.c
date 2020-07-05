#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int f_estrada_dia1 (void);
int f_estalagem (void);
int f_pre_globin(void);
int f_goblin_matar(void);
int f_goblin_pagando(void);
int goblin_intimidando(void);
int f_pre_goblin2(void);
int f_pos_goblin(void);
int f_sem_dinheiro(void);

//essa variavel é responsavel para definir a dificuldade de intimidar os goblins.
 int gob=2;
enum parte {estrada_dia1, estalagem, pre_globin, goblin_matar, goblin_pagando, pre_goblin2, pos_goblin, sem_dinheiro};

int estrada (void)
{
    system("cls");

    int (*parte[8])(void);

    enum parte estado = estrada_dia1;

    parte[estrada_dia1] = f_estrada_dia1;
    parte[estalagem] = f_estalagem;
    parte[pre_globin] = f_pre_globin;
    parte[pre_goblin2] = f_pre_goblin2;
    parte[goblin_matar] = f_goblin_matar;
    parte[goblin_pagando] = f_goblin_pagando;
    parte[pos_goblin] = f_pos_goblin;
    parte[sem_dinheiro] = f_sem_dinheiro;

    do
    {
        estado = parte[estado]();
    }
    while(parte != 'estrada_dia1');
    return 0;
}

int f_estrada_dia1(void)
{
    extern int vida;
    extern int dano;
    extern int ouro;
    FILE *estrada1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        estrada1 = fopen("historia\\Estrada\\Estrada_dia_1.txt","r");
        while(fscanf(estrada1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');

    if(state == '1')
    {
        // VERIFICA SE VOCE TEM DINHEIRO O SUFICIENTE PARA ESSA AÇÃO.
        if(ouro >= 25)
        {
            return estalagem;
        }
        else
            // SUA VIDA É DESCONTADA POR CONTA DA SUA AÇÃO.
            dano, ouro,vida-=20;
        system("cls");
        vod();
        printf("Você estava sem dinheiro para dormir na estalagem, e todos tiveram que dormir em maio a mata.\n");
        printf("Ao acordar cansados, com frio e com fome, todos perderam 20 de vida.\n");
        printf("Tecle para continuar.");
        getch();
        return pre_goblin2;
    }
}

int f_estalagem(void)
{
    extern int vida;
    extern int dano;
    extern int ouro;
    FILE *estrada1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    // COMO É NECESSARIO GASTAR DINHEIRO PARA DORMIR NA ESTALAGEM, ESSE DINHEIRO É DESCONTADO
    ouro-=25;
    do
    {
        system("cls");
        vod();
        estrada1 = fopen("historia\\Estrada\\Estrada_Estalagem_ desc.txt","r");
        while(fscanf(estrada1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return pre_globin;
}

int f_pre_globin(void)
{
    FILE *go;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        go = fopen("historia\\Estrada\\pre_goblin.txt","r");
        while(fscanf(go,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '3');
    if (state == '1') return goblin_pagando;
    else if (state == '2') return goblin_intimidando();
    else if (state == '3') return goblin_matar;

}

int goblin_intimidando(void)
{
    srand(time(NULL));
    int t;
    int x;
    extern int dano;
    extern int ouro;
    extern int vida;
    extern int gob;
    char state;
    // Nesse arquivo é gerado um numero aleatorio, para que a decisão do NPC seja randomica a cada jogo, ele pode dizer sim, ou não.
    x = 1 + rand() % (gob - 1 + 1);
    //cada vez que o jogador tenta pagar os goblins sem ter dinheiro, se torna muito mais dificil intimidalos.
    if(x == 1)
    {
        FILE *go;
        char a;
        char state;
        setlocale(LC_ALL, "");
        do
        {
            system("cls");
            vod();
            go = fopen("historia\\Estrada\\goblin_intimidando_sucesso.txt","r");
            while(fscanf(go,"%c",&a) != EOF)
            {
                printf("%c",a);
            }
            state = getch();
        }
        while(state < '0' || state > '1');
        if(state == '1') return pos_goblin;
    }

    else if(x >= 2)
    {
        int vmonstro=100, dmonstro=40;
        char monstro[40] = "Goblins";
        FILE *go;
        char a;
        char state;
        setlocale(LC_ALL, "");
        system("cls");
        vod();
        go = fopen("historia\\Estrada\\goblin_intimidando_fail.txt","r");
        while(fscanf(go,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        getch();
        return batalha(vmonstro,dmonstro,monstro);
    }

}

int f_pre_goblin2(void)
{
    FILE *go;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        go = fopen("historia\\Estrada\\pre_goblin2.txt","r");
        while(fscanf(go,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '3');
    if (state == '1') return goblin_pagando;
    else if (state == '2') return goblin_intimidando();
    else if (state == '3') return goblin_matar;
}

int f_goblin_matar(void)
{
    FILE *go;
    char a;
    char state;
    int vmonstro=100, dmonstro=40;
    char monstro[40] = "Goblins";
    setlocale(LC_ALL, "");

    system("cls");
    vod();
    go = fopen("historia\\Estrada\\goblin_brigar.txt","r");
    while(fscanf(go,"%c",&a) != EOF)
    {
        printf("%c",a);
    }
    getch();
    batalha(vmonstro,dmonstro,monstro);

}

int f_goblin_pagando (void)
{//SE VOCE NAO TEM DINHEIRO SUFICIENTE EH MANDADO EMBORA, E NAO DARA PARA VOLTAR AO MESMO LUGAR
    extern int vida;
    extern int ouro;
    extern int gob;
    if(ouro >= 25)
    {
        FILE *go;
        char a;
        char state;
        extern int ouro;
        ouro-=25;
        setlocale(LC_ALL, "");

        system("cls");
        vod();
        go = fopen("historia\\Estrada\\goblin_pagando.txt","r");
        while(fscanf(go,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        getch();
        return pos_goblin;

    }
    else
    vida -= 10;
    system("cls");
    printf("Voce nao teve ouro suficiente para pagar os goblins.\n");
    printf("Eles socam a barriga de Thoradir, fazendo com que ele perca 10 de vida.\n");
    printf("E os mandam embora.\n");
    getch();
    system("cls");
    gob+=2;
    return sem_dinheiro;
}

int f_pos_goblin (void)
{
    FILE *go;
    char a;
    char state;
    setlocale(LC_ALL, "");

    system("cls");
    vod();
    go = fopen("historia\\Estrada\\pos_goblin.txt","r");
    while(fscanf(go,"%c",&a) != EOF)
    {
        printf("%c",a);
    }
    getch();
    return floresta();
}

int f_sem_dinheiro(void)
{
    FILE *go;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        go = fopen("historia\\Estrada\\pre_goblin2.txt","r");
        while(fscanf(go,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '3');
    if (state == '2') return goblin_intimidando();
    else if(state == '1')
    {
        system("cls");
        printf("Eles sabem que voce nao tem dinheiro.\n");
        getch();
        system("cls");
        return sem_dinheiro;
    }
    else if (state == '3') return goblin_matar;
}
