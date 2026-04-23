#include "ft_printf.h"

//terceiro passo
static int ft_put_hex(unsigned long n, char *base)
{
    int count;

    count = 0;
    if ( n >= 16)
        count += ft_put_hex(n / 16, base);
    count += write (1, &base[n % 16], 1);
    return (count);
}

//segundo passo
int ft_print_hex(unsigned long n, char type)
{
    if (type == 'x')
        return (ft_put_hex(n, "0123456789abcdef"));
    return (ft_put_hex(n, "0123456789ABCDEF"));
}

//primeiro passo
int ft_print_ptr(void *ptr)
{
    int count;

    if (ptr == NULL)
        return (write (1, "(nil)", 5));
    count = 0;
    count += write (1, "0x", 2);
    count += ft_print_hex((unsigned long)ptr, 'x');
    return (count);
}
