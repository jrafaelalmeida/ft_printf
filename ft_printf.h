/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpacheco <jpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:43:42 by jpacheco          #+#    #+#             */
/*   Updated: 2023/05/08 20:43:43 by jpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nb);
int	ft_puthex(unsigned long nb, const char c);
int	ft_putpointer(unsigned long nb);
int	ft_utoa(unsigned int n);

#endif