#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int dano_sair_prisao (void)
{
    srand(time(NULL));
    extern int vida;
    extern int dano;
    extern int ouro;
    int vida_p = 100;
    int x;
    int state;
    int t;
    int i=0;

//ESSE ARQUIVO EH RESPONSAVEL POR ABRIR UMA PORTA EM DETERMINADA PARTE DO GAME, A PORTA TEM UMA QUANTIDADE DE VIDA, E CONFORME SUAS ACOES A VIDA DECAI.
    do
    {
        x = 10 + rand() % (100 - 10 + 1);
        vida_p = (vida_p - x);
        if (i == 0){
        printf("\t\t\nThoradir soca a porta com toda a sua forca!\n");
        }
        else if(i != 0)
        {
            printf("\nSoca novamente porta\n");
        }
        i++;
        state = getch();
        if(vida_p <= 0)
        {

            printf("A porta foi derrubada!\n");
            getch();
            system("cls");
            vod();
            setlocale(LC_ALL, "");
            printf("Porem Thoradir ferriu sua mao enquanto derrubava a porta. E perdeu 5 de HP");
            dano,ouro,vida-=5;
            getch();
            return fuga_prisao();
        }
    }
    while(state == '1');





}
