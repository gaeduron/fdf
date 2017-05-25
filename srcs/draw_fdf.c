/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:53:59 by gduron            #+#    #+#             */
/*   Updated: 2017/05/25 16:48:43 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    create_back_line(t_env *env, int y, int x)
{
	env->a.x = ((x + abs(env->y_len - 1 - y)) * (env->seg + 10));
	env->b.x = (((x - 1) + abs(env->y_len - 1 - (y))) * (env->seg + 10));

	env->a.y = (((y - (env->x_len - 1 - x)) * env->seg)
			- (env->map[y][x] * env->seg) / 10) + env->win_size_y / 2;
	env->b.y = (((y - (env->x_len - 1 - (x - 1))) * env->seg)
			- (env->map[y][x - 1] * env->seg) / 10) + env->win_size_y / 2;
}

void    create_up_line(t_env *env, int y, int x)
{
	env->a.x = ((x + abs(env->y_len - 1 - y)) * (env->seg + 10));
	env->b.x = ((x + abs(env->y_len - 1 - (y - 1))) * (env->seg + 10));

	env->a.y = (((y - ((env->x_len - 1 - x))) * env->seg)
			- (env->map[y][x] * env->seg) / 10) + env->win_size_y / 2;
	env->b.y = ((((y - 1) - ((env->x_len - 1 - x))) * env->seg)
			- (env->map[y - 1][x] * env->seg) / 10) + env->win_size_y / 2;
}

void	draw_fdf(t_env *env, int y, int x)
{
	if (x)
	{
		create_back_line(env, y, x);
		do_line(env, &env->a, &env->b);
	}
	if (y)
	{
		create_up_line(env, y, x);
		do_line(env, &env->a, &env->b);
	}
	//	if (x && y)
	//	{
	//		create_diago_line(env, y, x);
	//		do_line(env, env->a, env->b);
	//	}
}
