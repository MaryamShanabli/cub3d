/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arg_and_Validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:19:40 by helfayez          #+#    #+#             */
/*   Updated: 2026/10/16 16:31:03 by helfayez         ###   ########.fr       */
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
