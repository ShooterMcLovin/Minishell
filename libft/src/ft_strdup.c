/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:23:52 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 23:20:06 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (str)
	{
		while (*s1)
		{
			str[i++] = *s1++;
		}
		str[i] = 0;
	}
	return (str);
}


char	*ft_strdup2(const char *s1)
{
	int		i;
	int		j;
	char	*str;
	int trigger = 1;
	if (!s1 || !s1[0])
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) );
	if (!str)
		return (NULL);
	i = 0;
	j = 0; 
	while (s1[j] && trigger)
	{	
		if (s1[j] == 34 && trigger == 1)
		{
			if (s1[j + 1] && s1[j + 1] == 34){
				trigger = 1;
				j++;
			}
			else
				trigger = 2; // 
			j++;
			
		}
		else if (s1[j] == 39 && trigger == 1)
		{
			if (s1[j + 1] && s1[j + 1] == 39){
				trigger = 1;
				j++;
			}
			else
				trigger = 3;
			j++;
		}
		else if ((trigger == 2 &&  s1[j] == 34)||(trigger == 3 && s1[j] == 39)){
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