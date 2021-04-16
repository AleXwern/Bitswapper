/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitswapper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:31:52 by marvin            #+#    #+#             */
/*   Updated: 2021/04/14 22:31:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSWAPPER_H
# define BITSWAPPER_H

# include "C:\SDL\SDL2-2.0.12\include\SDL.h"
# include "libft_asm.h"
# include "bmp.h"
# include <stdio.h>
# include <string.h>

typedef struct		s_screen
{
	uint32_t		wid;
	uint32_t		hgt;
	uint32_t		*pixels;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_screen;

typedef struct		s_bitswapper
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	t_screen		*screen;
	t_gfx			*image;
}					t_bitswapper;

void	bmp_export(t_gfx *gfx);

#endif