/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:01:49 by alpicard          #+#    #+#             */
/*   Updated: 2022/12/12 16:42:28 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printnbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10)
		len += ft_printchar(nb + '0');
	else if (nb >= 10)
	{
		len += ft_printnbr(nb / 10);
		len += ft_printchar(nb % 10 + '0');
	}
	return (len);
}
