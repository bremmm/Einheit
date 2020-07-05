#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#define ANSI_COLOR_BLUE         "\x1B[94m"
#define ANSI_COLOR_RESET        "\x1b[0m"
#define ANSI_COLOR_RED              "\x1b[91m"
#define ANSI_COLOR_YELLOW       "\x1b[93m"
#define ANSI_COLOR_LIGHT_MAGENTA "\x1b[95m"

void batalha (int vmonstro, int dmonstro, char monstro[])
{
    extern int vida;
    extern int dano;
    extern int ouro;
    int x,y,z;
    float t;
    static int v=0;
    srand(time(NULL));
    if(v == 0)
    {
        system("cls");
        vod();
        printf("Uma batalha se inicia! O sistema de batalha eh baseado em turnos.\n");
        printf("Voce podera atacar uma vez por turno, e o monstro o mesmo.\n");
        printf("Seu dano eh baseado no dano minimo possivel que você pode possuir,\n");
        printf("E seu dano atual possuido(%d)\n",dano);
        printf("Pressione qualquer tecla para continuar.\n");
        v++;
    }
    getch();
    system("cls");
    vod();
    printf("%s pretendem arrancar suas viceras e comer ao cair da noite.\n",monstro);
    printf("A batalha se inicia.\n\n");
    printf("Pressione qualquer tecla para continuar.\n");
    getch();
    system("cls");

    do
    {
        if (vida > 0)
        {
            char state;
            system("cls");
            vod();
            bat2(vmonstro, monstro);
            //FUNCAO BAT, BATALHA, QUE MOSTRA OS ATAQUES QUE VOCE PODE FAZER COM CADA HEROI
            bat();
            state = getch();
            if(state == '1')
            {
                int r=0;
                int d, dm;
                r = 1 + rand() % (2 - 1 + 1);
                //NUMERO ALEATORIO PARA VER SE VAI TER CONTRA ATAQUE OU NÃO
                if(r == 1)
                {
                    d = 30 + rand() % (dano - 30 + 1);
                    dm = 10 + rand() % (30 - 10 + 1);
                    printf("\n");
                    printf("Thoradir atacou e deu %d de dano, mas recebeu um contra ataque!\n", d);
                    vmonstro -= d;
                    printf("Perdendo %d de vida!\n", dm);
                    vida -= dm;
                    getch();
                }
                else if(r == 2)
                {
                    d = 20 + rand() % (dano - 20 + 1);
                    printf("\n");
                    printf("Thoradir atacou furiosamente!\n");
                    printf("Causou %d de dano\n", d);
                    getch();
                    vmonstro -= d;
                }

            }
            else if(state == '2')
            {

                int d;
                d = 20 + rand() % (dano - 20 + 1);
                printf("\n");
                printf("Grigor ataca a distancia com uma bola de fogo!\n");
                printf("Causando %d de dano!\n", d);
                getch();
                vmonstro -= d;

            }
            else if(state == '3')
            {
                int d;
                d = 20 + rand() % (40 - 20 + 1);
                printf("\n");
                printf("Sariel ataca rapidamente, seus ataques causam menos danos mas nao podem ser revidados!\n");
                printf("Causando %d de dano!\n", d);
                vmonstro -= d;
                getch();
            }
        }
        if (vmonstro > 0)
        {
            system("cls");
            vod();
            bat2(vmonstro, monstro);
            printf("Eh o turno do monstro atacar!\n");
            int d;
            d =  35 + rand() % (dmonstro - 35 + 1);
            printf("\nO monstro ataca e causa %d de dano!", d);
            vida -= d;

            getch();
        }
        //VERIFICAÇÃO DE VIDA DE AMBOS
        if(vmonstro <=0 && vida > 0)
        {
            printf("\nO MONSTRO FOI DERROTADO COM SUCESSO!\n");
            getch();
            return f_pos_goblin();
        }
        else if(vida <= 0)
        {
            system("cls");
            printf("\nSeu time foi massacrado perante o(s) %s.\n",monstro);
            printf("\nTodos morreram, a jornada chega ao fim.");
            printf("\nFim de jogo.");
            printf("\n\nPressione para sair.");
            getch();
            exit(0);
        }
        //A BATALHA ACABA QUANDO ALGUM DOS DOIS MORREM
    }
    while(vmonstro > 0 && vida > 0);
}

void bat(void)
{
    // OPÇOES DE COMBATE
    printf("1 - Atacar com machado(Thoradir, ataque forte corpo-a-corpo)\n");
    printf("2 - Atacar com magia(Grigor, ataque a longa distancia)\n");
    printf("3 - Atacar rapidamente(Sariel, ataque corpo-a-corpo)\n");
}

void bat2(int vmonstro, char monstro[])
{
    //VIDA DO MONSTRO APARECERÁ NA TELA
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %s\n",monstro);
    printf(ANSI_COLOR_LIGHT_MAGENTA "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|----------|\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %c " ANSI_COLOR_RESET, 3);
    printf("%d ",vmonstro);
    printf(ANSI_COLOR_LIGHT_MAGENTA "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|----------|\n" ANSI_COLOR_RESET);
    printf("\n");
}
