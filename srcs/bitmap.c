/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:57:45 by jpeyron           #+#    #+#             */
/*   Updated: 2021/02/08 12:16:15 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cub3d.h"
#include "libft.h"

void	bmp_header(t_all *all, int fd)
{
	int	header_size;
	int	file_size;

	header_size = 54;
	file_size = all->win->wid * all->win->len * 4 + header_size;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &header_size, 4);
}

void	image_infos(t_all *all, int fd)
{
	int	header_size;
	int	plane;
	int	image_size;

	header_size = 40;
	plane = 1;
	image_size = all->win->wid * all->win->len;
	write(fd, &header_size, 4);
	write(fd, &all->win->wid, 4);
	write(fd, &all->win->len, 4);
	write(fd, &plane, 2);
	write(fd, &all->win->img->bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	write_pixs(t_win *win, int fd)
{
	int	r;
	int	g;
	int	b;
	int y;
	int x;

	y = win->len;
	while (--y >= 0)
	{
		x = -1;
		while (++x < win->wid)
		{
			r = win->img->addr[y * win->img->line_l + x * win->img->bpp / 8];
			g = win->img->addr[y * win->img->line_l + x * win->img->bpp / 8
				+ 1];
			b = win->img->addr[y * win->img->line_l + x * win->img->bpp / 8
				+ 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
		}
	}
}

int		save_bmp(t_all *all, char *name)
{
	int	fd;

	if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU)) < 0)
		return (!error(BITMAP_OPEN_ERROR, "", 0));	
	bmp_header(all, fd);
	image_infos(all, fd);
	write_pixs(all->win, fd);
	close(fd);
	return (1);
}
