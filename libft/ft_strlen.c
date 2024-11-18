/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:49:18 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:21 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
/*
int	main(void)
{
	char test1[20] = "Hello";
	char test2[25] = "Good morning!";

	// Should return 5
	printf("%zu\n", ft_strlen(test1));

	// Should return 13
	printf("%zu\n", ft_strlen(test2));
	return (0);
}
*/