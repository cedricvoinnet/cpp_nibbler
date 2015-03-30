#include <algorithm>
#include <iostream>
#include "Snake.hh"

Snake::Snake(int x, int y)
{
  _body.push_back(std::make_pair(x / 2, y / 2 - 2));
  _body.push_back(std::make_pair(x / 2, y / 2 - 1));
  _body.push_back(std::make_pair(x / 2, y / 2));
  _body.push_back(std::make_pair(x / 2, y / 2 + 1));
  _dir = NORTH;
}

t_direction	Snake::getDirection() const
{
  return (_dir);
}

std::vector<std::pair<int, int> >	Snake::getBody() const
{
  return (_body);
}

void			Snake::goForward()
{
  std::pair<int, int>	tmp = _body[0];

  std::rotate(_body.rbegin(), _body.rbegin() + 1, _body.rend());
  _body[0] = tmp;
  switch (_dir)
    {
    case NORTH:
      _body[0].second -= 1;
      break;
    case EAST:
      _body[0].first += 1;
      break;
    case SOUTH:
      _body[0].second += 1;
      break;
    case WEST:
      _body[0].first -= 1;
      break;
    }
  int i = 0;
  for (std::vector<std::pair<int, int> >::iterator it = _body.begin(); it != _body.end(); it++, i++)
    std::cout << i << ": " << it->first << ", " << it->second << std::endl;
  std::cout << "--------------------" << std::endl;
}

void	Snake::chDir(t_move const &turn)
{
  if (turn == LEFT)
    _dir = static_cast<t_direction>((_dir + 3) % 4);
  else
    _dir = static_cast<t_direction>((_dir + 1) % 4);
}

void						Snake::grow()
{
  int						beforeLastX;
  int						beforeLastY;
  std::vector<std::pair<int, int> >::iterator	tail = _body.end() - 2;

  beforeLastX = tail->first;
  beforeLastY = tail->second;
  ++tail;
  if (tail->first - beforeLastX != 0)
    _body.push_back(std::make_pair(tail->first + (tail->first - beforeLastX), tail->second));
  else if (tail->second - beforeLastY != 0)
    _body.push_back(std::make_pair(tail->first, tail->second + (tail->second - beforeLastY)));
}
