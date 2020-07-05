#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>

int lockpick_sair_prisao (void)
{
    srand(time(NULL));

    int lockpick = 3;
    int vida = 100;
    int x;
    int state;
    int t;
    int j=0;
//ESSE ARQUIVO EH RESPONSAVEL POR ABRIR UMA PORTA EM DETERMINADA PARTE DO GAME, A PORTA TEM UMA QUANTIDADE DE VIDA, E CONFORME SUAS ACOES A VIDA DECAI.
    setlocale(LC_ALL, "");
    printf("\nPressione 1(um) para realizar as acoes.\n");
    do
    {
        if(lockpick > 0)
        {
        x = 30 + rand() % (40 - 30 + 1);
        vida = (vida - x);
        printf("\t\t\nUtiliza de um de seus lockpicks para destrancar a porta!\n");
        getch();

        if(vida > 0 && lockpick > 0)
        {
            lockpick--;
            printf("Uma das lockpicks quebrou, restam %d!\n",lockpick);
        getch();
        }
        else if (vida <= 0 && lockpick > 0)
        {
            printf("A porta foi destrancada com sucesso!");
             getch();
            return fuga_prisao();
        }
        }
        else if(lockpick <= 0 && vida > 0)
        {
            setlocale(LC_ALL, "");
            printf("\nSariel nao conseguiu destrancar a porta. Os lockpicks que carregava consigo eram gastos e velhos.");
            printf("\nThoradir vai precisar usar a forca para quebrar a porta.\n");
            getch();
            return dano_sair_prisao();
        }
             state = getch();

    }
    while(state == '1');



}
