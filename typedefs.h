#pragma once
#ifndef TYPES_H
#define TYPES_H

#include <vector>

/*
	This file contains type-definitions and generic functions. 
*/

using namespace std;


//Type-definitions/aliases

template<typename T>
using matrix = vector<vector<T>>; 

template<typename T>
using graph = vector<vector<vector<T>>>; 

template<typename T>
using particle_int = pair<pair<int,int>, T>;

template<typename T, typename X, typename Y>
using particle_custom = pair<pair<X, Y>, T>; 


//Basic utility functions

	void print_int_coordinates(const pair<int, int>& coordinates) {
		cout << "(" << coordinates.first << "," << coordinates.second << ")\n";
	}

	void print_double_coordinates(const pair<double, double>& coordinates) {
		cout << "(" << coordinates.first << "," << coordinates.second << ")\n";
	}
	

	template<typename T>
	void print_vector(const vector<T>& vector, bool SPACED) {
		
		for (auto& i : vector) {

			cout << i << " ";
			if (SPACED) cout << "\n";
		}
		cout << "\n";
	}
	
	template<typename T>
	void print_matrix(const matrix<T>& matrix, bool SPACED) {

		for (auto& row : matrix) {
			
			for (auto& column : row) {

				cout << column << " ";
				if (SPACED) cout << "\n"; 
			}
	
			if (!SPACED) cout << "\n";
		}
		cout << "\n"; 
	}

	//Quick-print function:

	template<typename T>
	void print(T arg) {
		cout << arg << " ";
	}

#endif 
