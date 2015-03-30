#ifndef IGRAPHIC_HH_
# define IGRAPHIC_HH_

# include <utility>
# include <vector>

typedef enum	e_move{
  LEFT,
  RIGHT,
  QUIT,
  NONE
}		t_move;

class	IGraphic
{
public:
  virtual ~IGraphic() {};
public:
  virtual t_move	getEvent() = 0;
  virtual void		display(std::vector<std::pair<int, int> >, std::pair<int, int>) = 0;
};

typedef IGraphic *(*graphCreate)(int, int);
typedef void (*graphDelete)(IGraphic *);

#endif	// !IGRAPHIC_HH_
