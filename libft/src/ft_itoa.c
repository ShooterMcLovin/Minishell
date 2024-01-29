/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:02:03 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:52:57 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	nod(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ret;
	size_t		j;
	long int	num;

	j = nod(n);
	num = n;
	if (n < 0)
	{
		num = -num;
		j++;
	}
	ret = (char *)malloc(j + 1);
	if (!ret)
		return (NULL);
	ret[j] = '\0';
	while (j--)
	{
		ret[j] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
