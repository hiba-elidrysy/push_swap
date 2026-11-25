#include "push_swap.h"

int count_nbr(const char *str)
{
    int x;
    int i;
    int count;

    x = 1;
    i = 0;
    count = 0;
    while (x)
    {
        while(str[i] == ' ')
            i++;
        if(str[i] == '-' || str[i] == '+')
            i++;
        if(str[i] >= '0' && str[i] <= '9')
        {
            count++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            if(str[i] != ' ')
                x = 0;
        }
        else
            x = 0;
    }
    if (str[i] && str[i] != ' ')
        return (0);
    return (count);
}

char *put_chr(const char *str, int *i)
{
    int count;
    int j;
    int k;
    char *nbr;

    count = 0;
    j = *i;
    if(str[*i] == '-' || str[*i] == '+')
    {
        count++;
        (*i)++;
    }
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        count++;
        (*i)++;
    }
    nbr = malloc(count + 1);
    if (!nbr)
        return (NULL);
    nbr[count] = '\0';
    k = 0;
    while(k < count)
        nbr[k++] = str[j++];
    return (nbr);
}


void    num_free(char **num, int k)
{
    int i;

    i = 0;
    while(i < k)
        free(num[i++]);
}

char    **ft_split(const char *str)
{
    int i;
    int j;
    int count;
    char    **nbr;
    
    count = count_nbr(str);
    if (count == 0)
    {
        ft_putchar("Error\n");
        return (NULL);
    }
    nbr = (char **)malloc(sizeof(char *) * (count + 1));
    nbr[count] = NULL;
    i = 0;
    j = 0;
    while(j < count)
    {
        while(str[i] == ' ')
            i++;
        nbr[j] = put_chr(str, &i);
        if(!nbr[j])
        {
            num_free(nbr, j);
            return (NULL);
        }
        j++; 
    }
    return (nbr);
}

int is_valid(const char *str)
{
    if(ft_split(str))
        return (1);
    else
        return (0);
}

char *ft_strjoin(const char **str, int count)
{
    int i;
    int j;
    int k;
    int tmp_len;
    int len;
    char *total;

    i = 1;
    len = 0;
    while (i < count)
    {
        if (is_valid(str[i]))
        {
            tmp_len = ft_strlen(str[i]);
            len += tmp_len;
            i++;            
        }
        else
            return(NULL);
    }
    total = malloc(2 * len + 1);
    if (!total)
        return (NULL);
    total[len] = '\0';
    i = 1;
    k = 0;
    while(i < count)
    {
        j = 0;
        while(str[i][j])
        {
            total[k] = str[i][j];
            k++;
            j++;
        }
        total[k++] = ' ';
        i++;
    }
    return (total);
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