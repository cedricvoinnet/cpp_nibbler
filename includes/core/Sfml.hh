//
// sfml.hh for nibbler in /home/verove_j/rendu/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Fri Mar 27 10:58:03 2015 Jordan Verove
// Last update Fri Mar 27 14:37:30 2015 Jordan Verove
//

#ifndef SFML_HH_
# define SFML_HH_

#include "IGraphic.hh"

class	Sfml
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

#endif /* SFML_HH_ */
