#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MISSIN_COMD 0   //missing command
#define ERR_UKNOWN_COMD 1   //unknown command
#define ERR_BAD_IP_ADDR 2   //bad IP address
#define ERR_USUPPORT_IF 3   //unsupport interface

void oneWordCommands(char **argv);
void twoWordsCommands(char **argv);
void threeWordsCommands(char **argv);
#warning change funct name
void someName(short errno, char *program_name);

int main(int argc, char **argv)
{
    switch(argc)
    {
        case 2 :
            //printf("argc == 2\n");
            oneCommands(argv);
            break;
        case 3 :
            twoWordsCommands(argv);
            //printf("argc == 3\n");
            break;
        case 4 :
            threeWordsCommands(char **argv)
            //printf("argc == 4\n");
            break;
        default :
            printf("error\n");
            break;
    }
    return (0);
}

void oneWordCommands(char **argv)
{
    if (strcmp("start", argv[1]) == 0)
        printf("start\n");
    else if (strcmp("stop", argv[1]) == 0)
        printf("stop\n");
    else if (strcmp("stat", argv[1]) == 0)
        printf("all stat\n");
    else if (strcmp("--help", argv[1]) == 0 || strcmp("-h", argv[1]) == 0)
        printf ("help\n");
    else
        someName(ERR_UKNOWN_COMD, argv[0] + 2);   // +2 for skiping ./
}

void twoWordsCommands(char **argv)
{
    if (strcmp("stat", argv[1]) == 0)
        printf("Statistics for %s interface:\n");
    else
        someName(ERR_UKNOWN_COMD, argv[0] + 2);
    //some method is here
}

void threeWordsCommands(char **argv)
{
    
}

void someName(short errno, char *program_name)
{
    switch(errno)
    {
        case ERR_MISSIN_COMD :
            printf("%s: missing file operand\n", program_name);
            break;
        case ERR_UKNOWN_COMD :
            printf("%s: unknown file operand\n", program_name);
            break;
        case ERR_BAD_IP_ADDR :
            printf("%s: bad ip address\n", program_name);
            break;
        case ERR_USUPPORT_IF :
            printf("%s: unsupporting interface\n", program_name);
            break;
        default :
            printf("%s: unexpected error\n", program_name);
            break;
    }
    printf("Try '%s --help' for more information.\n", program_name);
}