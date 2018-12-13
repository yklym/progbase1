// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum AppOptionsError
{
    AppOptionsError_NO_ERROR,
    AppOptionsError_INPUT_FILE_MISSING,
    // errors that require errorArgument value (below)
    AppOptionsError_UNKNOWN_OPTION,
    AppOptionsError_UNKNOWN_VALUE,
    AppOptionsError_OPTION_VALUE_MISSING,
    AppOptionsError_OPTION_VALUE_NOT_INT,
};

struct AppOptions
{
    char *inputFileName; // single value, default `NULL`
    // options with values
    char *outputFileName; // string after `-o`, default `NULL`
    int n;                // integer after `-n`, default `0`
    // boolean options
    bool encodeMode; // `-e`, default `false`
    bool decodeMode; // `-d`, default `false`
    bool testMode;   // `-t`, default `false`
    bool helpMode;   // `-h`, default `false`
    // errors
    enum AppOptionsError error; // default `AppOptionsError_NO_ERROR`
    char *errorArgument;        // pointer to arg that causes error, default `NULL`
};

struct AppOptions parseOptions(int argc, char *argv[argc])
{
    bool IfOutput = false;
    bool IfInt = false;

    struct AppOptions parse;
    parse.inputFileName = NULL;
    parse.outputFileName = NULL;
    parse.n = 0;
    parse.encodeMode = false;
    parse.decodeMode = false;
    parse.testMode = false;
    parse.helpMode = false;
    parse.error = AppOptionsError_NO_ERROR;
    parse.errorArgument = NULL;

    char buf[100];
    for (int i = 1; i < argc; i++)
    {
        strcpy(buf, argv[i]);
        int length = strlen(buf);

        if (buf[0] == '-')
        {
            if (IfInt)
            {
                parse.error = AppOptionsError_OPTION_VALUE_NOT_INT;
                parse.errorArgument = argv[i];
                return parse;
            }
            if (IfOutput)
            {
                parse.error = AppOptionsError_OPTION_VALUE_MISSING;
                parse.errorArgument = argv[i];
                return parse;
            }
            for (int j = 1; j < length; j++)
            {
                if (buf[j] == 'd')
                {
                    parse.decodeMode = true;
                }
                else if (buf[j] == 'h')
                {
                    parse.helpMode = true;
                }
                else if (buf[j] == 'e')
                {
                    parse.encodeMode = true;
                }
                else if (buf[j] == 't')
                {
                    parse.testMode = true;
                }
                else if (buf[j] == 'n')
                {
                    IfInt = true;
                }
                else if (buf[j] == 'o')
                {
                    IfOutput = true;
                }
                else 
                {
                    parse.error = AppOptionsError_UNKNOWN_OPTION;
                    parse.errorArgument = argv[i];

                    return parse;
                }
            }
        }
        else
        {
            if ((parse.inputFileName != NULL && !IfOutput) || (parse.outputFileName != NULL && parse.inputFileName != NULL))
            {
                parse.error = AppOptionsError_UNKNOWN_VALUE;
                parse.errorArgument = argv[i];
                return parse;
            }
            if (IfInt)
            {
                for (int k = 0; k < length; k++)
                {
                    if (!isdigit(buf[k]))
                    {
                        parse.errorArgument = argv[i];

                        parse.error = AppOptionsError_OPTION_VALUE_NOT_INT;
                        return parse;
                    }
                }
                parse.n = atoi(argv[i]);
                IfInt = false;
            }
            else if (IfOutput)
            {
                parse.outputFileName = argv[i];
                IfOutput = false;
            }
            else if (parse.inputFileName == NULL)
            {
                parse.inputFileName = argv[i];
            }
            else if (parse.inputFileName != NULL)
            {
                parse.error = AppOptionsError_UNKNOWN_VALUE;
                parse.errorArgument = argv[i];
                return parse;
            }
        }
    }
    if (parse.inputFileName == NULL)
    {
        parse.error = AppOptionsError_INPUT_FILE_MISSING;
    }
    if (IfOutput || IfInt)
    {
        parse.error = AppOptionsError_OPTION_VALUE_MISSING;
        parse.errorArgument = argv[argc - 1];
    }
    return parse;
}

int main(int argc, char *argv[])
{
    // Початок програми
    parseOptions(argc, argv);

    // Кінець програми
    return 0;
}
