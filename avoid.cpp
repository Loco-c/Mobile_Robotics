#include <iostream>
#include <stdlib.h>
#include <Aria.h>

#include "avoid.h"
// Implementation

// Constructor
avoid::avoid() : ArAction("avoidance")
{
	speed = 200;// Set the robots speed to 50 mm/s. 200 is top speed  
	state = detect; //  setting the intail state
	range = 400; // setting distance for robot to avoid 600
	walls = false; // setting walls to false
	
}

// Body of action
ArActionDesired * avoid::fire(ArActionDesired d)// removed most of code

{
	desiredState.reset(); // reset the desired state (must be done)
	
	 // Get sonar readings from any Sonar active or closest within -50, 50 degrees
	
	
	frontSonar = myRobot->getClosestSonarRange(-50, 50); // using front sensor
	rearSonar= myRobot->getClosestSonarRange(130, -130);  // using rear sensor
	leftSonar = myRobot->getClosestSonarRange(20, -100);  // using left sensor
	rightSonar = myRobot->getClosestSonarRange (- 20, 100);  // using right sensor
	
	
	//detect object in range -done

	//decide which way to turn from object - done
	//if no objects in range state = detect - done

		// Implementing avoid Function 
	switch (state)
	{
	case detect :
		if (frontSonar >= range) { walls = true; } // stating that if range is equal to 500m then return walls as true
		
		if (walls)
		{
			if (frontSonar >= range) { state = front; }


			else if (leftSonar >= range)
			{
				state = right;   //else if the state equals right then set deltaHeading to -1(left) 
			}
		

		else if (rightSonar >= range)
			{
				state = left;   // if state equals left then set deltaheading 1 (right)
			}
			

			else if (rearSonar >= range)
			{
				state = Rear;
			}
			else{state = detect;}
			
			
		}else if (!walls) { state = detect; deltaHeading = 0; } // no walls found.
		break;

	case right:
		deltaHeading = 5; // Set Delta Headiing to Right  
		speed = 0;
		if (leftSonar >= range)
		{ 
			state = detect;
			deltaHeading = 0;
			speed = 200;
		}
		break;
	case left:
		deltaHeading = -5; // Set Delta heading to Left
		speed = 0;
		if (rightSonar >= range)
		{ 
			state = detect;
			deltaHeading = 0;
			speed = 200;
		 
		}
		break;
	case front:
		deltaHeading = 5; // Set Delta heading to front
		speed = 0;
		if (frontSonar >= range)
		{
			state = detect;
			deltaHeading = 0;
			speed = 200;

		}
		break;

	case Rear:
		
		deltaHeading = 0; // set to robot to go forward if rear sonar detects any thing  
		speed = 200;
		
		if (!walls)
		{
			state = detect;
			deltaHeading = 0;
			speed = 200;

		}
		break;

	}

	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // Set the heading change of the robot


	std::cout << " frontSonar: " << frontSonar << " leftSonar: " << leftSonar << " RightSonar: " << rightSonar << " rearSonar: " <<rearSonar << std::endl;
	return &desiredState; // give the desired state to the robot for actioning

	}