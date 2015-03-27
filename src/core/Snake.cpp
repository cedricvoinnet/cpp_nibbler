#include <algorithm>
#include <iostream>
#include "Snake.hh"

Snake::Snake(int x, int y)
{
  _alive = true;
  _body.push_back(std::make_pair(x / 2, y / 2 - 2));
  _body.push_back(std::make_pair(x / 2, y / 2 - 1));
  _body.push_back(std::make_pair(x / 2, y / 2));
  _body.push_back(std::make_pair(x / 2, y / 2 + 1));
  // std::cout << _body[0].first << ", " << _body[0].second << std::endl;
  // std::cout << _body[1].first << ", " << _body[1].second << std::endl;
  // std::cout << _body[2].first << ", " << _body[2].second << std::endl;
  // std::cout << _body[3].first << ", " << _body[3].second << std::endl;
  // std::cout << "--------------------------" << std::endl;
  _dir = NORTH;
}

t_direction	getDirection()
{
  return (_dir);
}

std::vector<std::pair<int, int> >	getBody() const
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
    default:
      break;
    }
}

