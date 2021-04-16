/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:33:25 by marvin            #+#    #+#             */
/*   Updated: 2021/04/14 22:33:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitswapper.h"

void error_out()
{
	printf("Error %s\n", SDL_GetError());
	exit(-1);
}

int		key_handle(uint32_t key, t_bitswapper *bts)
{
	uint32_t	pixels;

	pixels = bts->image->wid * bts->image->hgt;
	switch (key)
	{
	case SDL_SCANCODE_ESCAPE:
		return (1);
	case SDL_SCANCODE_LEFT:
		for (int i = 0; i < pixels; i++)
			bts->image->data[i] = ft_rotate_left(bts->image->data[i]);
		printf("Bytes Shifted left\n");
		break;
	case SDL_SCANCODE_RIGHT:
		for (int i = 0; i < pixels; i++)
			bts->image->data[i] = ft_rotate_right(bts->image->data[i]);
		printf("Bytes Shifted right\n");
		break;
	case SDL_SCANCODE_UP:
	case SDL_SCANCODE_DOWN:
		for (int i = 0; i < pixels; i++)
			bts->image->data[i] = ft_bswap(bts->image->data[i]);
		printf("Bytes Shifted around\n");
		break;
	case SDL_SCANCODE_E:
		bmp_export(bts->image);
		break;
	default:
		break;
	}
	return (0);
}

void	program_loop(t_bitswapper *bts)
{
	SDL_Event		event;
	uint32_t		key;

	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			if (SDL_HasEvents(SDL_MOUSEMOTION, SDL_MOUSEWHEEL))
				SDL_FlushEvents(SDL_MOUSEMOTION, SDL_MOUSEWHEEL);
			if (event.type == SDL_QUIT)
				break;
			if (event.key.state == SDL_PRESSED)
				if (key_handle(event.key.keysym.scancode, bts))
					break;
		}
		ft_memcpy(bts->screen->pixels, bts->image->data, bts->screen->hgt * 4 * bts->screen->wid);
		SDL_RenderPresent(bts->render);
	}
}

int		main(int argc, char* argv[])
{
	t_bitswapper	bts;
	t_screen		screen;
	t_gfx			image;

	printf("Henlo\n");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		error_out();
	image = read_bmp("LD.bmp", 0, 0);
	printf("%d %d\n", image.hgt, image.wid);
	screen.hgt = image.hgt;
	screen.wid = image.wid;
	if (!(bts.window = SDL_CreateWindow("BitSwapper", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, screen.wid, screen.hgt, 0)))
		error_out();
	if (!(bts.render = SDL_CreateRenderer(bts.window, -1, SDL_RENDERER_SOFTWARE)))
		if (!(bts.render = SDL_GetRenderer(bts.window)))
			error_out();
	
	if (!(screen.surface = SDL_GetWindowSurface(bts.window)))
		error_out();
	screen.texture = SDL_CreateTextureFromSurface(bts.render, screen.surface);
	screen.pixels = (t_uint32*)screen.surface->pixels;
	
	bts.screen = &screen;
	bts.image = &image;
	program_loop(&bts);
	SDL_Quit();
	return (1);
}
