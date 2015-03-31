//
// sfml.cpp for nibbler in /home/verove_j/rendu/cpp_nibbler/cpp_nibbler
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Thu Mar 26 09:31:58 2015 Jordan Verove
// Last update Tue Mar 31 14:08:37 2015 Jordan Verove
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

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
  sf::Shape	Background;
  sf::Shape	perso;
  int		x_resize;
  int		y_resize;
  unsigned int		i = 0;

  (void) food;
  (void) snake;

  x_resize = 800 / _x;
  y_resize = 600 / _y;
  (void) x_resize;
  (void) y_resize;
  if (!Image.LoadFromFile("snake.png"))
    {
      std::cout<< "error on img file" << std::endl;
    }
  else
    Sprite.SetImage(Image);
  Background.AddPoint(0, 0, sf::Color(255, 255, 255));
  Background.AddPoint(800, 0, sf::Color(255, 255, 255));
  Background.AddPoint(800, 600, sf::Color(255, 255, 255));
  Background.AddPoint(0, 800, sf::Color(255, 255, 255));
  Background.EnableFill(true);
  window.Clear();
  window.Draw(Background);
  Sprite.Scale(x_resize, y_resize);
  Sprite.SetPosition(800 / (_x / snake[i].first), (600 / (_y / snake[i].second)));
  window.Draw(Sprite);
  /*  while (i < snake.size())
    {
      Sprite.Scale(x_resize, y_resize);
      Sprite.SetPosition(800 / (_x / snake[i].first), (600 / (_y / snake[i].second)));
      window.Draw(Sprite);
      //      window.Display();
      i = i + 1;
      }*/
  /*  while (i < snake.size())
    {
      perso.AddPoint((800 / (_x / snake[i].first)), 
    }*/
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
