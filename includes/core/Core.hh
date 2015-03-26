#ifndef CORE_HH_
# define CORE_HH_

# include <string>
# include "Snake.hh"

class	Core
{
private:
  Snake		_snake;
  unsigned int	_boardWidth;
  unsigned int	_boardHeight;
  void		*_lib;
public:
  Core(int, int, void *);
  ~Core();
public:
  void		gameLoop();
};

#endif	// !CORE_HH_
