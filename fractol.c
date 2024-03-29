/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:40:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 14:15:02 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	check(&f, argc, argv);
	init_fractol(&f);
	choose_fractol(&f);
	mlx_hook(f.win, 17, 0, close_win, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}

void	init_fractol(t_fractol *init)
{
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, WIDTH, HEIGHT, "FRACT'OL");
	init->img.img = mlx_new_image(init->mlx, WIDTH, HEIGHT);
	init->img.addr = mlx_get_data_addr(init->img.img, &init->img.bpp,
			&init->img.line_length, &init->img.endian);
	init->min.r = -2.0;
	init->max.r = 2;
	init->min.i = -2.0;
	init->max.i = 2.0;
	init->max_iterations = 150;
	init->shift = 1;
	init->key = 0;
}
