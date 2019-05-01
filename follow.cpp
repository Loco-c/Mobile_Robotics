#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include "follow.h"
// Implementation

// Constructor
follow::follow() : ArAction("Follow Edge")
{
	speed = 200; // Set the robots speed to 50 mm/s. 200 is top speed
	deltaHeading = 0; // Straight line

	setPoint = 400; // 0.5 m was 500
	
					// Proportional control
	pGain = 0.01; //Changed from 0 to 0.01
	pre_error = 0.00; // previous error 
	DGain = 0.01; // Derivative Proportinal 
	Maxout = 0.00; // max output 
	
	
	walls = false; // setting walls to false 
	range = 400; // setting distance to 400m
	state = View_walls;
}

// Body of action
ArActionDesired * follow::fire(ArActionDesired d)
{
	desiredState.reset(); // reset the desired state (must be done)

						  // Get sonar readings
	frontSonar = myRobot->getClosestSonarRange(-50, 50); // using front sensor
	rearSonar = myRobot->getClosestSonarRange(130, -130);  // using rear sensor
	leftSonar = myRobot->getClosestSonarRange(20, -100);// 20 t0 40
	rightSonar = myRobot->getClosestSonarRange(-20, 100); // -20 to -40


	// Find error
	//200 = 700 - 500
	error = rightSonar - leftSonar - rearSonar - frontSonar - setPoint;
	/*
	error = leftSonar - setPoint;
	error = rearSonar - setPoint;
	error = frontSonar - setPoint;
	*/
// Calculate proportional output
	output = pGain * error;
	if (output < 0) {
		if (output < -Maxout) {
			std::cout << "Output:  " << output <<std::endl;
		}
	}

// Calcalute Derivative
	pre_error = error;
	output = DGain * error - pre_error;
	if (output < 0) {
		if (output < -Maxout) {
			std::cout << "Output:  " << output << std::endl;
		}
	}

	
	
	// Implement control action
	deltaHeading = output;

	std:: cout << " LeftSonar: " << leftSonar << " RighSonar: " << rightSonar << " frontSonar: " << frontSonar  << " rearSonar: "<< rearSonar << " error: " << error << " output:  " << output << " Previous Error :"<< pre_error << std:: endl;


	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // Set the heading change of the robot

	return &desiredState; // give the desired state to the robot for actioning
}


