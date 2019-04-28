// Signatures
class follow : public ArAction // Class action inherits from ArAction
{
 public:
   follow(); // Constructor
   virtual ~follow() {}  // Destructor
   virtual ArActionDesired * fire(ArActionDesired d); // Body of the action
   ArActionDesired desiredState; // Holds state of the robot that we wish to action
 protected:
   int speed; // Speed of the robot in mm/s
   double deltaHeading; // Change in heading
   // Reading
   double frontSonar; // front sensors
   double rearSonar; // rear sensors 
   double leftSonar; // left sensor
   double rightSonar; // right sensors
   

   // Control variables
   double setPoint; // Set point of the controller
   double error; // Current error
   double output; // Final output signal
   double pGain; //  Proportional Gain
   double pre_error; // previous Gain
   double DGain; //  Derivative Gain;
   double Maxout;// angle
};
