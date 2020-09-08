/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt template
 **********************************************************************/

Name: Danny Lisamay and Dheera Vuppala
Hours to complete assignment: 10 hrs

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assigments we used out PS3a and implented physical simulation and 
animations. The program took in two time parameters, time and delta time and read a textfile(universe). 

The three functions that were importants for the physics aspect were 
Calculating the radius. r = sqrt(dx^2 + dy^2)
Calculating the pairwise force. F = G*m1*m2/r^2
Calculating the Force for XY. Fx = F*dx/r, Fy = F*dy/r
Calculating the Velocity vel += (dT/vel)
Calculating the new Position pos += (dT/pos)

Step method, that tied them all together.
  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
OO - In order for this to run, we needed essintial functionality from the class done in PS3a and its draw function.

Vector used to hold body objects.

All of the physics class funtions, we importnat listed above.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
Created all physics funtions. (Given in assigment,)
Examples below; 

double NBody::CalcRadius(NBody& nBody){
    return sqrt((pow((xPos - nBody.GetXPos()),2) + pow((yPos - nBody.GetYPos()),2)));
}

//Forces
double NBody::CalcPairwiseForce(NBody& nBody, double radius){
    double force = G* nBody.GetMass() * mass;
    return force/pow(radius,2);
}


double NBody::CalcForceXY(double delta, double radius, double pwForce){
    return pwForce*delta/radius;
}

Did not use smart pointers.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Dheera Vuppala and I worked together.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Displaying orbit counter clockwise.
Physics.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Extra Credit - Displays Elasped Time
Extra Credit - Plays music file
Extra Credit - Created new universe. 3 Ninja Squirells racing to get corn first. Named: MyUniverse.txt
