/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:21:30 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/24 11:30:48 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_read(int fd, char *save)
{
	int		read_bytes;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchrgnl(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(save);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = 0;
		save = ft_strjoingnl(save, buff);
		if (!save)
			return (ft_free(buff));
	}
	free(buff);
	return (save);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*ret;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (ft_free(save));
	ret = malloc((ft_strlen(save) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	c = 0;
	while (save && save[i])
		ret[c++] = save[i++];
	ret[c] = '\0';
	free(save);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd] || fd < 0)
		return (NULL);
	next_line = ft_substrgnl(save[fd], '\n');
	save[fd] = ft_save(save[fd]);
	return (next_line);
}
