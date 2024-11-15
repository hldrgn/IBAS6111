#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define size 8

void PB(char b[size][size])
{
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0; j < size; j += 1)
        {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int IS(char b[size][size], int g, int v)
{
    int i, j;
    for (i = 0; i < g; i += 1)
    {
        if (b[i][v] == 'Q')
        {
            return 0;
        }
    }

    for (i = g, j = v; i >= 0 && j >= 0; i -= 1, j -= 1)
    {
        if (b[i][j] == 'Q')
        {
            return 0;
        }
    }

    for (i = g, j = v; i >= 0 && j < size; i -= 1, j += 1)
    {
        if (b[i][j] == 'Q')
        {
            return 0;
        }
    }

    return 1;
}

int SNQ(char b[size][size], int g, int sr, int sc)
{
    if (g == size)
    {
        return 1;
    }
    if (g == sr)
    {
        return SNQ(b, g + 1, sr, sc);
    }
    for (int v = 0; v < size; v += 1)
    {
        if (IS(b, g, v))
        {
            b[g][v] = 'Q';
            if (SNQ(b, g + 1, sr, sc))
            {
                return 1;
            }
            b[g][v] = '.';
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "RU");
    char b[size][size];
    char cont;
    while (1) {
        for (int i = 0; i < size; i += 1)
        {
            for (int j = 0; j < size; j += 1)
            {
                b[i][j] = '.';
            }
        }
        int sg, sv;
        do
        {
            printf("Введите начальную позицию для первого ферзя (строка и столбец от 0 до 7):\n");
            scanf("%d %d", &sg, &sv);
        } while ((sg < 0 or sg > 7) or (sv < 0 or sv > 7));
        b[sg][sv] = 'Q';
        printf("Начальная доска:\n");
        PB(b);
        if (!SNQ(b, 0, sg, sv))
        {
            printf("Нет решения!\n");
        }
        else
        {
            printf("Решение: \n");
            PB(b);
        }

        printf("Хотите продолжить (y/n)? ");
        scanf(" %c", &cont);
        if (cont != 'y') {
            break; 
        }
    }

    return 0;
}
