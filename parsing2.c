/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:55:49 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/25 09:56:46 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_after_malloc(int fd, t_data *map_data)
{
	int	len;

	len = (int)ft_strlen(map_data->flat_map);
	if (len != ((map_data->width * map_data->height) + (map_data->height -1)))
	{
		ft_printf("error : Map is not a rectangle \n");
		ft_free(fd, map_data);
	}
	if (ft_authorised_char(map_data->flat_map) == 1)
	{
		ft_printf("error: Map not filled properly\n");
		ft_free(fd, map_data);
	}
	if (ft_check_walls(map_data) == 1)
	{
		ft_printf("error : Map must be surrounded by walls\n");
		ft_free(fd, map_data);
	}
}

/*check if the file descriptor has .ber extension*/
int	check_extension(char *file)
{
	char	*lastdot;
	int		len;

	len = ft_strlen(file);
	lastdot = ft_strrchr(file, '.');
	if (lastdot != NULL && !ft_strncmp(lastdot, ".ber", 4) && len >= 5)
	{
		return (0);
	}
	return (1);
}

/*if returns 1 then we could have a valid path*/
int	check_collectible(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

/*if returns 1 then we could have a valid path*/
int	check_escape(t_data *map_data, char *str)
{
	int	i;

	i = 0;
	while (map_data->flat_map[i])
	{
		if (map_data->flat_map[i] == 'E')
		{
			if (str[i + 1] == 'P')
				return (1);
			if (str[i - 1] == 'P')
				return (1);
			if (str[i - map_data->width] == 'P')
				return (1);
			if (str[i + map_data->width] == 'P')
				return (1);
		}
		i++;
	}
	return (0);
}

/*check if the map is surrounded by walls*/
int	ft_check_walls(t_data *map_data)
{
	int	i;

	i = 0;
	map_data->len = (int)ft_strlen(map_data->flat_map);
	while (i < map_data->len)
	{
		if (i < map_data->width || i > (map_data->len - map_data->width))
		{
			if (map_data->flat_map[i] != '1')
			{
				return (1);
			}
		}
		if (map_data->flat_map[i] == '\n' && (map_data->flat_map[i - 1] != '1'
				|| map_data->flat_map[i + 1] != '1'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
