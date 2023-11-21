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
                          push_swap.c \
                          quick_sort.c \
                          src/index.c \
                          src/operations/get_rotated.c \
                          src/operations/swap_push.c \
                          src/sort_3.c \
						  src/rotate_direction.c \
						  src/input_check.c \
						  keta_sort.c

OBJS =		$(SRCS:.c=.o)

LIBFT =	./includes/libft/libft.a

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@cd includes/libft && make && make clean

GET_NEXT_LINE = includes/get_next_line/get_next_line.c \
				includes/get_next_line/get_next_line_utils.c

BONUS_SRCS = checker/checker.c \
			 checker/operations/get_rotated.c \
			 checker/operations/swap_push.c \
			 push_wap.c \
             quick_sort.c \
             src/index.c \
             src/operations/get_rotated.c \
             src/operations/swap_push.c \
             src/sort_3.c \
			 src/rotate_direction.c \
			 src/input_check.c \
			 keta_sort.c \
			 $(GET_NEXT_LINE)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

BONUS_NAME = bonus_checker

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

all :		$(NAME)

clean :
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)

fclean :	clean
			@$(RM) $(NAME)
			@$(RM) $(BONUS_NAME)
			@cd	includes/libft && make fclean

re :		fclean all

libft: $(LIBFT)

.PHONY: all clean fclean re
