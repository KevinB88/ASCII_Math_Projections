#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;


void timer_millis(int time, bool MESSAGE) {
	
	if (MESSAGE) cout << "Timer started for: " << time << " milliseconds.\n"; 

	this_thread::sleep_for(chrono::milliseconds(time)); 

	if (MESSAGE) cout << "Timer ended.\n"; 
}

void time_seconds(int time, bool MESSAGE) {

	if (MESSAGE) cout << "Timer started for: " << time << " seconds.\n";

	this_thread::sleep_for(chrono::seconds(time));

	if (MESSAGE) cout << "Timer ended.\n";
}

#endif
