/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:06:11 by gduron            #+#    #+#             */
/*   Updated: 2017/05/26 18:48:10 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				abs(int val)
{
	return (val > 0 ? val : -val);
}

static	void	init_draw_line_delta(int *dx, int *dy, t_point *cu, t_point *b)
{
	*dx = abs(b->x - cu->x);
	*dy = abs(b->y - cu->y);
}

static	int		get_color(t_point *curr, t_point *b, t_env *env)
{
	int tmp_color;

	if (curr->color < b->color)
		curr->color++;
	if (curr->color > b->color)
		curr->color--;
	if (curr->color * env->scale < 0xff)
	{
		tmp_color = 0xff0000;
		tmp_color += (curr->color) * env->scale;
	}
	if (curr->color * env->scale < 0x1ff && curr->color * env->scale >= 0xff)
	{
		tmp_color = 0xff00ff;
		tmp_color -= (curr->color * env->scale - 0xff) * 0x010000;
	}
	if (curr->color * env->scale < 0x2ff && curr->color * env->scale >= 0x1ff)
	{
		tmp_color = 0xff;
		tmp_color += (curr->color * env->scale - 0x1ff) * 0x100;
	}
	if (curr->color * env->scale >= 0x2ff && curr->color * env->scale < 0x3fe)
		tmp_color += 0xffff + ((curr->color * env->scale - 0x2ff) * 0x010000);
	curr->color * env->scale >= 0x3ff ? tmp_color = 0xffffff : 0;
	return (tmp_color);
}

static	void	draw_line(t_point *curr, t_point *b, t_env *e, int e_tmp)
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
		mlx_pixel_put(e->mlx, e->win, curr->x, curr->y, get_color(curr, b, e));
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
	mlx_pixel_put(env->mlx, env->win, a->x, a->y, get_color(a, b, env));
}
