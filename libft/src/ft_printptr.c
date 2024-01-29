/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:11 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/06 16:34:14 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (3);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len + 2);
}

static void	ft_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_ptr(num / 16);
		ft_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			ft_printchar('0' + num);
		else
			ft_printchar('a' + (num - 10));
	}
}

int	ft_printptr(unsigned long long ptr)
{
	ft_printstr("0x");
	if (ptr == 0)
		ft_printchar('0');
	else
		ft_ptr(ptr);
	return (ft_ptr_len(ptr));
}
