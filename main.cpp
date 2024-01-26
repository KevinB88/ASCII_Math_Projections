#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "vector_operations.cpp"
#include "math_constants.h"
#include "typedefs.h"

using namespace std;

//Utility function:

template<typename X, typename Y>
void print_pair(const pair<X, Y>& pair, bool coordinate) {
	
	if (coordinate) {
		cout << "(" << pair.first << ", " << pair.second << ")\n";
	} else {
		cout << pair.first << ", " << pair.second;
	}
}

int main() {

	int upper_bound;
	char filler_character;

	//build function to automate this process; choosing a data-type of interest

			matrix<char> Q1(upper_bound, vector<char>(upper_bound, ' '));
			matrix<char> Q2(upper_bound, vector<char>(upper_bound, ' '));
			matrix<char> Q3(upper_bound, vector<char>(upper_bound, ' '));
			matrix<char> Q4(upper_bound, vector<char>(upper_bound, ' '));

			graph<char> cartesian = { Q2, Q1, Q3, Q4 };

	//0 to 2pi

	double X = 0;

	while (0 != 2 * constants::pi) {

		//pair<double, double> point = { X, sin(X) };

		pair<int, int> point_integer = { X, 100 * sin(X) };

		//print_pair(point, true);

	
		
		//print_pair(point_integer, true); 


		X += 0.01;

		this_thread::sleep_for(chrono::milliseconds(50));
	}

	return 0;
}
 