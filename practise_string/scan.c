// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <ctype.h>
#include <string.h>

void clearBuf (){
    for (char _ch; (_ch = getchar()) != '\0';){}
}

int main() {
    // Початок програми
    char str[10];
    const int bufLen = 10;
    // Кінець програми

    // scanf("%9s", str);
    fgets(str, bufLen, stdin);
    if (strlen(str)>= bufLen){
        clearBuf();

    }
    clearBuf();
    printf("Entered str: %s\n", str);

    for (int i = 0; str[i] != '\n'; i++){
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])){
            str[i] = tolower(str[i]);
        }
    }
    printf("Entered str: %s\n", str);

    for (int i = 0; str[i]!= '\0'; i++){
        if (isdigit(str[i])){

        }
    }

    int n = 0;
    n = getInt();
    str[n]= '\0';
    return 0;

}

