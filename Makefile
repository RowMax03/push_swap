################################################################################
#     ██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗   #
#     ██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗  #
#     ██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝  #
#     ██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝   #
#     ██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║       #
#     ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝       #
################################################################################

NAME = push_swap

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra
RM =		rm -rf

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS = $(INPUT) $(OPERATIONS) $(SORTING) push_swap.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))
SRC_DIR = src/

INPUT = $(addprefix $(SRC_DIR), $(addprefix $(INPUT_DIR), $(INPUT_FILES)))
INPUT_DIR = input/
INPUT_FILES = argv_to_stack.c input_check.c index.c

OPERATIONS = $(addprefix $(SRC_DIR), $(addprefix $(OPERATIONS_DIR), $(OPERATION_FILES)))
OPERATIONS_DIR = operations/
OPERATION_FILES = get_rotated.c swap_push.c

SORTING = $(addprefix $(SRC_DIR), $(addprefix $(SORTING_DIR), $(SORTING_FILES)))
SORTING_DIR = sorting/
SORTING_FILES = quick_sort.c sort_3.c k_insert.c rotate_direction.c

################################################################################
#                              PROGRAM'S INCLUDES                              #
################################################################################

LIBFT =	./libs/libft/libft.a
LIBFT_DIR = ./libs/libft

$(LIBFT):
			@cd libs/libft && make && make clean

GET_NEXT_LINE = libs/get_next_line/get_next_line.c \
				libs/get_next_line/get_next_line_utils.c

INCLUDES =	-I ./includes \
			-I ./libs/libft \
			-I ./libs/get_next_line

################################################################################
#                                 PROGRAM'S OBJS                               #
################################################################################

OBJS =		$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

################################################################################
#                                     BONUS                                    #
################################################################################

BONUS_NAME = bonus_checker

BONUS_SRCS = $(INPUT) $(CHECKER) $(CHEKER_OPERATIONS) $(GET_NEXT_LINE)

CHECKER = $(addprefix $(CHECKER_DIR), $(CHECKER_FILES))
CHECKER_DIR = checker/
CHECKER_FILES = checker.c

CHEKER_OPERATIONS = $(addprefix $(CHECKER_DIR), $(addprefix $(CHEKER_OPERATIONS_DIR), $(CHEKER_OPERATIONS_FILES)))
CHEKER_OPERATIONS_DIR = operations/
CHEKER_OPERATIONS_FILES = get_rotated.c swap_push.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

################################################################################
#                                     RULES                                    #
################################################################################

bonus: $(BONUS_NAME)

all :		$(NAME)

clean :
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)

fclean :	clean
			@$(RM) $(NAME)
			@$(RM) $(BONUS_NAME)
			@cd	libs/libft && make fclean

re :		fclean all

libft: $(LIBFT)

.PHONY: all clean fclean re
