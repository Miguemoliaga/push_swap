NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

SRCS	=	push_swap.c \
 			five_num_sort.c \
			mov_push.c \
			mov_rev.c \
			mov_rot.c \
			mov_swap.c \
			sort_alg.c \
		  	sort_utils.c \
			three_num_sort.c \
			utils.c

LIBFT	= libft/

MAKE_LIB= make bonus

INCLUDE	= -L${LIBFT} -lft 

OBJS	= ${SRCS:.c=.o}

SIZE 	?= 100

RM		= rm -rf

OS		:= $(shell uname -s)

ifeq ($(OS), Linux)
	INCLUDE += -static-libasan
	MAKE_LIB = make so
endif

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I${LIBFT} $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${MAKE_LIB} -C ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

clean:
		@${RM} ${OBJS} *.dSYM
		(cd libft; make fclean)

fclean:		clean
		@${RM} ${NAME}

check: $(NAME)
	@./$(NAME) `python3 -c 'import random; print(" ".join(map(str, random.sample(range(1, 100001), $(SIZE)))))'`

bonus: all

re:		fclean all

.PHONY:	clean re fclean bonus all