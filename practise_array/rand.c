// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <time.h>
int main() {
    // Початок програми
    int arr[10];
    const int randmax = 50;
    const int randmin = -50;
    srand(time(0));
    for(int j = 0; j < 10; j++){
        arr[j]= rand() % (randmax - randmin - 1) + randmin ;
    }
    printf("a\n");
    for(int i = 0; i < 10; i++){
        printf("%i ", arr[i]);
    }
    puts("");
    

    // Кінець програми
    return 0;
}