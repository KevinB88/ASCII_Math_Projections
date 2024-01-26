#include <iostream>
#include <vector>
#include <cmath>
#include "typedefs.h"
#include "time_functions.h"
#include "math_constants.h"

/*
	Graphs are always defined to have the following matrices
	within their vector:

	graph[0] = Quad II
	graph[1] = Quad I
	graph[2] = Quad III
	graph[3] = Quad IV
*/

using namespace std;

/*
	Private helper function used exclusively within this file.

	The value returned is the index of the quadrant within the graph 3-D vector.
*/

//* helper function *Test for bugs/errors
int particle_quadrant_helper(const pair<int,int>& particle) {

/*
	Quad I:		(0,0) -> (+X,+Y)
	Quad II:	(0,0) -> (-X,+Y)
	Quad III:	(0,0) -> (-X, -Y)
	Quad IV:	(0,0) -> (+X, -Y)
*/

	if (particle.first >= 0 && particle.second >= 0) return 1;
	else if (particle.first < 0 && particle.second >= 0) return 0;
	else if (particle.first <= 0 && particle.second < 0) return 2;
	else if (particle.first > 0 && particle.second < 0) return 3;
	else return -1;
}

//Requires optimization

template<typename T>
void point_translation(vector<vector<T>>& quadrant, pair<int, int> point, int q, T value) {

	int t_x;
	int t_y;

	pair<int, int> origin;

	if (q == 1) {
		origin = { quadrant.size() - 1, 0 };

		t_x = origin.first - point.second;
		t_y = origin.second - point.first;

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {

			//temp message:
			cout << "Out of bounds!\n";

			//error message
			//generate the appropriate bounds for the point
			return;
		}
		quadrant[t_x][t_y] = value;
	}
	else if (q == 2) {
		origin = { quadrant.size() - 1, quadrant.size() - 1 };

		t_x = origin.first - point.second;
		t_y = origin.second - (-1 * point.first);

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {


			//temp message:
			cout << "Out of bounds!\n";

			//error message
			//generate the appropriate bounds for the point
			return;
		}

		quadrant[t_x][t_y] = value;
	}
	else if (q == 3) {
		origin = { 0, quadrant.size() - 1 };

		t_x = origin.first + (point.second * -1);
		t_y = origin.second - (point.first * -1);

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {

			//temp message:
			cout << "Out of bounds!\n";

			//error message
			//generate the appropriate bounds for the point
			return;
		}
		quadrant[t_x][t_y] = value;
	}
	else if (q == 4) {
		origin = { 0,0 };

		t_x = origin.first + point.first;
		t_y = origin.second + (-1 * point.second);

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {

			//temp message:
			cout << "Out of bounds!\n";

			//error message
			//generate the appropriate bounds for the point

			return;
		}
		quadrant[t_x][t_y] = value;
	}
	else {
		cout << "ERROR: Invalid quadrant.\n";
		return;
	}
}


// Function to determine the bounds of the particle 

//* helper function *Test for bugs/errors
template<typename T>
void graph_bound_print(const graph<T>& cartesian, const pair<int,int>& particle){
/*
		Graphs are always defined to have the following matrices
		within their vector:

		graph[0] = Quad II
		graph[1] = Quad I
		graph[2] = Quad III
		graph[3] = Quad IV
*/

/*
	Quad I:		(0,0) -> (+X,+Y)
	Quad II:	(0,0) -> (-X,+Y)
	Quad III:	(0,0) -> (-X, -Y)
	Quad IV:	(0,0) -> (+X, -Y)
*/
	int quadrant = particle_quadrant_helper(particle); 
	int quadrant_bound = cartesian[0].size()-1; 

	switch (quadrant) {

		case 1:
			cout << "Quadrant I Bounds : \t(0,0) -> (" << quadrant_bound << "," << quadrant_bound << ")\n"; 
			return;
		case 0: 
			cout << "Qudrant II Bounds : \t(0,0) -> (" << -1 * quadrant_bound << "," << quadrant_bound << ")\n";
			return;
		case 2:
			cout << "Quadrant III Bounds: \t(0,0) -> (" << -1 * quadrant_bound << "," << -1 * quadrant_bound << ")\n";
			return;
		case 3:
			cout << "Quadrant IV Bounds: \t(0,0) -> (" << quadrant_bound << "," << -1 * quadrant_bound << ")\n"; 
			return;
		default:
			cout << "ERROR: Invalid quadrant, please review your cartesian graph.\n";
			return;
	}
}

//* helper function *Test for bugs/errors
template<typename T>
bool particle_within_bounds(const graph<T>& cartesian, const pair<int,int>& particle, bool BOUND_MESSAGE) {

	bool x_bound				= false; 
	bool y_bound				= false;

	//Determining the quadrant for print operations.
	int q						= -1; 
	int quadrant				= particle_quadrant_helper(particle);
	int quadrant_bound			= cartesian[0].size() - 1;

	//QuadI
	if (quadrant == 1) {
		
		x_bound = (particle.first >= 0 && particle.first <= quadrant_bound);
		y_bound = (particle.second >= 0 && particle.second <= quadrant_bound);

		q = 1;
	}
	//QuadII
	else if (quadrant == 0) {

		x_bound = (particle.first >= -1 * quadrant_bound && particle.first <= 0);
		y_bound = (particle.second >= 0 && particle.second <= quadrant_bound);

		q = 2;
	}
	//QuadIII
	else if (quadrant == 2) {
		
		x_bound = (particle.first >= -1 * quadrant_bound && particle.first <= 0);
		y_bound = (particle.second >= -1 * quadrant_bound && particle.second <= 0);

		q = 3; 
	}
	//QuadIV
	else if (quadrant == 3) {
		
		x_bound = (particle.first >= 0 && particle.first <= quadrant_bound);
		y_bound = (particle.second >= -1 * quadrant_bound && particle.second <= 0);
	}

	if (x_bound && y_bound) return true;
	else {
		if (BOUND_MESSAGE) {
			cout << "The point: \t(" << particle.first << "," << particle.second << ") is out of bounds within quadrant: " << q << "\n"; 
			graph_bound_print(cartesian, particle);
		}
		return false;
	}
}


