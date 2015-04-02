##
## Makefile for nibbler in /home/voinne_c/rendu/cpp_nibbler
## 
## Made by Cédric Voinnet
## Login   <voinne_c@epitech.net>
## 
## Started on  Mon Mar 23 10:48:19 2015 Cédric Voinnet
## Last update Thu Apr  2 19:06:29 2015 Cédric Voinnet
##

CC	=	g++

RM	=	rm -f

FLAGS	=	-fpic -W -Wall -Werror -Wextra

INC	=	-Iincludes/core/

NAME	=	nibbler

NAME_L1	=	lib_nibbler_xlib.so

NAME_L2	=	lib_nibbler_sfml.so

NAME_L3	=	lib_nibbler_ncurses.so

SRC	=	src/core/main.cpp \
		src/core/Core.cpp \
		src/core/Snake.cpp \
		src/core/Error.cpp

SRC_L1	=	src/xlib/Xlib.cpp \
		src/core/Error.cpp

SRC_L2	=	src/sfml/sfml.cpp

SRC_L3	=	src/ncurses/ncurses.cpp \
		src/core/Error.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_L1	=	$(SRC_L1:.cpp=.o)

OBJ_L2	=	$(SRC_L2:.cpp=.o)

OBJ_L3	=	$(SRC_L3:.cpp=.o)

all:		$(NAME) $(NAME_L1) $(NAME_L2) $(NAME_L3)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -ldl

$(NAME_L1):	$(OBJ_L1)
		$(CC) $(OBJ_L1) -lX11 -shared -o $(NAME_L1)

$(NAME_L2):	$(OBJ_L2)
		$(CC) $(OBJ_L2) -lsfml-window -lsfml-graphics -shared -o $(NAME_L2)

$(NAME_L3):	$(OBJ_L3)
		$(CC) $(OBJ_L3) -lncurses -shared -o $(NAME_L3)

%.o:		%.cpp
		$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OBJ_L1): 	INC += -Iincludes/xlib/

$(OBJ_L2): 	INC += -Iincludes/sfml/

$(OBJ_L3): 	INC += -Iincludes/ncurses/

clean:
		$(RM) $(OBJ) $(OBJ_L1) $(OBJ_L2) $(OBJ_L3)

fclean:		clean
		$(RM) $(NAME) $(NAME_L1) $(NAME_L2) $(NAME_L3)

re:		fclean all

.PHONY:		re fclean all clean
