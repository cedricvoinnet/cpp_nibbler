//
// Ncurses.hh for nibbler in /home/gazzol_j/rendu/cpp_nibbler/includes/ncurses
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Mar 30 10:33:22 2015 julien gazzola
// Last update Wed Apr  1 14:44:53 2015 julien gazzola
//

#ifndef NCURSES_HH_
# define NCURSES_HH_

# include <vector>
# include <utility>
# include "IGraphic.hh"

class	Ncurses : public IGraphic
{
private:
  int		_x;
  int		_y;
  WINDOW	*_nibbler;

public:
  Ncurses(int x, int y);
  ~Ncurses();
  t_move	getEvent();
  void		display(std::vector<std::pair<int, int> >, std::pair<int, int>);
  void		display_snake(std::vector<std::pair<int, int> >);
  void		display_food(std::pair<int, int>);
};

extern "C"
{
  IGraphic	*create(int , int);
  void		destroy(IGraphic *);
}

#endif	// !NCURSES_HH_
