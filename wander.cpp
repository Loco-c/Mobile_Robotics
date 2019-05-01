

#include <iostream>
#include <Aria.h>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <vector>

// header files include
#include "wander.h"

//using std::ofstream;
//using std::ifstream;
using std::cin;
// Constructor
wander::wander() : ArAction("FSM")
{
	speed = 200; // set the speed to 0,5mm
	srands = 0; // random function 
	state = Forward;//
	counter = 0;
	Points = 1;

	/*
	// File write  and reads for Current Position 
	Writer_C.open("wander_Cpos.csv");
	Writer_C << "Current Pos X, Current Pos Y" << "\n";
	Reader_C.open("wander_Cpos.csv");
	Reader_C >> Pos_X >>Pos_Y; 

	// File write and read for Previous Position
	Writer_P.open("wander_pre_pos.csv");
	Writer_P << "Previous X, Previous Y" << "\n";
	Reader_P.open("wander_pre_pos.csv");
	Reader_P >> Pos_X >> Pos_Y;
	*/

}

// Body of action
ArActionDesired * wander::fire(ArActionDesired d)
{
	desiredState.reset(); // reset the desired state (must be done)
	// setting previous position to my currebt position 
	/*
	Pos_X = 0.0;
	Pos_Y = 0.0;

	
	previousposition = currentposition; // 
	//if (currentposition <= previousposition) { state = changePos; } //  telling robot to keep moving 
	
	if (Writer_C.is_open()) { //

		Writer_C << Pos_X << "," << Pos_Y << "\n";// writes both values of PosX and posY 
		std::cout << "Current PosX:   " << Pos_X  << "Current PosY:  "  << Pos_Y << std::endl;
	}
	else {
		std::cout << "Fail to load file!\n" << std::endl;
	}
	////

	if (Writer_P.is_open()) { //

		Writer_P << Pos_X << "," << Pos_Y << "\n";// writes both values of PosX and posY 
		std::cout << "Previous PosX:   " << Pos_X  << "Previous PosY:  " << Pos_Y << std:: endl;
	}
	else  {
		std::cout << "Fail to load file!\n" << std::endl;
	}
	*/
	//currentposition = (myRobot->getX(), myRobot->getY());  // getting robot current pos
	// setting previous position to my currebt position 	

	// Get sonar readings
	
	
	//currentposition = myRobot->getX(),myRobot->getY();
	//previousposition = currentposition;

	if (counter == 0) { // If the counter has finished counting down to 0
		state = static_cast<Estate>(rand() % 3); //Set the state to a random state from 0 - 3| static cast turns the random int into the ENUM [Estate] so that state can be set to the new state
		counter = rand() % 69 + 50; // Set the timer to a random number 50 - 120
	}
	
	// Implementing wander Function
	
	
	//if (previousposition <= currentposition){state = Forward;} 

	/*
	for (int i = 1; i > Points; i++) 
	{
		std::cout << "" << std::endl;
		return ;

	}
	*/
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
		--counter; //for counter function uses-=1

	std::cout << "  Wander State:  " << state << "  Timer: " << counter << std::endl;
	desiredState.setDeltaHeading(deltaHeading);
	desiredState.setVel(speed);
	return &desiredState; // give the desired state to the robot for actioning
}

