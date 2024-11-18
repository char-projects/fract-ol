/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:48:41 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:48:43 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Return value: None
External functions: None
Description: Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*
void	to_upper(unsigned int i, char *c)
{
	(void)i; // Unused parameter
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	i++;
}

int	main(void)
{
	char str[] = "hello, world";
	printf("Before: %s\n", str);
	ft_striteri(str, to_upper);
	printf("After: %s\n", str);
}
*/
