enum score
{
	

};

class Nodes :public ArAction
{
public:

	Nodes();
	~Nodes() {};
	virtual ArActionDesired * fire(ArActionDesired d);
	ArActionDesired desiredState;

protected:



};
