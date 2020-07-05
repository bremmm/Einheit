#include <stdio.h>
#include <windows.h>

int main (void)
{
    int i;

    for (i=0; i < 255; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
        printf("HAHAHAHAHA %d\n\n", i);
    }
    getch();
}
