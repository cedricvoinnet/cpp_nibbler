#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <vector>
# include <utility>
# include "IGraphic.hh"

typedef enum	e_direction
  {
    NORTH,
    EAST,
    SOUTH,
    WEST
  }		t_direction;

class					Snake
{
 private:
  std::vector<std::pair<int ,int> >	_body;
  t_direction				_dir;
 public:
  Snake(int, int);
  ~Snake() {};
 public:
  t_direction				getDirection() const;
  std::vector<std::pair<int, int> >	getBody() const;
public:
  void					goForward();
  void					chDir(t_move const &);
};

#endif	// !SNAKE_HH_
