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

void    move_up_w(t_data *map)
{
    int i;

    i = 0;
    while (i++ < map->len)
    {
        if (map->flat_map[i] == 'P')
            break;
    }
    if (map->flat_map[i - map->width] == 'C')
        map->col_counter++;
    if (map->flat_map[i - map->width] == 'E' 
        && map->collectible == map->col_counter)
        exit_game(); // a creer
    else if (map->flat_map[i - map->width] != '1' 
        && map->flat_map[i - map->width] != 'E')
        map->flat_map[i] = '0';
        map->flat_map[i - map->width] = 'P'
        map->move_counter++;
        //fonction rafraichit l image
    
}

int	close(int keycode, t_data *map)
{
	mlx_destroy_window(map->mlx, map->win);
	return (0);
}