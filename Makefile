# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 15:43:21 by rsandova          #+#    #+#              #
#    Updated: 2020/02/11 17:20:35 by rsandova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES = ft_printf.c numbers.c letters.c ft_ltoa_base.c pointer.c \
			ft_u_itoa.c ft_itoa_hex.c ft_str_toupper.c width.c flags.c \
			point.c star.c

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc -c -Wall -Werror -Wextra
HEADERS = -I.libftprintf.h -I.libft/libft.h

RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ bonus
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJ)

clean:
	@make -C libft/ clean
	@mkdir -p $(OBJ_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@$(RM)  $(NAME)

re: fclean all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $< $(HEADERS) $(LIBFT) -o $@
	@echo "Compilation of function "$<