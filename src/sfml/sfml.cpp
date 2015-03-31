//
// sfml.cpp for nibbler in /home/verove_j/rendu/cpp_nibbler/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Thu Mar 26 09:31:58 2015 Jordan Verove
// Last update Tue Mar 31 08:34:43 2015 Cédric Voinnet
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Sfml.hh"

Sfml::Sfml(int x, int y):
  _x(x), _y(y)
{ 
  this->window.Create(sf::VideoMode(800, 600), "Nibbler");
}

Sfml::~Sfml()
{
  window.Close();
}

void		Sfml::display(std::vector<std::pair<int, int> > snake, std::pair<int, int> food)
{
  sf::Sprite	Sprite;
  sf::Image	Image;

  (void) food;
  (void) snake;
  if (!Image.LoadFromFile("snake.png"))
    {
      std::cout<< "error on img file" << std::endl;
    }
  else
    Sprite.SetImage(Image);
}

t_move		Sfml::getEvent()
{
  sf::Event	event;
  
  if (window.GetEvent(event))
    {
      switch (event.Type)
	{
	case sf::Event::Closed:
	  window.Close();
	  while (window.GetEvent(event));
	  return (QUIT);
	case sf::Event::KeyPressed:
	  switch(event.Key.Code)
	    {
	    case sf::Key::Escape:
	      std::cout << "echape" <<std::endl;
	      window.Close();
	      while (window.GetEvent(event));
              return (QUIT);
	    case sf::Key::Left:
	      std::cout << "Left" << std::endl;
	      while (window.GetEvent(event));
	      return (LEFT);
	    case sf::Key::Right:
	      std::cout << "Right" <<std::endl;
	      while (window.GetEvent(event));
	      return (RIGHT);
	    default:
	      while (window.GetEvent(event));
	      return (NONE);
	    }
	default:
	  return (NONE);
        }
    }
  return (NONE);
}

IGraphic *create(int xMax, int yMax)
{
  return (new Sfml(xMax, yMax));
}

void	destroy(IGraphic *toDestroy)
{
  delete toDestroy;
}

/*
int		main()
{
  Sfml		new_sfml;

  new_sfml.getEvent();
}
*/
