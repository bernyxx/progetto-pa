/*
 * Match.hpp
 *
 *  Created on: 2 ott 2022
 *      Author: Kevin
 */

#ifndef PLAYERMATCH_HPP_
#define PLAYERMATCH_HPP_

class PlayerMatch{
private:
	int kills;
	int assists;
	int deaths;
	double kd;

public:
	PlayerMatch(int, int, int, double);
	~PlayerMatch();
	int* getValues();
	double getKD();
};



#endif /* PLAYERMATCH_HPP_ */
