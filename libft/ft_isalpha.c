/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:44:45 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:03:43 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks for an alphabetic character; it is equivalent to
(isupper(c) ||  islower(c)) */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int	main(void)
{
	// Should return 1
        printf("Test 0: %d\n", ft_isalpha('b'));
        printf("Test 1: %d\n", ft_isalpha('W'));
        printf("Test 2: %d\n", ft_isalpha('z'));

        // Should return 0
        printf("Test 3: %d\n", ft_isalpha('?'));
        printf("Test 4: %d\n", ft_isalpha(-1));

        return (0);
}
*/