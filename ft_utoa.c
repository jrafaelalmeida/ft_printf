/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpacheco <jpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:02:49 by jpacheco          #+#    #+#             */
/*   Updated: 2023/05/08 22:02:50 by jpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	ft_utoa(unsigned int n)
{
	size_t	len;
	char	*numbers;
	int		count;

	count = 0;
	len = ft_count_digits(n);
	numbers = malloc((len + 1) * sizeof(char));
	if (!numbers)
		return (0);
	numbers[len] = '\0';
	if (n == 0)
		numbers[0] = '0';
	while (n != 0)
	{
		len--;
		numbers[len] = (n % 10) + '0';
		n = n / 10;
	}
	count += ft_putstr(numbers);
	free(numbers);
	return (count);
}
