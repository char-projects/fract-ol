/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:45:07 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:04:49 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks for a digit (0 through 9) */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
int	main(void)
{
	// Should return 1
        printf("Test 0: %d\n", ft_isdigit('3'));
        printf("Test 1: %d\n", ft_isdigit('8'));
        printf("Test 2: %d\n", ft_isdigit('0'));

        // Should return 0
        printf("Test 3: %d\n", ft_isdigit('f'));
        printf("Test 4: %d\n", ft_isdigit(-1));

        return (0);
}
*/