//
// sfml.hh for nibbler in /home/verove_j/rendu/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Fri Mar 27 10:58:03 2015 Jordan Verove
// Last update Fri Mar 27 16:44:09 2015 Cédric Voinnet
//

#ifndef SFML_HH_
# define SFML_HH_

#include <SFML/Window.hpp>

#include "IGraphic.hh"

class	Sfml : public IGraphic
{

private:
  int		_x;
  int		_y;
  sf::Window	window;

public:
  Sfml(int x, int y);
  ~Sfml();
  t_move	getEvent();
  void		display();
  
};

extern "C"
{
  IGraphic *create(int, int);
  void	destroy(IGraphic *);
}

#endif /* SFML_HH_ */
