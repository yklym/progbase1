#include <stdio.h>  // Для друку в термінал
#include <math.h>   // Для математичних функцій
#include <stdlib.h> // Деякі додаткові функції
#include <ctype.h>  // Спрощений ввід і вивід даних у консоль
#include <string.h>

int main()
{
    unsigned long long res = 0;
    char mainstring[20];
    fgets(mainstring, 20, stdin);

    int tmp = 0;

    unsigned long long step = 1;
    for (int i = strlen(mainstring) - 2; i >= 0; i--)
    {
        if (isxdigit(mainstring[i]))
        {
            if (isdigit(mainstring[i]))
            {
                res += (mainstring[i] - 48) * step;
            }
            else if (isupper(mainstring[i]))
            {
                res += (mainstring[i] - 55) * step;
            }
            else if (islower(mainstring[i]))
            {
                res += (mainstring[i] - 87) * step;
            }
            step *= 16;

            tmp++;
        } else return 1;
    }
    if (tmp >= 17 || (mainstring[0]) == '\n')
    {
        return 1;
    }
    printf("%llu \n", res);
    return 0;
}