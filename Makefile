CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = esn.out
PRINTF_DIR = Ft_printf
ESN_DIR = ESN

SRCS = $(ESN_DIR)/email_sticky_note.c $(ESN_DIR)/email_sticky_note_utils.c $(ESN_DIR)/email_sticky_note_strs.c \
       $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_utils_printf.c $(PRINTF_DIR)/ft_putnbrptr_printf.c \
       $(PRINTF_DIR)/ft_putnbrhexa_printf.c $(PRINTF_DIR)/ft_itoa.c $(PRINTF_DIR)/ft_uitoa.c

OBJS = ${SRCS:.c=.o}
DEPS = ${OBJS:.o=.d}

GREEN_COLOR = "\033[32m"
CYAN_COLOR = "\033[36m"
BLUE_COLOR = "\033[34m"
X = "\033[0m"
BOLD = "\033[1m"

all: ${NAME}

-include ${DEPS}

${NAME}: ${OBJS}
	@echo $(BOLD)$(GREEN_COLOR)Compiling the following files:$(X)$(CYAN_COLOR)[$(SRCS)]$(X)
	@$(CC) ${FLAGS} -o ${NAME} ${OBJS}
	@echo $(BOLD)$(GREEN_COLOR)Compilation done.

%.o : %.c
	@${CC} ${FLAGS} -MMD -MP -o $@ -c $< -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)

clean :
	@rm -f ${OBJS} ${DEPS}
	@echo $(BOLD)$(GREEN_COLOR)Cleaning the following files: $(X)$(BLUE_COLOR)[$(SRCS)]$(X)
	@echo $(BOLD)$(GREEN_COLOR)Cleaning done.

fclean : clean
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
