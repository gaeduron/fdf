/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:51:56 by gduron            #+#    #+#             */
/*   Updated: 2017/05/31 14:30:26 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	get_flag(int ac, char **av, t_env *env)
{
	env->padding_x = ac > 2 ? ft_atoi(av[2]) : 10;
	if (ac > 2)
		env->padding_x = av[2][0] == 'x' ? 1 : env->padding_x;
	env->padding_y = ac > 3 ? ft_atoi(av[3]) : 1;
	if (ac > 3)
		env->padding_y = av[3][0] == 'x' ? 1 : env->padding_y;
	env->scale = ac > 4 ? ft_atoi(av[4]) : 1;
	if (ac > 4)
		env->scale = av[4][0] == 'x' || env->scale == 0 ? 1 : env->scale;
	env->perspective = ac > 5 ? ft_atoi(av[5]) : 0;
	if (ac > 5)
		env->perspective = av[5][0] == 'x' ? 0 : env->perspective;
	env->size = ac > 6 ? ft_atoi(av[6]) : 1;
	if (ac > 6)
		env->size = av[6][0] == 'x' || env->size > 4 ? 1 : env->size;
	env->zoom = ac > 7 ? ft_atoi(av[7]) : 0;
	if (ac > 7)
		env->zoom = av[7][0] == 'x' || env->zoom > 200 ? 0 : env->zoom;
}

int				main(int ac, char **av)
{
	t_env	env;

	if (ac >= 2 && ac <= 8)
	{
		get_flag(ac, av, &env);
		files_manager(ac, av, &env);
	}
	else
	{
		write(2, "usage:  ./fdf source_file x y scale perspective size zoom\n",
				59);
		write(2, "	use 'x' to replace flag by default value\n", 43);
	}
	return (0);
}
