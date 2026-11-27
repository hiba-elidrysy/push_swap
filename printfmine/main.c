#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("%d\n", printf("%d %", 10));
    printf("%d", ft_printf("%d %", 10));
    return (0);
}