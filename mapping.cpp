#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

#include "mapping.h"

using std::ofstream;


mapping::mapping() : ArAction("avoidance")
{
	window.create(sf::VideoMode(940, 680), "Robot Map!");
	robotshape.setFillColor(sf::Color(255, 0, 0)); // colour of robot 
	robotshape.setSize(sf::Vector2f(250.f, 300.f)); // setting size of robot
	window.setActive(false); // allows window to be written too
	Writer.open("Mapping.csv");
	//Writer.clear(); // for testing purposes
	Writer << "Global X, Global Y"  << "\n";


}
ArActionDesired * mapping::fire(ArActionDesired d)// removed most of code

{
	desiredState.reset(); // reset the desired state (must be done)
	window.setActive(true); // set too display all 
robotshape.setPosition(sf::Vector2f(myRobot->getX(),myRobot->getY())); // robot positions 
	robotshape.setRotation(myRobot->getTh()); // get theta
   
	
	// Implementation	
	robotX = myRobot->getX(); // positions X
	robotY = myRobot->getY(); // positions Y
	pos_Th = myRobot->getTh()*(M_PI/180); // positionstheta 
	pos_X = 0.0; //  position of x 
	pos_Y = 0.0; // position of Y
	gPosX = 0.0; // gobal position of x 
	gPosY = 0.0; // gobal position of Y
 	r = myRobot->getSonarRange(4); // range
	angle = -0.174533; // angle
	robotR = myRobot->getRobotRadius(); // robot radius

	
	//equation
	pos_X = cos(angle) * (r + robotR);
	pos_Y = sin(angle) * (r + robotR);
	gPosX = (pos_X*cos(pos_Th)) + (pos_Y*-sin(pos_Th));
	gPosY = (pos_X*sin(pos_Th)) + (pos_Y*cos(pos_Th));
	gPosX = gPosX + robotX;
	gPosY = gPosY + robotY;
	std::cout <<"GlobalPosX:    "  << gPosX  << "  GlobalPosY:    " <<gPosY << std::endl;
	//Write Robot postion into a file text 
	
	
	if (Writer.is_open()) {

		Writer << gPosX << "," << gPosY << "\n";// writes both values of gPosX and gposY 

	}else{
		std::cout << "Fail to load file!\n" << std::endl;		
	}


	
	//Camera View
	sf::View camera(sf::FloatRect(0, 0, 10000, 10000));// sf::View camera(sf::FloatRect(0, 0, 10000, 10000));
	camera.setCenter(0, 0);
	camera.move(100.f, 100.f);

		int SonarAngle_Array[16] = { 90 , 50 , 30 , 10, -10, -30 , -50 , -90 , -90 ,-130 , -150 , -170 , 170 , 150 , 130, 90 }; // Front & back Sonar angles listed 

		for (int i = 0; i < 16; i++) {
			int SonarReading = myRobot->getSonarRange(i);
			int SonarAngle = SonarAngle_Array[i];
			// add mathes here add points ( x and y pose)


		//	sf::Vector3f xyTheta = sf::Vector3f(myRobot->getX(), myRobot->getY(), myRobot->getTh());
			// return value x, y  to file 
			 // vectors for x and y positon


		}
		// scatter points creator
		sf::CircleShape temp;
		temp.setFillColor(sf::Color(255, 0, 0));// set colour 
		temp.setRadius(50.f); //size of shape   
		temp.setPosition(gPosX, gPosY);
		scatterpoints.push_back(temp);
		
	
		// window close function 
		sf::Event  event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;
			}
		}
		
		robotshape.setPosition(sf::Vector2f(myRobot->getX(),myRobot->getY()));

		// for loop to plot scatter points 
	window.clear();
	
		for (int i = 0; i < scatterpoints.size(); i++) {
			window.draw(scatterpoints.at(i));
		}
		
		
		window.draw(robotshape);
		window.setView(camera);
		window.display();
	

		//Writer.close(); // close files
	return &desiredState; // give the desired state to the robot for actioning

}