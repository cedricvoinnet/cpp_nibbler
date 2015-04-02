#ifndef XLIB_HH_
# define XLIB_HH_

# include <vector>
# include <utility>
# include <X11/Xlib.h>
# include "IGraphic.hh"

class	Xlib : public IGraphic
{
private:
  int		_windowX;
  int		_windowY;
  int		_squareSize;
  Display	*_display;
  Window	_window;
  GC		_gc;
  XColor	_yellow;
  XColor	_brown;
  XColor        _green;
public:
  Xlib(int x, int y);
  ~Xlib();
public:
  t_move	getEvent();
  void		display(std::vector<std::pair<int, int> >, std::pair<int, int>);
private:
  void		initXlib();
private:
  void		printSnake(std::vector<std::pair<int, int> >) const;
  void		printFood(std::pair<int, int>) const;
};

extern "C"
{
  IGraphic	*create(int , int);
  void		destroy(IGraphic *);
}

#endif	// !XLIB_HH_
