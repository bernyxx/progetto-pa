#ifndef COACH_HPP_
#define COACH_HPP_

#include <string>
#include <vector>
#include "person.hpp"

class Coach : virtual public Person{
private:
	// nickname del giocatore
	std::string nickname;

	// nome della squadra (organizzazione) che allena
	std::string team;

	// lista di partite in cui ha fatto da coach (indipendente dal team)
	std::vector<double> matches;

public:

	// costruttore (per un nuovo coach senza partite giocate)
	Coach(std::string, std::string, int, std::string);

	// costruttore che richiede inoltre anche una lista di partite
	Coach(std::string, std::string, int, std::string, std::vector<double>*);

	// distruttore
	virtual ~Coach();

	virtual std::string toString();

	// coach nickname
	virtual std::string getNickname();

	// METODI TEAM

	// ritorna true se il coach fa parte di una squadra
	// ritorna false se � un free agent
	virtual bool hasTeam();

	virtual std::string getTeam();
	virtual void setTeam(std::string);
	virtual void unsetTeam();

	// OPERATOR OVERLOAD

	// Overload degli operatori per comparare due coach
	// L'ordine � stabilito sulla statistica "rating" (vedi getRating)
	virtual bool operator>(Coach&);
	virtual bool operator<(Coach&);


	// aggiungi una partita al vector matches
	// richiede un double come argomento (rating della partita)
	// calcolato come media del rapporto uccisioni/morti dei giocatore della propria squadra
	virtual void addMatch(double);

	// restituisce il rating del coach calcolato facendo la media dei rating delle partite
	virtual double getRating();

	// restituisce il vettore matches (utile soprattutto per l'ereditariet�)
	virtual std::vector<double>* getCoachMatches();

};



#endif /* COACH_HPP_ */
