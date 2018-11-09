// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>            // Для друку в термінал
#include <math.h>             // Для математичних функцій
#include <stdlib.h>           // Деякі додаткові функції
#include <progbase/console.h> // Спрощений ввід і вивід даних у консоль
#include <time.h>

int getColor(char colorCode); // place before int main() {}
void putsblue(char str[50]);
void putsred(char str[50]);

int main()
{
    // Початок програми
    Console_clear();
    Console_reset();
    srand(time(0));
    int kMain = 0;

    do
    {
        putsblue("M E N U");
        printf("1.Array\n");
        printf("2.Matrix.\n");
        printf("3.Bonus\n");
        putsred("4.Escape");
        scanf("%i", &kMain);
        switch (kMain)
        {

        //CASE1__ARRAY
        case 1:
        {
            int nArray = 0; //ARRAY SIZE
            do
            {
                Console_clear();
                putsblue("Enter N :");
                scanf("%i", &nArray);
            } while (nArray < 1);
            Console_clear();
            //ARRAY INIZIALIZATION
            float array[nArray];
            for (int i = 0; i < nArray; i++)
            {
                array[i] = 0;
            }

            //MENU 1
            int k1 = 0;
            do
            {
                // Console_clear();
                putsblue("\nYour array:");
                for (int i = 0; i < nArray; i++)
                {
                    printf("%.2f  ", array[i]);
                }
                puts("\n");
                putsblue("M E N U");
                puts("1.Randomize");
                puts("2.Change by zero");
                puts("3.Get max value");
                puts("4.Summ of all positive");
                puts("5.Swap max&min");
                puts("6.Increase all by n");
                putsred("<--7.Main Menu");

                scanf("%i", &k1);

                switch (k1)
                {
                //RANDOMIZE
                case 1:
                {
                    Console_clear();
                    int rmax = 0;
                    int rmin = 0;
                    do
                    {
                        putsblue("Min rand value is:");
                        scanf("%i", &rmin);

                        putsblue("Max rand value is:");
                        scanf("%i", &rmax);
                        if (rmin > rmax)
                        {
                            putsred("Error, min > max!");
                        }
                        rmax *= 100;
                        rmin *= 100;
                    } while (rmin > rmax);
                    for (int i = 0; i < nArray; i++)
                    {
                        // float scale = rand() / (float)rmax;
                        array[i] = (rand() % (rmax - rmin + 1) + rmin) / 100.0;
                    }
                    Console_clear();
                    Console_setCursorAttribute(FG_CYAN);
                    printf("Elements between %i and %i\n", rmin / 100, rmax / 100);
                    Console_reset();
                }
                break;

                case 2:
                {
                    for (int i = 0; i < nArray; i++)
                    {
                        array[i] = 0;
                    }
                    Console_clear();
                    putsblue("All elements were set to zero");
                }
                break;

                case 3:
                {
                    Console_clear();
                    float arrmax = array[0];
                    int arrmaxindex = 0;
                    for (int i = 0; i < nArray; i++)
                    {
                        if (arrmax < array[i])
                        {
                            arrmax = array[i];
                            arrmaxindex = i;
                        }
                    }
                    Console_setCursorAttribute(FG_CYAN);
                    printf("Element # %i is maximal and equals %.2f\n", arrmaxindex + 1, arrmax);
                    Console_reset();
                }
                break;

                case 4:
                {
                    float positiveSumm = 0;
                    for (int i = 0; i < nArray; i++)
                    {
                        if (array[i] > 0)
                        {
                            positiveSumm += array[i];
                        }
                    }
                    Console_clear();
                    Console_setCursorAttribute(FG_CYAN);
                    printf("The summ of positive elements equals %.2f\n", positiveSumm);
                    Console_reset();
                }
                break;

                case 5:
                {
                    Console_clear();
                    float arrmax = array[0];
                    int arrmaxindex = 0;
                    for (int i = 0; i < nArray; i++)
                    {
                        if (arrmax < array[i])
                        {
                            arrmax = array[i];
                            arrmaxindex = i;
                        }
                    }

                    float arrmin = array[0];
                    int arrminindex = 0;
                    for (int i = 0; i < nArray; i++)
                    {
                        if (arrmin > array[i])
                        {
                            arrmin = array[i];
                            arrminindex = i;
                        }
                    }

                    array[arrminindex] = arrmax;
                    array[arrmaxindex] = arrmin;
                    putsblue("Positions of max&min were swaped!");
                }
                break;

                case 6:
                {
                    Console_clear();
                    float n = 0;
                    putsblue("All elements will be increased by:");
                    scanf("%f", &n);

                    for (int i = 0; i < nArray; i++)
                    {
                        array[i] += n;
                    }
                    Console_clear();
                    Console_setCursorAttribute(FG_CYAN);
                    printf("All the elements were increased by %f", n);
                    Console_reset();
                }
                break;

                case 7:
                {
                    Console_clear();
                }
                break;

                default:
                    printf("Error!\nEnter valid list number\n");
                    break;
                }

                // Console_clear();
            } while (k1 != 7);
        }
        break;

        case 2:
        {
            int iMatrix = 0;
            int jMatrix = 0;
            //INIZIALIZING ARRAY
            do
            {
                Console_clear();
                putsblue("Enter I :");
                scanf("%i", &iMatrix);
            } while (iMatrix < 1);
            do
            {
                putsblue("Enter J :");
                scanf("%i", &jMatrix);
            } while (jMatrix < 1);

            int matrix[iMatrix][jMatrix];

            for (int i = 0; i < iMatrix; i++)
            {
                for (int j = 0; j < jMatrix; j++)
                {
                    matrix[i][j] = 0;
                }
            }

            int k2 = 0;
            puts("\n");
            Console_clear();
            do
            {
                for (int i = 0; i < iMatrix; i++)
                {
                    for (int j = 0; j < jMatrix; j++)
                    {
                        printf("%5.1i|", matrix[i][j]);
                    }
                    puts("");
                }
                puts("\n\n");
                putsblue("Choose  your option:");
                puts("1.Randomize");
                puts("2.Set to zero");
                puts("3.Min vaue");
                puts("4.Summ in the choosen line");
                puts("5.Swap max&min");
                puts("6.Cnage choosen element");
                putsred("<--7.Main Menu");
                scanf("%i", &k2);

                switch (k2)
                {
                case 1:
                {
                    Console_clear();
                    int rmax = 0;
                    int rmin = 0;
                    do
                    {
                        putsblue("Min rand value is:");
                        scanf("%i", &rmin);

                        putsblue("Max rand value is:");
                        scanf("%i", &rmax);
                        if (rmin > rmax)
                        {
                            putsred("Error, min > max!");
                        }
                    } while (rmin > rmax);

                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            matrix[i][j] = rand() % (rmax - rmin + 1) + rmin;
                        }
                    }
                    Console_clear();
                    putsblue("All elements have random values");
                }
                break;

                case 2:
                {
                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            matrix[i][j] = 0;
                        }
                    }
                    Console_clear();
                    putsblue("All elements were set to zero");
                }
                break;

                case 3:
                {
                    Console_clear();
                    int matrixmin = matrix[0][0];
                    int matrixminindexi = 0;
                    int matrixminindexj = 0;

                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            if (matrixmin > matrix[i][j])
                            {
                                matrixmin = matrix[i][j];
                                matrixminindexi = i;
                                matrixminindexj = j;
                            }
                        }
                    }
                    Console_setCursorAttribute(FG_CYAN);
                    printf("Element  row # %i column # %i is maximal and equals %i\n", matrixminindexi + 1, matrixminindexj + 1, matrixmin);
                    Console_reset();
                }
                break;

                case 4:
                {
                    Console_clear();
                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            printf("%8.1i|", matrix[i][j]);
                        }
                        puts("");
                    }
                    puts("");
                    int n4 = 0;
                    int res = 0;

                    putsblue("Choose matrix line:");
                    scanf("%i", &n4);
                    Console_clear();

                    for (int i = 0; i < jMatrix; i++)
                    {
                        res += matrix[n4 - 1][i];
                    }
                    Console_setCursorAttribute(FG_CYAN);
                    printf("Summ in the line %i equals %i\n", n4, res);
                    Console_reset();
                }
                break;

                case 5:
                {
                    Console_clear();
                    int matrixmax = matrix[0][0];

                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            if (matrixmax < matrix[i][j])
                            {
                                matrixmax = matrix[i][j];
                            }
                        }
                    }

                    int matrixmin = matrix[0][0];

                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            if (matrixmin > matrix[i][j])
                            {
                                matrixmin = matrix[i][j];
                            }
                        }
                    }
                    int temp = matrixmax;
                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            if (matrix[i][j] == matrixmax)
                            {
                                matrix[i][j] = matrixmin;
                            }
                            else if (matrixmin == matrix[i][j])
                            {
                                matrix[i][j] = temp;
                            }
                        }
                    }
                    putsblue("Swaped max and min values!");
                }
                break;

                case 6:
                {
                    Console_clear();
                    for (int i = 0; i < iMatrix; i++)
                    {
                        for (int j = 0; j < jMatrix; j++)
                        {
                            printf("%5.1i|", matrix[i][j]);
                        }
                        puts("");
                    }
                    puts("");

                    int i6 = 0;
                    int j6 = 0;

                    putsblue("Enter line number");
                    scanf("%i", &i6);
                    putsblue("Enter column number");
                    scanf("%i", &j6);
                    putsblue("Enter new value");
                    scanf("%i", &matrix[i6 - 1][j6 - 1]);
                    Console_clear();
                }
                break;

                case 7:
                {
                    Console_clear();
                }
                break;

                default:
                {
                    Console_clear();
                    putsred("ERROR, choose valid menu option!");
                }
                break;
                }

            } while (k2 != 7);
        }
        break;

        case 3:
        {
            const char image[28][28] = {
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0x6, 0x6, 0x6, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0x0, 0x3, 0x3, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x3, 0x3, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0x6, 0x6, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0x0, 0x3, 0x3, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x3, 0x3, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0xF, 0xF, 0xF, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0x0, 0x3, 0x0, 0x0, 0xF, 0xF, 0x7, 0x7, 0x7, 0x0, 0x0, 0x3, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0xF, 0xF, 0xF, 0xF, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0x0, 0xF, 0x0, 0x7, 0x0, 0x7, 0x0, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0x7, 0x7, 0x7, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x6},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0x0, 0x0, 0x0, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0x0, 0x0, 0x0, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0xF, 0xF, 0x0, 0xF, 0xF, 0x0, 0xF, 0x0, 0xF, 0xF, 0xF, 0x0, 0x1, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0x2, 0x0, 0x0, 0xF, 0xF, 0x3, 0x0, 0xF, 0xF, 0xF, 0x0, 0x1, 0x0, 0xF, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x2, 0x0, 0xF, 0xF, 0xF, 0x3, 0x3, 0x0, 0xF, 0xF, 0xF, 0x0, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x2, 0x0, 0xF, 0xF, 0xF, 0x3, 0x3, 0x3, 0x0, 0xF, 0xF, 0x0, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF},
                {0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0x0, 0x0, 0xF, 0x0, 0xF, 0x0, 0x3, 0x3, 0x3, 0x0, 0x0, 0xF, 0xF, 0x0, 0xF, 0xF, 0xF, 0xF},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1},
                {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1}};
            char keaster = 0;
            do
            {
                Console_clear();

                char color = 0;
                for (int i = 0; i < 28; i++)
                {
                    for (int j = 0; j < 28; j++)
                    {
                        color = getColor(image[i][j]);
                        Console_setCursorAttribute(color);
                        printf("  ");
                    }
                    puts("");
                }
                Console_reset();

                Console_setCursorPosition(30, 2);

                putsred("Enter to exit");
                // scanf("%i",&keaster);
                keaster = Console_getChar();

            } while (keaster != '\n');
            Console_clear();
            Console_reset();
            puts("");
        }
        break;

        case 4:
            break;

        default:
        {
            Console_clear();
            putsred("Error, wrong value");
            printf("\n");
        }
        break;
        }
    } while (kMain != 4);
    return 0;
}

