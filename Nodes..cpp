#include <iostream>
#include <Aria.h>

#include "Nodes.h"



Nodes::Nodes() : ArAction("Node Score")
{

}
ArActionDesired * Nodes::fire(ArActionDesired d)
{
	desiredState.reset();





	return &desiredState;
}