// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>  // Для друку в термінал
#include <math.h>   // Для математичних функцій
#include <stdlib.h> // Деякі додаткові функції
#include <ctype.h>  // Спрощений ввід і вивід даних у консоль
#include <string.h>

enum hex
{
    A = 10,
    B,
    C,
    D,
    E,
    F,
};

int main()
{
    int res = 0;
    // Початок програми
    char mainstring[18];
    fgets(mainstring, 17, stdin);
    // mainstring[16] = '\0';

    // mainstring[0] = 'a';
    // mainstring[1] = 'b';
    // mainstring[2] = '\0';


    printf("%li \n", strlen(mainstring));

    for(int i = 0; i < strlen(mainstring); i++){

        if(mainstring[i] == '\n'){
            mainstring[i] = '\0';
        }
        //  if(!isxdigit(ch)){
        //     //  return 1;
        //  }
    }

    for (int i = strlen(mainstring) - 1 ; i>=0 ; i--)
    {
        int indx = 0;
        char ch = mainstring[i];
        // ch[1] = '\0';
        if (isdigit(ch))
        {
            res += (ch-48) * pow(16, i);
        } else
        if (isalpha(ch))
        {
            switch (ch)
            {
            case 'a':
            case 'A':
            {
                res += 10 * pow(16, indx);
            }
            break;

            case 'B':
            case 'b':
            {
                res += 11 * pow(16, indx);
            }
            break;

            case 'C':
            case 'c':
            {
                res += 12 * pow(16, indx);
            }
            break;

            case 'D':
            case 'd':
            {
                res += D * pow(16, indx);
            }
            break;

            case 'E':
            case 'e':
            {
                res += E * pow(16, i);
            }
            break;

            case 'F':
            case 'f':
            {
                res += 15 * pow(16, i);
            }
            break;

            default:
            { 
                continue;
            }
            break;
            }
            
        }
        indx +=1;
    }
    printf("%i\n Res %i", res, mainstring[0]-48);
    // Кінець програми
    return 0;
}