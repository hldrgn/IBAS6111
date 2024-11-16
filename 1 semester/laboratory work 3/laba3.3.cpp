#include <locale.h>
#include <stdio.h> 
#include <string.h> 

void viv(int a, char* vivod) {
    const char* ed[] = { "", "один ", "два ", "три ", "четыре ", "пять ",
               "шесть ", "семь ", "восемь ", "девять " };
    const char* doped[] = { "десять ", "одиннадцать ", "двенадцать ",
                           "тринадцать ", "четырнадцать ", "пятнадцать ",
                           "шестнадцать ", "семнадцать ", "восемнадцать ",
                           "девятнадцать " };
    const char* des[] = { "", "десять ", "двадцать ", "тридцать ",
                           "сорок ", "пятьдесят ", "шестьдесят ",
                           "семьдесят ", "восемьдесят ", "девяносто " };
    const char* sot[] = { "", "сто ", "двести ", "триста ",
                               "четыреста ", "пятьсот ", "шестьсот ",
                               "семьсот ", "восемьсот ", "девятьсот " };
    const char* tis[] = { "тысяч ", "одна тысяча ", "две тысячи ", "три тысячи ", "четыре тысячи ", "пять тысяч ",
               "шесть тысяч ", "семь тысяч ", "восемь тысяч ", "девять тысяч " };
    const char* mil[] = { "миллионов ", "один миллион ", "два миллиона ", "три миллиона ", "четыре миллиона ", "пять миллионов ",
                   "шесть миллионов ", "семь миллионов ", "восемь миллионов ", "девять миллионов " };
    if (a > 0 and a < 10) { // от нуля до 10
        strcat(vivod, ed[a]);
    }
    else if (a > 9 and a < 20) { // от 10 до 20
        strcat(vivod, doped[a - 10]);
    }
    else if (a > 19 and a < 100) { // от 20 до 100
        strcat(vivod, des[a / 10]);
        viv(a % 10, vivod);
    }
    else if (a > 99 and a < 1000) { // от ста до 1к
        strcat(vivod, sot[a / 100]);
        viv(a % 100, vivod);
    }
    else if (a > 999 and a < 10000) { // от 1к до 10к
        strcat(vivod, tis[a / 1000]);
        viv(a % 1000, vivod);
    }
    else if (a > 9999 and a < 20000) { // от 10к до 20к
        strcat(vivod, doped[(a / 1000)-10]);
        strcat(vivod, "тысяч ");
        viv(a % 1000, vivod);
    }
    else if (a > 19999 and a < 100000) { // от 20к до 100к
        strcat(vivod, des[a/10000]);
        strcat(vivod, tis[a / 1000 % 10]);
        viv(a % 1000, vivod);
    }
    else if (a > 99999 and a < 1000000) { // от 100к до 1млн
        strcat(vivod, sot[a / 100000]);
        if (a % 100000 < 1000) {
            strcat(vivod, "тысяч ");
        }
        viv(a % 100000, vivod);
    }
    else if (a > 999999 and a < 10000000) { // от 1млн до 10млн
        strcat(vivod, mil[a / 1000000]);
        
        viv(a % 1000000, vivod);
    }
    else if (a > 9999999 and a < 20000000) { // от 10млн до 20млн
        strcat(vivod, doped[(a / 1000000) - 10]);
        strcat(vivod, "миллионов ");
        viv(a % 1000000, vivod);
    }
    else if (a > 19999999 and a < 100000000) { // от 20млн до 100млн
        strcat(vivod, des[a / 10000000]);
        strcat(vivod, mil[a / 1000000 % 10]);
        viv(a % 1000000, vivod);
    }
    else if (a > 99999999 and a < 1000000000) { // от 100млн до 1млрд
        strcat(vivod, sot[a / 100000000]);
        if (a % 100000000 < 1000000) {
            strcat(vivod, "миллионов ");
        }
        viv(a % 100000000, vivod);
    }
}

void nado(int a, char* vivod) {
    if (a == 0) {
        strcat(vivod, "нуль ");
    }
    else {
        viv(a, vivod);
    }
    printf("---------------------------------------------------------------\n");
    printf("Введите число на письме: \n");
    printf("[ \%s\]\n", vivod);
    printf("---------------------------------------------------------------\n");
}

int main() {
    setlocale(LC_ALL, "");
    char vivod[100] = "";
    int a, c = 0, v = 1;
    do {
        do {
            c++;
            if (c >= 2) {
                printf("Ну вообще-то правильно будет от 0 до 999 999 999\n");
                printf("А ну, еще раз пробуй\n");
            }
            printf("---------------------------------------------------------------\n");
            printf("Введите число в цифрах до 1 миллиарда- ");
            scanf_s("%d", &a);
        } while (a < 0 or a >= 1000000000);
        nado(a, vivod);
        *vivod = NULL;
        c = 0;
        printf("Если хотите продолжить то введите 1, если нет, то 0\n");
        printf("Ваш выбор - ");
        scanf("%d", &v);
    } while (v == 1);
    return 0;
}
