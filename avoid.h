// Signatures
enum Avoid
{
	detect,
	right,
	left,
	front,
	Rear
	
	
};

class avoid : public ArAction // Class action inherits from ArAction
{
public:
	avoid(); // Constructor
	virtual ~avoid() {}  // Destructor
	virtual ArActionDesired * fire(ArActionDesired d); // Body of the action
	ArActionDesired desiredState; // Holds state of the robot that we wish to action
	Avoid state;
	int speed; // Speed of the robot in mm/s   
	bool walls; // function required for detection purposes 
	double leftSonar;
	double rightSonar;
	double frontSonar;
	double rearSonar;
 
protected:
	double deltaHeading; //set direction of robot
	 int range; // set stopping range of robot before coliding will objects

};
