/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:12:09 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:52:41 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	if (!str)
		return (0);
	sign = 1;
	res = 0;
	i = 0;
	while (((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r')))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
