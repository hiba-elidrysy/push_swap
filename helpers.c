#include "push_swap.h"

int ft_strlen(const char *str)
{
    int count;

    count = 0;
    while (*str++)
        count++;
    return (count);
}

void ft_putchar(const char *str)
{
    while(*str)
        write(1, str++, 1);
}


int ft_atoi(const char *str)
{
    long nbr;
    int sign;

    nbr = 0;
    sign = 1;
    while (*str == ' ')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }
    return ((int)(nbr * sign));
}

int ft_strcmp(const char *s1, const char *s2)
{
    while(s1 && s2 && *s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return ((int)(*s2 - *s1));
}