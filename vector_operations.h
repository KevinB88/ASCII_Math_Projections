#pragma once
#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

template <typename T>

/*
	given the quadrant of the graph, translate the point into the appropriate quadrant
*/




template<typename T>
void point_translation(vector<vector<T>>& quadrant, pair<int,int> point, int q, T value){

	int t_x;
	int t_y;

	pair<int, int> origin;

	if (q == 1) {
		origin = { quadrant.size() - 1, 0 };

		t_x = origin.first - point.second;
		t_y = origin.second - point.first;

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {

			//error message
			//generate the appropriate bounds for the point
			return;
		}
		quadrant[t_x][t_y] = value;
	}
	else if (q == 2) {
		origin = { quadrant.size() - 1, quadrant.size() - 1};

		t_x = origin.first - point.second; 
		t_y = origin.second - (-1 * point.first);

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {
			
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

			//error message
			//generate the appropriate bounds for the point
			return;
		}
		quadrant[t_x][t_y] = value
	} 
	else if (q == 4) {
		origin = { 0,0 };

		t_x = origin.first + point.first;
		t_y = origin.second + (-1 * point.second);

		if ((t_x < 0 || t_x >= quadrant.size()) || (t_y < 0 || t_y >= quadrant.size())) {
			
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





#endif