/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:50:27 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:50:29 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	printf("%c\n", ft_toupper('h'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('P'));
}
*/