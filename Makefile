RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
NAME = push_swap
NAME_B = checker
INCS = -I incs -I libft/incs 

SOURCES = main.c\
	parser.c\
	operations.c\
	sort_1_to_5.c\
	quicksort.c\
	optimize.c\
	utils.c

SOURCES_B = checker.c\
	parser.c\
	utils.c\
	instructions.c\
	operations.c

LIBFT = libft/libft.a

SRCS = ${addprefix ${DIR_S}/,${SOURCES}}
# OBJS = ${addprefix ${DIR_O}/,${SOURCES:.c=.o}}

SRCS_B = ${addprefix ${DIR_B}/,${SOURCES_B}}
# OBJS = ${addprefix ${DIR_O}/,${SOURCES:.c=.o}}

DIR_S = srcs
DIR_B = bonus

${NAME}: ${SRCS}
	@make -s -C libft
	@echo "${BLUE}Compiling ${NAME}${END}"
	@CC ${CFLAGS} ${SRCS} ${LIBFT} ${INCS} -o ${NAME}
	@echo "${GREEN}Done!${END}"

test:
	@make -s -C libft
	@echo "${YELLOW}Testing ${NAME}${END}"
	@${CC} ${CFLAGS} -fsanitize=address ${SRCS} ${LIBFT} ${INCS} -o ${NAME}
	@echo "${GREEN}Done!${END}"

${NAME_B}: ${NAME} ${SRCS_B} 
	@echo "${BLUE}Compiling ${NAME_B}${END}"
	@${CC} ${CFLAGS} ${SRCS_B} ${LIBFT} ${INCS} -o ${NAME_B}
	@echo "${GREEN}Done!${END}"

bonus : ${NAME_B}

all: ${NAME}

clean:
# @echo "${RED}Removing files${END}"
	@make clean -C libft
	@echo "${GREEN}Done!${END}"

fclean:
	@make fclean -C libft
	@echo "${RED}Removing ${NAME} && ${NAME_B}${END}"
	@rm -rf ${NAME}
	@rm -rf ${NAME_B}
	@echo "${GREEN}Done!${END}"

re: fclean all

.PHONY: all clean fclean re bonus test
