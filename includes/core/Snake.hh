#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <vector>
# include <utility>

typedef enum	e_direction
  {
    UP,
    LEFT,
    DOWN,
    RIGHT
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
};

#endif	// !SNAKE_HH_
