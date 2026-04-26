/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:16:27 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/23 23:00:54 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), type));
	else if (type == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	int		i;

	if (!str)
		return (-1);
	va_start (ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break;
			count += ft_dispatch(str[i], &ap);
		}
		else
			count += write (1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

/*
int main(void)
{
	int ft_ret, orig_ret;
	char *str = "Teste 42";
	void *ptr = &str;

	printf("=== COMPARATIVO FT_PRINTF VS PRINTF ===\n\n");
	
	// --- %c (Char) ---
	printf("[%%c]\n");
	ft_ret = ft_printf(" FT: %c\n", 'A');
	orig_ret = printf(" OR: %c\n", 'A');
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %s (String) ---
	printf("[%%s]\n");
	ft_ret = ft_printf(" FT: %s\n", str);
	orig_ret = printf(" OR: %s\n", str);
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %p (Ponteiro) ---
	printf("[%%p]\n");
	ft_ret = ft_printf(" FT: %p\n", ptr);
	orig_ret = printf(" OR: %p\n", ptr);
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %d e %i (Inteiros) ---
	printf("[%%d e %%i]\n");
	ft_ret = ft_printf(" FT: %d | %i\n", INT_MIN, 2147483647);
	orig_ret = printf(" OR: %d | %i\n", INT_MIN, 2147483647);
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %u (Unsigned) ---
	printf("[%%u]\n");
	ft_ret = ft_printf(" FT: %u\n", UINT_MAX);
	orig_ret = printf(" OR: %u\n", UINT_MAX);
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %x (Hexa Lower) ---
	printf("[%%x]\n");
	ft_ret = ft_printf(" FT: %x\n", 255);
	orig_ret = printf(" OR: %x\n", 255);
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %X (Hexa Upper) ---
	printf("[%%X]\n");
	ft_ret = ft_printf(" FT: %X\n", 255);
	orig_ret = printf(" OR: %X\n", 255);
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- %% (Percentagem) ---
	printf("[%%%%]\n");
	ft_ret = ft_printf(" FT: %%\n");
	orig_ret = printf(" OR: %%\n");
	printf("Retornos -> FT: %d | OR: %d\n\n", ft_ret, orig_ret);

	// --- Caso Nulo (String NULL) ---
	printf("[String NULL]\n");
	ft_ret = ft_printf(" FT: %s\n", (char *)NULL);
	orig_ret = printf(" OR: %s\n", (char *)NULL);
	printf("Retornos -> FT: %d | OR: %d\n", ft_ret, orig_ret);

	return (0);
}
*/