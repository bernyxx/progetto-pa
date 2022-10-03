/*
 * PlayerMatch.cpp
 *
 *  Created on: 2 ott 2022
 *      Author: Kevin
 */

#include "playerMatch.hpp"

#include <iostream>

PlayerMatch::PlayerMatch(int k, int a, int d){
	kills = k;
	assists = a;
	deaths = d;
}

PlayerMatch::~PlayerMatch(){
	std::cout << "Distr. PlayerMatch" << std::endl;
}




