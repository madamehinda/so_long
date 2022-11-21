/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:47:52 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/21 18:06:07 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int key_code, t_data *map)
{
	if (key_code == ESC)
		exit_game(map);
	if (key_code == W_KEY || key_code == UP_KEY)
		move_up_w(map);
	if (key_code == A_KEY || key_code == LEFT_KEY)
		move_left_a(map);
	if (key_code == S_KEY || key_code == DOWN_KEY)
		move_down_s(map);
	if (key_code == D_KEY || key_code == RIGHT_KEY)
		move_right_d(map);
	return (0);
}

void	move_up_w(t_data *map)
{
	int	i;

	i = 0;
	while (i++ < map->len)
	{
		if (map->flat_map[i] == 'P')
			break ;
	}
	if (map->flat_map[i - map->width] == 'C')
		map->collectible--;
	if (map->flat_map[i - map->width] == 'E'
		&& map->collectible < 1)
		exit_game(map);
	else if (map->flat_map[i - map->width] != '1'
		&& map->flat_map[i - map->width] != 'E')
	{
		map->flat_map[i] = '0';
		map->flat_map[i - map->width] = 'P';
		map->move_counter++;
		ft_printf("%d\n", map->move_counter);
		ft_set_img(map);
	}
}

void	move_down_s(t_data *map)
{
	int	i;

	i = 0;
	while (i++ < map->len)
	{
		if (map->flat_map[i] == 'P')
			break ;
	}
	if (map->flat_map[i + map->width] == 'C')
		map->collectible--;
	if (map->flat_map[i + map->width] == 'E'
		&& map->collectible < 1)
		exit_game(map);
	else if (map->flat_map[i + map->width] != '1'
		&& map->flat_map[i + map->width] != 'E')
	{
		map->flat_map[i] = '0';
		map->flat_map[i + map->width] = 'P';
		map->move_counter++;
		ft_printf("%d\n", map->move_counter);
		ft_set_img(map);
	}
}

void	move_left_a(t_data *map)
{
	int	i;

	i = 0;
	while (i++ < map->len)
	{
		if (map->flat_map[i] == 'P')
			break ;
	}
	if (map->flat_map[i - 1] == 'C')
		map->collectible--;
	if (map->flat_map[i - 1] == 'E'
		&& map->collectible < 1)
		exit_game(map);
	else if (map->flat_map[i - 1] != '1'
		&& map->flat_map[i - 1] != 'E')
	{
		map->flat_map[i] = '0';
		map->flat_map[i - 1] = 'P';
		map->move_counter++;
		ft_printf("%d\n", map->move_counter);
		ft_set_img(map);
	}
}

void	move_right_d(t_data *map)
{
	int	i;

	i = 0;
	while (i++ < map->len)
	{
		if (map->flat_map[i] == 'P')
			break ;
	}
	if (map->flat_map[i + 1] == 'C')
		map->collectible--;
	if (map->flat_map[i + 1] == 'E'
		&& map->collectible < 1)
		exit_game(map);
	else if (map->flat_map[i + 1] != '1'
		&& map->flat_map[i + 1] != 'E')
	{
		map->flat_map[i] = '0';
		map->flat_map[i + 1] = 'P';
		map->move_counter++;
		ft_printf("%d\n", map->move_counter);
		ft_set_img(map);
	}
}
