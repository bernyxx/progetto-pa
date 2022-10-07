/*
 * PlayerMatch.cpp
 *
 *  Created on: 2 ott 2022
 *      Author: Kevin
 */

#include "playerMatch.hpp"

#include <iostream>
#include <cmath>


PlayerMatch::PlayerMatch(int k, int a, int d, double kd){
	kills = k;
	assists = a;
	deaths = d;
	this->kd = kd;
}

PlayerMatch::~PlayerMatch(){
	std::cout << "Distr. PlayerMatch" << std::endl;
}

int* PlayerMatch::getValues(){
	int* result = new int[3];
	result[0] = kills;
	result[1] = assists;
	result[2] = deaths;
	return result;
}

double PlayerMatch::getKD(){
	//return round((kills / (double) deaths) * 100) / 100;
	return kd;
}




