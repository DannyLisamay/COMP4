//
//  ps6Aiport
//  AirportServer.h
//
//  Created by Dheera Vuppala and Danny Lisamay on 11/30/19.
//  Copyright © 2019 Dheera Vuppala. All rights reserved.
//
/**
*  AirportServer.h
*  This class defines the methods called by the Airplanes
*/

#ifndef AIRPORT_SERVER_H
#define AIRPORT_SERVER_H

#include <mutex>
#include <condition_variable>
#include <random>

#include "AirportRunways.h"



class AirportServer {
 public:
	/**
	*  Default constructor for AirportServer class
	*/
AirportServer() {
// ***** Initialize any Locks and/or Condition Variables
// here as necessary *****
}  // end AirportServer default constructor


	  /**
	  *  Called by an Airplane when it wishes to land on a runway
	  */
void reserveRunway(int airplaneNum, AirportRunways::RunwayNumber runway);

	/**
	*  Called by an Airplane when it is finished landing
	*/
void releaseRunway(int airplaneNum, AirportRunways::RunwayNumber runway);


 private:
enum RunwayNumber { RUNWAY_4L, RUNWAY_4R,
    RUNWAY_9,
    RUNWAY_14,
    RUNWAY_15L, RUNWAY_15R };
// Constants and Random number generator for use in Thread sleep calls
static const int MAX_TAXI_TIME = 10;
    // Maximum time the airplane will occupy
    // the requested runway after landing, in milliseconds
static const int MAX_WAIT_TIME = 100;
    // Maximum time between landings, in milliseconds

	/**
	*  Declarations of mutexes and condition variables
	*/
mutex runwaysMutex;
// Used to enforce mutual exclusion for acquiring & releasing runways
mutex mtxRunway4L, mtxRunway4R, mtxRunway9,
    mtxRunway14, mtxRunway15L, mtxRunway15R;

	/**
	 *  ***** Add declarations of your own Locks and Condition Variables here *****
	 */
condition_variable cvRunwayAvailible, cvMaxAirplanes;
};  // end class AirportServer

#endif
