/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:56:31 by marvin            #+#    #+#             */
/*   Updated: 2021/04/15 18:56:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include <stdio.h>

int			write_to_pixdata(t_bmphead bmp, t_uint32 bread, int fd)
{
	int		toread;
	char	dummy[500];

	ft_bzero(dummy, 500);
	while (bread < bmp.pdoff)
	{
		toread = bmp.pdoff - bread;
		if (toread > 500)
			toread = 500;
		write(fd, dummy, toread);
		bread += toread;
		if (toread == 0)
			return (0);
	}
	if (bread > bmp.pdoff)
		return (0);
	return (1);
}

void	write_array(t_gfx *gfx, int fd)
{
	int		i;
	int		pad = 0;
	int		start;
	char	dum[3] = {0, 0, 0};

	i = gfx->hgt - 1;
	if (gfx->pitch % 4 != 0)
		pad = 4 - (gfx->pitch % 4);
	printf("Pad %d %d\n", pad, gfx->pitch);
	start = i * gfx->wid;
	while (1)
	{
		write(fd, gfx->data + start, gfx->wid * 4);
		//if (pad > 0)
		//	write(fd, dum, pad);
		if (i == 0)
			break;
		start -= gfx->wid;
		i--;
	}
	printf("Export succesful\n");
}

void	bmp_export(t_gfx *gfx)
{
	t_bmphead	head;
	t_bmpinfo	info;
	int			fd;
	t_uint32	truwid;
	t_uint32	bread;

	fd = open("LD.bmp", O_RDONLY);
	read(fd, &head, sizeof(head));
	read(fd, &info, sizeof(info));
	printf("fsize %d\npdoff %d\nheader %d\ndim %d %d\nplanes %d\nbpp %d\ncomp %d\nimgsize %d\nxppm %d\nyppm %d\ncolcount %d\nimpcol %d\n",
		head.fsize, head.pdoff, info. headsize, info.width, info.heigth, info.planes,
		info.bpp, info.compr, info.imgsize, info.xppm, info.yppm, info.colcount, info.impcol);
	close(fd);
	fd = open("out.bmp", O_CREAT | O_WRONLY | O_TRUNC);
	if (fd == -1)
		return;
	truwid = gfx->wid;
	if (truwid % 4 != 0)
		truwid += 4 - (truwid % 4);
	bread = write(fd, &head, sizeof(head));
	bread += write(fd, &info, sizeof(info));
	write_to_pixdata(head, bread, fd);
	write_array(gfx, fd);
	close(fd);
}