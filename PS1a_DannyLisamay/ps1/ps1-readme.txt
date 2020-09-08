/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Danny Lisamay
Hours to complete assignment: 10hr
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
Implemented a LFSR(Linear Feedback Shift Register) which is a register that takes in a linear function of a previous state and performed XOR operation on a choosen "tap" bit and last bit in register. Then the register shifts by one position and the output of the XOR operation is now the first bit in the register.

Ex. 00010001
If the "tap" is at the 1 position, we will XOR the bit to the the furtest position to the right(at the first position) with the bit furthest to the left(at the last position). 1 XOR 0, giving us 1. The regisiter will now shift.
0010001-

Now using the output of the XOR operation will be the first bit.

00100011 


/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
None, will be seeking tutor/TA for next assigment.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Learning C++ syntax. New to C++. Unsure how to use boost unit tests. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
