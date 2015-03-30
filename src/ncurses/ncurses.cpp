//
// ncurses.cpp for ncurses in /home/gazzol_j/rendu/cpp_nibbler/src/ncurses
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Mar 30 10:27:12 2015 julien gazzola
// Last update Mon Mar 30 11:28:36 2015 julien gazzola
//


#include "IGraphic.hh"
#include "Ncurses.hh"

Ncurses::Ncurses(int x, int y):
  _x(x), _y(y)
{
  
}

Ncurses::~Ncurses()
{

}


t_move		Ncurses::getEvent()
{
  return (NONE);
}

void		Ncurses::display()
{
  
}
	
IGraphic	*create(int xMax, int yMax)
{
  return (new Ncurses(xMax, yMax));
}

void		destroy(IGraphic *toDestroy)
{
  delete toDestroy;
}
