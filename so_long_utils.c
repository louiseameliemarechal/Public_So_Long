/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <lmarecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:22 by lmarecha          #+#    #+#             */
/*   Updated: 2022/06/01 15:07:23 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_data *game)
{
	game->ourson = NULL;
	game->saumon = NULL;
	game->iceberg = NULL;
	game->banquise = NULL;
	game->exit = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->steps = 0;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_cancel_game(char **map) // si je quitte le jeu avant de l'avoir vraiment commence
{
	if (map != NULL)
		free_tab(map);
	ft_printf("Error\n");
	exit(0);
}

int	ft_abort_game(t_data *game) // si je dois quitter le jeu apres avoir cree les windows etc
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tab(game->map);
	exit(0);
}

int	ft_destroy_game(t_data *game) // quand je quitte le jeu apres l'avoir commence
{
	mlx_destroy_image(game->mlx, game->ourson);
	mlx_destroy_image(game->mlx, game->saumon);
	mlx_destroy_image(game->mlx, game->iceberg);
	mlx_destroy_image(game->mlx, game->banquise);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tab(game->map);
	exit(0);
}
