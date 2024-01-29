/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:40:32 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:54:39 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen(s1);
	while (s_len && ft_strchr(set, s1[s_len]))
		s_len--;
	trimmed = ft_substr((char *)s1, 0, s_len + 1);
	return (trimmed);
}
