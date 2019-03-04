 #include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <progbase.h>
#include <progbase/console.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    srand(time(0));
    
         
        {
            Console_clear();
            bool isSubmenu2Running = true;

            int n = 0;
            int m = 0;
            int matrix[n][m];

            printf("Enter your N here (strings): ");
            scanf("%i", &n);

            printf("Enter your M here (columns): ");
            scanf("%i", &m);


            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }


            while (isSubmenu2Running)
            {

                Console_clear();

                puts("\nThis is MATRIX submenu!");

                puts("\nMatrix: ");

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        printf("[ %2.1d ]", matrix[i][j]);
                    }
                    puts(" ");
                }

                puts("\n\n1) To fill the matrix with random numbers from L to H.");
                puts("2) To reset all elements of the array.");
                puts("3) To find the minimal element and its indexes (i and j).");
                puts("4) To find the sum of line items for a given index.");
                puts("5) To swape places of the maximum and minimum elements of the array.");
                puts("6) To change the value of an item by specified indexes to a specified one.");

                puts("\n\n0. <- Back");
                printf("> Enter your option: ");

                char submenu2Input = Console_getChar();
                printf("You entered: '%c'\n", submenu2Input);

                switch (submenu2Input)
                {

                case '0':
                {

                    isSubmenu2Running = false;
                    break;
                }
                case '1':
                {

                    int a = 0;
                    int b = 0;

                    printf("Enter L (min): ");
                    scanf("%i", &a);
                    puts(" ");

                    printf("Enter H (max): ");
                    scanf("%i", &b);
                    puts(" ");

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            matrix[i][j] = rand() % (b - a + 1) + a;
                        }
                    }
                    
                }break;
                case '2':
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            matrix[i][j] = 0;
                        }
                    }
                }
                case '3':
                {
                    int indexI = 0;
                    int indexJ = 0;
                    int min = matrix[0][0];
                    for (int i = 1; i < n; i++)
                    {
                        for (int j = 1; j < m; j++)
                        {
                            if (min > matrix[i][j])
                            {
                                min = matrix[i][j];
                                indexI = i;
                                indexJ = j;
                            }
                        }
                    }
                    printf("The min is %i, its index is [%2.1i][%2.1i]!", min, indexI, indexJ);
                    break;
                }
                case '4':
                {
                    int sum = 0;
                    int i = 0;
                    printf("> I want to use this line - ");
                    scanf("%i", &i);

                    if (i >= 0 && i < n)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            sum = sum + matrix[i][j];
                        }
                        printf("The sum of elements when i = %i is %i", i, sum);
                    }
                    else
                        printf("Please, print another i here");
                    break;
                }
                case '5':
                {
                    int maxEl = matrix[0][0];
                    int minEl = matrix[0][0];
                    int indexIMaxEl = 0;
                    int indexJMaxEl = 0;
                    int indexIMinEl = 0;
                    int indexJMinEl = 0;

                    for (int i = 1; i < n; i++)
                    {
                        for (int j = 1; j < m; j++)
                        {
                            for (int g = 1; g < n; g++)
                            {
                                for (int f = 1; f < m; f++)
                                {

                                    if (maxEl < matrix[i][j])
                                    {
                                        maxEl = matrix[i][j];
                                        indexIMaxEl = i;
                                        indexJMaxEl = j;
                                    }

                                    if (minEl > matrix[g][f])
                                    {
                                        minEl = matrix[g][f];
                                        indexIMinEl = g;
                                        indexJMinEl = f;
                                    }
                                }
                            }
                        }
                    }
                    matrix[indexIMaxEl][indexJMaxEl] = minEl;
                    matrix[indexIMinEl][indexJMinEl] = maxEl;
                    break;
                }
                case '6':
                {
                    int i = 0;
                    int j = 0;
                    float indexValue = 0;

                    printf("Enter your i here - ");
                    scanf("%i", &i);

                    printf("Enter your j here - ");
                    scanf("%i", &j);

                    if (i >= 0 && i < n && j >= 0 && j < m)
                    {
                        printf("\n\nelement[%i][%i] = %i", i, j, matrix[i][j]);
                        puts("\nWhat value do you want?");
                        printf("\n\n> I want its ");
                        scanf("%f", &indexValue);
                        matrix[i][j] = indexValue;
                    }
                    else
                        printf("Please, input valid dates!");

                    break;
                }
                default:{
                    break;
                }
                }
            }
        }
        }