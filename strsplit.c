#include <string.h>
#include <stdlib.h>

char *strnew(size_t size)
{
    char *str;

    if (!(str = malloc(sizeof(char) * size + 1)))
    {
        perror("Malloc error in strnew");
        exit(EXIT_FAILURE);
    }
    memset(str, 0, size + 1);
    return (str);
}

size_t countWords(const char *s, char sep)
{
    size_t c_words;
    
    c_words = 0;
    while (*s)
    {
        if (*s != sep)
        {
            c_words++;
            while (*s != sep && *s)
                s++;
            if (*s == '\0')
                break ;
        }
        s++;
    }
    return (c_words);
}

static size_t countLength(const char *s, char sep)
{
    size_t c_lenght = 0;

    while (*s != sep && *s)
    {
        c_lenght++;
        s++;
    }
    return (c_lenght);
}

char **strsplit(char const *s, char c)
{
    char **ans;
    size_t wl = 0, i = 0;

    if (!s)
        return (NULL);
    if (!(ans = (char**)malloc(sizeof(char*) * (countWords(s, c) + 1))))
        return (NULL);
    while (*s != '\0')
    {
        if (*s != c)
        {
            wl = countLength(s, c);
            ans[i] = strnew(wl);
            strncpy(ans[i++], s, wl);
            s += wl;
        }
        if (*s == '\0')
            break ;
        s++;
    }
    ans[i] = NULL; //terminated
    return (ans);
}