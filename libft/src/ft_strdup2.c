/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:12:04 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 23:20:16 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*strdup2_part2(char *str, const char *s1, int j, int trigger)
{
	int	i;

	i = 0;
	while (s1[j] && trigger)
	{
		if (s1[j] == 34 && trigger == 1)
			trigger = set_trigger(s1, j++, trigger);
		else if (s1[j] == 39 && trigger == 1)
			trigger = set_trigger_single(s1, j++, trigger);
		else if ((trigger == 2 && s1[j] == 34) || (trigger == 3 && s1[j] == 39))
		{
			j++;
			trigger = 1;
		}
		else if ((trigger == 1 && s1[j] == ' ') || s1[j] == 0)
			trigger = 0;
		else
			str[i++] = s1[j++];
	}
	str[i] = 0;
	return (str);
}

// char	*ft_strdup2(const char *s1)
// {
// 	int		j;
// 	int		len;
// 	char	*str;
// 	int		trigger;

// 	trigger = 1;
// 	if (!s1 || !s1[0])
// 		return (NULL);
// 	len = dup_len((char *)s1) + 1;
// 	str = (char *)malloc(sizeof(char) * len);
// 	if (!str)
// 		return (NULL);
// 	j = 0;
// 	str = strdup2_part2(str, s1, j, trigger);
// 	return (str);
// }
