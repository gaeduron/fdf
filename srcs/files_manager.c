/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:47:55 by gduron            #+#    #+#             */
/*   Updated: 2017/05/24 13:52:01 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error: file don't open\n", 24);
		return ;
	}
	do_fdf(fd);
	close(fd);
}

void	files_manager(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
		open_file(av[i++]);
}
