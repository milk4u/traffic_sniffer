#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sniffer.h"

#define ERR_MISSIN_COMD 0   //missing command
#define ERR_UKNOWN_COMD 1   //unknown command
#define ERR_BAD_IP_ADDR 2   //bad IP address
#define ERR_UKNOWN_IFAC 3   //unsupport interface
#define ERR_TOO_MANY_AG 4   //too many arguments

void oneWordCommands(char **words);
void twoWordsCommands(char **words);
void threeWordsCommands(char **words);
void printErrorMessage(short errno);

int main(void)
{
    char *line, **words;
    int c_words;

    while(1)
    {
        line = mygetline();
        c_words = countWords(line, ' ');
        words = strsplit(line, ' ');

        switch(c_words)
        {
            case 0 :
                printErrorMessage(ERR_MISSIN_COMD);
                break;
            case 1 :
                //printf("argc == 2\n");
                oneWordCommands(words);
                break;
            case 2 :
                twoWordsCommands(words);
                //printf("argc == 3\n");
                break;
            case 3 :
                threeWordsCommands(words);
                //printf("argc == 4\n");
                break;
            default :
                printErrorMessage(ERR_TOO_MANY_AG);
                break;
        }
    }
    return (0);
}

void oneWordCommands(char **words)
{
    if (strcmp("start", words[0]) == 0)
    {
        #warning start sniffing here
        printf("start\n");
    }
    else if (strcmp("stop", words[0]) == 0)
    {
        printf("stop\n");
        #warning save data here
        exit(EXIT_SUCCESS);
    }
    else if (strcmp("stat", words[0]) == 0)
    {
        #warning showing stat here
        printf("all stat\n");
    }
    else if (strcmp("--help", words[0]) == 0 || strcmp("-h", words[0]) == 0)
    {
        printf("help\n");
        #warning showing --help here
    }
    else
        printErrorMessage(ERR_UKNOWN_COMD);
}

void twoWordsCommands(char **words)
{
    if (strcmp("stat", words[0]) == 0)
    {
        if (!isValidIface(words[1]))
            printErrorMessage(ERR_UKNOWN_IFAC);
        else
            printf("Statistics for %s interface:\n", words[1]);
            #warning dosmth with showing all collected statistics for particular interface
    }
    else
        printErrorMessage(ERR_UKNOWN_COMD);
}

void threeWordsCommands(char **words)
{
    if (strcmp("show", words[0]) == 0)
    {
        if (!isValidIPAddress(words[1]))
            printErrorMessage(ERR_BAD_IP_ADDR);
        else if (strcmp("count", words[2]) == 0)
            printf("Number of packets received from %s address: ", words[1]);
            #warning dosmth with count number of packets received from ip address
    }
    else if (strcmp("select", words[0]) == 0 && strcmp("iface", words[1]) == 0)
    {
        if (!isValidIface(words[2]))
            printErrorMessage(ERR_UKNOWN_IFAC);
        else
            printf ("Selected interface %s for sniffing", words[2]);
            #warning dosmth with selecting interface for sniffing
    }
}

void printErrorMessage(short errno)
{

    switch(errno)
    {
        case ERR_MISSIN_COMD :
            printf("Missing file operand\n");
            break;
        case ERR_UKNOWN_COMD :
            printf("Unknown file operand\n");
            break;
        case ERR_BAD_IP_ADDR :
            printf("Bad ip address\n");
            break;
        case ERR_UKNOWN_IFAC :
            printf("Unknown interface\n");
            break;
        case ERR_TOO_MANY_AG :
            printf("Too many arguments exeption\n");
            break;
        default :
            printf("Unexpected error\n");
            break;
    }
    printf("Try '--help' for more information.\n");
}