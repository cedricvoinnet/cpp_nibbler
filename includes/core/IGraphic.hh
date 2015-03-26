#ifndef IGRAPHIC_HH_
# define IGRAPHIC_HH_

typedef enum	e_move{
  LEFT,
  RIGHT,
  QUIT,
  NONE
}		t_move;

class	IGraphic
{
private:
  virtual ~IGraphic() {};
public:
  virtual t_move	getEvent() const = 0;
  virtual void		display() = 0;
};

typedef IGraphic *(*graphCreat)();
typedef void (*graphDelete)(IGraphic *);

#endif	// !IGRAPHIC_HH_
