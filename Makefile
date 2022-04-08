##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRCM	=	main.c

SRC	=	sources/bsq.c	\
		sources/functions.c	\
		sources/functions2.c

OBJ	=	$(SRC:.c=.o)	\
		$(SRCM:.c=.o)

NAME	=	bsq

LDFLAG	=	-L./lib/my -lmy
CFLAGS	+=	-Wall	\
		-Wextra

RM	=	rm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(SRC) $(SRCM) -g $(LDFLAG)
clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda

tests_run:
	make -C lib/my/
	gcc $(SRC) tests/test_calc.c --coverage -lcriterion $(LDFLAG)
	./a.out

re:	fclean all

.PHONY: re fclean clean all
