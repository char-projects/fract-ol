/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:45:16 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:05:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks for any printable character including space */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

/*
int	main(void)
{
	// Should return 1
        printf("Test 0: %d\n", ft_isprint('b'));
        printf("Test 1: %d\n", ft_isprint(' '));
        printf("Test 2: %d\n", ft_isprint('+'));

        // Should return 0
        printf("Test 3: %d\n", ft_isprint('\n'));
        printf("Test 4: %d\n", ft_isprint('\0'));

        return (0);
}
*/