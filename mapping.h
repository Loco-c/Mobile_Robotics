#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

#include <fstream>

using std::ofstream;

class mapping : public ArAction // Class action inherits from ArAction
{
public:
	mapping(); // Constructor
	virtual ~mapping() {}  // Destructor
	virtual ArActionDesired * fire(ArActionDesired d); // Body of the action
	ArActionDesired desiredState; // Holds state of the robot that we wish to action
	
	sf::RenderWindow window;
	sf::RectangleShape robotshape;
	std::vector<sf::CircleShape > scatterpoints;
	double robotR;
	double angle;
	double r;
	double gPosY;
	double gPosX;
	double pos_X;
	double pos_Y;
	double pos_Th;
	double robotY;
	double robotX;
protected:
	ofstream Writer;

};