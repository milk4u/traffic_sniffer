#ifndef SNIFFER_H
#define SNIFFER_H

char **strsplit(char const *s, char c);
size_t countWords(const char *s, char sep);
int isValidIPAddress(char *str);
int isValidIface(char *iface);
char *mygetline(void);

#endif