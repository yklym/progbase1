// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <time.h>
int main() {
    const int alength = 10;
    const int blength = 10;
    // Початок програми
    int A[alength];
    int B[blength];
    const int randmax = 10;
    const int randmin = 10;
    srand(time(0));

    for(int i = 0; i < blength; i++){
        B[i]=0;
    }
    for(int j = 0; j < 10; j++){
        A[j]= rand() % (randmax - randmin - 1) + randmin ;
    }
    int c = 0;
    for (int i < alength; i++)
    {
        int value = A[i];
        if (value == 3){
            c += 1;
        }
    }    printf("a\n");
    for(int i = 0; i < 10; i++){
        printf("%i ", A[i]);
    }
    puts("");
    
    

    // Кінець програми
    return 0;
}