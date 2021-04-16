# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 22:15:26 by marvin            #+#    #+#              #
#    Updated: 2021/04/14 22:15:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bitswapper.exe
FLAG	= -m64 -no-pie -O2
ELF 	= win64
SRCFILE	= main.c bmp_reader.c bmp_export.c
ASMFILE	= ft_strlen.asm ft_putstr_fd.asm ft_putendl_fd.asm \
		ft_putstr.asm ft_putendl.asm ft_putchar.asm ft_memset.asm \
		ft_atoi.asm ft_strcpy.asm ft_strclr.asm ft_strequ.asm \
		ft_striter.asm ft_striteri.asm \
		ft_memccpy.asm ft_memchr.asm ft_memcmp.asm ft_memcpy.asm \
		ft_memmove.asm ft_strcat.asm ft_strchr.asm ft_strcmp.asm ft_bzero.asm \
		ft_isalpha.asm ft_isascii.asm ft_isblank.asm ft_isdigit.asm ft_isalnum.asm\
		ft_isprint.asm ft_isnegative.asm \
		ft_bswap.asm ft_rotate_left.asm ft_rotate_right.asm \
		ft_test.asm
SRCEXT	= .asm
OBJEXT	= .o
SRC		= $(addprefix ./src/,$(SRCFILE))
OBJ		= $(addprefix ./obj/,$(SRCFILE:.c=.o)) $(addprefix ./obj/,$(ASMFILE:.asm=.o))
LIB		= libft_asm.a C:\SDL\SDL2-2.0.12\lib\x64\SDL2main.lib C:\SDL\SDL2-2.0.12\lib\x64\SDL2.lib
INCLS	= -I ./ -I C:\SDL\SDL2-2.0.12\include
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./src/%.c
	@mkdir -p obj
	gcc $(FLAG) -c $< -o $@

./obj/%.o:./asm/%.asm
	@mkdir -p obj
	nasm -f $(ELF) $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIB)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf ./obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
