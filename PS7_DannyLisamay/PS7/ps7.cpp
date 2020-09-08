//
//  ps7.cpp
//  ps7
//
//  Created by Dheera Vuppala on 11/30/19.
//  Copyright © 2019 Dheera Vuppala. All rights reserved.
//
#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;
using namespace std;

int main(int argc, const char* argv[]) {
    
    string name(argv[1]);
    string outputName = name + "intouch.log.rpt";
    string output="";
    string begin;
    string end;
    int lines = 1;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    ptime b;
    ptime e;
    date date1;
    date date2;
    time_duration time;
    string start = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    start += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log.c.166\\) ";
    start += "server started";
    string finalString = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    finalString += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";
    finalString += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";
    boost::regex sRegex(start, boost::regex::perl);
    boost::regex eRegex(finalString);
    boost::smatch match;
    string line;
    string total;
    ifstream file;
    //ifstream file(name.c_str());
    //ofstream file; 
    file.open(name.c_str());
    bool s = false;
    if (file.is_open()) {
        while (getline(file, line)) {
            begin.clear();
            end.clear();
            if (boost::regex_search(line, match, sRegex)) {
                   begin = match[1] + "-" + match[2] + "-" + match[3];
                begin += " " + match[4] + ":" + match[5] + ":" + match[6];
                   total = match[1] + "-" + match[2] + "-" + match[3];
                   date1 = date(from_simple_string(total));
                   hours = stoi(match[4]);
                   minutes = stoi(match[5]);
                   seconds = stoi(match[6]);
                   b = ptime(date1, time_duration(hours, minutes, seconds));
                   if (s == true) {
                     output += "**** Incomplete Boot **** \n\n"; //followed wording from example output file!
                   }
                   // Now we want to add this to the output string as boot start.
                   output += "=== Device boot ===\n";
                   output += to_string(lines) + "(" + name + "): ";
                   output += begin + " Boot Start\n";
                   s = true;
                 }
            
            if (boost::regex_match(line, match, eRegex)) {
             end = match[1] + "-" + match[2] + "-" + match[3];
             end += " " + match[4] + ":" + match[5] + ":" + match[6];
             total = match[1] + "-" + match[2] + "-" + match[3];
             date2 = date(from_simple_string(total));
             hours = stoi(match[4]);
             minutes = stoi(match[5]);
            seconds = stoi(match[6]);
             e = ptime(date2, time_duration(hours, minutes, seconds));
             output += to_string(lines) + "(" + name + "): ";
             output += end + " Boot Completed\n";
             time = e - b;
             output += "\tElapsed Time: ";
             output += to_string(time.total_milliseconds()) + "ms \n\n";
             s = false;
            }
            lines++;
        }
        file.close();
    }
     ofstream write(outputName.c_str());
     write << output;
    // done.close();
    
}
