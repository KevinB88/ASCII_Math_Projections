#pragma once
#ifndef TYPES_H
#define TYPES_H

#include <vector>

using namespace std;

template<typename T>
using matrix = vector<vector<T>>; 

template<typename T>
using graph = vector<vector<vector<T>>>; 

//Name is subject to change
template<typename T>
using particle_int = pair<pair<int,int>, T>;

template<typename T, typename X, typename Y>
using particle_custom = pair<pair<X, Y>, T>; 

#endif 
