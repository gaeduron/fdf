/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:51:56 by gduron            #+#    #+#             */
/*   Updated: 2017/05/25 12:58:48 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int		close_tab(int keycode)
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
	env.win = mlx_new_window(env.mlx, 2560, 1396, "____WIN_SQUARE____");
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
	a.y = 1396 / 2;
	a.color = 0x00ffffff;
	b.x = 2560 / 2;
	b.y = 1396;
	b.color = 0x00ffffff;
	do_line(&env, &a, &b);
	mlx_key_hook(env.win, close_tab, 0);
	mlx_loop(env.mlx);
	return (0);
}
*/
int		main(int ac, char **av)
{
	if (ac == 2)
		files_manager(ac, av);
	else
		write(2, "usage: ./fdf source_file\n", 26);
	return (0);
}
