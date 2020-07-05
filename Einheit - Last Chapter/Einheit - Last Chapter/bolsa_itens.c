#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
//https://cboard.cprogramming.com/cplusplus-programming/31905-beep.html
#include <locale.h>
//https://github.com/shiena/ansicolor/blob/master/README.md
#define ANSI_COLOR_BLUE          "\x1B[94m"
#define ANSI_COLOR_RESET         "\x1b[0m "
#define ANSI_COLOR_RED           "\x1b[91m"
#define ANSI_COLOR_YELLOW        "\x1b[93m"
#define ANSI_COLOR_LIGHT_MAGENTA "\x1b[95m"

void vod (void)
{
    //USADO PARA MOSTRAR A VIDA, OURO E DANO DO PERSONAGEM NA PARTE SUPERIOR DIREITA DA TELA
    extern int dano;
    extern int ouro;
    extern int vida;
    extern int gob;
    printf(ANSI_COLOR_LIGHT_MAGENTA "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|--------------|\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %c " ANSI_COLOR_RESET, 3);
    printf("%d /",vida);
    printf(ANSI_COLOR_BLUE " %c " ANSI_COLOR_RESET, 6);
    printf("%d\n", dano);
    printf(ANSI_COLOR_YELLOW "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %c " ANSI_COLOR_RESET, 4);
    printf("%d \n", ouro);
    printf(ANSI_COLOR_LIGHT_MAGENTA "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|--------------|\n" ANSI_COLOR_RESET);
}

