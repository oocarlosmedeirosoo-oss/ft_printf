#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int count;
    int i;

    va_start(ap, fmt);
    i = 0;
    count = 0;
    while (fmt[i])
    {
        if (fmt[i] == '%')
        {
            i++;
            count += ft_dispatch(fmt[i], ap);
        }
        else
        {
            write (1, &fmt[i], 1);
            count++;
        }
        i++;
    }
    va_end(ap);
    return (count);
}

int	ft_dispatch(char type, va_list ap)
{
	if (type == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), type));
	else if (type == '%')
		return (write(1, "%", 1));
	return (0);
}