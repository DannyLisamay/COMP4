/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Danny Lisamay
Hours to complete assignment: 3-4 hrs

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment, there is an input text file. In the first line of the
text file there is an iteger value that repesents the number of particals(planets).
In the second line there is number that repesents the radius of the unerverse.
The following lines have 6 values. the xPos, yPos, xVel, yVel, mass, and filename.
Using the given values, this program displays the given particals, in the 
given x and y values. The x and y value had to be adjusted accoring to the
SFML window used. The other 3 valus will be used in part b of this assignment.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
OO created NBody class which parameters were inputed text file values and
reference to SFML window that was being used in main. The class contained 
a draw method that draw given partical in intended position.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
Did not use smart pointers.

took information from inputed text file and scaled accoringly,
then created new NBody object.
Pushed new object into vector. Vector was not used in part a, 
maybe will be used in part b.
for(int i = 0; i< numOfParticals; i++){
        double xPos, yPos, xVel, yVel, mass;
        string filename;
        //xPos scales and sets to center of "Universe"
        cin >> xPos;
        xPos /= 5e+8;
        xPos += radiusOfUniverse/5e+8;
        //yPos scales and sets to center of "Universe"
        cin >> yPos;
        yPos /= 5e+8;
        yPos += radiusOfUniverse/5e+8;
        //xVel scales
        cin >> xVel;
        xVel /= 5e+8;
        //yVel scales
        cin >> yVel;
        yVel /= 5e+8;
        //mass scales
        cin >> mass;
        mass /= 5e+8;
        //filename
        cin >> filename;
        
        //creates new nbody and pushes on to vector
        NBody nbody (xPos, yPos, xVel, yVel, mass, filename, window);
        vecNBody.push_back(nbody);
    }

    Construtor of NBody, called its draw method. Main method created 
    intended window and displayed.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
n/a

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Created background of stars for extra credit