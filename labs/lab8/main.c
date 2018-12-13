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
    KW_LONG = 0, // 'int'
    KW_BREAK,    // 'if'
    KW_DO,       // 'return'
    KW_WHILE,    // "long", "break", "do", "while", "float", "printf"};
    KW_FLOAT,
    KW_PRINTF,
};

enum TokenOperators //"+", "-", "*", "/", "=", ">"
{
    OP_PLUS,     // '+'
    OP_MINUS,    // -
    OP_MULT,     // '*'
    OP_DIVISION, // /
    OP_EQUALITY, // =
    OP_ISBIGGER, // >
                 // ..
};

enum TokenLiterals
{
    LIT_INTEGER = 1, // 42
    LIT_FLOAT,       // 3.14159
    LIT_STRING,      // "Some string\n"
                     // ..
};

enum TokenDelimiters
{
    DEL_RIGHTPAR = 0,
    DEL_LEFTPAR,   // ")","(" "," ";" "{","}"
    DEL_COMMA,     // ','
    DEL_SEMICOLON, // ';'
    DEL_LEFTFIGPAR,
    DEL_RIGHTFIGPAR,
};

enum TokenType
{
    TOKEN_KEYWORD = 1,
    TOKEN_IDENTIFIER = 2,
    TOKEN_LITERAL = 3,
    TOKEN_OPERATOR = 4,
    TOKEN_DELIMITER = 5,
};

