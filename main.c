/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <lmarecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:15:06 by lmarecha          #+#    #+#             */
/*   Updated: 2022/06/01 15:07:11 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_letters(char **map) // check que la map contient les bonnes lettres
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_read_map(char **argv)
{
	char	*buf;
	int		fdin;
	int		file;

	fdin = open(argv[1], O_RDONLY); //ouvre la map
	if (fdin < 0)
		return (0);
	file = 1023;
	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
		return (NULL);
	while (file != 0)
	{
		buf[file] = '\0'; //termine la string par un \0 pour etre sur que tu lises pas trop loin
		file = read(fdin, buf, 1023); // lis le file (quand tu as tout lu file=0 fin de boucle)
	}
	if (ft_strrchr(buf, 'C') == 0 || ft_strrchr(buf, 'E') == 0
		|| ft_strrchr(buf, 'P') == 0) // verifie que tu as bien au moins un exit, un collectable et un depart dans la map
	{
		free(buf);
		return (0);
	}
	return (buf);
}

int	ft_check_map(char **map)
{
	int		i;
	size_t	j;

	i = 0;
	if (ft_check_letters(map) == 0) // verifie que je n'ai bien que des lettres authorisees dans ma string
		return (0);
	while (map[i])
	{
		j = ft_strlen(map[i]); // je stock la taille de ma premiere ligne pour la comparer aux autres (pour etre sur que ma map est carree)
		if ((i != 0) && (j != ft_strlen(map[i - 1]))) // je compare la taille de chaque ligne avec la premiere
			ft_cancel_game(map); // si la taille n'est pas la meme je free ce que j'ai besoin
		if (ft_strrchr(map[0], '0') != 0 || ft_strrchr(map[0], 'C') != 0
			|| ft_strrchr(map[0], 'E') != 0 || ft_strrchr(map[0], 'P') != 0)
			ft_cancel_game(map); // je verifie que ma premiere ligne ne contient que des murs
		if (map[i][0] != '1' || map[i][j - 1] != '1') // je verifie que les contours gauche et droite de ma map sont des murs
			ft_cancel_game(map); // si les contours sont pas tous des murs je free
		i++;
	}
	if (ft_strrchr(map[i - 1], '0') != 0 || ft_strrchr(map[i - 1], 'C') != 0 // je verifie que la derniere ligne de ma map n'est faite que de murs
		|| ft_strrchr(map[i - 1], 'E') != 0 || ft_strrchr(map[i - 1], 'P') != 0)
		ft_cancel_game(map);
	return (1);
}

int	check_and_initialize_map(t_data *game, char *buf)
{
	int		y;
	int		x;

	game->steps = 1;
	game->map = ft_split(buf, '\n'); // je split ma string par \n pour pouvoir isoler chaque ligne
	free(buf);
	if (ft_check_map(game->map) != 1) // je verifie que le format de ma map est ok
		ft_cancel_game(game->map);
	y = 0;
	while (game->map[y]) // je compte le nombre de lignes dans ma map (hauteur)
		y++;
	x = ft_strlen(game->map[0]); // de calcul la taille de ma premiere ligne (largeur de la map)
	game->mlx = mlx_init(); // j'initialise la minilibx
	if (game->mlx == NULL)
		ft_cancel_game(game->map); // je verifgie que l'initialisation a marche
	game->win = mlx_new_window(game->mlx, x * 64, y * 64, "So Long"); // je cre la fenetre de la taille de ma map grace a la hauteur et la largeur calcule avant et je lui donne un nom 64 = 64px pour la taille des images
	if (game->win == NULL) // je verifie que la window a ete creee
		ft_cancel_game(game->map);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*buf;
	t_data	game;

	if (argc < 2 || argc > 2)
		return (0);
	if (ft_strncmp(argv[1], ".ber", ft_strlen(argv[1])) != 0)
		return (0);
	buf = ft_read_map(argv); // tu mets toute la carte dans un char * pour pouvoir tout lire d'un coup et faire tes verifications une fois (verif de collectable, depart, et exit)
	initialize_game(&game); // initialise toute la structure a 0 ou NULL
	if (buf == 0)
	{
		free(buf);
		ft_cancel_game(game.map); // fonction pour free le jeu
	}
	if (check_and_initialize_map(&game, buf) == 0) // je verifie la map et j'initialise la window
		return (0);
	ft_create_images(&game); // je cre les images taille etc
	ft_create_window(&game); // j'ajoute les images sur la ma map
	mlx_key_hook(game.win, ft_choose_ourson_move, &game); // pour faire bouger ton personnage
	mlx_hook(game.win, 17, 0, ft_destroy_game, &game); // pour fermer le jeu avec la croix (17, 0 = masque a action pour la croix pour fermer fenetre)
	mlx_loop(game.mlx); // loop pour que le jeu se tienne
	return (0);
}
