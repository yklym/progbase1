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

    struct AppOptions test;
    test.inputFileName = NULL;
    test.outputFileName = NULL;
    test.n = 0;
    test.encodeMode = false;
    test.decodeMode = false;
    test.testMode = false;
    test.helpMode = false;
    test.error = AppOptionsError_NO_ERROR;
    test.errorArgument = NULL;

    char buf[100];
    for (int i = 1; i < argc; i++)
    {
        strcpy(buf, argv[i]);
        int length = strlen(buf);

        if (buf[0] == '-')
        {
            if (IfInt)
            {
                test.error = AppOptionsError_OPTION_VALUE_MISSING;
                test.errorArgument = argv[i];
            }
            if (IfOutput)
            {
                test.error = AppOptionsError_OPTION_VALUE_MISSING;
                test.errorArgument = argv[i];
            }
            for (int j = 1; j < length; j++)
            {
                if (buf[j] == 'd')
                {
                    test.decodeMode = true;
                }
                else if (buf[j] == 'h')
                {
                    test.helpMode = true;
                }
                else if (buf[j] == 'e')
                {
                    test.encodeMode = true;
                }
                else if (buf[j] == 't')
                {
                    test.testMode = true;
                }
                else if (buf[j] == 'n')
                {
                    IfInt = true;
                }
                else if (buf[j] == 'o')
                {
                    IfOutput = true;
                }
            }
        }
        else
        {
            if (IfInt)

            {
                for(int k = 0; k < length; k++){
                    if (!isdigit(buf[k])){
                        test.error = AppOptionsError_OPTION_VALUE_NOT_INT;
                    }
                }
                test.n = atoi(argv[i]);
            }
            else if (IfOutput)
            {
                test.outputFileName = argv[i];
            }
            else
            {
                test.inputFileName = argv[i];
            }
        }
    }

    return test;
}

int main(int argc, char *argv[])
{
    // Початок програми
    parseOptions(argc, argv);

    // Кінець програми
    return 0;
}
