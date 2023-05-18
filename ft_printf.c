/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpacheco <jpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:44:13 by jpacheco          #+#    #+#             */
/*   Updated: 2023/05/09 00:27:18 by jpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(char type, va_list ap)
{
	int	count;

	count = 0;
	if (!type)
		return (0);
	if (type == '%')
		count += write(1, "%", 1);
	else if (type == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		count += ft_putpointer(va_arg(ap, unsigned long));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (type == 'u')
		count += ft_utoa(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), type);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (0);
	while (*format != 0)
	{
		if (*format == '%')
			count += conversion(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
