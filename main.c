/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:51:56 by gduron            #+#    #+#             */
/*   Updated: 2017/05/24 11:24:50 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_tab(int keycode)
{
	ft_printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int main()
{
	t_env env;
	t_point a;
	t_point	b;
	int	x;
	int	y;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 400, 400, "____WIN_SQUARE____");
	y = 150;
	while (y < 250)
	{
		x = 150;
		while (x < 250)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, 0x00ff0000);
			x++;
		}
		y++;
	}
	a.x = 0;
	a.y = 0;
	b.i = 1;
	a.color = 0x00ffffff;
	b.x = ;
	b.y = 100;
	b.i = 0;
	b.color = 0x00ffffff;
	do_line(&env, &a, &b);
	mlx_key_hook(env.win, close_tab, 0);
	mlx_loop(env.mlx);
	return (0);
}
