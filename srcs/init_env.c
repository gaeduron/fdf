/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:17:20 by gduron            #+#    #+#             */
/*   Updated: 2017/05/26 19:06:54 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	find_matrice_size_in_str(int *y_len, int *x_len, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			*y_len += 1;
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isspace((int)str[i]) &&
				(!str[i + 1] || ft_isspace((int)str[i + 1])))
			*x_len += 1;
		i++;
	}
}

static	int		**allocate_int_tab(int y_len, int x_len)
{
	int	**map;
	int	i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * y_len)))
		return (0);
	while (i < y_len)
	{
		if (!(map[i++] = (int*)malloc(sizeof(int) * x_len)))
			return (0);
	}
	return (map);
}

static	int		string_to_matrice(char *str, int **map, int *x_len)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	x = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && x != *x_len) || x > *x_len)
		{
			ft_printf("Found wrong line length. Exiting.\n");
			return (0);
		}
		str[i] == '\n' ? y++ : 0;
		str[i] == '\n' ? x = 0 : 0;
		if ((!i && !ft_isspace(str[i])) ||
				(i && ft_isspace(str[i - 1]) && !ft_isspace(str[i])))
		{
			map[y][x] = ft_atoi(str + i);
			x++;
		}
		i++;
	}
	return (1);
}

static	int		**create_int_tab_from_str(int fd, int *y_len, int *x_len)
{
	char	*str;
	int		**map;
	int		i;

	*y_len = 0;
	*x_len = 0;
	i = 0;
	if (!(str = read_file_desctriptor(fd)) || !str[0])
	{
		str ? free(str) : 0;
		return (0);
	}
	find_matrice_size_in_str(y_len, x_len, str);
	if (!(map = allocate_int_tab(*y_len, *x_len)))
	{
		str ? free(str) : 0;
		return (0);
	}
	if (!(string_to_matrice(str, map, x_len)))
	{
		str ? free(str) : 0;
		return (0);
	}
	free(str);
	return (map);
}

int				init_t_env(t_env *env, int fd)
{
	if (!(env->map = create_int_tab_from_str(fd, &(env->y_len), &(env->x_len))))
		return (0);
	env->win_size_x = 2560;
	env->win_size_y = 1396;
	if (env->x_len >= env->y_len)
		env->seg = (env->win_size_y * env->size) / (env->x_len * 2) + env->zoom;
	if (env->x_len < env->y_len)
		env->seg = (env->win_size_y * env->size) / (env->y_len * 2) + env->zoom;
	env->seg < 2 ? env->seg = 2 : 0;
	env->perspective += env->seg / 2;
	env->padding_x += (env->win_size_x / 2)
		- ((((env->seg + env->perspective) * env->x_len)
					+ ((env->seg + env->perspective) * env->y_len)) / 2);
	env->padding_y += (env->win_size_y)
		- ((((env->seg - env->perspective) * env->x_len)
					+ ((env->seg - env->perspective) * env->y_len)) / 2);
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx,
					env->win_size_x, env->win_size_y, "fdf")))
		return (0);
	return (1);
}
