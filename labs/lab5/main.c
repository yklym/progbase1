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
#include <stdbool.h>

void printAllChar(int ASCIMIN, int ASCIMAX); //prints ASCI characters with indexes
void scanClear();
void putsblue(char str[50]);
void putsred(char str[50]);

int main()
{
    // Початок програми
    int kmain = 0;
    srand(time(0));
    Console_clear();
    putsblue("Good morning, master Bruce");
    putsblue("Shall I make you some coffe?");
    puts("");

    do
    {
        putsblue("M E N U");
        puts("1.Characters");
        puts("2.String");
        putsred("3.Quit");
        putsblue("4\'The Hobbit\'\nChapter I: AN UNEXPECTED PARTY ");

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
                putsblue("M E N U");
                printf("1.Alphanumeric\n");
                printf("2.Alphabetic (uppercase)\n");
                printf("3.Alphabetic (lowercase)\n");
                printf("4.Alphabetic (All)\n");
                printf("5.Decimal digit\n");
                printf("6.Hexadecimal digit\n");
                printf("7.Punctuation\n");
                putsred("\n\n8.<-- Go to Main menu");

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
                    putsred("I dont understand you\n");
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

            putsblue("Would you be so kind to enter N, please:");
            do
            {
                scanf("%i", &N);
                scanClear();
            } while (N <= 0);
            // N+=1;

            char main[N];

            for (int i = 0; i < N - 1; i++)
            {
                main[i] = rand() % (126 - 32 + 1) + 32;
            }
            main[N - 1] = '\0';

            Console_clear();
            do
            {
                Console_setCursorAttribute(FG_CYAN);
                putsblue("Your string:");
                Console_reset();
                printf("\"%s\"\n\n\n", main);

                putsblue("M E N U");
                puts("1.Change string");
                puts("2.Reset string");
                puts("3.Exctract substring");
                puts("4.Substrings divided by char");
                puts("5.The longest word");
                puts("6.Output all decimals");
                puts("7.Output summ of float");
                putsred("\n\n<--8.Main menu");
                scanf("%i", &kString);
                scanClear();
                switch (kString)
                {
                case 1:
                {
                    Console_clear();
                    putsblue("Enter your string:");
                    fgets(main, N + 1, stdin);
                    int strLength = strlen(main);
                    int hasNL = main[strLength - 1] == '\n';
                    if (hasNL)
                    {
                        main[strLength - 1] = '\0';
                    }
                    else if (strLength >= N)
                    {
                        scanClear();
                    }
                    Console_clear();
                }
                break;
                case 2:
                {
                    Console_clear();
                    main[0] = '\0';
                    Console_clear();
                }
                break;

                case 3:
                {
                    Console_clear();
                    puts(main);
                    putsblue("Choose index");
                    int indexBuf3 = 0;

                    do
                    {
                        scanf("%i", &indexBuf3);
                    } while (indexBuf3 > N || indexBuf3 < 0);
                    scanClear();

                    putsblue("Enter length");
                    int lenghtcase3 = 0;
                    scanf("%i", &lenghtcase3);

                    char strBuf3[N];
                    for (int i = indexBuf3 - 1, j = 0; i <= lenghtcase3; i++)
                    {
                        strBuf3[j] = main[i];
                        j++;
                    }

                    Console_clear();
                    putsblue("Your substring:");
                    printf("\"%s\"\n", strBuf3);
                }
                break;

                case 4:
                {
                    Console_clear();
                    puts(main);
                    putsblue("Subdividing char:");
                    char cahrBuf4 = ' ';
                    // scanClear();
                    scanf("%c", &cahrBuf4);
                    scanClear();
                    Console_clear();
                    Console_setCursorAttribute(FG_CYAN);
                    printf("Strings divided by \'%c\'\n", cahrBuf4);
                    Console_reset();
                    char strBuf4[N];
                    int tmpI = 0;
                    for (int i = 0;; i++)
                    {
                        char ch = main[i];
                        if (ch == cahrBuf4 || ch == '\0')
                        {
                            if (tmpI != 0)
                            {
                                strBuf4[tmpI] = '\0';
                                printf(">\"%s\"\n\n", strBuf4);

                                tmpI = 0;
                            }
                            if (ch == '\0')
                            {
                                break;
                            }
                        }
                        else
                        {
                            strBuf4[tmpI] = ch;
                            tmpI += 1;
                        }
                        // puts("\n");
                    }
                }
                break;

                case 5:
                {
                    Console_clear();
                    puts(main);
                    char maxlength[N];
                    maxlength[0] = '\0';
                    char strBuf5[N];
                    int tmpI = 0;
                    for (int i = 0;; i++)
                    {
                        char ch = main[i];
                        if (ch == '\0' || (isalpha(ch) == 0))
                        {
                            if (tmpI != 0)
                            {
                                strBuf5[tmpI] = '\0';
                                if (strlen(strBuf5) > strlen(maxlength))
                                {
                                    strcpy(maxlength, strBuf5);
                                }
                                tmpI = 0;
                            }
                            if (ch == '\0')
                            {
                                break;
                            }
                        }
                        else if (isalpha(ch))
                        {
                            strBuf5[tmpI] = ch;
                            tmpI += 1;
                        }
                        puts("\n");
                    }
                    Console_clear();
                    putsblue("The longest word is:");
                    puts(maxlength);
                }
                break;

                case 6:
                {
                    Console_clear();
                    char strBuf6[N];
                    strBuf6[0] = '\0';
                    int j = 0;
                    putsblue("Your decimals are:");
                    for (int i = 0;; i++)
                    {
                        char ch = main[i];
                        if (!(isdigit(ch)) || ch == '\0')
                        {
                            if (j != 0)
                            {
                                strBuf6[j] = '\0';
                                puts(strBuf6);
                                j = 0;
                            }
                            if (ch == '\0')
                            {
                                break;
                            }
                        }
                        else if (isdigit(ch))
                        {
                            strBuf6[j] = ch;
                            j += 1;
                        }
                    }
                }
                break;

                case 7:
                {
                    Console_clear();
                    char strBuf7[N];
                    strBuf7[0] = '0';
                    bool dotSaved = false;
                    float res = 0;
                    putsblue("Floats are:");
                    for (int i = 0, j = 0;; i++)
                    {
                        char ch = main[i];
                        if ((!isdigit(ch) && dotSaved) || ch == '\0')
                        {
                            if (j != 0)
                            {
                                strBuf7[j] = '\0';
                                puts(strBuf7);
                                res += atof(strBuf7);
                                j = 0;
                                dotSaved = false;
                            }
                            if (ch == '\0')
                            {
                                break;
                            }
                        }
                        if (!isdigit(ch) && !dotSaved && ch != '.')
                        {
                            strBuf7[j] = '\0';
                            j = 0;
                        }
                        bool dotSavedNot = (isdigit(ch) || ch == '.') && !dotSaved;
                        if (dotSavedNot || (isdigit(ch) && dotSaved))
                        {
                            strBuf7[j] = ch;
                            j += 1;
                            if (ch == '.')
                            {
                                dotSaved = true;
                            }
                        }
                    }
                    putsblue("Your res is:");
                    printf("%.2f\n", res);
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
                    putsred("Error, wrong value");
                }
                }
            } while (kString != 8);
        }
        break;

        case 3:
        {
            Console_clear();
        }
        break;

        case 4:
        {
            puts("\n");
            char bookmain[10000];
            strcpy(bookmain, "In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet hole, filled with the ends of worms\
and an oozy smell, nor yet a dry, bare, sandy hole with nothing in it to sit down on or to eat: it was a \
hobbit-hole, and that means comfort.It had a perfectly round door like a porthole, painted green, with a shiny yellow brass knob in the \
exact middle. The door opened on to a tube-shaped hall like a tunnel: a very comfortable tunnel \
without smoke, with panelled walls, and floors tiled and carpeted, provided with polished chairs, and \
lots and lots of pegs for hats and coats — the hobbit was fond of visitors. The tunnel wound on and on, \
going fairly but not quite straight into the side of the hill — The Hill, as all the people for many miles \
round called it — and many little round doors opened out of it, first on one side and then on another. No \
going upstairs for the hobbit: bedrooms, bathrooms, cellars, pantries (lots of these), wardrobes (he had \
whole rooms devoted to clothes), kitchens, dining-rooms, all were on the same floor, and indeed on \
the same passage. The best rooms were all on the left-hand side (going in), for these were the only \
ones to have windows, deep-set round windows looking over his garden, and meadows beyond, sloping \
down to the river. This hobbit was a very well-to-do hobbit, and his name was Baggins. The Bagginses had lived in \
the neighbourhood of The Hill for time out of mind, and people considered them very respectable, not \
only because most of them were rich, but also because they never had any adventures or did anything \
unexpected: you could tell what a Baggins would say on any question without the bother of asking \
him. This is a story of how a Baggins had an adventure, and found himself doing and saying things \
altogether unexpected. He may have lost the neighbours’ respect, but he gained — well,you will see \
whether he gained anything in the end.The mother of our particular hobbit — what is a hobbit? I suppose hobbits need some description \
nowadays, since they have become rare and shy of the Big People, as they call us. They are (or were) a \
little people, about half our height, and smaller than the bearded Dwarves. Hobbits have no beards. \
There is little or no magic about them, except the ordinary everyday sort which helps them to \
disappear quietly and quickly when large stupid folk like you and me come blundering along, making \
a noise like elephants which they can hear a mile off. They are inclined to be fat in the stomach; they \
dress in bright colours (chiefly green and yellow); wear no shoes, because their feet grow natural \
leathery soles and thick warm brown hair like the stuff on their heads (which is curly); have long \
clever brown fingers, good-natured faces, and laugh deep fruity laughs (especially after dinner, which \
they have twice a day when they can get it). Now you know enough to go on with. As I was saying, the \
mother of this hobbit — of Bilbo Baggins, that is — was the famous Belladonna Took, one of the three \
remarkable daughters of the Old Took, head of the hobbits who lived across The Water, the small river \
that ran at the foot of The Hill. It was often said (in other families) that long ago one of the Took \
ancestors must have taken a fairy wife. That was, of course, absurd, but certainly there was still \
something not entirely hobbitlike about them, and once in a while members of the Took-clan would go \
and have adventures. They discreetly disappeared, and the family hushed it up; but the fact remained");

            Console_clear();
            int page = 0;
            putsred("Lets start reading, choose a page");
            char buf[1005];
            while(1)
            {
                scanf("%i", &page);
                if (page == 0){
                    break;
                }
                Console_clear();

                for (int j = 0; j < 1000; j++)
                {
                    buf[j] = bookmain[(page - 1) * 1000 + j];
                }
                for (int i = 0; i < 3; i++)
                {
                    buf[1000 + i + 1] = '.';
                }
                buf[1004] = '\0';
                Console_setCursorAttribute(FG_GREEN);
                printf("Hobbit, chapter 1, page %i\n\n", page);
                Console_reset();
                puts(buf);

                putsblue("\n\nChoose your page(4 pages, 0 to exit)");
            };
            Console_clear();
        }
        break;

        default:
        {
            Console_clear();
            putsred("Sorry, master, I dont understand you\n");
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
void scanClear()
{
    for (char _ch; (_ch = getchar()) != '\n';)
    {
    }
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