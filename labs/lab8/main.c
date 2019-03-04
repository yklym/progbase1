// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int error = 0;
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
int parseCode(char *p);
struct StringTable createStringTable(char *items, int cap, int rowCap);
char *readWord(char *str, char *dest, int destsize);
char *readDigit(char *src, char *dest, int destSize);
char *readChar(char *src, char *dest, int destSize);

bool isDelimiter(char src);
bool isOperator(char src);

void outputTokens(struct TokenList *list1);
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

    if (parseCode(string))
    {
        puts("ERROR");
        return 1;
    }
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

int parseCode(char *p)
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
            bool check = isFloatOrInt(ch);
            ch = readDigit(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);

            tokens[tokensList.count].type = TOKEN_LITERAL;
            if (check)
            {
                tokens[tokensList.count].subType = LIT_FLOAT;
            }
            else
            {
                tokens[tokensList.count].subType = LIT_INTEGER;
            }

            tokens[tokensList.count].lexeme = lexemsList.items + lexemsList.count * lexArrRowCap;
            // lexemsList.count += 1;

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
            for (int i = 0; i < 6; i++)
            {
                if (strcmp(keyword[i], tokens[tokensList.count].lexeme) == 0)
                {
                    tokens[tokensList.count].type = TOKEN_KEYWORD;
                    tokens[tokensList.count].subType = i;
                }
            }
            // IS IDENTIFIER

            for (int i = 0; i < idList.count; i++)
            {
                if (strcmp(tokens[tokensList.count].lexeme, idListTmp) == 0)
                {
                    idListTmp += lexArrRowCap;
                    tokens[tokensList.count].type = TOKEN_IDENTIFIER;
                }
            }

            if (tokens[tokensList.count].type != TOKEN_IDENTIFIER && tokens[tokensList.count].type != TOKEN_KEYWORD && tokens[tokensList.count].subType != 3)
            {

                strcpy(idListTmp, tokens[tokensList.count].lexeme);
                idListTmp += idList.rowCapacity * idList.count;
                idList.count += 1;
                tokens[tokensList.count].type = TOKEN_IDENTIFIER;
                idListTmp += lexArrRowCap;
            }

            tokensList.count += 1;
            lexemsList.count += 1;
        }
        else if (isDelimiter(*ch))
        {
            ch = readChar(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            tokens[tokensList.count].type = TOKEN_DELIMITER;
            tokens[tokensList.count].lexeme = (lexemsList.items + lexemsList.count * lexArrRowCap);

            for (int i = 0; i < 6; i++)
            {
                if (strcmp(delimiters[i], tokens[tokensList.count].lexeme) == 0)
                {
                    tokens[tokensList.count].subType = i;
                }
            }

            tokensList.count += 1;
            lexemsList.count += 1;
        }
        else if (isOperator(*ch))
        {
            ch = readChar(ch, lexemsList.items + lexemsList.count * lexArrRowCap, lexArrRowCap);
            tokens[tokensList.count].lexeme = (lexemsList.items + lexemsList.count * lexArrRowCap);
            tokens[tokensList.count].type = TOKEN_OPERATOR;

            for (int i = 0; i < 6; i++)
            {
                if (strcmp(operators[i], tokens[tokensList.count].lexeme) == 0)
                {
                    tokens[tokensList.count].subType = i;
                }
            }

            lexemsList.count += 1;
            tokensList.count += 1;
        }
        else
        {
            ch += 1;
        }
        if (ch == NULL)
        {
            return 1;
        }
    }
    // struct Token *tempPointer = &tokens[tokenCount].lexeme;
    outputTokens(&tokensList);
    findIds();
    return 0;
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
        if (*p == '\n')
        {
            *dest = '\\';
            dest++;
            
            *dest = 'n';
            dest++;
            p++;

        }
        else
        {
            *dest = *p;
            dest++;
            p++;
        }
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
                return NULL;
                //ERROR
            }
        }
        else
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
    while (!isspace(*p) || p == NULL)
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
void outputTokens(struct TokenList *list1)
{
    struct Token *list = list1->token;
    puts("TOKENS>>>:");
    int i = 0;
    while (i < list1->count)
    {
        switch (list->type)
        {

        case TOKEN_KEYWORD:
        {
            switch (list->subType)
            {
            case KW_BREAK:
            {
                printf("TOKEN KEYWORD      ");
                printf("type = BREAK      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case KW_FLOAT:
            {
                printf("TOKEN KEYWORD      ");
                printf("type = FLOAT      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case KW_DO:
            {
                printf("TOKEN KEYWORD      ");
                printf("type = DO      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case KW_LONG:
            {
                printf("TOKEN KEYWORD      ");
                printf("type = LONG      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case KW_WHILE:
            {
                printf("TOKEN KEYWORD      ");
                printf("type = WHILE      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;

            default:
                break;
            }
        }
        break;
        case TOKEN_DELIMITER:
        {
            printf("TOKEN DELIMITER:     ");
            switch (list->subType)
            {
            case DEL_COMMA:
            {
                printf("type = comma      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case DEL_LEFTFIGPAR:
            {
                printf("type = leftfigpar      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case DEL_LEFTPAR:
            {
                printf("type = leftPar      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case DEL_RIGHTFIGPAR:
            {
                printf("type = rightfigpar     ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case DEL_RIGHTPAR:
            {
                printf("type = rightpar     ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case DEL_SEMICOLON:
            {
                printf("type = semicolon     ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            default:
                break;
            }
        }
        break;

        case TOKEN_IDENTIFIER:
        {
            printf("TOKEN_IDENTIFIER ");
            printf("             \"%s\"\n", list->lexeme);
        }
        break;

        case TOKEN_LITERAL:
        {
            switch (list->subType)
            {
            case LIT_FLOAT:
            {
                printf("TOKEN LITERAL      ");
                printf("type = float      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case LIT_INTEGER:
            {
                printf("TOKEN LITERAL      ");
                printf("type = int      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case LIT_STRING:
            {
                printf("TOKEN LITERAL      ");
                printf("type = string      ");
                printf("%s \n", list->lexeme);
            }
            break;
            default:
                break;
            }
        }
        break;

        case TOKEN_OPERATOR:
        {
            switch (list->subType)
            {
            case OP_DIVISION:
            {
                printf("TOKEN OPERATOR      ");
                printf("type = division      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case OP_EQUALITY:
            {
                printf("TOKEN OPERATOR      ");
                printf("type = equality      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case OP_ISBIGGER:
            {
                printf("TOKEN OPERATOR      ");
                printf("type = isbigger      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case OP_MINUS:
            {
                printf("TOKEN OPERATOR      ");
                printf("type = minus      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case OP_MULT:
            {
                printf("TOKEN OPERATOR      ");
                printf("type = mult      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            case OP_PLUS:
            {
                printf("TOKEN OPERATOR      ");
                printf("type = plus      ");
                printf("\"%s\" \n", list->lexeme);
            }
            break;
            default:
                break;
            }
        }
        break;
        default:
            break;
        }
        list++;
        i++;
    }
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