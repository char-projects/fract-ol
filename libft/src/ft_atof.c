/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:31:28 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 22:30:38 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	ft_atof(char *str)
{
	double	nb;
	double	fract;
	int		sign;
	double	power;

	nb = 0;
	fract = 0.0;
	sign = 1;
	power = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str != '.')
		nb = (nb * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str)
	{
		power /= 10;
		fract = fract + (*str++ - '0') * power;
	}
	return ((nb + fract) * sign);
}
