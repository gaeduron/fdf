/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:17:20 by gduron            #+#    #+#             */
/*   Updated: 2017/05/25 13:34:38 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_matrice_size_in_str(int *y_len, int *x_len, char *str)
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

int		**allocate_int_tab(int y_len, int x_len)
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

void	string_to_matrice(char *str, int **map)
{
	int     i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	x = 0;
	while (str[i])
	{
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
}

int		**create_int_tab_from_str(int fd, int *y_len, int *x_len)
{
	char	*str;
	int		**map;
	int		i;
//	int		x[1];
//	int		y[1];

/*	*y = 0;
	*x = 0;
	if (!y_len || !x_len)
	{
		y_len = y;
		x_len = x;
	}*/
	*y_len = 0;
	*x_len = 0;
	i = 0;
	if (!(str = read_file_desctriptor(fd)))
		return (0);
	find_matrice_size_in_str(y_len, x_len, str);
	if (!(map = allocate_int_tab(*y_len, *x_len)))
		return (0);
	string_to_matrice(str, map);
	return (map);
}

int		init_t_env(t_env *env, int fd)
{
	env->top = 0;
	if (!(env->map = create_int_tab_from_str(fd, &(env->y_len), &(env->x_len))))
		return (0);
	env->win_size_x = 2560;
	env->win_size_y = 1396;
	if (env->x_len > env->y_len)
		env->seg = (env->win_size_x - env->top) / (env->x_len);
	if (env->x_len < env->y_len)
		env->seg = (env->win_size_y - env->top) / (env->y_len);
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx,
					env->win_size_x, env->win_size_y, "fdf")))
		return (0);
	return (1);
}
