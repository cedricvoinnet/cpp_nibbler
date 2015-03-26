#include <iostream>
#include <sstream>
#include <dlfcn.h>
#include "Core.hh"
#include "Error.hh"

Core			*checkArg(char **av)
{
  int			width;
  int			height;
  void			*lib;
  std::stringstream	ss;

  ss << av[1];
  ss >> width;
  if (width < 10 || width > 30)
    throw ArgError("Width must be between 10 and 30");
  ss.clear();
  ss << av[2];
  ss >> height;
  if (height < 10 || height > 45)
    throw ArgError("Height must be between 10 and 45");
  if (!(lib = dlopen(av[3], RTLD_LAZY)))
    throw ArgError("No such library");
  return (new Core(width, height, lib));
}

int	main(int ac, char **av)
{
  Core	*gameCore;

  if (ac != 4)
    {
      std::cout << "Usage: " << av[0] << " [width] [heigth] [dynamic lib]" << std::endl;
      return (-1);
    }
  try {
    gameCore = checkArg(av);
  }
  catch (Error const &error) {
    std::cout << error.errorName() << ": " << error.what() << std::endl;
    return (-1);
  }
  try {
    gameCore->gameLoop();
  }
  catch (Error const &error) {
    std::cout << error.errorName() << ": " << error.what() << std::endl;
  }
  delete gameCore;
  return (0);
}
