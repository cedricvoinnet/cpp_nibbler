#include <dlfcn.h>
#include "Core.hh"

Core::Core(int width, int height, void *lib)
  : _snake(Snake(width, height)),
    _boardWidth(width),
    _boardHeight(height),
    _lib(lib)
{
}

Core::~Core()
{
  dlclose(_lib);
}

bool	Core::isAlive()
{
  return (true);
}

void	Core::gameLoop()
{
  while (isAlive())
    {
      _snake.goForward();
    }
}
