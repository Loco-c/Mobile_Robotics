#include <iostream>
#include <stdlib.h>
#include <Aria.h>


#include "Path_finding.h"




Path_finding::Path_finding() : ArAction("A* Path finding")
{

}
ArActionDesired * Path_finding::fire(ArActionDesired d)
{
	desiredState.reset();





	return &desiredState;
}