/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:33:16 by alpicard          #+#    #+#             */
/*   Updated: 2022/12/12 16:39:45 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_switch(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	i = 0;
	return (0);
}
