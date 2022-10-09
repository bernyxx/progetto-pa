/*
 * Match.hpp
 *
 *  Created on: 2 ott 2022
 *      Author: Kevin
 */

#ifndef PLAYERMATCH_HPP_
#define PLAYERMATCH_HPP_

class PlayerMatch{

// classe che fa da contenitore per alcune statistiche di un giocatore in una partita
private:
	int kills;
	int assists;
	int deaths;
	double kd;

public:
	PlayerMatch(int, int, int, double);
	~PlayerMatch();

	// restituisce un array con 3 valori nel seguente ordine: 0-> kills, 1-> assists, 2-> deaths
	int* getValues();

	// restituisce il rapporto uccisioni/morti
	double getKD();
};



#endif /* PLAYERMATCH_HPP_ */
