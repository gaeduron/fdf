/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:12:40 by gduron            #+#    #+#             */
/*   Updated: 2017/05/25 12:49:23 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct	s_point
{
	int		x;
	int		y;
	int		color;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		**map;
	int		x_len;
	int		y_len;
	int		seg;
	int		top;
	int		win_size_x;
	int		win_size_y;
	t_point	a;
	t_point	b;
}				t_env;

void    do_line(t_env *env, t_point *a, t_point *b);
void	do_fdf(int fd);
void	files_manager(int ac, char **av);
int		main(int ac, char **av);
int		init_t_env(t_env *env, int fd);
char	*read_file_desctriptor(int fd);
# endif
