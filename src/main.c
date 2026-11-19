/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:21:24 by helfayez          #+#    #+#             */
/*   Updated: 2026/11/19 13:18:02 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"
int main(int argc, char **argv)
{
    t_game game;
    if(argc != 2)
    {
        write(2, "Error\n",6);
        exit(1);
    }
    if(!check_cub(argv[1]))
    {
        write(2, "Error\n",6);
        exit(1);
    }
    scene_value(&game.scene);
    pars_cub_file(argv[1], &game);

    return(0);
}
