/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:11:39 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/18 11:54:10 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define LEFT_KEY       65361
# define UP_KEY         65362
# define RIGHT_KEY      65363
# define DOWN_KEY       65364
# define A_KEY          97
# define W_KEY          119
# define S_KEY          115
# define D_KEY          100
# define ESC            65307

# define BACKGROUND "./sprites/background.xpm"
# define COLLECT "./sprites/collect.xpm"
# define EXIT "./sprites/exit.xpm"
# define EXITS "./sprites/exits.xpm"
# define PLAYER "./sprites/player.xpm"
# define WALL "./sprites/wall.xpm"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "Libft/get_next_line.h"
# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_data
{
    char    *flat_map;
    int     height;
    int     width;
    int     len;
    int     rectangle;
    int     collectible;
    int     col_counter;
    int     exit;
    int     player;
    int     move_counter;
    void    *mlx;
    void    *win;
    void    *img_player;
    void    *img_collectible;
    void    *img_exit;
    void    *img_wall;
    void    *img_background;
} t_data;


int     check_extension(char *file);
int     ft_authorised_char(char *file);
int     stlen_line(int fd,char *argv);
void	ft_read(t_data *map_data,char **argv);
int     ft_check_caracter(char c, char const *str);
int     ft_check_walls(t_data *map_data);
void	check_before_malloc(int argc, char **argv);
void	check_after_malloc(int fd, t_data *map_data);
void    ft_free(int fd, t_data *map_data);
void	ft_check_p(t_data *map_data, char *str);
int     check_collectible(char *str);
int     check_escape(t_data *map_data, char *str);
void	ft_read_the_map(t_data *map_data,int fd);
void    init_img(t_data *map);
void    ft_set_items(t_data *map, int w, int h);
void	ft_set_img(t_data *map);
int	    exit_game(t_data *map);
int	press_key(int key_code, t_data *map);
void    move_up_w(t_data *map);
void    move_down_s(t_data *map);
void    move_left_a(t_data *map);
void    move_right_d(t_data *map);





#endif
