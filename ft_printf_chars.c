#include "ft_printf.h"

int ft_print_char(char c)
{
    int count;
    count = write(1, &c, 1);
    return (count);
}

int ft_print_str(char *s)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (s == NULL)
        return (write(1, "(null)", 6));
    while (s[i])
    {
        write(1, &s[i], 1);
        count++;
        i++;
    }
    return (count);
}
