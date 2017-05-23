# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/19 17:15:28 by qho               #+#    #+#              #
#    Updated: 2017/05/22 21:49:28 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	filler

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

FILES	=	main ft_print ft_init ft_load ft_play ft_parse ft_heatmap ft_play2
INC		=	./inc/
SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		=	$(addprefix build/, $(addsuffix .o, $(FILES)))

GNL		=	get_next_line/gnl.a
LIBFT	=	libft/libft.a

.PHONY: clean fclean re norm

all: $(NAME)	

$(NAME): $(SRC)
	@make -C libft
	@make -C get_next_line
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(GNL) -I $(INC)
	@echo "\033[32mCompiled fdf\033[0m"

norm:
	norminette $(SRC) $(INC)

clean:
	@make -C libft clean
	@make -C get_next_line clean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mObject files cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@make -C get_next_line fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31mExecutable cleaned\033[0m"

re: fclean all