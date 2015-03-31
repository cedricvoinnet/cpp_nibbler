##
## Makefile for nibbler in /home/voinne_c/rendu/cpp_nibbler
## 
## Made by Cédric Voinnet
## Login   <voinne_c@epitech.net>
## 
## Started on  Mon Mar 23 10:48:19 2015 Cédric Voinnet
## Last update Tue Mar 31 12:25:33 2015 Cédric Voinnet
##

CC	=	g++

RM	=	rm -f

FLAGS	=	-fpic -W -Wall -Werror -Wextra

INC	=	-Iincludes/core/ \
		-Iincludes/gtk/ \
		-Iincludes/sfml/ \
		-Iincludes/ncurses/

NAME	=	nibbler

NAME_L1	=	lib_nibbler_gtk.so

NAME_L2	=	lib_nibbler_sfml.so

NAME_L3	=	lib_nibbler_ncurses.so

SRC	=	src/core/main.cpp \
		src/core/Core.cpp \
		src/core/Snake.cpp \
		src/core/Error.cpp

SRC_L1	=	src/gtk/Gtk.cpp

SRC_L2	=	src/sfml/sfml.cpp

SRC_L3	=	src/ncurses/ncurses.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_L1	=	$(SRC_L1:.cpp=.o)

OBJ_L2	=	$(SRC_L2:.cpp=.o)

OBJ_L3	=	$(SRC_L3:.cpp=.o)

$(OBJ_L1): FLAGS += `pkg-config gtk+-2.0 --cflags --libs`

all:		$(NAME) $(NAME_L2) $(NAME_L3) $(NAME_L1)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -ldl

$(NAME_L1):	$(OBJ_L1)
		$(CC) $(OBJ_L1) `pkg-config gtk+-2.0 --cflags --libs` -shared -o $(NAME_L1)

$(NAME_L2):	$(OBJ_L2)
		$(CC) $(OBJ_L2) -lsfml-window -lsfml-graphics -shared -o $(NAME_L2)

$(NAME_L3):	$(OBJ_L3)
		$(CC) $(OBJ_L3) -lncurses -shared -o $(NAME_L3)

%.o:		%.cpp
		$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		$(RM) $(OBJ) $(OBJ_L1) $(OBJ_L2) $(OBJ_L3)

fclean:		clean
		$(RM) $(NAME) $(NAME_L1) $(NAME_L2) $(NAME_L3)

re:		fclean all

.PHONY:		re fclean all clean
