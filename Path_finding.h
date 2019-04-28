#pragma once
enum Pathfinding
{
	PathSearch

};

class Path_finding :public ArAction
{
public:

	Path_finding();
	~Path_finding() {}; 
	virtual ArActionDesired * fire(ArActionDesired d);
	ArActionDesired desiredState;

protected:



};