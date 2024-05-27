##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile for my radar
##

SRC	=	src/main.c	\
		src/error_handling.c	\
		src/get_buffer.c	\
		src/print.c	\
		src/connect_terminals.c	\
		src/get_map.c	\
		src/game_loop.c	\
		src/game_status.c	\
		src/display_game.c	\
		src/sigaction_functions.c	\
		src/free.c	\
		side_functions/my_strcmp.c	\
		side_functions/my_strcpy.c	\
		side_functions/my_is_numeric.c	\
		side_functions/str_to_array.c	\
		side_functions/my_arraylen.c	\
		side_functions/str_to_int.c	\
		side_functions/free_array.c	\

SRC_TEST	=	tests/unit_test.c	\
				src/error_handling.c	\
				src/get_buffer.c	\
				src/print.c	\
				src/connect_terminals.c	\
				src/get_map.c	\
				src/game_loop.c	\
				src/game_status.c	\
				src/display_game.c	\
				src/sigaction_functions.c	\
				src/free.c	\
				side_functions/my_strcmp.c	\
				side_functions/my_strcpy.c	\
				side_functions/my_is_numeric.c	\
				side_functions/str_to_array.c	\
				side_functions/my_arraylen.c	\
				side_functions/str_to_int.c	\
				side_functions/free_array.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_TEST =	$(SRC_TEST:.c=.o)

NAME	=	my_navy

LIB	=	./lib/libmini.a

CPPFLAGS	=	-iquote./include/

LDFLAGS	=	-L./lib/

LDLIBS	=	 -lmini

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(LIB):
	make -C ./miniprintf/

$(NAME):	$(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	make clean -C ./miniprintf

fclean:	clean
	$(RM) $(NAME) test_run
	make fclean -C ./miniprintf

debug: CFLAGS += -ggdb3
debug: re

unit_tests: $(LIB) $(OBJ_TEST)
	$(CC) -o test_run $(OBJ_TEST) -lcriterion --coverage $(LDFLAGS) $(LDLIBS)

tests_run:	unit_tests
	./test_run

re:	fclean	all

.PHONY: all clean fclean re
