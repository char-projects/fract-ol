/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:56:26 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 22:30:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_hex(unsigned long long n, unsigned int base, char *basestr)
{
	int	count;

	count = 0;
	if (n >= base)
		count += ft_putnbr_hex(n / base, base, basestr);
	count += ft_putchar(basestr[n % base]);
	return (count);
}

int	ft_putpointer(unsigned long long hello)
{
	int	count;

	count = 0;
	if (hello == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += write(1, "0x", 2);
		count += ft_putnbr_hex(hello, 16, "0123456789abcdef");
	}
	return (count);
}

int	ft_putudec(unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
		count += ft_putchar('0');
	else
	{
		if (i / 10)
			ft_putudec(i / 10);
		ft_putchar((i % 10) + '0');
		while (i > 0)
		{
			i /= 10;
			count++;
		}
	}
	return (count);
}

int	find_conversion(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_putpointer(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putudec(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_putnbr_hex(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		i += ft_putnbr_hex(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += find_conversion(str[++i], args);
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