int getColor(char colorCode)
{
    // colors encoding table (hex code -> console color)
    const char colorsTable[16][2] = {
        {0x0, BG_BLACK},
        {0x1, BG_INTENSITY_BLACK},
        {0x2, BG_RED},
        {0x3, BG_INTENSITY_RED},
        {0x4, BG_GREEN},
        {0x5, BG_INTENSITY_GREEN},
        {0x6, BG_YELLOW},
        {0x7, BG_INTENSITY_YELLOW},
        {0x8, BG_BLUE},
        {0x9, BG_INTENSITY_BLUE},
        {0xa, BG_MAGENTA},
        {0xb, BG_INTENSITY_MAGENTA},
        {0xc, BG_CYAN},
        {0xd, BG_INTENSITY_CYAN},
        {0xe, BG_WHITE},
        {0xf, BG_INTENSITY_WHITE}};
    const int tableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);
    for (int i = 0; i < tableLength; i++)
    {
        char colorPairCode = colorsTable[i][0];
        char colorPairColor = colorsTable[i][1];
        if (colorCode == colorPairCode)
        {
            return colorPairColor; // we have found our color
        }
    }
    return 0; // it's an error
}

void putsblue(char str[50])
{
    Console_setCursorAttribute(FG_CYAN);
    puts(str);
    Console_reset();
}
void putsred(char str[50])
{
    Console_setCursorAttribute(FG_INTENSITY_RED);
    puts(str);
    Console_reset();
}