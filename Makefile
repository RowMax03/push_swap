#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _
# ___ __|  __/   |   |  (   |    <    __/
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = push_swap

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra
AR =		ar rcs
RM =		rm -rf

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=            push_wap.c \
                          find_median.c \
                          push_swap.c \
                          quick_sort.c \
                          src/index.c \
                          src/operations/get_rotated.c \
                          src/operations/swap_push.c \
                          src/sort_3.c \
						  src/rotate_direction.c \
						  src/input_check.c

OBJS =		$(SRCS:.c=.o)

LIBFT =	./includes/libft/libft.a

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@cd includes/libft && make && make clean

all :		$(NAME)

clean :
			$(RM) $(OBJS)

fclean :	clean
			@$(RM) $(NAME)
			@$(RM) ./libft

re :		fclean all

libft: $(LIBFT)

.PHONY: all clean fclean re
