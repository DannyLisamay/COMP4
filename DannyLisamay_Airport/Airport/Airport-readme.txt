/**********************************************************************
 *  Airport-readme template                                                   
 *  Airport Simulation (C++11 Concurrency)                       
 **********************************************************************/

Your name: Danny Lisamay 
Partner: Dheera Vuppala 

Operating system you're using (Linux, OS X, or Windows): Mac OS X

If Windows, which solution?:

Text editor or IDE you're using: Xcode

Hours to complete assignment: 12-14 hrs 

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment, we simulated an airport runway program. In this program, multiple airplanes were sending landing requests at the same time and we had to be able to give each plane a runway to land on (while following the airport runway guidelines...ex runway X can't be used with runway Y) and making sure no airplane crashed. Basically this meant we had to implement concurrency/synchronization, since the landing requests came at the same time. 


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

In this assignment the algorithm to determine when each plane's request was "locked" and then "released" as well as the algorithm created to satisfy the airport runway rules listed in the powerpoint provided were essential. Additionally, the OO design significant to this assignment was already given to us (Airport - was the main driver class, and the AirportServer class was the one that handled the multiple requests). 


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

You can create a thread using a function pointer, function object, or through a lambda function. In the Airport main class, created a thread used a lambda function, as shown below: 

auto run = [](Airplane*ap){
ap->land();
};

apths.push_back(std::thread(run, ap));


Next, for Synchronization, I created a condition variable called cvMaxAirplanes and checks to see if the condition that the Runway was already in use - if it's not the lock is released as long as maxNumLandingRequets <6:

cvMaxAirplanes.wait(runwaysLock,[]() {return
             AirportRunways::getNumLandingRequests() < 6 ; });


Additionally, to make sure the program followed the runway guidelines and rules outlined in the projectPDF, I created a switch statement. 

switch(runway){
			case AirportRunways::RUNWAY_4L:
				cvRunwayAvailible.wait(runwaysLock, [runway]{return( AirportRunways::runwayInUse[runway] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15L] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15R] !=  1);});
				//cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15L] !=  1);});
				//cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15R] !=  1);});
				//mtxRunway4L.lock();
				//mtxRunway15L.try_lock();
				//mtxRunway15R.try_lock();
				break;

			case AirportRunways::RUNWAY_4R:
				cvRunwayAvailible.wait(runwaysLock, [runway]{return ( AirportRunways::runwayInUse[runway] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_9] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15L] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15R] !=  1);});
				//mtxRunway4R.lock();
				//mtxRunway9.try_lock();
				//mtxRunway15L.try_lock();
				//mtxRunway15R.try_lock();
				break;



This continues for all the possible cases, but follows the pattern above! 



 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/

In this assignment, I learned about concurrency in C++. This included synchronization techniques using mutex and condition variables. In layman's terms this means, I learned how to create a program that can receive multiple requests / instructions at the same time, and can execute all without the program crashing. In the case of this assignment, it meant receiving multiple landing requests, and taking care of all the requests (instead of only dealing with one) while making sure the program didn't crash. We dealt with one request at a time and we did this by learning about threads, mutex, and condition variables. 

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

Worked with a partner: Danny Lisamay 
Also watched YouTube videos on how mutex/condition variables work, as well as looking at C++ 11 libraries so we could understand what functions like (conditionvariable.wait() were available for us to use) 

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

The biggest problems we encountered included getting the program to accept up to 6 requests. This was tough because we could get 1 to 2 requests always working, but then realized the reason we were running into this issue was that we weren't incrementing the numRequests properly. While this was a small error, it took a long time to debug. 


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

I'm submitting this as PSX so I also ran the cpplint style check on the three files that I modified (Airport.cpp, AirportServer.h, AirportServer.cpp). The cpplint style check said that the C++11 header thread, mutex, and condition variable was not supported so it gave error for those lines. However, we need those lines for the code to work + those lines were already provided for us (we didn't add those), so I couldn't take them out. For this reason, the cpplint style check fails, but passes all the tab spaces, etc other style checks. 


PSX: I chose to submit PS6 as PSX because the first time around for PS6, while I got the lambda function portion working, the airport was still crashing and wouldn't run for at least 15 minutes. When I tried PS6 the first time, I wasn't using condition variables, resulting in many errors. 
