/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:30:23 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/17 14:26:06 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int close_win(t_fractal *f)
{
    mlx_destroy_window(f->mlx, f->win);
    exit(EXIT_SUCCESS);
}

int key_hook(int key, t_fractal *f)
{
    if (key == 53 || key == 65307)
        close_win(f);
    return (0);
}

int mouse_hook(int key, int x, int y, t_fractal *f)
{
	int flag;

	flag = 0;
    if (key == 5 && flag == 0)
		flag = zoom(f, x, y, 1.1);
	else if(key == 4 && flag == 0)
		flag = zoom(f, x, y, 0.9);
	if(flag == 1)
	{
		mlx_clear_window(f->mlx, f->win);
		choose(f);
	}
    return (0);
}
