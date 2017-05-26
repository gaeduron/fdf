/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:47:55 by gduron            #+#    #+#             */
/*   Updated: 2017/05/26 18:51:17 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	open_file(char *file_name, t_env *env)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error: file don't open\n", 24);
		return ;
	}
	do_fdf(fd, env);
	close(fd);
}

void			files_manager(int ac, char **av, t_env *env)
{
	ac = 1;
	open_file(av[ac], env);
}
