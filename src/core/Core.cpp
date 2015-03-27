#include <dlfcn.h>
#include "Error.hh"
#include "IGraphic.hh"
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

void		Core::gameLoop()
{
  graphCreate	pMaker;
  IGraphic	*graphicDisp;
  void		*mkr;

  if (!(mkr = dlsym(_lib, "create")))
    throw ArgError("Cannot load graphic object");
  pMaker = (graphCreate)mkr;

  graphicDisp = pMaker(_boardWidth, _boardHeight);

  while (isAlive())
    {
      graphicDisp->getEvent();
      //      _snake.goForward();
    }
}
