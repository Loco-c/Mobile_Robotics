#include <fstream>
#include "mapping.h"
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
  double currentposition; // Position of Robot
  double previousposition; // Previous Position 
protected:
	double deltaHeading; // Change in heading
	int srands; // random function for movement
	/*
	ofstream Writer_C; //  Writes current position of Robot 
	ofstream Writer_P; // Writes previous position of Robot 
	ifstream Reader_C; // Reads current position of Robot 
	ifstream Reader_P; //Reads previous position of  Robot 
	double Pos_X;
	double Pos_Y;
	*/

};

