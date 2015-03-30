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
    default:
      break;
    }
  std::cout << "0: " << _body[0].first << ", " << _body[0].second << std::endl;
  std::cout << "1: " << _body[1].first << ", " << _body[1].second << std::endl;
  std::cout << "2: " << _body[2].first << ", " << _body[2].second << std::endl;
  std::cout << "3: " << _body[3].first << ", " << _body[3].second << std::endl;
  std::cout << "--------------------------" << std::endl;
}

void	Snake::chDir(t_move const &turn)
{
  switch (turn)
    {
    case LEFT:
      switch (_dir)
	{
	case NORTH:
	  _dir = WEST;
	  break;
	case EAST:
	  _dir = NORTH;
	  break;
	case SOUTH:
	  _dir = EAST;
	  break;
	case WEST:
	  _dir = SOUTH;
	  break;
	}
      break;
    case RIGHT:
      switch (_dir)
	{
	case NORTH:
	  _dir = EAST;
	  break;
	case EAST:
	  _dir = SOUTH;
	  break;
	case SOUTH:
	  _dir = WEST;
	  break;
	case WEST:
	  _dir = NORTH;
	  break;
	}
      break;
    default:
      break;
    }
}
