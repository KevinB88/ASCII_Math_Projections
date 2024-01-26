#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
	constexpr double pi = 3.14159265358979323846;
}

double radians_conversion(double degrees) {
	return (degrees / 180) * constants::pi; 
}

double degrees_conversion(double radians) {
	return (radians / constants::pi) * 180;
}

#endif