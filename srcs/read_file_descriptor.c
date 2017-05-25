/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_descriptor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:38:29 by gduron            #+#    #+#             */
/*   Updated: 2017/05/25 13:48:00 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned char	*read_loop(unsigned char *dest, unsigned char *buff,
		unsigned long ret)
{
	unsigned int i;

	buff[ret] = '\0';
	if (!(dest = (unsigned char*)ft_strjoin((char *)dest, (char *)buff)))
		exit(0);
	i = 0;
	return (dest);
}

char			*read_file_desctriptor(int fd)
{
	unsigned char	*dest;
	unsigned char	*buff;
	unsigned long	ret;
	unsigned long	i;

	i = 1;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * 1)))
		return (0);
	dest[0] = '\0';
	if (!(buff = (unsigned char *)malloc(sizeof(unsigned char) * (65537))))
		return (0);
	while ((ret = read(fd, buff, 65537)) > 0)
	{
		dest = read_loop(dest, buff, ret);
		if (dest == 0)
		{
			free(buff);
			return (0);
		}
		i++;
	}
	free(buff);
	return ((char*)dest);
}
