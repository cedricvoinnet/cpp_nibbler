#include "Snake.hh"

Snake::Snake(int x, int y)
{
  _body.push_back(std::make_pair(x / 2, y / 2 - 2));
  _body.push_back(std::make_pair(x / 2, y / 2 - 1));
  _body.push_back(std::make_pair(x / 2, y / 2));
  _body.push_back(std::make_pair(x / 2, y / 2 + 1));
  _dir = UP;
}
