/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:09:24 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/21 16:10:59 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_before_malloc(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("usage: ./so_long <****.ber>\n", 2);
		exit(-1);
	}
	if (check_extension(argv[1]) == 1)
	{
		ft_printf("error: not the right extension\n");
		exit(-1);
	}
}

void	ft_free(int fd, t_data *map_data)
{
	free(map_data->flat_map);
	close(fd);
	free(map_data);
	exit(-1);
}

/*void *mlx_intit(void)
function which connects the software with the display of the OS*/

/*void * mlx_new_window ( void mlx_ptr, int size_x, int size_y, char *title )
function that floats a new window on the display. It comes up with 
the pointer and horizontal vertical size you've taken earlier, and the title 
of the window.*/

/*int mlx_loop ( void *mlx_ptr );
function that waits for the keyboard and mouse input from the 
floating window. */

int	main(int argc, char **argv)
{
	t_data	*map_data;

	check_before_malloc(argc, argv);
	map_data = malloc(sizeof(t_data));
	ft_read(map_data, argv);
	map_data->mlx = mlx_init();
	map_data->win = mlx_new_window(map_data->mlx, ((map_data->width -1) * 80),
			(map_data->height * 80), "so_long");
	init_img(map_data);
	ft_set_img(map_data);
	map_data->move_counter = 0;
	mlx_hook(map_data->win, 2, 1L << 0, &press_key, map_data);
	mlx_hook(map_data->win, 17, 1L << 0, &exit_game, map_data);
	mlx_loop(map_data->mlx);
	free(map_data);
}
