#include <iostream>
#include <thread>
#include <condition_variable>

#include "AirportServer.h"


/**
*  Called by an Airplane when it wishes to land on a runway
*/
void AirportServer::reserveRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	// Acquire runway(s)
	{  // Begin critical region
unique_lock<mutex> runwaysLock(runwaysMutex);

{
lock_guard<mutex> lk(AirportRunways::checkMutex);

cout << "Airplane #" << airplaneNum << " is acquiring any needed runway(s) for landing on Runway "
<< AirportRunways::runwayName(runway) << endl;
}

		/**
		 *  ***** Add your synchronization here! *****
		 */
		cvMaxAirplanes.wait(runwaysLock,[]() {return
             AirportRunways::getNumLandingRequests() < 6 ; });

		AirportRunways::incNumLandingRequests();
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

			case AirportRunways::RUNWAY_9:
				cvRunwayAvailible.wait(runwaysLock, [runway]{return ( AirportRunways::runwayInUse[runway] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_9] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_4R] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_15R] !=  1);});
				//mtxRunway9.lock();
				//mtxRunway4R.try_lock();
				//mtxRunway15R.try_lock();
				break;

			case AirportRunways::RUNWAY_14:
				cvRunwayAvailible.wait(runwaysLock, [runway]{return ( AirportRunways::runwayInUse[runway] !=  1);});
				//mtxRunway14.lock();
				break;

			case AirportRunways::RUNWAY_15L:
				cvRunwayAvailible.wait(runwaysLock, [runway]{return ( AirportRunways::runwayInUse[runway] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_4L] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_4R] !=  1);});
				//mtxRunway15L.lock();
				//mtxRunway4L.try_lock();
				//mtxRunway4R.try_lock();
				break;

			case AirportRunways::RUNWAY_15R:
				cvRunwayAvailible.wait(runwaysLock, [runway]{return ( AirportRunways::runwayInUse[runway] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_4L] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_4R] !=  1);});
				cvRunwayAvailible.wait(runwaysLock, []{return( AirportRunways::runwayInUse[RUNWAY_9] !=  1);});
				//mtxRunway15R.lock();
				//mtxRunway4L.try_lock();
				//mtxRunway4R.try_lock();
				//mtxRunway9.try_lock();
				break;
		}

		// Check status of the airport for any rule violations
		AirportRunways::checkAirportStatus(runway);

		//runwaysLock.unlock();
	} // End critical region

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Taxi for a random number of milliseconds
	std::uniform_int_distribution<int> taxiTimeDistribution(1, MAX_TAXI_TIME);
	int taxiTime = taxiTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is taxiing on Runway " << AirportRunways::runwayName(runway)
			 << " for " << taxiTime << " milliseconds\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(taxiTime));

} // end AirportServer::reserveRunway()


 /**
  *  Called by an Airplane when it is finished landing
  */
void AirportServer::releaseRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	// Release the landing runway and any other needed runways
	{ // Begin critical region

		unique_lock<mutex> runwaysLock(runwaysMutex);

		{
			lock_guard<mutex> lk(AirportRunways::checkMutex);

			cout << "Airplane #" << airplaneNum << " is releasing any needed runway(s) after landing on Runway "
				 << AirportRunways::runwayName(runway) << endl;
		}

		/**
		*  ***** Add your synchronization here! *****
		*/
			AirportRunways::decNumLandingRequests();

			switch(runway){
			case AirportRunways::RUNWAY_4L:
				//mtxRunway4L.unlock();
				//mtxRunway15L.unlock();
				//mtxRunway15R.unlock();
				cvRunwayAvailible.notify_one();
				break;

			case AirportRunways::RUNWAY_4R:
				//mtxRunway4R.unlock();
				//mtxRunway9.unlock();
				//mtxRunway15L.unlock();
				//mtxRunway15R.unlock();
				cvRunwayAvailible.notify_one();
				break;

			case AirportRunways::RUNWAY_9:
				//mtxRunway9.unlock();
				//mtxRunway4R.unlock();
				//mtxRunway15R.unlock();
				cvRunwayAvailible.notify_one();
				break;

			case AirportRunways::RUNWAY_14:
				//mtxRunway14.unlock();
				cvRunwayAvailible.notify_one();
				break;

			case AirportRunways::RUNWAY_15L:
				//mtxRunway15L.unlock();
				//mtxRunway4L.unlock();
				//mtxRunway4R.unlock();
				cvRunwayAvailible.notify_one();
				break;

			case AirportRunways::RUNWAY_15R:
				//mtxRunway15R.unlock();
				//mtxRunway4L.unlock();
				//mtxRunway4R.unlock();
				//mtxRunway9.unlock();
				cvRunwayAvailible.notify_one();
				break;
		}

		// Update the status of the airport to indicate that the landing is complete
		AirportRunways::finishedWithRunway(runway);

		runwaysLock.unlock();

	} // End critical region

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Wait for a random number of milliseconds before requesting the next landing for this Airplane
	std::uniform_int_distribution<int> waitTimeDistribution(1, MAX_WAIT_TIME);
	int waitTime = waitTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is waiting for " << waitTime << " milliseconds before landing again\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

} // end AirportServer::releaseRunway()
