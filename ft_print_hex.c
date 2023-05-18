/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpacheco <jpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:02:47 by jpacheco          #+#    #+#             */
/*   Updated: 2023/05/08 22:02:47 by jpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, const char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_puthex((nb / 16), c);
		count += ft_puthex((nb % 16), c);
	}
	else
		count += write(1, &base[nb], 1);
	return (count);
}
