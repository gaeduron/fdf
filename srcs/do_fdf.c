/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:54:39 by gduron            #+#    #+#             */
/*   Updated: 2017/05/26 19:02:52 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				close_tab(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

static	void	free_all(t_env *env)
{
	while (--env->y_len >= 0)
		free(env->map[env->y_len]);
	free(env->map);
	return ;
}

void			do_fdf(int fd, t_env *env)
{
	int		x;
	int		y;

	if (!(init_t_env(env, fd)))
	{
		write(1, "error\n", 6);
		return ;
	}
	y = 0;
	while (y < env->y_len)
	{
		x = 0;
		while (x < env->x_len)
		{
			draw_fdf(env, y, x);
			x++;
		}
		y++;
	}
	mlx_key_hook(env->win, close_tab, 0);
	mlx_loop(env->mlx);
	free_all(env);
	return ;
}
