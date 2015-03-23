##
## Makefile for nibbler in /home/voinne_c/rendu/cpp_nibbler
## 
## Made by Cédric Voinnet
## Login   <voinne_c@epitech.net>
## 
## Started on  Mon Mar 23 10:48:19 2015 Cédric Voinnet
## Last update Mon Mar 23 11:05:58 2015 Cédric Voinnet
##

CC	=	g++

RM	=	rm -f

CFLAGS	=	-fpic -W -Wall -Werror -Wextra

NAME	=	nibbler

NAME_L1	=	lib_nibbler_.so

NAME_L2	=	lib_nibbler_.so

NAME_L3	=	lib_nibbler_.so

SRC	=	

SRC_L1	=	

SRC_L2	=	

SRC_L3	=	

OBJ	=	$(SRC:.cpp=.o)

OBJ_L1	=	$(SRC_L1:.cpp=.o)

OBJ_L2	=	$(SRC_L2:.cpp=.o)

OBJ_L3	=	$(SRC_L3:.cpp=.o)

all:		$(NAME) $(NAME_L1) $(NAME_L2) $(NAME_L3)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

$(NAME_L1):	$(OBJ_L1)
		$(CC) $(OBJ_L1) -shared -o $(NAME_L1)

$(NAME_L2):	$(OBJ_L2)
		$(CC) $(OBJ_L2) -shared -o $(NAME_L2)

$(NAME_L3):	$(OBJ_L3)
		$(CC) $(OBJ_L3) -shared -o $(NAME_L3)

%.o:		%.cpp
		$(CC) $(CFLAGS) -o $@ -c $<
