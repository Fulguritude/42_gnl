# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduquesn <tduquesn@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 21:33:56 by tduquesn          #+#    #+#              #
#    Updated: 2017/12/12 19:50:00 by tduquesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line
LFT		=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address

HDDIR	=	.
LFTDIR	=	./libft/
TSTDIR	=	./tests/

HDRS	=	get_next_line.h
SRCS	=	get_next_line.c
			
TESTS	=	Chanson_d_automne		\
			Ozymandias_Shelley		\
			Ozymandias_Smith

OBJS	=	$(SRCS:.c=.o)

MAIN	=	main_get_next_line.c

$(LFT):
	$(MAKE) -C $(LFTDIR) $(LIBFT)

$(NAME): $(LFT)
	gcc $(CFLAGS) -c $(SRCS) -I$(LFTDIR)hdr/
	gcc $(CFLAGS) -c $(TSTDIR)$(MAIN) -I$(LFTDIR)hdr/ -o $(TSTDIR)$(MAIN:.c=.o)
	gcc -o $(NAME) $(OBJS) $(TSTDIR)$(MAIN:.c=.o) -lft -L$(LFTDIR) -lasan

all: $(LFT) $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(TSTDIR)$(MAIN:.c=.o)

fclean:clean
	$(MAKE) -C $(LFTDIR) fclean
	rm -f $(NAME)

re:fclean all

test:re
	./$(NAME) $(addprefix $(TSTDIR),$(TESTS))
	@make clean
