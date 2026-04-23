/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbosa <cbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:01:58 by cbarbosa          #+#    #+#             */
/*   Updated: 2026/04/23 21:17:43 by cbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int		count;
	long	nbr;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += write (1, "-", 1);
		nbr = -nbr;
	}
	count += ft_print_unsigned((unsigned int)nbr);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += write (1, &"0123456789"[n % 10], 1);
	return (count);
}

/* #include <stdio.h>

int	main(void)
{
	int	res_ft;
	int	res_orig;


	ft_printf("TESTES\n");
	
	res_ft = ft_print_int(12345);
	ft_printf("\nRetorno do meu ft: %d\n", res_ft);
	printf("\nRetorno do PRINTF: %d\n", res_ft);

	ft_printf("\n");
	
	res_ft = ft_print_int(-987);
	ft_printf("\nRetorno do meu ft: %d\n", res_ft);
	printf("\nRetorno do PRINTF: %d\n", res_ft);

	ft_printf("\n");
	
	res_ft = ft_print_int(0);
	ft_printf("\nRetorno do meu ft: %d\n", res_ft);
	printf("\nRetorno do PRINTF: %d\n", res_ft);

	ft_printf("\n");
	
	res_ft = ft_print_int(-2147483648);
	ft_printf("\nRetorno do meu ft: %d\n", res_ft);
	printf("\nRetorno do PRINTF: %d\n", res_ft);


	ft_printf("\n");
	
	res_ft = ft_print_unsigned(4294967295U);
	ft_printf("\nRetorno do meu ft: %d\n", res_ft);
	printf("\nRetorno do PRINTF: %d\n", res_ft);

 	return (0);
} */