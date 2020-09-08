/**********************************************************************
 *  ps2-readme                                                  
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Danny Lisamay

Hours to complete assignment: 9 - 10 hrs

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
Recursive Graphics (Pythagoras Tree) created PTree.cpp, PTree.hpp and 
makefile. The assignment was to take in 2 command line arguments. L (the 
size of the base square) and N (Depth of recursion). Using the inputed 
arguments the program will out put a Pythagroas tree on a window. 

(Extra Credit: Takes color agrument for extra credit)
 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Used Recursive function called pTree in the PTree class. The funtion took 
3 arguments sfml window, parent square, and the depth. Using these arguments and 
using sfml draw class the program drew the parent square in the bottom 
center of window. Next using the last square, the "parent" found the inteded 
"Transformation point" then starting with the left children i rotated -45 degrees.
Each child was sqrt(2)/2 smaller than last.(45 -45 -90 triangle formula)
Then recursivly drew left children to inteded depth. Similarly found intended
right position and rotated 45 degrees and drew to intended depth.

(Extra Credit: changed size of each child)
(Extra Credit: changed size and roation to accomadate for 30-60-90 triangle)
/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
 Took in two agrument L and N created PTree object using arguments.   
    int L = stoi(argv[1]);
    int N = stoi(argv[2]);
    int windowLength = 6 * L;
    int windowHeight = 4 * L;
    PTree ptree(L, N);

Created base square set postion to bottom middle of window and called recursive function
    sf::RectangleShape baseSquare(sf::Vector2f(L, L));
    baseSquare.setPosition(L *2.5, L *4)
    // Recusivly draw tree
    ptree.pTree(window, baseSquare, N, color);

Used formula of 45-45-90 triangle 
    float sizeFormula = sqrt(2.f) / 2; // new square size will be sqrt(2)/2

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
 I learned more about SFML API, maily Drawable, color, and window.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Conversed with classmates to brain storm ideas. Help with finding position.


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
 Finding position to rotate children. Brain storming with classmates helped.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 Extra credit: added color to tree. Set original fill color to rgb(0,0,50). 
 incremented by r +50, g +20, and b +5. 

 Extra credit: Implemented tree with different angles. Implemented using 
 30 - 60 - 90 triangle. Left child was rotated 30 degrees and size formula 
 is side * sqrt(3) / 2. Right child was rotated 60 degrees and size formula 
 is side * 1/2. Changed size of window to fit.
