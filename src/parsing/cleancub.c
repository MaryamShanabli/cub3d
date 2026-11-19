/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleancub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:17:54 by helfayez          #+#    #+#             */
/*   Updated: 2026/11/19 14:37:46 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "././cub3d.h"

void free_windo(t_scene * scene)
{
    int i;

    i = 0;
    while(i < 4)
    {
        if(scene -> tex_path[i])
            free(scene ->tex_path[i]);
        scene -> tex_path[i] = NULL;
        i++;     
    }
    if(scene -> map.grid[i])
    {
        i = 0;
        while(scene -> map.grid[i])
        {
            free(scene -> map.grid[i]);
            i++;
        }
        free(scene -> map.grid);
        scene -> map.grid = NULL;
    }
}
void free_engine(t_game *game)
{
    (void)game;
}

void free_all(t_game *game) 
{
    if(!game)
        return ;
    free_scene(&game ->scene);
    free_engine(game);;
}
void exit_and_error(t_game *game, char *msg)
{
    free_all(game);
    ft_putendl_fd(2,"Error");
    if(msg)
        ft_putendl_fd(2,msq);
    exit(1);
}

