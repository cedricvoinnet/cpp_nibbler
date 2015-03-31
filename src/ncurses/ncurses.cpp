//
// ncurses.cpp for ncurses in /home/gazzol_j/rendu/cpp_nibbler/src/ncurses
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Mar 30 10:27:12 2015 julien gazzola
// Last update Tue Mar 31 13:39:29 2015 julien gazzola
//

#include <unistd.h>
#include <ncurses.h>
#include "IGraphic.hh"
#include "Ncurses.hh"

Ncurses::Ncurses(int x, int y):
  _x(x), _y(y)
{
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, 1);
  nodelay(stdscr, 1);
  curs_set(0);
  this->_nibbler = (newwin(y, x, 0, 0));
}

Ncurses::~Ncurses()
{
  delwin(this->_nibbler);
  endwin();
}


t_move		Ncurses::getEvent()
{
  int		ch;

  ch = getch();
  if (ch == 27)
    return (QUIT);
  else if (ch == 261)
    return (RIGHT);
  else if (ch == 260)
    return (LEFT);
  return (NONE);
}

void		Ncurses::display_snake(std::vector<std::pair<int, int> > snake)
{
  for (std::vector<std::pair<int, int> >::iterator it = snake.begin(); it != snake.end(); it++)
    mvwprintw(this->_nibbler, it->second, it->first, " ");
}

void		Ncurses::display_food(std::pair<int, int> food)
{
  mvwprintw(this->_nibbler, food.second, food.first, " ");
}

void		Ncurses::display(std::vector<std::pair<int, int> > snake, std::pair<int, int> food)
{
  wclear(this->_nibbler);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_RED, COLOR_RED);
  wattron(this->_nibbler, COLOR_PAIR(1));
  wbkgd(this->_nibbler, COLOR_PAIR(1));
  wrefresh(this->_nibbler);
  wattron(this->_nibbler, COLOR_PAIR(3));
  wattron(this->_nibbler, COLOR_PAIR(2));
  display_food(food);
  display_snake(snake);
  wrefresh(this->_nibbler);
  wattroff(this->_nibbler, COLOR_PAIR(2));
  wattroff(this->_nibbler, COLOR_PAIR(3));
  wrefresh(this->_nibbler);
  wattroff(this->_nibbler, COLOR_PAIR(1));
}
	
IGraphic	*create(int xMax, int yMax)
{
  return (new Ncurses(xMax, yMax));
}

void		destroy(IGraphic *toDestroy)
{
  delete toDestroy;
}
