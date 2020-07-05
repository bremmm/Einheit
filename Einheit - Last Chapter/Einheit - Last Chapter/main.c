#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <locale.h>
#define HISTORIA_H_INCLUDED
//CORES DEFINIDAS E USADAS NO MENU
#define ANSI_COLOR_BLUE         "\x1B[94m"
#define ANSI_COLOR_RESET        "\x1b[0m"
#define ANSI_COLOR_RED              "\x1b[91m"
#define WHITE  "\x1b[37m"
//http://personalizandoc.blogspot.com/2012/11/comando-systemcls-limpando-tela.html
//VÁRIAVEIS GLOBAIS USADAS POR OUTROS ARQUIVOS DO PROJETO.
int ouro = 25;
int dano = 50;
int vida = 100;
int main (void)
{
    //ESTA APRTE DO PROJETO APENAS SERVE PARA LISTAR E APRESENTAR AS FUNÇÕES DO JOGO AO JOGADOR.
    //75 arquivos.
    //1700 linhas de codigos.

    //José Otávio Bremm
    //Lucas Trizzini
    //DEIXAR O COMPILADOR COM CORES DIFERENTES
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    char raca;
    char escolha[100];
    char nome[200];
    char menu;
    int a;
    char enter;
    int t=time(NULL);
    char b,c, d, e, f, g, h, i, j;
    static int cont=0;

    if(cont == 0)
    {
        //USADO PARA DEIXAR A TELA EM TELA CHEIA
        keybd_event(VK_MENU,0x36,0,0);
        keybd_event(VK_RETURN,0x1C,0,0);
        keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
        system("pause > nul");
        t=time(NULL);
        while(time(NULL)-t < 2);

    }
    if(cont == 0)
    {
        printf("\t\t\t\t\t\tAntes de tudo, nos informe seu nome para podermos personalizar seu jogo: ");
        scanf("%s",nome);
        if ((strcmp (nome, "hendrick") == 0) || (strcmp(nome,"Hendrick")==0) || (strcmp(nome,"HENDRICK")==0))
        {
            system("cls");
            printf("\t\t\t\t\t\tBalrog montado em cima do Smaug aparece, voce eh evaporado da face da terra.\n");
            printf("\t\t\t\t\t\t\t\t\t  Fim de jogo\n");
            FILE *youshall;
            youshall = fopen("imagens\\youshall.txt","r");
            while(fscanf(youshall,"%c",&c) != EOF)
            {
                printf("%c",c);
            }
            system("start chrome.exe https://youtu.be/VlaiBeLrntQ?t=36s");
            exit(0);
        }
        else if ((strcmp (nome, "andre") == 0) || (strcmp(nome,"Andre")==0) || (strcmp(nome,"ANDRE")==0)||(strcmp (nome, "muriel") == 0) || (strcmp(nome,"Muriel")==0) || (strcmp(nome,"MURIEL")==0))
        {
            FILE *mordomo;
            mordomo = fopen("imagens\\mordomo.txt","r");
            while(fscanf(mordomo,"%c",&c) != EOF)
            {
                //IRÁ COLORIR AS LETRAS SE FOREM AS SELECIONADAS
                if(c=='@')
                {
                    printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, c);
                }
                else if(c=='&')
                {
                    printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, c);
                }
                else
                    printf("%c",c);
            }
            t=time(NULL);
            while(time(NULL)-t < 3);
        }
        cont++;
    }
    do
    {
        //Abaixo daqui estao todas as imagens presentes no menu, os pilares sao imprimidos pela coordenadas de cada um;
        //o menu também
        // o dragão é apenas imprimido, foi centralizado dentro do proprio txt.
        system("cls");
        FILE *algdom, *algdom2, *algdom3;
        algdom = fopen("imagens\\algdom.txt","r");
        while(fscanf(algdom,"%c",&b) != EOF)
        {
            printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET,b);
        }

        algdom2 = fopen("imagens\\algdom2.txt","r");
        while(fscanf(algdom2,"%c",&c) != EOF)
        {
            printf(ANSI_COLOR_RED "%c"  ANSI_COLOR_RESET,c);
        }

        int m=55,n=25;
        setlocale(LC_ALL, "");
        FILE *menu1;
        char mn;
        menu1 = fopen("imagens//menu.txt","r");
        while(fscanf(menu1,"%c",&mn) != EOF)
        {
            if((mn == '\n')||( mn == '10')||(mn == '\r'))
            {
                n = 25;
                m++;
            }
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){n,m});
            n++;
            if(mn == '1' || mn == '2' || mn == '3' || mn == '4' || mn == '5')
            {
                printf("\x1b[31m""%c"ANSI_COLOR_RESET,mn);
            }
            printf(WHITE"%c"ANSI_COLOR_RESET,mn);
        }

        int i=7,j=1;
        char p1,p2;
        FILE *pilar1, *pilar2;
        pilar1 = fopen("imagens//pilar.txt","r");
        while(fscanf(pilar1,"%c",&p1) != EOF)
        {
            if((p1 == '\n')||( p1 == '10')||(p1 == '\r'))
            {
                j = 1;
                i++;
            }
            //VAI PEGAR AS COORDENADAS PEDIDAS E IMPRIMIR A IMAGEM NESSAS COORDENADAS
            //SEMPRE QUE FOR \N, 10 OU \R (QUEBRAS DE LINHA) ELE VAI INCREMENTAR A LINHA, QUANDO SAIR DA FUNÇÃO VAI IMPRIMIR
            //A PROXIMA COLUNA COM O j++;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){j,i});
            j++;
            printf(WHITE"%c"ANSI_COLOR_RESET,p1);
        }
        int i2=7,j2=115;
        pilar2 = fopen("imagens//pilar.txt","r");
        while(fscanf(pilar2,"%c",&p2) != EOF)
        {
            if((p2 == '\n')||( p2 == '10')||(p2 == '\r'))
            {
                j2 = 115;
                i2++;
            }
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){j2,i2});
            j2++;
            printf(WHITE"%c"ANSI_COLOR_RESET,p2);
        }
        menu = getch();

        if(menu == '2')
        {
            //BEEP, USADO PARA EMITIR SOM.
            Beep(600,200);
            system("cls");
            printf("\n");
            printf("\t\tEinheit eh um tipo de jogo em que os jogadores assumem papeis de personagens e seguem uma historia de acordo com suas escolhas.\n");
            printf("\t\t\t\tTodas as suas escolhas  podem mudar o rumo da historia, e principalmente do final do jogo.\n");
            printf("\t\t\t\t\t\tSeja paciente, e pense bem antes de cada acao. Bom jogo!");
            printf("\n");
            printf("\n");
            printf("\t\t\t\t\t\tPressione qualquer tecla para voltar.");
            getch();
        }
        else if(menu == '3')
        {
            Beep(600,200);
            system("cls");
            printf("\n");
            printf("\t\t\t\t\tJogo desenvolvido para capacitacao e avalicao na materia de algoritmos 2, UTFPR-DV\n");
            printf("\n");
            printf("\t\t\t\t\tDesenvolvedores : Jose Otavio Bremm, 2003295\n");
            printf("\t\t\t\t\t                  Lucas Trizzini, 2002450\n");
            printf("\n");
            printf("\t\t\t\t\tAgradecimentos  : ");
            printf(ANSI_COLOR_RED "Muriel Mazzeto\n"ANSI_COLOR_RESET);
            printf(ANSI_COLOR_RED "\t\t\t\t\t                  Andre Marasca\n"ANSI_COLOR_RESET);
            printf("\n");
            printf("\t\t\t\t\tPressione qualquer tecla para voltar.");
            getch();
        }
        else if(menu == '5')
        {
            Beep(600,200);
            system("cls");
            printf("\t\t\t\t\t\t\t\t\tTem certeza que deseja sair?\n");
            printf("\t\t\t\t\t\t\t\t\t\t1 - Sim\n");
            printf("\t\t\t\t\t\t\t\t\t\t2 - Nao\n");
            menu = getch();
            if(menu == '1') exit(0);
            else if(menu == '2') return main();
        }
        else if(menu == '4')
        {
            //CHAMA A FUNCAO BESTIARIO_AUTOMATO
            Beep(600,200);
            bestiario_automato();
        }
        else if (menu == '1')
        {
            //CHAMA A FUNCAO ESCOLHA_PERSONAGEM
            Beep(600,200);
            escolha_personagem();
        }

    }//Enquanto menu for diferente de 38(& em ASCII)
    while(menu != 37);
    return 0;
}





