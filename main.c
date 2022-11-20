/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:09:24 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/18 17:15:48 by hferjani         ###   ########.fr       */
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
/*void *mlx_intit(void)
function which connects the software with the display of the OS*/

/*void * mlx_new_window ( void mlx_ptr, int size_x, int size_y, char *title )
function that floats a new window on the display. It comes up with 
the pointer and horizontal vertical size you've taken earlier, and the title of the window.*/

/*int mlx_loop ( void *mlx_ptr );
function that waits for the keyboard and mouse input from the floating window. */
int	main(int argc ,char **argv)
{
	t_data *map_data;

	check_before_malloc(argc, argv);
	map_data = malloc(sizeof(t_data));
	ft_read(map_data,argv);
	map_data->mlx = mlx_init();
	map_data->win = mlx_new_window(map_data->mlx, ((map_data->width -1) * 64), (map_data->height * 64), "so_long");
	init_img(map_data);
	ft_set_img(map_data);
	map_data->move_counter = 0;
	mlx_hook(map_data->win, 2, 1L << 0, &press_key, map_data);
	mlx_hook(map_data->win, 17, 1L << 0, &exit_game, map_data);
	mlx_loop(map_data->mlx);
	free(map_data);
}



/*int main()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	//void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./sprites/background.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./sprites/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./sprites/player.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./sprites/exit.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./sprites/exits.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "./sprites/collect.xpm", &img_width, &img_height);
	//img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 0, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_put_image_to_window(mlx, win, img6, 64, 64);
	//mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	return (0);
}*/
