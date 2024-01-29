/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:12:57 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/21 19:01:37 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_quoted(char *str)
{
	if (!str || !str[0])
		return (0);
	if (str[0] == 34)
		return (1);
	else if (str[0] == 39)
		return (2);
	else
		return (0);
}

int	has_quotes(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == 34)
			return (1);
		else if (str[i] == 39)
			return (2);
		i++;
	}
	return (0);
}

int	check_valid_quotes(char *input)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (!input || !input[0])
		return (0);
	while (input[i])
	{
		if (input[i] == 34 && trigger == 0)
			trigger = 1;
		else if (input[i] == 39 && trigger == 0)
			trigger = 2;
		else if (input[i] == 39 && trigger == 2)
			trigger = 0;
		else if (input[i] == 34 && trigger == 1)
			trigger = 0;
		i++;
	}
	if (trigger != 0)
		return (0);
	else
		return (1);
}

int	is_quote(int c)
{
	if (c == 34)
		return (1);
	else if (c == 39)
		return (2);
	else
		return (0);
}
