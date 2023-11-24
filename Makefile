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
#                              PROGRAM'S INCLUDES                              #
################################################################################


LIBFT =	./libs/libft/libft.a
LIBFT_DIR = ./libs/libft

GET_NEXT_LINE = libs/get_next_line/get_next_line.c \
				libs/get_next_line/get_next_line_utils.c

INCLUDES =	-I ./includes \
			-I ./libs/libft \
			-I ./libs/get_next_line

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
#                                 PROGRAM'S OBJS                               #
################################################################################

OBJS =		$(SRCS:.c=.o)


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

################################################################################
#                                     RULES                                    #
################################################################################

all :	$(LIBFT) $(NAME) animation

bonus: $(BONUS_NAME)

$(LIBFT):
			@make -C $(LIBFT_DIR)

%.o: %.c
	@printf "$(CLEAR_LINE)$(CYAN)Compiling... $<$(NC)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBFT) -o $(NAME) \
			&& printf "\033[32m[✓] $(NAME) created\n\033[0m" \

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME) && \
	printf "\033[32m[✓] $(BONUS_NAME) created\n\033[0m"

clean :
			@$(RM) $(OBJS)
			@$(RM) $(BONUS_OBJS)
			@printf "$(RED)[x] $(NAME) objects deleted\n\033[0m"

fclean :	clean
			@$(RM) $(NAME) && printf "$(RED)[x] $(NAME) deleted\n\033[0m"
			@$(RM) $(BONUS_NAME) && printf "$(RED)[x] $(BONUS_NAME) deleted\n\033[0m"
			@cd	libs/libft && make fclean && printf "$(RED)[x] $(LIBFT) deleted\n\033[0m"

re :		fclean all

libft: $(LIBFT)

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
YELLOW=\033[0;33m
BOLD=\033[1m
NC=\033[0m # No Color
CLEAR_LINE=\033[K
MOVE_UP=\033[A

animation:
	@printf "$(RED)\
██████╗ ██╗   ██╗███████╗██╗  ██╗  \n\
██╔══██╗██║   ██║██╔════╝██║  ██║  \n\
██████╔╝██║   ██║███████╗███████║  \n\
██╔═══╝ ██║   ██║╚════██║██╔══██║  \n\
██║     ╚██████╔╝███████║██║  ██║  \n\
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝  \n"
	@sleep 1
	@for i in {1..6}; do \
		printf "$(MOVE_UP)$(CLEAR_LINE)"; \
	done
	@printf "$(RED)\
                                    ██████╗ ██╗   ██╗███████╗██╗  ██╗  \n\
                                    ██╔══██╗██║   ██║██╔════╝██║  ██║  \n\
                                    ██████╔╝██║   ██║███████╗███████║  \n\
                                    ██╔═══╝ ██║   ██║╚════██║██╔══██║  \n\
                                    ██║     ╚██████╔╝███████║██║  ██║  \n\
                                    ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝  \n"
	@sleep 1
	@for i in {1..6}; do \
		printf "$(MOVE_UP)$(CLEAR_LINE)"; \
	done
	@printf "$(YELLOW)\
███████╗██╗    ██╗ █████╗ ██████╗   ██████╗ ██╗   ██╗███████╗██╗  ██╗  \n\
██╔════╝██║    ██║██╔══██╗██╔══██╗  ██╔══██╗██║   ██║██╔════╝██║  ██║  \n\
███████╗██║ █╗ ██║███████║██████╔╝  ██████╔╝██║   ██║███████╗███████║  \n\
╚════██║██║███╗██║██╔══██║██╔═══╝   ██╔═══╝ ██║   ██║╚════██║██╔══██║  \n\
███████║╚███╔███╔╝██║  ██║██║       ██║     ╚██████╔╝███████║██║  ██║  \n\
╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝       ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝  \n"
	@sleep 1
	@for i in {1..6}; do \
		printf "$(MOVE_UP)$(CLEAR_LINE)"; \
	done
	@printf "$(GREEN)\
██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗   \n\
██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗  \n\
██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝  \n\
██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝   \n\
██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║       \n\
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝       \n\
"

.PHONY: all clean fclean re bonus libft

