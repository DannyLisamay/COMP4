//
//  ps6Aiport
//  Airport.cpp
//
//  Created by Dheera Vuppala and Danny Lisamay on 11/30/19.
//  Copyright © 2019 Dheera Vuppala. All rights reserved.
//
/**
*  Airport driver program
*/

#include <iostream>
#include <thread>
#include <vector>

#include "AirportServer.h"
#include "AirportRunways.h"
#include "Airplane.h"

// using namespace std;


/*void run(Airplane* ap)
{
	ap->land();

} // end run
*/

int main(void) {
AirportServer as;

std::vector<std::thread> apths;  // Airplane threads

// Create and launch the individual Airplane threads
for (int i = 1; i <= AirportRunways::NUM_AIRPLANES; i++) {
Airplane* ap = new Airplane(i, &as);
auto run = [](Airplane*ap){
ap->land();
};

apths.push_back(std::thread(run, ap));
}

// Wait for all Airplane threads to terminate (shouldn't happen!)
for (auto& th : apths) {
th.join();
}

return 0;
}  // end main
