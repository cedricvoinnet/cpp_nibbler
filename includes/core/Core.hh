#ifndef CORE_HH_
# define CORE_HH_

# include <string>
# include "Snake.hh"

class			Core
{
private:
  Snake			_snake;
  int			_boardWidth;
  int			_boardHeight;
  void			*_lib;
  std::pair<int, int>	_food;
public:
  Core(int, int, void *);
  ~Core();
public:
  void			gameLoop();
private:
  bool			isAlive();
  void			spawnFood();
  void			eatFood();
};

#endif	// !CORE_HH_
