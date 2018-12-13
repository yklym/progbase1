// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
enum Operator
{
    Operator_NONE,
    Operator_ADD,  // +
    Operator_SUB,  // -
    Operator_MULT, // *
    Operator_DIV,  // /
    Operator_EQ = 9, // ==
    Operator_NEQ ,    // != 10
    Operator_LT ,     // < 11 
    Operator_GT  ,     // > 12
};

struct Expression
{
    enum Operator op;
    char left[21];
    char right[21];
};
struct Assignment
{
    char name[21];
    struct Expression expr;
};

enum ErrType
{
    ErrType_NONE, // not an error
    ErrType_VARIABLE_NOT_FOUND,
};



struct Expression parseExpression(const char *str)
{
    struct Expression res;
    res.op = Operator_NONE;
    bool OpSaved = false;
    int a = 0, b = 0, c = 0;
    char buf[5];
    while (*str != '\0')
    {
        if (isspace(*str))
        {
        }
        else if (isdigit(*str) && !OpSaved)
        {
            res.left[a] = *str;
            a++;
        }
        else if (isdigit(*str) && OpSaved)
        {
            res.right[b] = *str;
            b++;
        }
        else
        {
            buf[c] = *str;
            c++;
            OpSaved = true;

        }
        str++;
    }
    res.left[a] = '\0';
    res.right[b] = '\0';
        buf[c] = '\0';
        printf("\"%s\"\n", buf);

    
    if(strcmp(buf, "==")==0){
        res.op = Operator_EQ;
            return res;

    } else 
    if(strcmp(buf, "!=")==0){
        res.op = Operator_NEQ;
            return res;

    } else 
    if(strcmp(buf, "<")==0){
        res.op = Operator_LT;
            return res;

    } else 
    if(strcmp(buf, ">")==0){
        res.op = Operator_GT;
    }

    return res;
}

int countFloats(const char *str)
{
    int res = 0;
    char buf[100];
    buf[0] = '0';
    bool dotSaved = false;

    for (int j = 0;; str++)
    {
        if ((!isdigit(*str) && dotSaved) || *str == '\0')
        {
            if (j != 0)
            {
                buf[j] = '\0';
                puts(buf);
                res += 1;
                j = 0;
                dotSaved = false;
            }
            if (*str == '\0')
            {
                break;
            }
        }
        if (!isdigit(*str) && !dotSaved && *str != '.')
        {
            buf[j] = '\0';
            j = 0;
        }
        bool dotSavedNot = (isdigit(*str) || (*str == '.' && j != 0)) && !dotSaved;
        if (dotSavedNot || (isdigit(*str) && dotSaved))
        {
            buf[j] = *str;
            j += 1;
            if (*str == '.')
            {
                dotSaved = true;
            }
        }
    }

    return res;
}
float getMaxOfValues( int arrayLen, struct Assignment array[arrayLen], enum ErrType *error)
{
    float res;
    // float max = 0;
    *error = ErrType_VARIABLE_NOT_FOUND;
    // for (int i = 0; i < arrayLen; i++){
    //     array[i].
    // }




    
    return NAN;
}
int main()
{
    
    char string[100];
    char *p;
    p = &string[0];
    fgets(string, 99, stdin);

    // printf("%i\n", countFloats(p));
    
    struct Expression r = parseExpression(p);
    printf("%i\n%s\n%s\n",r.op, r.left, r.right );
    return 0;
}