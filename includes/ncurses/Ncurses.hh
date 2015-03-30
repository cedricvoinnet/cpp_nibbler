//
// Ncurses.hh for nibbler in /home/gazzol_j/rendu/cpp_nibbler/includes/ncurses
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Mar 30 10:33:22 2015 julien gazzola
// Last update Mon Mar 30 11:30:03 2015 julien gazzola
//

#ifndef NCURSES_HH_
# define NCURSES_HH_

class	Ncurses : public IGraphic
{
private:
  int		_x;
  int		_y;

public:
  Ncurses(int x, int y);
  ~Ncurses();
  t_move	getEvent();
  void		display();
};

extern "C"
{
  IGraphic	*create(int , int);
  void		destroy(IGraphic *);
}

#endif	// !NCURSES_HH_
