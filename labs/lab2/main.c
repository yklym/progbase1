// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль

int main() {
    // Початок програми
    const float xmin  = -10.0;
    const float xmax  = 10.0;
    const float xstep = 0.5;

    float x = xmin;  // x is mutable
    float y = cos(x);
    while (x <= xmax) {
        // eval y(x)
        // print values
        y = cos(x);
        printFloat(x);
        puts("");
        printFloat(y);
        printString(" :");
        x += xstep;
    }
    // Кінець програми
    return 0;
}