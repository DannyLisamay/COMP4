/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/


Name:  Danny Lisamay
Partner: Dheera Vuppala




Hours to complete assignment: 6-7 hours 




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes! We completed the entire assignment. Our source code (ps7.cpp) passed cpp style checks, and we used BOOST date and time methods, as well as regular expressions. We know that they are working because we can open the output (.rpt) files and see the elapsed time in seconds between boost start and boost complete. 








/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/


We created two regex’s: one to detect the boot statement, and then the other to find boot statements that had successful boots. 


The first regex is as follows: 


string start = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
start += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log.c.166\\) ";
start += "server started";


This means that we looked in the input files to match the line number followed by the first logging message “(log.c.166) server started” which we know appears everytime the InTouch device boots up. 


The 2nd regex is as follows: 


string finalString = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    finalString += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";
    finalString += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";


This regex looks to match the line number followed by evidence that it was a successful boot. From the PS7 project description, we know that a successful boot can be seen via the log entry by the statement “oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080”, so our regex looks for that exact statement. 










/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/


I broke this problem into different parts. The first part required that we use the regex to find the line for starting boot and completion of boot. From those lines we get the date and time. Then from there we use the BOOST date and time functions to calculate the elapsed time. We can add that to the “output string”. We repeat this process for each time the inTouch device boots up and finishes. Each time we wrote the elapsed time to the output string, and finally at the end, we wrote the output string to another file)intouch device#.log.rpt) so that it’s easier to view. 


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/


We worked as partners + used stack overflow / BOOST library functions to understand how to use BOOST time and date functions. 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The biggest problem we had was formatting the output. The Assignment said the output should look like the following: 
each startup  whether it completed • if so, how much time it required  whether it failed


But the example ouput log seemed to have other details, so I wasn’t sure exactly how to format the ouput with spaces, although all the required parts exist. 




/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/