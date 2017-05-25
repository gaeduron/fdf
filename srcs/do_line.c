/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:06:11 by gduron            #+#    #+#             */
/*   Updated: 2017/05/24 13:52:03 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				abs(int val)
{
	return (val > 0 ? val : -val);
}

static	void	init_draw_line_delta(int *dx, int *dy, t_point *curr, t_point *b)
{
	*dx = abs(b->x - curr->x);
	*dy = abs(b->y - curr->y);
}

static	void	draw_line(t_point *curr, t_point *b, t_env *env, int e_tmp)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;

	init_draw_line_delta(&dx, &dy, curr, b);
	sx = curr->x < b->x ? 1 : -1;
	sy = curr->y < b->y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (!(curr->x == b->x && curr->y == b->y))
	{
		mlx_pixel_put(env->mlx, env->win, curr->x, curr->y, 0x00ff00ff);
		e_tmp = err;
		if (e_tmp > -dx)
		{
			err -= dy;
			curr->x += sx;
		}
		if (e_tmp < dy)
		{
			err += dx;
			curr->y += sy;
		}
	}
}

void			do_line(t_env *env, t_point *a, t_point *b)
{
	draw_line(a, b, env, 0);
	mlx_pixel_put(env->mlx, env->win, a->x, a->y, 0x00ff00ff);
}
