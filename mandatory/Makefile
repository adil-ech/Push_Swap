# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 22:39:53 by adechaji          #+#    #+#              #
#    Updated: 2024/12/24 17:26:38 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS 	= -Wall -Werror -Wextra
NAME	= push_swap.a
AR		= ar rcs
SRC     = pushop.c revrotateop.c rotateop.c swapop.c \
		sortstart.c sortmid.c largersort.c giantsort.c \
        minilibft/ft_lstnew_bonus.c minilibft/ft_lstadd_front_bonus.c minilibft/ft_lstsize_bonus.c \
		minilibft/ft_lstlast_bonus.c minilibft/ft_lstadd_back_bonus.c \
        minilibft/ft_lstdelone_bonus.c minilibft/ft_lstclear_bonus.c minilibft/ft_lstiter_bonus.c \
		minilibft/ft_lstmap_bonus.c minilibft/ft_atoi.c minilibft/ft_isdigit.c minilibft/ft_split.c \
		minilibft/ft_memcpy.c minilibft/ft_splithelpers.c
OBJ		:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean