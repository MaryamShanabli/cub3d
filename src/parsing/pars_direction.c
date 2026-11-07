/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:57:49 by helfayez          #+#    #+#             */
/*   Updated: 2026/11/07 21:17:22 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "././cub3d.h"

pars_map(char **tex_path, char *line)
{
    int i;
    int len;

    i = 0;
    if(*tex_path != NULL)
    {
        ft_putendl_fd(2, "ERROR: duplicate map");
        exit(1);
    }
    while(line[i] == ' ' || line[i] == '\t')
        i++;
    len = ft_stlen(&line[i]);
    if(len > 0 && line[i + line - 1] == '\n')
        line[i + line -1] = '\0';
    *tex_path = ft_strdup(&line[i]);
    if(!*tex_path)
    {
        ft_putendl_fd("ERROR: in malloc(in pars_map)", 2);
        exit(1);
    }
}

void pase_line(char *line, t_game *game)
{
    int i;

    i = 0;
    while(line[i] == ' ' || line[i] == '\t')
        i++;
    while(line[i] == '\n' || line[i] == '\0')
        return ;
    if(ft_strncmp(&line[i], "NO", 2) == 0)
        pars_map(&game -> scene.tex_path[NORTH], &line[i + 2]);
    else if(ft_strncmp(&line[i], "SO", 2) == 0)
        pars_map(&game -> scene.tex_path[SOUTH], &line[i + 2]);
    else if(ft_strncmp(&line[i], "WE", 2) == 0)
        pars_map(&game -> scene.tex_path[WEST], &line[i + 2]);
    else if(ft_strncmp(&line[i], "EA", 2) == 0)
        pars_map(&game -> scene.tex_path[EAST], &line[i + 2]);
    else
    {
        ft_putendl_fd("ERROR: unkown direction");
        exit(1);
    }
}
