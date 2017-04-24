#include <stdlib.h>
#include <string.h>

int isGoodIPString(char *str)
{
    short count_of_dots = 0, len = 0;

    if (str)
        while (str[len])
        {
            if (str[len] == '.')
                count_of_dots++;
            else if (str[len] < '0' || str[len] > '9')
                return (0);
            len++;
        }
    if (count_of_dots == 3 && (len > 6 && len < 16))
        return (1);
    return (0);   
}

int isValidIPAddress(char *str)
{
    int tmp = 0;

    if (!isGoodIPString(str))
        return (0);
    while (str != NULL)
    {
        tmp = atoi(str);
        if (tmp > 255 || (*str == '.' && *(str + 1) == '.'))
            return (0);
        if ((str = strchr(str, '.')) != NULL)
            str++;
    }
    return (1);
}