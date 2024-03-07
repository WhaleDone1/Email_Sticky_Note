#ifndef LIB_ESN_H
#define LIB_ESN_H

#include <stddef.h>

extern const char *filename;

int ft_strcmp(const char *s1, const char *s2);
int checkDuplicateName(const char *name);

size_t ft_strlen(const char *str);

char *ft_strstr(const char *big, const char *little);

void displayHelp(void);
void removeAddress(const char *name);
void addAddress(const char *name, const char *email, const char *note);
void getAddress(const char *name);

#endif