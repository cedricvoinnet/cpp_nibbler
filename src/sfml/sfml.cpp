//
// sfml.cpp for nibbler in /home/verove_j/rendu/cpp_nibbler/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Thu Mar 26 09:31:58 2015 Jordan Verove
// Last update Fri Mar 27 14:43:34 2015 Jordan Verove
//

#include <SFML/Window.hpp>
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

void		Sfml::display()
{
  
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
          return (QUIT);
	case sf::Event::KeyPressed:
	  switch(event.Key.Code)
            {
	    case sf::Key::Escape:
	      std::cout << "echape" <<std::endl;
              window.Close();
              return (QUIT);
	    case sf::Key::Left:
	      std::cout << "Left" << std::endl;
	      return (LEFT);
	    case sf::Key::Right:
	      std::cout << "Right" <<std::endl;
	      return (RIGHT);
	    default:
	      return (NONE);
	    }
	default:
	  return (NONE);
        }
    }
  return (NONE);
}
/*
int		main()
{
  Sfml		new_sfml;

  new_sfml.getEvent();
}
*/
