/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpacheco <jpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:44:10 by jpacheco          #+#    #+#             */
/*   Updated: 2023/05/08 23:55:43 by jpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	if (n < 10)
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_putpointer(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_puthex(nb, 'x');
	return (count);
}
