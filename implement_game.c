/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <lmarecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:53:56 by lmarecha          #+#    #+#             */
/*   Updated: 2022/06/01 15:04:35 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	still_has_collectable(char **map) // verifie si j'ai encore des collectables sur la map
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	can_exit(int keycode, char **map, int i, int j) // fonction qui veirife si toutes les conditions pour quitter le jeu sont ok (plus de collectable etc)
{
	if (map[i][j + 1] == 'E' && keycode == 100 // je verifie a chaque fois si la touche correspond a la case E
		&& still_has_collectable(map) == 0)	// exemple si la sortie E est a ma droite et que j'appuie sur la touche qui deplace le perso a droit + j'ai plus de collectable alors je peux quitter le jeu
		return (1);
	else if (map[i][j - 1] == 'E' && keycode == 97
		&& still_has_collectable(map) == 0)
		return (1);
	else if (map[i - 1][j] == 'E' && keycode == 119
		&& still_has_collectable(map) == 0)
		return (1);
	else if (map[i + 1][j] == 'E' && keycode == 115
		&& still_has_collectable(map) == 0)
		return (1);
	return (0);
}

void	find_ourson(char **map, int *x, int *y) // je cherche ou est mon ourson sur la map
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = j;
				*x = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_move_ourson(int keycode, t_data *game, int x, int y)
{
	int		i;
	int		j;
	char	c;

	find_ourson(game->map, &i, &j); // je regarde ou est placer mon personnage sur la map, j'envoi les adresses de i et j pour qu'elles soient modifie dans cette fonction apres avoir execute ma fonction find_ourson
	c = game->map[i][j]; // c = position de mon ourson a instant T
	if (game->map[i + x][j + y] != '1')
		ft_printf("You made %d steps so far\n", game->steps++); // je print chaque step sur le terminal
	if (can_exit(keycode, game->map, i, j) == 1) // si toutes les conditions sont rempli je quitte le jeu
		ft_destroy_game(game);
	else if (game->map[i + x][j + y] == 'C') // si je vais sur une case collectable j'echange la case perso avec une case decors et la case collectable avec mon perso
	{
		game->map[i + x][j + y] = c; // je met l'image de on ourson sur case collectable
		game->map[i][j] = '0'; // la case sur laquelle etait mon perso redevient un decors
	}
	else if (game->map[i + x][j + y] == 'E' // si je vais sur une exit et que c'est ok de partir je quitte
		&& still_has_collectable(game->map) == 1)
		return (0);
	else if (game->map[i + x][j + y] == '0') // si je vais sur une case decors ma case perso devient un decors et mon decors devient le perso
	{
		game->map[i + x][j + y] = c;
		game->map[i][j] = '0';
	}
	return (1);
}

int	ft_choose_ourson_move(int keycode, t_data *game)
{
	if (keycode == 65307) // code de la touche echape pour quitter le jeu
		ft_destroy_game(game);
	if (keycode == 119) // je me souviens plus des codes mais ils correspondent aux touches haut bas droite gauche
		ft_move_ourson(keycode, game, -1, 0);
	else if (keycode == 115)
		ft_move_ourson(keycode, game, 1, 0);
	else if (keycode == 97)
		ft_move_ourson(keycode, game, 0, -1);
	else if (keycode == 100)
		ft_move_ourson(keycode, game, 0, 1);
	ft_create_window(game); // je recharge la fenetre a chaque fois pour que les changements apparaissent 
	return (0);
}
