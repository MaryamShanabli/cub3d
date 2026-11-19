/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:57:49 by helfayez          #+#    #+#             */
/*   Updated: 2026/11/19 14:15:37 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "././cub3d.h"

void pars_map(char **tex_path, char *line)
{
    int i;
    int len;
    int fd;
    
    i = 0;
    if(*tex_path != NULL)
    {
        ft_putendl_fd(2, "Error: duplicate map");
        exit(1);
    }
    while(line[i] == ' ' || line[i] == '\t')
        i++;
    len = ft_strlen(&line[i]);
    if(len > 0 && line[i + len - 1] == '\n' 
                || line[i + len -1] == ' ' || line[i + len - 1 == '\t'])
        len --;
    if(len == 0)
    {
        ft_putendl_fd(2,"Error: empty map");
        exit(1);
    }
    line[i + len] = '\0';
    fd = open(&line[i], O_RDONLY);
    if(fd < 0)
    {
        ft_putendl_fd(2,"Error: cannot open map");
        exit(1);        
    }
    close(fd);
    *tex_path = ft_strdup(&line[i]);
    if(!*tex_path)
    {
        ft_putendl_fd("Error: in malloc(in pars_map)", 2);
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
    if(ft_strncmp(&line[i], "NO", 2) == 0 && (line[i + 2] == ' ' || line[i + 2] =='\t'))
        pars_map(&game -> scene.tex_path[NORTH], &line[i + 2]);
    else if(ft_strncmp(&line[i], "SO", 2) == 0 && (line[i + 2] == ' ' || line[i + 2] =='\t'))
        pars_map(&game -> scene.tex_path[SOUTH], &line[i + 2]);
    else if(ft_strncmp(&line[i], "WE", 2) == 0 && (line[i + 2] == ' ' || line[i + 2] =='\t'))
        pars_map(&game -> scene.tex_path[WEST], &line[i + 2]);
    else if(ft_strncmp(&line[i], "EA", 2) == 0 && (line[i + 2] == ' ' || line[i + 2] =='\t'))
        pars_map(&game -> scene.tex_path[EAST], &line[i + 2]);
    else
    {
        ft_putendl_fd(2,"Error: unkown direction");
        exit(1);
    }
}

