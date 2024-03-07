#include "../ESN/lib_esn.h"
#include "../Ft_printf/lib_ftprintf.h"

// size_t ft_strlen(const char *str) already in Ft_printf so no need here.

char *ft_strstr(const char *big, const char *little)
{
    size_t i;
    size_t j;

    i = 0;
    if (little[0] == '\0')
        return ((char *)big);
    while (big[i] != '\0')
    {
        j = 0;
        while (big[i + j] == little[j] && little[j] != '\0')
        {
            j++;
        }
        if (little[j] == '\0')
            return ((char *)&big[i]);
        i++;
    }
    return (NULL);
}

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
