#include "ft_printf.h"

static int ft_put_nbr(long nb)
{
    int count;

    count = 0;
    if (nb >= 10)
        count += ft_put_nbr(nb / 10);
    count += write (1, &"0123456789"[nb % 10], 1);
    return (count);
}

static int ft_put_unsigned(unsigned int n)
{
    int count;

    count = 0;
    if (n >= 10)
        count += ft_put_unsigned(n / 10);
    count += write (1, &"0123456789"[n % 10], 1);
    return (count);
}

int ft_print_nbr(int n)
{
    long nb;
    int count;

    nb = (long)n;
    count = 0;
    if (nb < 0)
    {
        count += write (1, "-", 1);
        nb = -nb;
    }
    count += ft_put_nbr(nb);
    return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_put_unsigned(n));
}
