/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:12:40 by gduron            #+#    #+#             */
/*   Updated: 2017/05/23 17:51:53 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../Libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"

typedef struct	s_point
{
	int		x;
	int		y;
	int		i;
	int		color;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

void    do_line(t_env *env, t_point *a, t_point *b);
# endif
