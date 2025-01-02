# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 00:34:39 by adechaji          #+#    #+#              #
#    Updated: 2025/01/02 01:39:47 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/ft_atoi.c src/ft_lstadd_back.c src/ft_lstlast.c src/ft_lstnew.c src/ft_lstsize.c \
       src/ft_memcpy.c src/ft_split.c src/ft_splithelpers.c src/ft_strlen.c \
       src/giantsort.c src/helpmepls.c src/parsing1.c src/parsing2.c src/swapop.c \
       src/pushop.c src/revrotateop.c src/rotateop.c src/sortmid.c src/sortstart.c push_swap.c 
BONUS_SRCS = src_bonus/ft_atoi_bonus.c src_bonus/ft_lstadd_back_bonus.c src_bonus/ft_lstlast_bonus.c \
             src_bonus/ft_lstnew_bonus.c src_bonus/ft_lstsize_bonus.c src_bonus/ft_memcpy_bonus.c \
             src_bonus/ft_split_bonus.c src_bonus/ft_splithelpers_bonus.c src_bonus/ft_strlen_bonus.c \
             src_bonus/ft_strncmp_bonus.c src_bonus/get_next_line_bonus.c src_bonus/get_next_line_utils_bonus.c \
             src_bonus/parsing1_bonus.c src_bonus/parsing2_bonus.c src_bonus/pushop_bonus.c \
             src_bonus/revrotateop_bonus.c src_bonus/rotateop_bonus.c src_bonus/swapop_bonus.c \
             src_bonus/helpmepls_bonus.c checker.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c push_swap.h push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all