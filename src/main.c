/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:21:24 by helfayez          #+#    #+#             */
/*   Updated: 2026/11/07 20:49:06 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        write(2, "ERROR\n",6);
        exit(1);
    }
    if(!check_cub(argv[1]))
    {
        write(2, "ERROR\n",6);
        exit(1);
    }
    scene_value(&game.scene);
    pars_cub_file(argv[1], &game);

    return(0);
}
