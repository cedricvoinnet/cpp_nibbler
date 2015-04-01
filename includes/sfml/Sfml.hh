//
// sfml.hh for nibbler in /home/verove_j/rendu/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Fri Mar 27 10:58:03 2015 Jordan Verove
// Last update Wed Apr  1 16:19:25 2015 Jordan Verove
//

#ifndef SFML_HH_
# define SFML_HH_

#include <SFML/Window.hpp>

#include "IGraphic.hh"

class	Sfml : public IGraphic
{

private:
  int			_x;
  int			_y;
  sf::RenderWindow	window;

public:
  Sfml(int x, int y);
  ~Sfml();
  t_move	getEvent();
  void		display(std::vector<std::pair<int, int> > snake, std::pair<int, int> food);
  void		display_snake(std::pair<int, int> snake, int color, int color2);
};

extern "C"
{
  IGraphic *create(int, int);
  void	destroy(IGraphic *);
}

#endif /* SFML_HH_ */
