//
// sfml.cpp for nibbler in /home/verove_j/rendu/cpp_nibbler/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Thu Mar 26 09:31:58 2015 Jordan Verove
// Last update Sat Apr  4 11:27:20 2015 Jordan Verove
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "Sfml.hh"

Sfml::Sfml(int x, int y)
{ 
  sf::Shape			background;

  this->window.Create(sf::VideoMode(800, 800, 32), "Nibbler");
  this->_x = 800 / x;
  this->_y = 800 / y;
  background.AddPoint(0, 0, sf::Color(0, 0, 0));
  background.AddPoint(800, 0, sf::Color(0, 0, 0));
  background.AddPoint(800, 800, sf::Color(0, 0, 0));
  background.AddPoint(0, 800, sf::Color(0, 0, 0));
  window.Draw(background);
}

Sfml::~Sfml()
{
  window.Close();
}

void		Sfml::display_snake(std::pair<int, int> snake, int color, int color2)
{
  sf::Shape	perso;

  perso.AddPoint(_x * (snake.first), _y * snake.second, sf::Color(color, color2, color));
  perso.AddPoint(_x * (snake.first + 1), _y * snake.second, sf::Color(color, color2, color));
  perso.AddPoint(_x * (snake.first + 1), _y * (snake.second + 1), sf::Color(color, color2, color));
  perso.AddPoint(_x * snake.first, _y * (snake.second + 1), sf::Color(color, color2, color));
  window.Draw(perso);
}

void		Sfml::display_food(std::pair<int, int> food, int color, int color2)
{
  sf::Shape	to_eat;

  to_eat.AddPoint(_x * (food.first), _y * food.second, sf::Color(color, color2, color));
  to_eat.AddPoint(_x * (food.first + 1), _y * food.second, sf::Color(color, color2, color));
  to_eat.AddPoint(_x * (food.first + 1), _y * (food.second + 1), sf::Color(color, color2, color));
  to_eat.AddPoint(_x * food.first, _y * (food.second + 1), sf::Color(color, color2, color));
  window.Draw(to_eat);      
}

void				Sfml::display(std::vector<std::pair<int, int> > snake, std::pair<int, int> food)
{
  unsigned int			i = 0;
  static int			first = 0;
  static std::pair<int, int>	tail;
  
  display_food(food, 255, 255);
  if (first == 0)
    {
      while (i < (snake.size() - 1))
	{
	  display_snake(snake[i], 51, 255);
	  i = i + 1;
	}
      first = 1;
      tail = snake[i - 1];
    }
  else
    {
      display_snake(snake[i], 51, 255);
      display_snake(tail, 0, 0);
      tail = snake[snake.size() - 1];
    }
  window.Display();
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

IGraphic *create(int xMax, int yMax)
{
  return (new Sfml(xMax, yMax));
}

void	destroy(IGraphic *toDestroy)
{
  delete toDestroy;
}
