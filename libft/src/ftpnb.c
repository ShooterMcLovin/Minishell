/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpnb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:44:26 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 11:30:38 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>
#include <string.h>

//  BASE_UP "0123456789ABCDEF"
void	ftpnb(int base, int nb)
{
	if (nb >= base)
	{
		ftpnb(base, nb / base);
		ftpnb(base, nb % base);
	}
	if (nb < base)
		write(1, &BASE_UP[nb], 1);
}

void	ft_print_bits(int c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (i % 4 == 0 && i % 8 != 0)
			write(1, " ", 1);
	}
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	if (ac == 1)
// 	{
// 		printf("Wrong Input (no args)\n");
// 		return(0);
// 	}
// 	ftpnb(2, atoi(av[1]));
// 	write(1, "\n", 1);
// 	ft_print_bits(atoi(av[1]));
// }
