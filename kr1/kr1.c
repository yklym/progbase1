#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int mainTask1Array();
int mainTask2Matrix();
int mainTask3String();

int main()
{
    int taskNumber = 0;
    scanf("%i", &taskNumber); // get task number input
    getchar();                // removing \n
    switch (taskNumber)
    {
    case 1:
        return mainTask1Array();
    case 2:
        return mainTask2Matrix();
    case 3:
        return mainTask3String();
    }

    return EXIT_FAILURE;
}

int mainTask1Array()
{
    int N, x, max = 0;
    scanf("%i", &N);
    getchar();

    int A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%i", &A[i]);
        getchar();
    }

    scanf("%i", &x);
    getchar();

    for (int i = 0; i < N; i++)
    {
        if (A[max] < A[i] && A[i] != x)
        {
            max = i;
        }
        if (((x >= 0 && A[i] < 0) || (x < 0 && A[i] >= 0)) && (A[i]!=x))
        {
            printf("%i ", A[i]);
         }//else if (){

    }
    if (max != 0){
        printf("\n %i\n", A[max]);
    } else printf("\n NaN");
    // @todo implement task
    return EXIT_SUCCESS;
}

int mainTask2Matrix()
{
    int N, M, x = 0;

    scanf("%i", &N);
    getchar();

    scanf("%i", &M);
    getchar();

    int A[N][M];
    int max = 0;
    int res = 0;
    int count = 0;
    int flag = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%i", &A[i][j]);
            getchar();
        }
    }

    scanf("%i", &x);
    getchar();

    for (int i = 0; i < N; i++)
    {
        res = 0;
        for (int j = 0; j < M; j++)
        {
            res += A[i][j];
            if (A[i][j] == x)
            {
                count++;
            }
        }
        if (max < res)
        {
            max = res;
            flag = i;
        }
    }
    for (int j = 0; j < M; j++)
    {
        printf("%i ", A[flag][j]);
    }

    printf("\n%i\n", count);

    // @todo implement task
    return EXIT_SUCCESS;
}

int mainTask3String()
{
    int strleng = 66;
    char S[strleng];
    char x = 0;
    int flag = 0;

    fgets(S, strleng, stdin);

    scanf("%c", &x);
    getchar();

    int tmpI = 0;
    char strBuf5[strleng];

    for (int i = 0;; i++)
    {
        char ch = S[i];
        if (ch == '\n' || isalpha(ch) == 0)
        {
            if (tmpI != 0)
            {

                strBuf5[tmpI] = '\0';
                if (flag == 0)
                {
                    printf("%s ", strBuf5);
                }
                tmpI = 0;
                flag = 0;
            }
            if (ch == '\n')
            {
                break;
            }
        }
        else if (isalpha(ch))
        {
            if (ch == x)
            {
                flag++;
            }
            strBuf5[tmpI] = ch;
            tmpI += 1;
        }
    }

    // @todo implement task
    return EXIT_SUCCESS;
}