/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:12:40 by gduron            #+#    #+#             */
/*   Updated: 2017/05/31 13:58:34 by gduron           ###   ########.fr       */
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
	int			x;
	int			y;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	int			x_len;
	int			y_len;
	int			seg;
	int			win_size_x;
	int			win_size_y;
	int			padding_x;
	int			padding_y;
	int			scale;
	int			perspective;
	int			size;
	int			zoom;
	t_point		a;
	t_point		b;
}				t_env;

void			do_line(t_env *env, t_point *a, t_point *b);
void			do_fdf(int fd, t_env *env);
void			draw_fdf(t_env *env, int y, int x);
void			files_manager(int ac, char **av, t_env *env);
int				main(int ac, char **av);
int				init_t_env(t_env *env, int fd);
char			*read_file_desctriptor(int fd);
int				close_tab(int keycode);
#endif
