// Компілювати за допомогою:
// gcc main.c -lprogbase -lm
// робить розрахунки за встановленою формулою
// і даними користувача

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль

int main(void) {
    // оголошуємо змінні
    float x = 0;
    float y = 0;
    float z = 0;
    float a0 = 0;
    float a1 = 0;
    float a2 = 0;
    float a = 0;
    
    //ввeдeня даних
    printf("Enter x:\n");
    scanf("%f", &x);
    
    printf("Enter y:\n");
    scanf("%f", &y);
    
    printf("Enter z:\n");
    scanf("%f", &z);
    
    //проведення розрахунків
    a = a0 + a1 + a2;
    a0 = pow(x, y + 1)/ pow(x - y, 1/z);
    a1 = (9 * y) + (z / x);
    a2 = pow(x + 1, 1 / fabs(sin(y)));
    
    //вивід даних
    puts("Result:");
    printf("x=%.3f\ny=%.3f\nz=%.3f\na0=%.3f\na1=%.3f\na2=%.3f\na=%.3f\n", x, y, z, a0, a1, a2, a); 
    return 0;
}