// Graph automator

template<typename T>
graph<T> graph_generate(int planar_bound, T native_projector) {

	matrix<T> Quad1(planar_bound, vector<T>(planar_bound, native_projector));
	matrix<T> Quad2(planar_bound, vector<T>(planar_bound, native_projector));
	matrix<T> Quad3(planar_bound, vector<T>(planar_bound, native_projector));
	matrix<T> Quad4(planar_bound, vector<T>(planar_bound, native_projector));

	return { Quad2, Quad1, Quad3, Quad4 }; 
}

/*
	More sophisticated particle translation:

	parameters: 
		the cartesian graph native to the particle
		the particle; it's position, and representing value
*/

template<typename T> 
void particle_graph_translator(graph<T>& cartesian, const pair<pair<int, int>, T>& particle, bool BOUND_MESSAGE) {

	pair<int, int> coordinates		= particle.first;

	T value							= particle.second; 

	int quadrant					= particle_quadrant_helper(coordinates); 

	int quadrant_bound				= cartesian[0].size() - 1;
	int translated_X				= 0;
	int translated_Y				= 0;

	switch (quadrant) {
		case 1:
			translated_X = quadrant_bound - coordinates.second;
			translated_Y = coordinates.first;
			break;
		case 0:
			translated_X = quadrant_bound - coordinates.second;
			translated_Y = quadrant_bound - (-1 * coordinates.first); 
			break;
		case 2:
			translated_X = (-1 * coordinates.second);
			translated_Y = quadrant_bound - (-1 * coordinates.first); 
			break;
		case 3:
			translated_X = coordinates.first;
			translated_Y = (-1 * coordinates.second);
			break;
	}

	if ((particle_within_bounds(cartesian, coordinates, BOUND_MESSAGE)) && quadrant != 3) {
		cartesian[quadrant][translated_X][translated_Y] = value;
		return;
	}
	else if ((particle_within_bounds(cartesian, coordinates, BOUND_MESSAGE)) && quadrant == 3) {
		cartesian[quadrant][translated_Y][translated_X] = value;
		return; 
	}
}

template<typename T>
void graph_print(const graph<T>& cartesian) {

/*
	Graphs are always defined to have the following matrices
	within their vector:

	graph[0] = Quad II
	graph[1] = Quad I
	graph[2] = Quad III
	graph[3] = Quad IV
*/

	int planar_height	= cartesian[0].size() + cartesian[1].size(); 
	int planar_width	= cartesian[0].size() + cartesian[2].size();


	for (int X = 0; X < planar_height; X++) {

		for (int Y = 0; Y < planar_width; Y++) {

			if (X < cartesian[0].size() && Y < cartesian[0][0].size()) {
				cout << cartesian[0][X][Y] << " ";
			}
			else if (X < cartesian[0].size() && Y >= cartesian[0][0].size()) {
				cout << cartesian[1][X][Y % cartesian[1][0].size()] << " ";
			}
			else if (X >= cartesian[0].size() && Y < cartesian[0][0].size()) {
				cout << cartesian[2][X % cartesian[2].size()][Y] << " ";
			}
			else if (X >= cartesian[0].size() && Y >= cartesian[0][0].size()) {
				cout << cartesian[3][X % cartesian[3].size()][Y % cartesian[3][0].size()] << " ";
			}
		}

			cout << "\n"; 
	}
}


int main() {
	
	graph<char> cartesian = graph_generate(25, '*');

	
			/*Create a function to automate points. 
				particle_int<char> point_1 = { {0,0},'A' };
				particle_int<char> point_2 = { {1,-1}, 'B' };
				particle_int<char> point_3 = { {-1,0}, 'C' };
				particle_int<char> point_4 = { {-1,-1}, 'D' }; 


				particle_graph_translator(cartesian, point_3, true); 

				graph_print(cartesian); */


	int pointA = 0;
	int pointB = 180; 

	double magnitude = sqrt(2); 

	while (true) {

		double x_position = magnitude * cos(radians_conversion(pointA));
		double y_position = magnitude * sin(radians_conversion(pointB)); 

		print_double_coordinates({ x_position,y_position }); 

		pointA %= 360;
		pointB %= 360;

		pointA++;
		pointB++; 

		timer_millis(50,false); 
	}

	return 0;
}

/*
	optimization techniques:

	Build a class around the cartesian graph functions:

	for point translation/projection

	function representation

	resetting the data-type being used within the graph:
	
	this option will completely wipe all the content drawn upon the graph.
	
	With the following option prompting the user:
		
		"Are you sure you would like to proceed? This option will wipe the entire graph."

	-options for operations on specific quadrants.

	-Allowing for controllable animations, via some mainframe where the user is able to control rates,positions, ect.


	New reminders: 2:38, 1/26/2024:

	To comment out multiple lines:
	
		ctrl-k, ctrl-c

		to undo.

		ctrl-k, ctrl-u

*/