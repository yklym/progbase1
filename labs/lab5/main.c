// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>            // Для друку в термінал
#include <math.h>             // Для математичних функцій
#include <stdlib.h>           // Деякі додаткові функції
#include <progbase/console.h> // Спрощений ввід і вивід даних у консоль
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <time.h>

void printAllChar(int ASCIMIN, int ASCIMAX);
void scanClear ();

int main()
{
    // Початок програми
    int kmain = 0;
    srand(time(0));
    Console_clear();
    printf("Good morning, master Bruce\n");
    printf("Shall I make you some coffe?\n");
    printf("\n");

    do
    {
        printf("1.Characters\n");
        printf("2.String\n");
        printf("3.Quit\n");

        scanf("%i", &kmain);
        scanClear();

        switch (kmain)
        {
        case 1:
        {
            int kChar = 0;
            Console_clear();
            do
            {
                // Console_clear();
                printf("1.Alphanumeric\n");
                printf("2.Alphabetic (uppercase)\n");
                printf("3.Alphabetic (lowercase)\n");
                printf("4.Alphabetic (All)\n");
                printf("5.Decimal digit\n");
                printf("6.Hexadecimal digit\n");
                printf("7.Punctuation\n");
                printf("\n\n8.<-- Go to Main menu\n");

                scanf("%i", &kChar);

                switch (kChar)
                {
                case 1:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(97, 122);
                    printAllChar(65, 90);
                    printAllChar(48, 57);
                    puts("\n");
                }
                break;

                case 2:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(65, 90);
                    puts("\n");
                }
                break;

                case 3:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(97, 122);
                    puts("\n");
                }
                break;

                case 4:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(97, 122);
                    printAllChar(65, 90);
                    puts("\n");
                }
                break;

                case 5:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(48, 57);
                    puts("\n");
                }
                break;

                case 6:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(48, 57);
                    printAllChar(97, 102);
                    printAllChar(65, 70);
                    puts("\n");
                }
                break;

                case 7:
                {
                    Console_clear();
                    puts("Your request:");
                    printAllChar(33, 47);
                    puts("\n");
                }
                break;

                case 8:
                {
                    Console_clear();
                }
                break;

                default:
                {
                    Console_clear();
                    printf("I dont understand you properly\n\n");
                }
                }
            } while (kChar != 8);
        }
        break;

        case 2:
        {
            Console_clear();
            int N = 0;
            int kString = 0;
            
            puts("Would you be so kind to enter N, please:");
            do{
                scanf("%i", &N);
                scanClear();
            } while(N <= 0);
            // N+=1;
            
            char main[N];
            
            for(int i = 0; i < N - 1; i++){
                main[i] = rand() % (126 - 32 + 1) + 32;
            }
            main [N+1] = '\0';

            Console_clear();
            do {
                puts("Your string:");
                printf("\"%s\"\n\n\n", main);

                puts("1.Change string");
                puts("2.Reset string");
                puts("3.Exctract substring");
                puts("4.Substrings divided by char");
                puts("5.The longest word");
                puts("6.");
                puts("7.");
                puts("<--8.Main menu");
                scanf("%i", &kString);
                scanClear();
                switch (kString){
                    case 1 : {
                        Console_clear();
                        puts("Enter your string:");
                        fgets(main, N + 1 , stdin);
                        int strLength = strlen(main);
                        int hasNL = main[strLength - 1] == '\n';
                        if (hasNL){
                            main[strLength - 1] = '\0';
                            // strLength -= 1;
                        } else if (strLength >= N) {
                            scanClear();
                        }
                        // scanClear();
                        Console_clear();
                
                    } break;
                     case 2: {
                        Console_clear();
                        main[0] = '\0';
                        Console_clear();
                    } break;
                    
                    case 3: {
                        Console_clear();
                        puts(main);
                        puts("Choose index");
                        int indexCase3 = 0;
                        
                        do {
                        scanf("%i", &indexCase3);
                        } while(indexCase3 > N || indexCase3 < 0);
                        scanClear();
                        
                        puts("Enter length");
                        int lenghtcase3 = 0;
                        scanf("%i", &lenghtcase3);
                        
                        char case3buf[N];
                        for(int i = indexCase3 - 1, j = 0; i <= lenghtcase3; i++){
                            case3buf[j] = main[i];
                            j++;
                        }
                        
                        Console_clear();
                        puts("Your substring:");
                        printf("\"%s\"\n", case3buf);
                    } break;
                    
                    case 4: {
                        Console_clear();
                        puts(main);
                        puts("Subdividing char:");
                        char case4char = ' ';
                        // scanClear();
                        scanf("%c", &case4char);
                        scanClear();
                        Console_clear();
                        printf("Strings divided by \'%c\'\n",  case4char);
                        char case4buf[N];
                        int tmpI = 0;
                        for(int i = 0; ; i++){
                            char ch = main[i];
                            if (ch == case4char || ch =='\0'){
                                if (tmpI != 0 ){
                                    case4buf[tmpI] = '\0';
                                    printf(">");
                                    puts(case4buf);
                                    tmpI = 0;
                                }
                                if (ch == '\0'){
                                    break;
                                } 
                            
                            } 
                            else {
                                    case4buf[tmpI] = ch;
                                    tmpI += 1;
                            }
                            // puts("\n");
                        }
                    } break;
                    
                    case 5: {
                        Console_clear();
                        puts(main);
                        char maxlength[N];
                        maxlength[0] = '\0';
                        char case4buf[N];
                        int tmpI = 0;
                        for(int i = 0; ; i++){
                            char ch = main[i];
                            if (ch == ' ' || ch =='\0'){
                                if (tmpI != 0 ){
                                    case4buf[tmpI] = '\0';
                                    if (strlen(case4buf)>strlen(maxlength)){
                                        strcpy(maxlength, case4buf);
                                        
                                    }
                                    tmpI = 0;
                                    
                                }
                                if (ch == '\0'){
                                    break;
                                } 
                            
                            } 
                            else if (ch >= 65 & ch <= 122){
                                    case4buf[tmpI] = ch;
                                    tmpI += 1;
                            }
                            puts("\n");
                        }
                        Console_clear();
                        puts("The longest word is:");
                        puts(maxlength);
                    } break;
                    
                    case 6: {
                        // scanClear();
                        Console_clear();
                        char case6buf[N];
                        // case6buf[0] = '\0';
                        // char case6digit[N];
                        // case6digit[0] = '\0';
                        int j = 0;
                        puts("Your decimals are:");
                        for(int i = 0; ; i++){
                            char ch = main[i];
                            if(!(isdigit(ch)) || ch == '\0'){
                                if(j!=0){
                                    case6buf[j] = '\0';
                                    puts(case6buf);
                                    j = 0;
                                }
                                if (ch == '\0'){
                                    break;
                                }

                            } else if (isdigit(ch)){
                                case6buf[j] = ch;
                                j+= 1;
                            }
                            
                            
                        }
                        // printf("%i\n",atoi(main));
                    } break;
                    
                    case 7: {
                        printf("HelloHElloHELO\n");
                    } break;
                    
                    
                    case 8:{
                        Console_clear();
                    } break;
                    
                    default: {
                        puts("Error, wrong value");
                    } 
                }
            } while(kString != 8);
        }
        break;

        case 3:
        {
            Console_clear();
        }
        break;

        default:
        {
            Console_clear();
            printf("Sorry, master, I dont understand you\n\n");
        }
        }

    } while (kmain != 3);

    // Кінець програми
    return 0;
}

void printAllChar(int ASCIMIN, int ASCIMAX)
{
    for (int output = ASCIMIN; output <= ASCIMAX; output++)
    {
        Console_setCursorAttribute(FG_CYAN);
        printf("%c", output);
        Console_reset();
        printf(" ");
    }
    printf("\n");
}
void scanClear () {
    for (char _ch; (_ch = getchar()) != '\n';){}
}