#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>


int f_alquimista(void);
int f_castelo(void);
int f_ferreiro(void);
int f_city(void);

enum cidadela {alquimista, castelo, ferreiro, city};

int cidade(void)
{
    setlocale(LC_ALL, "");
    int (*cidadela[4])(void);

    enum cidadela estado = city;

    cidadela[alquimista] = f_alquimista;
    cidadela[castelo] = f_castelo;
    cidadela[ferreiro] = f_ferreiro;
    cidadela[city] = f_city;

    do
    {
        estado = cidadela[estado]();
    }
    while(estado != 'city');

    return 0;

}
int f_city (void)
{
    FILE *desc_cidade, *local_cidade;
    char state;
    char f;
    int ouro;
    int t=time(NULL);
    system ("cls");
    static int i=0;
    if ( i == 0)
    {
        i = 1;
        local_cidade = fopen("historia\\Cidade\\cidade_desc.txt","r");
        while(fscanf(local_cidade, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }
        getch();
    }

    do
    {
        system ("cls");
        vod();
        desc_cidade = fopen("historia\\Cidade\\cidade_local.txt","r");
        while(fscanf(desc_cidade, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }
        state = getch();
    }
    while(state <= '0' || state > '4');
    if(state == '1') return ferreiro;
    else if (state == '2') return alquimista;
    else if (state == '3') return castelo;
    else if (state == '4') return estrada();

}



int f_ferreiro(void)
{
    FILE *desc_ferreiro, *local_ferreiro;
    char state;
    extern int vida;
    extern int dano;
    extern int ouro;
    char f;
    static int i=0;
    int t=time(NULL);
    system ("cls");
    if (i == 0)
    {
        i = 1;
        desc_ferreiro = fopen("historia\\Cidade\\ferreiro_desc.txt","r");
        while(fscanf(desc_ferreiro, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }
        getch();
    }

    do
    {
        system ("cls");
        vod();
        local_ferreiro = fopen("historia\\Cidade\\ferreiro_local.txt","r");
        while(fscanf(local_ferreiro, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }
        state = getch();
    }
    while(state <= '0' || state > '4');
    //VERIFICA SE VOCE TEM DINHEIRO SUFICIENTE PARA COMPRAR O ITEM
    if(state == '1')
    {
        if(ouro >=20)
        {
            system("cls");
            printf("Item comprado com sucesso!");
            dano +=10, ouro -=20;
            getch();
            return ferreiro;
        }
        else
            system("cls");
        printf("Você não tem ouro suficiente!");
        getch();
        return ferreiro;

    }
    else if (state == '2')
    {
        if(ouro >=9)
        {
            system("cls");
            printf("Item comprado com sucesso!");
            dano +=5, ouro -=9;
            getch();
            return ferreiro;
        }
        else
            system("cls");
        printf("Você não tem ouro suficiente!");
        getch();
        return ferreiro;
    }
    else if (state == '3')
    {
        if(ouro >=110)
        {
            system("cls");
            printf("Item comprado com sucesso!");
            dano +=35, ouro -=110;
            getch();
            return ferreiro;
        }
        else
            system("cls");
        printf("Você não tem ouro suficiente!");
        getch();
        return ferreiro;
    }
    else if (state == '4') return city;
}

int f_castelo(void)
{
    static int c = 0;
    if(c == 0)
    {
        c++;
        FILE *desc_castelo, *local_castelo;
        char state;
        char f;
        int ouro;
        int t=time(NULL);
        system ("cls");
        static int i;
        if (i == 0)
        {
            i++;
            desc_castelo = fopen("historia\\Cidade\\castelo_desc.txt","r");
            while(fscanf(desc_castelo, "%c", &f) !=  EOF)
            {
                printf("%c",f);
            }
            getch();
        }
        do
        {
            system ("cls");
            vod();
            local_castelo = fopen("historia\\Cidade\\castelo_local.txt","r");
            while(fscanf(local_castelo, "%c", &f) !=  EOF)
            {
                printf("%c",f);
            }
            state = getch();
        }
        while(state <= '0' || state > '2');

        if(state == '1')
        {
            system ("cls");
            vod();
            local_castelo = fopen("historia\\Cidade\\relato_rei.txt","r");
            while(fscanf(local_castelo, "%c", &f) !=  EOF)
            {
                printf("%c",f);
            }
            getch();
            return city;

        }
        else if (state == '2') return city;
    }
    else
        system("cls");
        printf("Voce ja visitou esse lugar, nao tem porque ir incomodar o rei novamente.\n");
        getch();
        return city;
}


int f_alquimista(void)
{
    FILE *desc_castelo, *local_castelo;
    char state;
    char f;
    int ouro;
    static int i;
    int t=time(NULL);
    system ("cls");
    if(i == 0)
    {
        i++;
        desc_castelo = fopen("historia\\Cidade\\alquimista_desc.txt","r");
        while(fscanf(desc_castelo, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }
        getch();
    }
    do
    {
        system ("cls");
        vod();
        local_castelo = fopen("historia\\Cidade\\alquimista_local.txt","r");
        while(fscanf(local_castelo, "%c", &f) !=  EOF)
        {
            printf("%c",f);
        }

        state = getch();
    }
    while(state <= '0' || state > '5');

    if(state == '1')
    {
        extern int vida;
        extern int ouro;
        if(ouro >=20)
        {
            system("cls");
            printf("Item comprado com sucesso! Sua vida aumentou.");
            vida +=25, ouro -=20;
            getch();
            return alquimista;
        }
        else
            system("cls");
        printf("Você não tem ouro suficiente!");
        getch();
        return alquimista;
    }
    else if (state == '2')
    {
        extern int vida;
        extern int ouro;
        if(ouro >=45)
        {
            system("cls");
            printf("Item comprado com sucesso! Sua vida aumentou.");
            vida +=50, ouro -=45;
            getch();
            return alquimista;
        }
        else
            system("cls");
        printf("Você não tem ouro suficiente!");
        getch();
        return alquimista;
    }//Algumas partes da historia não puderam ser implementadas, talvez em um proximo semestre.
    else if (state == '3')
    {
        setlocale(LC_ALL, "");
        system("cls");
        printf("Você não tem dinheiro suficiente, aperte para continuar");
        getch();
        return alquimista;
    }
    else if (state == '4')
    {
        if(ouro >=35)
        {
            extern int dano;
            extern int ouro;
            system("cls");
            printf("Item comprado com sucesso! Seu dano aumentou.");
            dano +=20, ouro -=35;
            getch();
            return alquimista;
        }
        else
            system("cls");
        printf("Você não tem ouro suficiente!");
        getch();
        return alquimista;
    }
    else if (state == '5') return city;
}


