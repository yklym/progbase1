// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль

struct IntList
{
    int *items;
    size_t capacity;
    size_t count;
};
void addItem(struct IntList *plist, int value);
void printlist(const struct IntList *plist);

void removeItemAt(struct IntList *plist, int index);

int main()
{
    // Початок програми

    const int arrayLength = 10;
    int array[arrayLength];
    struct IntList list;
    list.items = &array[0];
    list.capacity = arrayLength;
    list.count = 0;

    // Кінець програми
    return 0;
}

void addItem(struct IntList *plist, int value)
{

    int index = (*plist).count;
    (*plist).items[index] = value;
    (*plist).count += 1;
}

void printlist(const struct IntList *plist)
{
    printf("%zu:   ", (*plist).count);

    for (int i = 0; i < (*plist).count; i++)
    {
        int value = (*plist).items[i];
        printf("%d  ", value);
    }
}
void removeItemAt(struct IntList *plist, int index)
{
    if (index < 0 || index >= (*plist).count)
    {
    }
    for (int i = index; i < (*plist).count - 1; i++)
    {
        (*plist).items[i] = (*plist).items[i + 1];
    }
    (*plist).count -= 1;
}
