/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:59:18 by alpicard          #+#    #+#             */
/*   Updated: 2022/12/12 16:42:34 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
	{
		len += ft_printchar(str[i]);
		i++;
	}
	return (len);
}
