/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_graphic_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <lmarecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:42:44 by lmarecha          #+#    #+#             */
/*   Updated: 2022/06/01 15:08:37 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_images(t_data *game) // je cree chaque image de mon jeu cf .h pour les liens
{
	int	img_width;
	int	img_height;

	game->banquise = mlx_xpm_file_to_image(game->mlx, BANQUISE_PATH, &img_width,
			&img_height);
	if (game->banquise == NULL)
		ft_abort_game(game);
	game->iceberg = mlx_xpm_file_to_image(game->mlx, ICEBERG_PATH, &img_width,
			&img_height);
	if (game->iceberg == NULL)
		ft_abort_game(game);
	game->ourson = mlx_xpm_file_to_image(game->mlx, OURSON_PATH, &img_width,
			&img_height);
	if (game->ourson == NULL)
		ft_abort_game(game);
	game->saumon = mlx_xpm_file_to_image(game->mlx, SAUMON_PATH, &img_width,
			&img_height);
	if (game->saumon == NULL)
		ft_abort_game(game);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT_PATH, &img_width,
			&img_height);
	if (game->exit == NULL)
		ft_abort_game(game);
}

void	ft_add_image_to_window(t_data *game, int x, int y, char c) // pour ajouter les images sur la fenetre en fonction des lettres et chiffres qui la composent
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->iceberg, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->banquise, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->saumon, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->ourson, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
}

int	ft_create_window(t_data *game)
{
	int			i;
	size_t		j;
	int			x;
	int			y;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		x = 0;
		while (j < ft_strlen(game->map[0]))
		{
			ft_add_image_to_window(game, x, y, game->map[i][j]); // j'ajoute chaque image a ma fenetre selon les coordonnes ou je suis
			x += 64; // j'avance de 64 sur ma ligne car mes images sont en 64x64
			j++;
		}
		y += 64; // 'increse la hauteur de 64 car mes images sont en 64x64'
		i++;
	}
	return (0);
}