struct Token
{
    char *lexeme;
    enum TokenType type;
    int subType;
    int count;
    int capacity;
    size_t rowCapacity;
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
bool isFloatOrInt(char *p);
void findIds();
void parseCode(char *p);
struct StringTable createStringTable(char *items, int cap, int rowCap);
char *readWord(char *str, char *dest, int destsize);
char *readDigit(char *src, char *dest, int destSize);
char *readChar(char *src, char *dest, int destSize);

bool isDelimiter(char src);
bool isOperator(char src);
void printTokenList(struct Token list)
{
    for (int i = 0; i < list.count; i++)
    {
        printf(" ");
        printf(" ");
        printf(" ");
    }
}
int main()
{
    system("clear");
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

    parseCode(string);

    // Кінець програми
    return 0;
}

struct StringTable
createStringTable(char *items, int cap, int rowCap)
{
    struct StringTable table;
    table.count = 0;
    table.items = items;
    table.capacity = cap;

    table.rowCapacity = rowCap;
    return table;
}
char *readString(char *src, char *dest, int destSize);

void parseCode(char *p)
{

    int lexArrCap = 50;
    int lexArrRowCap = 20;
    char lexemsArray[lexArrCap][lexArrRowCap];
    struct StringTable lexemsList = createStringTable(&lexemsArray[0][0], lexArrCap, lexArrRowCap);
    int tokenAmount = 200;

    int idArrCap = 50;
    int idArrRowCap = 20;
    char idArray[lexArrCap][lexArrRowCap];
    struct StringTable idList = createStringTable(&idArray[0][0], idArrCap, idArrRowCap);
    char *idListTmp = idList.items;
    struct Token tokens[tokenAmount];
    struct TokenList tokensList;
    {
        tokensList.token = &tokens[0];
        tokensList.capacity = tokenAmount;
        tokensList.count = 0;
    }
    for (int i = 0; i < tokensList.capacity; i++)

    {
        tokens[i].lexeme = NULL;
        tokens[i].type = TOKEN_LITERAL;
        tokens[i].subType = 0;
    }

    char *keyword[] = {
        "long", "break", "do", "while", "float", "printf"};
    char *operators[] = {
        "+", "-", "*", "/", "=", ">"};
    char *delimiters[] = {
        ")", "(", ",", ";", "{", "}"};
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

            tokens[tokensList.count].type = TOKEN_LITERAL;
            if (isFloatOrInt(ch))
            {
                tokens[tokensList.count].subType = LIT_INTEGER;
            }
            else
            {
                tokens[tokensList.count].subType = LIT_FLOAT;
            }

            tokens[tokensList.count].lexeme = lexemsList.items + lexemsList.count * lexArrRowCap;
            // lexemsList.count += 1;
            puts(tokens[tokensList.count].lexeme);
            printf("||%i||%i||\n", tokens[tokensList.count].type, tokens[tokensList.count].subType);

            tokensList.count += 1;
            lexemsList.count += 1;
        }
        else if (isalpha(*ch) || *ch == '_' || *ch == '"')
        {
            if (*ch == '"')
            {
                ch = readString(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
                tokens[tokensList.count].subType = 3;
                tokens[tokensList.count].type = TOKEN_LITERAL;
            }
            else
            {
                ch = readWord(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            }


            tokens[tokensList.count].lexeme = (lexemsList.items + lexemsList.count * lexArrRowCap);
            for (int i = 1; i < 7; i++)
            {
                if (strcmp(keyword[i - 1], tokens[tokensList.count].lexeme) == 0)
                {
                    tokens[tokensList.count].type = TOKEN_KEYWORD;
                    tokens[tokensList.count].subType = i;
                }
            }



            for(int i = 0; i < idList.count ;i++ ){
                if(strcmp(tokens[tokensList.count].lexeme, idListTmp)==0){
                    idListTmp += lexArrRowCap;
                    tokens[tokensList.count].type =TOKEN_IDENTIFIER;
                }
            }
            
            
            
            if (tokens[tokensList.count].type != TOKEN_IDENTIFIER &&tokens[tokensList.count].type != TOKEN_KEYWORD && tokens[tokensList.count].type != TOKEN_LITERAL)
            {

                strcpy(idListTmp, tokens[tokensList.count].lexeme);
                idListTmp += idList.rowCapacity * idList.count;
                idList.count += 1;
                tokens[tokensList.count].type =TOKEN_IDENTIFIER;
                idListTmp += lexArrRowCap;

            }

            puts(tokens[tokensList.count].lexeme);
            printf("||%i||%i||\n", tokens[tokensList.count].type, tokens[tokensList.count].subType);

            tokensList.count += 1;
            lexemsList.count += 1;
        }
        else if (isDelimiter(*ch))
        {
            ch = readChar(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            tokens[tokensList.count].type = TOKEN_DELIMITER;
            tokens[tokensList.count].lexeme = (lexemsList.items + lexemsList.count * lexArrRowCap);

            for (int i = 1; i < 7; i++)
            {
                if (strcmp(delimiters[i - 1], tokens[tokensList.count].lexeme) == 0)
                {
                    tokens[tokensList.count].subType = i;
                }
            }

            puts(tokens[tokensList.count].lexeme);
            printf("||%i||%i||\n", tokens[tokensList.count].type, tokens[tokensList.count].subType);

            tokensList.count += 1;
            lexemsList.count += 1;
        }
        else if (isOperator(*ch))
        {
            ch = readChar(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            tokens[tokensList.count].lexeme = (lexemsList.items + lexemsList.count * lexArrRowCap);
            tokens[tokensList.count].type = TOKEN_OPERATOR;

            for (int i = 1; i < 7; i++)
            {
                if (strcmp(operators[i - 1], tokens[tokensList.count].lexeme) == 0)
                {
                    tokens[tokensList.count].subType = i;
                }
            }

            puts(tokens[tokensList.count].lexeme);
            printf("||%i||%i||\n", tokens[tokensList.count].type, tokens[tokensList.count].subType);
            lexemsList.count += 1;
            tokensList.count += 1;
        }
        else
        {
            ch += 1;
        }
    }
    // struct Token *tempPointer = &tokens[tokenCount].lexeme;
    findIds();
}
char *readString(char *src, char *dest, int destSize)
{
    char *p = src;
    bool isStringEnd = false;
    while (!isStringEnd)
    {
        if (*p == '"' && p != src)
        {
            isStringEnd = true;
        }
        *dest = *p;
        dest++;
        p++;
    }

    *dest = '\0';
    return p;
}
char *readWord(char *src, char *dest, int destSize)
{
    char *p = src;
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
    return p;
}
char *readChar(char *src, char *dest, int destSize)
{
    char *p = src;

    *dest = *p;
    dest++;
    *dest = '\0';
    p++;

    return p;
}
char *readDigit(char *src, char *dest, int destSize)
{
    char *p = src;
    int counter = 0;
    bool isDotSaved = false;

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
        else

            *dest = *p;
        dest++;
        p++;
        counter++;
    }
    *dest = '\0';

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
bool isFloatOrInt(char *p)
{
    bool result = false;
    while (*p != '\0')
    {
        if (*p == '.')
        {
            result = true;
            return result;
        }
        p++;
    }
    return result;
}
void findIds()
{
}
// {
//     int p;
//     for (int i = 0; p + 1 == NULL; i++)
//     {
//         if (p->type == TOKEN_KEYWORD && (p + 1)->subType == LIT_STRING)
//         {
//             (p + 1)->type = TOKEN_IDENTIFIER;
//         }
//         p += i;
//     }
// }