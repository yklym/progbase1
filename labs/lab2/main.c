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
    float y = 0;
    while (x <= xmax) {
        // eval y(x)
        // підстановка формули залежно від х
        if (x <= 3 && x > -5){
            y = -pow((x-1), 3) + 2 / (3 * x);
        }
        else {
            y = 0.5 * (1 / tan(x - 5));
        }
        // перевірка  
        if (x == 0 || tan(x-5) == 0){
             printf("y(%.1f) = ERROR\n", x);
        }
        else {
            printf("y(%.1f) = %f\n", x, y);
        }
        //зміна значення х
        x += xstep;
    }
    // Кінець програми
    return 0;
}