/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:55:49 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/09 15:07:24 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free(int fd, t_data *map_data)
{    
    free(map_data->flat_map);
	close(fd);
    free(map_data);
    exit(-1);
}

void	check_after_malloc(int fd, t_data *map_data)
{
    if((int)ft_strlen(map_data->flat_map) != ((map_data->width * map_data->height) + (map_data->height -1)))
	{
            ft_printf("error : Map is not a rectangle\n");
            ft_free(fd, map_data);
    }    
	if (ft_authorised_char(map_data->flat_map)==1)
    {
		ft_printf("error: Map not filled properly\n");
        ft_free(fd, map_data);
    }
	if (ft_check_walls(map_data)==1)
    {
		ft_printf("error : Map must be surrounded by walls\n");
        ft_free(fd, map_data);
    }
}
/*check if the file descriptor has .ber extension*/
int	check_extension(char *file)
{
	char	*lastDot;
	int		len;

	len = ft_strlen(file);
	lastDot = ft_strrchr(file,'.');
	if (lastDot != NULL && !ft_strncmp(lastDot, ".ber", 4) && len >= 5)
	{
		return (0);
	}
	return (1);
}