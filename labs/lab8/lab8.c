// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum TokenKeywords
{
    KW_INT,    // 'int'
    KW_IF,     // 'if'
    KW_RETURN, // 'return'
               // ..
};

enum TokenOperators
{
    OP_PLUS, // '+'
    OP_MULT, // '*'
             // ..
};

enum TokenLiterals
{
    LIT_INTEGER, // 42
    LIT_FLOAT,   // 3.14159
    LIT_STRING,  // "Some string\n"
                 // ..
};

enum TokenDelimiters
{
    DEL_LEFTPAR,   // '('
    DEL_RIGHTPAR,  // ')'
    DEL_COMMA,     // ','
    DEL_SEMICOLON, // ';'
                   // ..
};

enum TokenType
{
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_LITERAL,
    TOKEN_OPERATOR,
    TOKEN_DELIMITER,
};

struct Token
{
    char *lexeme;
    enum TokenType type;
    int subType;
};

struct TokenList
{
    struct Token *token;
    int count;
    int capacity;
};

struct StringTable
{
    char *items;
    size_t capacity;
    size_t count;
    size_t rowCapacity;
};

void parseCode(char *p);
struct StringTable createStringTable(char *items, int cap, int rowCap);
char *readWord(char *str, char *dest, int destsize);
char *readDigit(char *src, char *dest, int destSize);
char *readChar(char *src, char *dest, int destSize);

bool isDelimiter(char src);
bool isOperator(char src);
int main()
{
    // Початок програми
    const int stringLength = 200;
    char string[stringLength];
    strcpy(string, "long i = 0;\
do {\
  float f = -45 * i / 34.4;\
  printf(\"Set: %d\n\", f, i);\
  break;\
} while (i > 1);");
    
    puts(string);
    puts("------------");

    int tokenAmount = 200;
    struct Token tokensArr[tokenAmount];
    struct TokenList tokensList;
    {
        tokensList.token = &tokensArr[0];
        tokensList.capacity = tokenAmount;
        tokensList.count = 0;
    }

    parseCode(string);

    // Кінець програми
    return 0;
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

void parseCode(char *p)
{
    int lexArrCap = 50;
    int lexArrRowCap = 20;
    char lexemsArray[lexArrCap][lexArrRowCap];
    struct StringTable lexemsList = createStringTable(&lexemsArray[0][0], lexArrCap, lexArrRowCap);

    const int bufLen = 200;
    char buf[bufLen];
    char *keyword[] = {
        "long", "break", "do", "while", "float", "printf"};
    char *operators[] = {
        "+", "-", "*", "/", "="};
    char *delimiters[]={
        ")","(",",",";","{","}"
    };    
    char *ch = p;

    while (*ch != '\0')
    {
        if (isspace(*ch))
        {
            //ignore
            ch += 1;
        }
        else if (isdigit(*ch))
        {
            ch = readDigit(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            lexemsList.count += 1;
        }
        else if (isalpha(*ch) || *ch == '_')
        {
            ch = readWord(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            lexemsList.count += 1;
        }
        else if (isDelimiter(*ch))
        {
            ch = readChar(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            lexemsList.count += 1;
        }else if (isOperator(*ch))
        {
            ch = readChar(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            lexemsList.count += 1;
        } else
        {
            ch += 1;
        }
    }






}

char *readWord(char *src, char *dest, int destSize)
{
    char *p = src;
    char *destRet = dest;
    int counter = 0;
    while (isalnum(*p) || *p == '_')
    {
        if (counter < destSize)
        {
            *dest = *p;
            dest++;
            p++;
            counter++;
        }
    }
    *dest = '\0';
    puts(destRet);
    return p;
}
char *readChar(char *src, char *dest, int destSize)
{
    char *p = src;
    char *destRet = dest;

    *dest = *p;
    dest++;
    *dest = '\0';
    p++;

    puts(destRet);
    return p;
}
char *readDigit(char *src, char *dest, int destSize)
{
    char *p = src;
    int counter = 0;
    bool isDotSaved = false;
    char *destRet = dest;
    while (isdigit(*p) || *p == '.')
    {

        if (*p == '.')
        {
            if (!isDotSaved)
            {
                *dest = *p;
                dest++;
                p++;
                counter++;
                isDotSaved = true;
            }
            else
            {
                //ERROR
            }
        }

        *dest = *p;
        dest++;
        p++;
        counter++;
    }
    *dest = '\0';
    puts(destRet);
    return p;
}
bool isDelimiter(char src)
{
    bool result = false;
    if (src == ')' || src == '(' || src == ';' || src == ',' || src == '}' || src == ')')
    {
        result = true;
    }
    return result;
}
bool isOperator(char src)
{
    bool result = false;
    if (src == '+' || src == '-' || src == '*' || src == '/' || src == '>' || src == '=')
    {
        result = true;
    }
    return result;
}
