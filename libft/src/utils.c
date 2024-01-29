/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:14:22 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 17:16:24 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	set_trigger(const char *s1, int j, int trigger)
{
	if (s1[j + 1] && s1[j + 1] == 34)
		trigger = 1;
	else
		trigger = 2;
	return (trigger);
}

int	set_trigger_single(const char *s1, int j, int trigger)
{
	if (s1[j + 1] && s1[j + 1] == 39)
		trigger = 1;
	else
		trigger = 3;
	return (trigger);
}

int	duplen_part2(const char *s1, int trigger, int j)
{
	while (s1[j] && trigger)
	{
		if (s1[j] == 34 && trigger == 1)
			trigger = set_trigger(s1, j++, trigger);
		else if (s1[j] == 39 && trigger == 1)
			trigger = set_trigger_single(s1, j, trigger);
		else if ((trigger == 2 && s1[j] == 34) || (trigger == 3 && s1[j] == 39))
		{
			j++;
			trigger = 1;
		}
		else if ((trigger == 1 && s1[j] == ' ') || s1[j] == 0)
			trigger = 0;
		else
			j++;
	}
	return (j);
}

int	dup_len(char *s1)
{
	int	trigger;
	int	j;

	trigger = 1;
	j = 0;
	j = duplen_part2(s1, trigger, j);
	return (j);
}
