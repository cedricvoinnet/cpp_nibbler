#include <X11/keysym.h>
#include "Xlib.hh"
#include "Error.hh"

Xlib::Xlib(int x, int y, int windowX, int windowY)
{
  _gameX = x;
  _gameY = y;
  _windowX = windowX;
  _windowY = windowY;
  _squareSize = (_windowX/_gameX > _windowY/_gameY) ? _windowY/_gameY : _windowX/_gameX;
  initXlib();
}

Xlib::~Xlib()
{
  XCloseDisplay(_display);
}

void		Xlib::initXlib()
{
  Colormap	colormap;

  if (!(_display = XOpenDisplay(NULL)))
    throw GameError("Cannot open display");
  int blackColor = BlackPixel(_display, DefaultScreen(_display));
  int whiteColor = WhitePixel(_display, DefaultScreen(_display));
  _window = XCreateSimpleWindow(_display,
				RootWindow(_display, DefaultScreen(_display)),
				0, 0, _windowX, _windowY, 1, blackColor,
				whiteColor);
  XSelectInput(_display, _window, ExposureMask | KeyPressMask |
	       StructureNotifyMask);
  XMapWindow(_display, _window);
  _gc = XCreateGC(_display, _window, 0, NULL);
  colormap = DefaultColormap(_display, DefaultScreen(_display));
  if (!XAllocNamedColor(_display, colormap, "yellow", &_yellow, &_yellow))
    throw GameError("XAllocNamedColor - failed to allocated 'yellow' color.");
  if (!XAllocNamedColor(_display, colormap, "brown", &_brown, &_brown))
    throw GameError("XAllocNamedColor - failed to allocated 'brown' color.");
  if (!XAllocNamedColor(_display, colormap, "green", &_green, &_green))
    throw GameError("XAllocNamedColor - failed to allocated 'green' color.");
}

t_move			Xlib::getEvent()
{
  XEvent		ev;
  KeySym		escape;
  KeySym		left;
  KeySym		right;

  escape = XKeysymToKeycode(_display, XK_Escape);
  left = XKeysymToKeycode(_display, XK_Left);
  right = XKeysymToKeycode(_display, XK_Right);
  if (XPending(_display))
    {
      XNextEvent(_display, &ev);
      if (ev.type == KeyPress)
	{
	  if (ev.xkey.keycode == escape)
	    return (QUIT);
	  else if (ev.xkey.keycode == left)
	    return (LEFT);
	  else if (ev.xkey.keycode == right)
	    return (RIGHT);
	  while (XPending(_display))
	    XNextEvent(_display, &ev);
	}
    }
  return (NONE);
}

void		Xlib::display(std::vector<std::pair<int, int> > snake, std::pair<int, int> food)
{
  printBackground();
  printFood(food);
  printSnake(snake);
  XFlush(_display);
}

void		Xlib::printBackground() const
{
  int		xBegin = (_windowX - _gameX * _squareSize)/2;
  int		yBegin = (_windowY - _gameY * _squareSize)/2;

  XSetForeground(_display, _gc, BlackPixel(_display, DefaultScreen(_display)));  
  XFillRectangle(_display, _window, _gc, xBegin, yBegin, _gameX * _squareSize,
		 _gameY * _squareSize);
}

void			Xlib::printSnake(std::vector<std::pair<int, int> > snake) const
{
  int		xBegin = (_windowX - _gameX * _squareSize)/2;
  int		yBegin = (_windowY - _gameY * _squareSize)/2;
  static std::pair<int, int>			last = std::make_pair(0,0);
  std::vector<std::pair<int, int> >::iterator	it = snake.begin();

  for (;it != snake.end(); ++it)
    {
      if (it == snake.begin())
	XSetForeground(_display, _gc, _brown.pixel);
      else
	XSetForeground(_display, _gc, _green.pixel);
      XFillRectangle(_display, _window, _gc, xBegin + _squareSize * it->first,
		     yBegin + _squareSize * it->second, _squareSize,
		     _squareSize);
      XSetForeground(_display, _gc, _brown.pixel);
      XDrawRectangle(_display, _window, _gc, xBegin + _squareSize * it->first,
		     yBegin + _squareSize * it->second, _squareSize,
		     _squareSize);
    }
  XSetForeground(_display, _gc, BlackPixel(_display, DefaultScreen(_display)));
  XFillRectangle(_display, _window, _gc, xBegin + _squareSize * last.first,
		 yBegin + _squareSize * last.second, _squareSize, _squareSize);
  XDrawRectangle(_display, _window, _gc, xBegin + _squareSize * last.first,
		 yBegin + _squareSize * last.second, _squareSize, _squareSize);
  --it;
  last = std::make_pair(it->first, it->second);
}

void		Xlib::printFood(std::pair<int, int> food) const
{
  int		xBegin = (_windowX - _gameX * _squareSize)/2;
  int		yBegin = (_windowY - _gameY * _squareSize)/2;

  XSetForeground(_display, _gc, _yellow.pixel);
  XFillRectangle(_display, _window, _gc, xBegin + _squareSize * food.first,
		 yBegin + _squareSize * food.second, _squareSize, _squareSize);
}

IGraphic	*create(int xMax, int yMax)
{
  return (new Xlib(xMax, yMax));
}

void		destroy(IGraphic *toDestroy)
{
  delete toDestroy;
}
