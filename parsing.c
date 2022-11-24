/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:25 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/24 10:18:40 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*where on the map P could move "allegedly"*/
void	check_p(t_data *m, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (m->flat_map[++i] != '\0')
	{
		j = -1;
		while (m->flat_map[++j] != '\0')
		{
			if (str[j] == 'P')
			{
				if (str[j + 1] != '1' && str[j + 1] != 'E' && str[j + 1] != 'P')
					str[j + 1] = 'P';
				if (str[j - 1] != '1' && str[j - 1] != 'E' && str[j - 1] != 'P')
					str[j - 1] = 'P';
				if (str[j - m->width] != '1' && str[j - m->width]
					!= 'E' && str[j - m->width] != 'P')
					str[j - m->width] = 'P';
				if (str[j + m->width] != '1' && str[j + m->width]
					!= 'E' && str[j + m->width] != 'P')
					str[j + m->width] = 'P';
			}	
		}
	}
}

/*function to assess if there is a way to exit while collecting all the items*/
void	backtracking(int fd, t_data *map_data)
{
	char	*str;

	str = NULL;
	str = ft_strjoin(str, map_data->flat_map);
	if (!str)
		return ;
	map_data->len = (int)ft_strlen(map_data->flat_map);
	map_data->width += 1;
	check_p(map_data, str);
	if (check_escape(map_data, str) == 1 && check_collectible(str) == 1)
		ft_printf("valid path!\n");
	else
	{
		ft_printf("Error: Valid path needed!\n");
		free(str);
		ft_free(fd, map_data);
	}
	free(str);
}

/*check if the map is filled properly*/
int	ft_authorised_char(char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if ((s[i] != '0') && (s[i] != '1') && (s[i] != 'P') && (s[i] != 'C')
			&& (s[i] != 'E') && (s[i] != '\n'))
			return (1);
		if ((s[i] == 'E') || (s[i] == 'P'))
			j++;
		if ((s[i] == 'C'))
			k++;
		i++;
	}
	if ((j != 2) || (k < 1))
		return (1);
	return (0);
}

void	ft_read(t_data *map_data, char **argv)
{
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error : %s\n", strerror(errno));
		free(map_data);
		exit(-1);
	}
	ft_read_the_map(map_data, fd);
	check_after_malloc(fd, map_data);
	backtracking(fd, map_data);
	i = 0;
	map_data->collectible = 0;
	while (map_data->flat_map[i++])
	{
		if (map_data->flat_map[i] == 'C')
		{
			map_data->collectible++;
		}
	}
	close(fd);
}

void	ft_read_the_map(t_data *map_data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("there is nothing to display\n");
		free(map_data);
		exit(-1);
	}
	map_data->width = ft_strlen(line)- 1;
	map_data->flat_map = NULL;
	map_data->height = 0;
	map_data->flat_map = ft_strjoin(map_data->flat_map, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map_data->height++;
		if (line)
			map_data->flat_map = ft_strjoin(map_data->flat_map, line);
	}
}
