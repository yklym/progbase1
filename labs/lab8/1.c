// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
struct StringTable
{
    char *items;
    size_t capacity;
    size_t count;
    size_t rowCapacity;
};

struct StringTable
createStringTable(char *items, int cap, int rowCap);
void addString(struct StringTable *ptable, const char *str);
char * getStringAt(const struct StringTable *ptable);
void printTable(const struct StringTable *ptable);
int main()
{
    // Початок програми
    const int nRows = 10;
    const int nCols = 32;
    char mKeywords[nRows][nCols];
    struct StringTable tKeywords = createStringTable(&mKeywords[0][0], 0, nRows);

    // Кінець програми
    return 0;
}
char * getStringAt(const struct StringTable *ptable, ){

    int rowIndex = (*ptable).count;
    char *p = (*ptable).items;
    p += rowIndex * (*ptable).rowCapacity;
    return p;

}


struct StringTable
createStringTable(char *items, int cap, int rowCap)
{
    struct StringTable table;
    table.items = items;
    table.capacity = cap;
    table.count = 0;
    table.rowCapacity = rowCap;
    return table;
}
void addString(struct StringTable *ptable, const char *str)
{
    int rowIndex = (*ptable).count;
    char *p = getStringAt(*ptable, rowIndex);
    
    strcpy(p, str);
    (*ptable).count +=1;
}

void printTable(const struct StringTable *ptable){
for (int i = 0; i < (*ptable).count; i++){
    char * p
}
}