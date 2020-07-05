#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>
#define ANSI_COLOR_BLUE         "\x1B[94m"
#define ANSI_COLOR_RESET        "\x1b[0m"
#define ANSI_COLOR_RED              "\x1b[91m"
#define ANSI_COLOR_YELLOW       "\x1b[93m"

int f_taverna (void);
int f_comemorando_resultados(void);
int f_evitar_b(void);
int f_matar_b(void);
int f_brigar_b(void);
int f_prisao(void);
int f_boatos_prisao(void);
int f_forca_prisao(void);
int f_lockpick_prisao(void);
int f_adiantamento_rec(void);

enum parte {taverna, comemorando_resultados, evitar_b, matar_b, brigar_b, prisao, forca_prisao, lockpick_prisao, adiantamento_rec };

int f_historia (void)
{
    //AUTOMATO PARA NAVEGAR ENTRE AS TELAS DE CADA PARTE DA HISTORIA
    system("cls");
    //USADO PARA LIMPAR A TELA.
    printf("ATENÇÃO!\n");
    printf("Você vai se deparar com os seguintes simbolos durante a gameplay: \n");
    printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, 3);
    printf(" = VIDA\n");
    printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, 4);
    printf(" = OURO\n");
    printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, 6);
    printf(" = POTENCIAL DE DANO \n");
    printf("\n");
    printf("Precione qualquer tecla para continuar.");
    getch();
    system("cls");

    int (*parte[9])(void);

    enum parte estado = taverna;

    parte[taverna] = f_taverna;
    parte[comemorando_resultados] = f_comemorando_resultados;
    parte[evitar_b] = f_evitar_b;
    parte[matar_b] = f_matar_b;
    parte[brigar_b] = f_brigar_b;
    parte[prisao] = f_prisao;
    parte[lockpick_prisao] = f_lockpick_prisao;
    parte[forca_prisao] = f_forca_prisao;
    parte[adiantamento_rec] = f_adiantamento_rec;

    do
    {
        estado = parte[estado]();
    }
    while(parte != 'taverna');
    return 0;
}

f_taverna(void)
{
    FILE *taverna1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        taverna1 = fopen("historia\\taverna.txt","r");
        while(fscanf(taverna1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');

    if(state == '1') return comemorando_resultados;

}

int f_comemorando_resultados(void)
{
    FILE *resultados;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        resultados = fopen("historia\\comemorando_resultado.txt","r");
        while(fscanf(resultados,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '3');

    if(state == '1') return evitar_b;
    else if(state == '2') return brigar_b;
    else if(state == '3') return matar_b;

}

int f_evitar_b(void)
{
    FILE *evitar;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {

        system("cls");
        vod();
        evitar = fopen("historia\\evitar_b.txt","r");
        while(fscanf(evitar,"%c",&a) != EOF)
        {
                printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '2');
    if(state == '1') return adiantamento_rec;
    // A f_aceitar_quest está dentro do arquivo "fuga_prisao";
    if(state =='2')
    {
            system("cls");
            vod();
            evitar = fopen("historia\\aceita_rec.txt","r");
            while(fscanf(evitar,"%c",&a) != EOF)
            {
                printf("%c",a);
            }
            getch();
            return f_aceitar_quest();
    }

}

int f_matar_b(void)
{
    FILE *matar;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        matar = fopen("historia\\matar_b.txt","r");
        while(fscanf(matar,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');

    if(state == '1')
    {
        extern int dano;
        extern int ouro;
        system("cls");
        printf("Seus bens foram confiscados, você perdeu ouro e todas as suas armas.");
        getch();
        ouro = 0;
        dano = 0;
        return prisao;
    }


}

int f_brigar_b(void)
{
    FILE *brigar;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        brigar = fopen("historia\\brigar_b.txt","r");
        while(fscanf(brigar,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '3');

    if(state == '1') return adiantamento_rec;
    else if(state == '2')
    {
            FILE *aceita;
            char b;
            system("cls");
            vod();
            aceita = fopen("historia\\aceita_rec.txt","r");
            while(fscanf(aceita,"%c",&b) != EOF)
            {
                printf("%c",b);
            }
            getch();
            return f_aceitar_quest();
    };

}

int f_prisao(void)
{
    FILE *prisao1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        prisao1 = fopen("historia\\prisao.txt","r");
        while(fscanf(prisao1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '2');
    if(state == '2') return forca_prisao;
    else if(state == '1') return lockpick_prisao;
}

int f_forca_prisao(void)
{
     FILE *prisao1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        prisao1 = fopen("historia\\forca_prisao.txt","r");
        while(fscanf(prisao1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return dano_sair_prisao();
}

int f_lockpick_prisao (void)
{

 FILE *prisao1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        prisao1 = fopen("historia\\lockpick_prisao.txt","r");
        while(fscanf(prisao1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return lockpick_sair_prisao();

}

int f_adiantamento_rec (void)
{
    FILE *prisao1;
    char a;
    char state;
    setlocale(LC_ALL, "");
    do
    {
        system("cls");
        vod();
        prisao1 = fopen("historia\\adiantamento_rec.txt","r");
        while(fscanf(prisao1,"%c",&a) != EOF)
        {
            printf("%c",a);
        }
        state = getch();
    }
    while(state < '0' || state > '1');
    if(state == '1') return adiantamento();
}
