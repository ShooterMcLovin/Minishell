/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:44:16 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/27 13:51:40 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printnbr_base(unsigned int nb, char *base_ref, unsigned int base)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	nbr = nb;
	if ((int)nb < 0 && base == 10)
	{
		len += ft_printchar('-');
		nbr = nb * -1;
	}
	if (nbr >= base)
		len += ft_printnbr_base(nbr / base, base_ref, base);
	len += ft_printchar(base_ref[nbr % base]);
	return (len);
}
