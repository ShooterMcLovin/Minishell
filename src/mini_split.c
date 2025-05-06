/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:20:09 by alpicard          #+#    #+#             */
/*   Updated: 2025/05/04 16:00:52 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	no_of_words(char *s, int trigger, int i, int no_wrds)
{
	if (s[i] == 39)
	{
		i++;
		trigger = 2;
	}
	else if (s[i] == 34)
	{
		i++;
		trigger = 1;
	}
	while (s[i])
	{
		if (s[i] == ' ' && trigger == 0)
			no_wrds++;
		else if (s[i] == 34 && trigger == 1)
			trigger = 0;
		else if (s[i] == 39 && trigger == 2)
			trigger = 0;
		else if (s[i] == '|' && trigger == 0)
			no_wrds++;
		i++;
	}
	return (no_wrds);
}

int	mini_len(char *s, int start, int trigger, int len)
{
	while (s[start])
	{
		if (s[start] == 34 && trigger == 1)
			trigger = 0;
		else if (s[start] == 39 && trigger == 2)
			trigger = 0;
		else if (s[start] == 34 && trigger == 0)
			trigger = 1;
		else if (s[start] == 39 && trigger == 0)
			trigger = 2;
		else if (s[start] == ' ' && trigger == 0)
			return (len);
		else if (s[start] == '|' && trigger == 0)
			return (len);
		len++;
		start++;
	}
	return (len);
}

int	word_len(char *s, int start)
{
	int	trigger;
	int	len;

	trigger = 0;
	len = 0;
	if (s[start] == '|')
		return (1);
	if (s[start] == 39)
	{
		start++;
		len++;
		trigger = 2;
	}
	else if (s[start] == 34)
	{
		start++;
		len++;
		trigger = 1;
	}
	len += mini_len(s, start, trigger, len);
	return (len);
}

char	**no_name(char *s, int wrd_no, int no_wrds, char **split)
{
	int	len;
	int	i;

	i = 0;
	while (++wrd_no < no_wrds)
	{
		while (s[i] && s[i] == ' ')
			i++;
		len = word_len(s, i);
		split[wrd_no] = ft_substr(s, i, len);
		if (split[wrd_no][0] == '\0')
		{
			free(split[wrd_no]);
			split[wrd_no] = NULL;
			return (split);
		}
		i += len;
	}
	return (split);
}

char	**mini_split(char *s)
{
	char	**split;
	int		no_wrds;
	int		wrd_no;

	no_wrds = no_of_words(s, 0, 0, 0) + 1;
	split = ft_calloc(no_wrds + 1, sizeof(char *));
	if (!split)
		return (NULL);
	wrd_no = -1;
	return (no_name(s, wrd_no, no_wrds, split));
}
