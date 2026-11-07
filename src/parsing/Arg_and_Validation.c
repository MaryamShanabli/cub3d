/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg_and_Validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:19:40 by helfayez          #+#    #+#             */
/*   Updated: 2026/11/07 20:47:28 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "././cub3d.h"

char check_cub(char *myfile)
{
    size_t file_len;
    char *end;
    
    file_len = ft_strlen(myfile);
    end = myfile + file_len -4;
    if(!myfile)
        return 0;
    if(file_len >= 4)    
    if (ft_strncmp(end,".cub", 4) != 0)
        return 0;
    if(myfile[file_len - 5] == '/')
        return 0;
   return(1);
}
void scene_value(t_scene *scene)
{
    int i;
    
    i = 0;
    while(i < 4)
    {
        scene -> tex_path[i] = NULL;
        i++;
    }
    scene -> floor_color = -1;
    scene -> ceil_color = -1;
    scene -> map.grid = NULL;
}
void pars_cub_file(char *file_path, t_game *game)
{
    int fd;
    char *line;
    
    fd = open(file_path, O_RDONLY);
    if(fd < 0)
    {
        ft_putendl_fd("ERROR: cannot open file\n", 2);
        exit(1);
    }
    line = get_next_line(fd);
    while(line != NULL)
    {
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
