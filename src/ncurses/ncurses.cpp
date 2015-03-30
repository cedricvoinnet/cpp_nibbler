//
// ncurses.cpp for ncurses in /home/gazzol_j/rendu/cpp_nibbler/src/ncurses
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Mar 30 10:27:12 2015 julien gazzola
// Last update Mon Mar 30 17:46:10 2015 julien gazzola
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
  this->_nibbler = (newwin(x, y, 0, 0));
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
  (void) snake;
}

void		Ncurses::display_food(std::pair<int, int> food)
{
  (void) food;
}

void		Ncurses::display(std::vector<std::pair<int, int> > snake, std::pair<int, int> food)
{
  display_snake(snake);
  display_food(food);
  wclear(this->_nibbler);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  wattron(this->_nibbler, COLOR_PAIR(1));
  wbkgd(this->_nibbler, COLOR_PAIR(1));
  wrefresh(this->_nibbler);
  wattron(this->_nibbler, COLOR_PAIR(2));
  wprintw(this->_nibbler, " ");
  wattroff(this->_nibbler, COLOR_PAIR(2));
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
