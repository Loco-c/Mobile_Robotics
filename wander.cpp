

#include <iostream>
#include <Aria.h>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <vector>

// header files include
#include "wander.h"

// using std::ofstream;
// using std::ifstream;
using std::cin;
// Constructor
wander::wander() : ArAction("FSM")
{
	speed = 200;	 // set the speed to 0,5mm
	srands = 0;		 // random function
	state = Forward; //
	counter = 0;
	Points = 1;
}

// Body of action
ArActionDesired *wander::fire(ArActionDesired d)
{
	desiredState.reset(); // reset the desired state (must be done)

	if (counter == 0)
	{											 // If the counter has finished counting down to 0
		state = static_cast<Estate>(rand() % 3); // Set the state to a random state from 0 - 3| static cast turns the random int into the ENUM [Estate] so that state can be set to the new state
		counter = rand() % 69 + 50;				 // Set the timer to a random number 50 - 120
	}

	switch (state)
	{
	case Forward:
		deltaHeading = 200; // states speed of robot = 200
		speed = 200;
		break;
	case Right:
		deltaHeading = 1; // right function value 10
		break;
	case Left:
		deltaHeading = -1; // Left function value -10
		break;
	case changePos:
		deltaHeading = 200;

		break;
	}
	--counter; // for counter function uses-=1

	std::cout << "  Wander State:  " << state << "  Timer: " << counter << std::endl;
	desiredState.setDeltaHeading(deltaHeading);
	desiredState.setVel(speed);
	return &desiredState; // give the desired state to the robot for action
}
