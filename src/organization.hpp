#ifndef ORGANIZATION_HPP_
#define ORGANIZATION_HPP_

#include <vector>
#include <memory>
#include "player.hpp"
#include "coach.hpp"

class Organization{
private:
	// nome della squadra/organizzazione
	std::string name;

	// vettore di puntatori ai giocatori membri della squadra
	std::vector<std::shared_ptr<Player>> players;

	// puntatore al coach
	std::shared_ptr<Coach> coach;


public:

	// costruttore
	// richiede nome del team e la lista di organizzazioni dove verrà inserita la squadra
	Organization(std::string, std::vector<Organization*>*);

	// distruttore
	~Organization();

	// simile ad un copy constructor, crea un nuovo vettore dove trasferisce manualmente i puntatori dei vecchi player
	// non crea semplicemente un puntatore al vecchio vettore
	Organization (Organization&, std::vector<Organization*>*);

	std::string getName();

	// stampa una panoramica della squadra
	void print();

	// METODI COACH
	// ritorna true se la squadra ha un coach
	// ritorna false in caso contrario
	std::shared_ptr<Coach> getCoach();

	void setCoach(std::shared_ptr<Coach>);
	void removeCoach();
	bool hasCoach();

	// METODI PLAYER
	void addPlayer(std::shared_ptr<Player>);

	// rimuove un giocatore dato il nickname
	void removePlayer(std::string);

	// restituisce un puntatore ad un giocatore dato il nickname
	std::shared_ptr<Player> getPlayer(std::string);

	// restituisce un puntatore al miglior giocatore della squadra -> il giocatore con la piï¿½ alta media del rapporto KD per partita (vedi getAvgKD in Player)
	std::shared_ptr<Player> getBestPlayer();

	// restituisce true se la squadra ha il giocatore con nickname passato come argomento
	// altrimenti restituisce false
	bool hasPlayer(std::string);

	// restituisce un puntatore al vettore dei puntatori dei giocatori della squadra
	std::vector<std::shared_ptr<Player>>* getPlayers();

};




#endif /* ORGANIZATION_HPP_ */
