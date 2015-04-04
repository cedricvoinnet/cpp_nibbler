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
  std::string		lib_name;

  ss << av[1];
  ss >> width;
  if (width < 20 || width > 160)
    throw ArgError("Width must be between 20 and 160");
  ss.clear();
  ss << av[2];
  ss >> height;
  if (height < 20 || height > 45)
    throw ArgError("Height must be between 20 and 45");
  ss.clear();
  ss << "./";
  ss << av[3];
  ss >> lib_name;
  if (!(lib = dlopen(lib_name.c_str(), RTLD_LAZY)))
    throw ArgError("No such file");
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
