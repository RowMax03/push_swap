# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 08:11:09 by mreidenb          #+#    #+#              #
#    Updated: 2023/11/23 20:43:42 by mreidenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGSS	= -Wall -Wextra -Werror
INCFLAG	= -I .
AR		= ar
ARFLAGS = -rcs

NAME	= libft.a
MAIN	= isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy\
		memmove strlcpy strlcat toupper tolower strchr strrchr strncmp memchr\
		memcmp strnstr atoi calloc strdup substr strjoin strtrim split itoa\
		strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd printf/ft_printf\
		atoi_l
BONUS	= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear\
		lstiter lstmap

MAINFILES	= $(addprefix ft_,$(addsuffix .c, $(MAIN)))
BONUSFILES	= $(addprefix ft_,$(addsuffix .c, $(BONUS)))
MAINOBJ	= $(MAINFILES:.c=.o)
BONUSOBJ = $(BONUSFILES:.c=.o)

$(NAME): $(MAINOBJ)
	@$(AR) $(ARFLAGS) $@ $^

bonus:	$(BONUSOBJ)
	$(AR) $(ARFLAGS) $(NAME) $^ 

%.o : %.c
	@$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

clean:
	@rm -f $(MAINOBJ) $(BONUSOBJ)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME) bonus

.PHONY: bonus clean fclean re all