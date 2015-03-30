#include <algorithm>
#include <iostream>
#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Error.hh"
#include "IGraphic.hh"
#include "Core.hh"

Core::Core(int width, int height, void *lib)
  : _snake(Snake(width, height)),
    _boardWidth(width - 1),
    _boardHeight(height - 1),
    _lib(lib)
{
  srand(time(NULL));
  spawnFood();
}

Core::~Core()
{
  dlclose(_lib);
}

bool					Core::isAlive()
{
  std::vector<std::pair<int, int> >	snakeBody = _snake.getBody();

  if (std::find(snakeBody.begin() + 1, snakeBody.end(), snakeBody[0]) != snakeBody.end())
    return (false);
  return (snakeBody[0].first > 0 && snakeBody[0].first <= _boardWidth &&
	  snakeBody[0].second > 0 && snakeBody[0].second <= _boardHeight);
}

void					Core::spawnFood()
{
  std::vector<std::pair<int, int> >	snakeBody = _snake.getBody();

  _food = std::make_pair(rand() % _boardWidth, rand() % _boardHeight);
  while (std::find(snakeBody.begin(), snakeBody.end(), _food) != snakeBody.end())
    _food = std::make_pair(rand() % _boardWidth, rand() % _boardHeight);
}

void	Core::eatFood()
{
  std::vector<std::pair<int, int> >	snakeBody = _snake.getBody();

  if (snakeBody[0] == _food)
    {
      _snake.grow();
      spawnFood();
    }
}

void		Core::gameLoop()
{
  graphCreate	gCreate;
  graphDelete	gDelete;
  IGraphic	*graphicDisp;
  t_move	key;

  if (!(gCreate = reinterpret_cast<graphCreate>(dlsym(_lib, "create"))))
    throw LoadError("Cannot load graphic object");
  if (!(gDelete = reinterpret_cast<graphDelete>(dlsym(_lib, "destroy"))))
    throw LoadError("Cannot load graphic object");
  graphicDisp = gCreate(_boardWidth, _boardHeight);
  while (isAlive())
    {
      std::cout << "food: " << _food.first << ", " << _food.second << std::endl;
      graphicDisp->display();
      eatFood();
      if ((key = graphicDisp->getEvent()) == QUIT)
	break;
      if (key != NONE)
      	_snake.chDir(key);
      _snake.goForward();
      usleep(200000);
    }
  gDelete(graphicDisp);
}
