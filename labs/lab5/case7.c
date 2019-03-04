// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>            // Для друку в термінал
#include <math.h>             // Для математичних функцій
#include <stdlib.h>           // Деякі додаткові функції
#include <progbase/console.h> // Спрощений ввід і вивід даних у консоль
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    // Початок програми
    char main[50];
    strcpy(main, "g34.45ji456 -4.aa.3k23!12.23.34");
    char str[50];
    char buf[50];
    int bufX = 0;
    bool dotSaved = false;
    float res = 0;
    for (int i = 0, j = 0;; i++)
    {
        char ch = main[i];
        if ((!isdigit(ch) && dotSaved) || ch == '\0')
        {
            if (j != 0)
            {
                str[j] = '\0';
                puts(str);
                res += atof(str);
                j = 0;
                dotSaved = false;
            }
            if (ch == '\0')
            {
                break;
            }
        } if(!isdigit(ch) && !dotSaved && ch != '.'){
            str[j] = '\0';
            j = 0;
        }
        bool dotSavedNot = (isdigit(ch) || ch == '.') && !dotSaved;
        if (dotSavedNot || (isdigit(ch) && dotSaved))
        {
            str[j] = ch;
            j += 1;
            if (ch == '.')
            {
                dotSaved = true;
            }
        }
    }
    puts("Your res is:");
    printf("%.2f\n", res);

    // Кінець програми
    return 0;
}