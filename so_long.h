/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <lmarecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:15:26 by lmarecha          #+#    #+#             */
/*   Updated: 2022/04/13 11:49:55 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include "mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# define BANQUISE_PATH "./Images/Banquise.xpm"
# define ICEBERG_PATH "./Images/Iceberg.xpm"
# define OURSON_PATH "./Images/Ourson.xpm"
# define SAUMON_PATH "./Images/Saumon.xpm"
# define EXIT_PATH "./Images/Exit.xpm"

typedef struct s_data {
	void	*ourson;
	void	*saumon;
	void	*iceberg;
	void	*banquise;
	void	*exit;
	void	*mlx;
	void	*win;
	char	**map;
	int		steps;
}	t_data;

int		ft_cancel_game(char **map);
void	free_tab(char **tab);
int		ft_close(int keycode, t_data *game);
void	ft_create_images(t_data *game);
int		ft_create_window(t_data *game);
int		is_ok_to_move(int keycode, char **map, int i, int j);
int		ft_choose_ourson_move(int keycode, t_data *game);
int		ft_destroy_game(t_data *game);
int		ft_abort_game(t_data *game);
void	initialize_game(t_data *game);

#endif
