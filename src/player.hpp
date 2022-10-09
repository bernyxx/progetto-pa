/*
 * player.hpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "person.hpp"
#include "playerMatch.hpp"

// ruolo del giocatore
enum PlayerRole {
	NONE, LURKER, ENTRY, SUPPORT, IGL
};


// stato del giocatore
enum Status{
	ACTIVE, BENCHED, RETIRED
};

class Player : virtual public Person{
private:
	std::string nickname;
	std::string team;
	PlayerRole role;
	Status status;
	std::vector<PlayerMatch*> matches;


public:
	// costruttore (per un nuovo giocatore senza partite giocate)
	Player(std::string, std::string, int, std::string, PlayerRole, Status);

	// costruttore che richiede inoltre anche una lista di partite
	Player(std::string, std::string, int, std::string, PlayerRole, Status, std::vector<PlayerMatch*>*);

	// distruttore
	virtual ~Player();

	virtual std::string toString();

	// player nickname
	virtual std::string getNickname();

	// METODI PlayerRole
	virtual PlayerRole getRole();
	virtual void changeRole(PlayerRole);

	// METODI Status
	virtual Status getStatus();
	virtual void changeStatus(Status);


	// METODI TEAM

	// ritorna true se il coach fa parte di una squadra
	// ritorna false se è un free agent
	bool hasTeam();

	std::string getTeam();
	void setTeam(std::string);
	void unsetTeam();

	// OPERATOR OVERLOAD

	// Overload degli operatori per comparare due coach
	// L'ordine è stabilito sulla statistica "AvgKD" (Average KD ratio per match)
	// KD ratio = Rapporto uccisioni/morti
	bool operator>(Player&);
	bool operator< (Player&);

	// Player matches methods
	void addMatch(PlayerMatch*);
	void printMatches();

	// STATISTICHE GIOCATORE

	int getTotalKills();
	int getTotalAssists();
	int getTotalDeaths();

	// Rapport uccisioni/morti calcolato sul totale delle uccisioni e delle morti
	// (non come media del rapporto su ogni partita)
	double getTotalKD();

	double getAvgKills();
	double getAvgAssists();
	double getAvgDeaths();

	// Average KD ratio per match -> La statistica più importante
	// Un valore più elevato corrisponde ad un giocatore migliore
	// Calcolato facendo la media del rapporto uccisioni/morti di ogni partita
	// Valore più affidabile della metrica getTotalKD
	double getAvgKD();

	// Stampa tutte le statistiche
	void printStats();

	// restituisce il vettore matches (utile soprattutto per l'ereditarietà)
	std::vector<PlayerMatch*>* getPlayerMatches();

};




#endif /* PLAYER_HPP_ */
