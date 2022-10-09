#ifndef ORGANIZATION_HPP_
#define ORGANIZATION_HPP_

#include <vector>
#include "player.hpp"
#include "coach.hpp"

class Organization{
private:
	// nome della squadra/organizzazione
	std::string name;

	// vettore di puntatori ai giocatori membri della squadra
	std::vector<Player*> players;

	// puntatore al coach
	Coach* coach;

public:
	// costruttore
	// richiede nome del team e la lista di organizzazioni dove verrà inserita la squadra
	Organization(std::string, std::vector<Organization*>*);

	// distruttore
	~Organization();

	std::string getName();

	// stampa una panoramica della squadra
	void print();

	// METODI COACH
	// ritorna true se la squadra ha un coach
	// ritorna false in caso contrario
	Coach* getCoach();

	void setCoach(Coach*);
	void removeCoach();
	bool hasCoach();

	// METODI PLAYER
	void addPlayer(Player*);

	// rimuove un giocatore dato il nickname
	void removePlayer(std::string);

	// restituisce un puntatore ad un giocatore dato il nickname
	Player* getPlayer(std::string);

	// restituisce un puntatore al miglior giocatore della squadra -> il giocatore con la più alta media del rapporto KD per partita (vedi getAvgKD in Player)
	Player* getBestPlayer();

	// restituisce true se la squadra ha il giocatore con nickname passato come argomento
	// altrimenti restituisce false
	bool hasPlayer(std::string);

};




#endif /* ORGANIZATION_HPP_ */
