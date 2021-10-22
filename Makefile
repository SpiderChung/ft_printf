# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 17:16:54 by schung            #+#    #+#              #
#    Updated: 2021/10/22 17:17:03 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h

SRC = ft_printf.c

SRC_BONUS = ft_

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME): $(SRC) $(HEAD)   
	@$(CC) $(SRC)
	@$(LIB) $(OBJ)
	@$(RANLIB)
	@echo "[INFO] Library [$(NAME)] created"

bonus:
	@$(CC) $(SRC_BONUS)
	@$(LIB) $(OBJ_BONUS)
	@$(RANLIB)
	@echo "[INFO] Bonus Library [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@echo "[INFO] Removed objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "[INFO] Library and objects removed "

re: fclean all

.PHONY: all clean fclean re
