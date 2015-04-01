#include <string>

#ifndef ERROR_HH_
# define ERROR_HH_

class			Error : public std::exception
{
public:
  Error(std::string const &, std::string const & = "Error");
  ~Error() throw();
  const char		*errorName() const throw();
  virtual const char	*what() const throw();
private:
  std::string		_message;
  std::string		_name;
};

class	LoadError : public Error
{
public:
  LoadError(std::string const &message, std::string const &name = "LoadError");
};

class	ArgError : public Error
{
public:
  ArgError(std::string const &message, std::string const &name = "ArgError");
};

class	GameError : public Error
{
public:
  GameError(std::string const &message, std::string const &name = "GameError");
};
#endif // !ERROR_HH_
