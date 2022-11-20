/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:21:09 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/18 17:09:19 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

/*sprites are converted to img*/
void    init_img(t_data *map)
{
    int		img_width;
	int		img_height;

	map->img_player = mlx_xpm_file_to_image
		(map->mlx, PLAYER, &img_width, &img_height);
	map->img_collectible = mlx_xpm_file_to_image
		(map->mlx, COLLECT, &img_width, &img_height);
	map->img_exit = mlx_xpm_file_to_image
		(map->mlx, EXIT, &img_width, &img_height);
	//map->img_exits = mlx_xpm_file_to_image
		//(map->mlx, EXITS, &img_width, &img_height);
	map->img_wall = mlx_xpm_file_to_image
		(map->mlx, WALL, &img_width, &img_height);
	map->img_background = mlx_xpm_file_to_image
		(map->mlx, BACKGROUND, &img_width, &img_height);
}
/*img are set where they belong*/
void    ft_set_items(t_data *map, int w, int h)
{
    if (map->flat_map[h * map->width + w] == '1')
        mlx_put_image_to_window(map->mlx, map->win, map->img_wall, w * 64, h * 64);
    else if (map->flat_map[h * map->width + w] == 'C')
        mlx_put_image_to_window(map->mlx, map->win, map->img_collectible, w * 64, h * 64);
    else if (map->flat_map[h * map->width + w] == 'P')
        mlx_put_image_to_window(map->mlx, map->win, map->img_player, w * 64, h * 64);
    //else if (map->flat_map[h * map->width + w] == 'E' && map->collectible == 0)
        //mlx_put_image_to_window(map->mlx, map->win, map->img_exits, w * 64, h * 64);
    else if (map->flat_map[h * map->width + w] == 'E')
        mlx_put_image_to_window(map->mlx, map->win, map->img_exit, w * 64, h * 64);
    else
        mlx_put_image_to_window(map->mlx, map->win, map->img_background, w * 64, h * 64);
}

/*loop helping the function dispatching img - called after every move*/
void	ft_set_img(t_data *map)
{
    int height;
    int width;

    height = 0;
    while (height < map->height)
    {
        width = 0;
        while (width < map->width - 1)
        {
            ft_set_items(map, width, height);
            width++;
        }
        height++;
    }
    
}

/*free and exits the game*/
int	exit_game(t_data *map)
{
    ft_printf("Total moves: %d\n", map->move_counter);
    mlx_destroy_image(map->mlx, map->img_player);
    mlx_destroy_image(map->mlx, map->img_collectible);
    mlx_destroy_image(map->mlx, map->img_exit);
    //mlx_destroy_image(map->mlx, map->img_exits);
    mlx_destroy_image(map->mlx, map->img_wall);
    mlx_destroy_image(map->mlx, map->img_background);
	mlx_destroy_window(map->mlx, map->win);
    mlx_destroy_display(map->mlx);
    free(map->mlx);
    free(map->flat_map);
    free(map);
	exit (0);
}