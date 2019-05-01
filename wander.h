#include <fstream>
#include "mapping.h"
#include <vector>
enum Estate
{
	Forward,
	Right,
	Left,
	changePos
};

using std::ofstream;
using std::ifstream;

class wander : public ArAction // Class action inherits from ArAction
{
public:
		wander(); // Constructor
		virtual ~wander() {}  // Destructor
		virtual ArActionDesired * fire(ArActionDesired d); // Body of the action
		ArActionDesired desiredState; // Holds state of the robot that we wish to action
		int speed; // seting speed for the robot movement 
		Estate state; //state

		int counter; // To counter each case 
	
protected:
	double deltaHeading; // Change in heading
	int srands; // random function for movement
	int Points; // set points 
 

};

