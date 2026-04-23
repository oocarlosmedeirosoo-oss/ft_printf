/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:03:20 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/23 20:52:46 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16, base);
	count += write (1, &base[n % 16], 1);
	return (count);
}

int	ft_print_hex(unsigned long n, char type)
{
	if (type == 'x')
		return (ft_put_hex(n, "0123456789abcdef"));
	return (ft_put_hex(n, "0123456789ABCDEF"));
}

int	ft_print_ptr(void	*ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += write (1, "(nil)", 5);
		return (count);
	}
	count += write (1, "0x", 2);
	count += ft_put_hex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}

/* #include <stdio.h>

int main(void)
{
	int x = 56;
	int *ptr = &x;
	char c = 'A';
	char *ptr2 = &c;
	void *ponteiro;
	void * ptr3 = NULL;
	
	printf("%p\n", ptr);
	printf("%p\n", ptr2);
	printf("%p\n", ptr3);
	printf("%p\n", ponteiro);
	printf("%p\n", NULL);
	printf("\n");
	
	ft_print_ptr(ptr);
	printf("\n");
	ft_print_ptr(ptr2);
	printf("\n");
	ft_print_ptr(ptr3);
	printf("\n");
	ft_print_ptr(ponteiro);
	printf("\n");
	ft_print_ptr(NULL);
	printf("\n");
	return (0);
} */