/*
 * MatchManager.cpp
 *
 *  Created on: 2 ott 2022
 *      Author: Kevin
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "../nlohmann/json.hpp"
#include "organization.hpp"
#include "player.hpp"
#include "customRound.hpp"

using json = nlohmann::json;


class MatchManager {

public:

	static Player* findPlayer(std::vector<Organization*> *db,
			std::string nickname) {

//		for (std::vector<Organization*>::iterator i = db->begin();
//				i != db->end(); ++i) {
//			if ((*i)->hasPlayer(nickname)) {
//				Player *pl = (*i)->getPlayer(nickname);
//				return pl;
//			}
//		}

		std::vector<Organization*>::iterator it = std::find_if(db->begin(),db->end(), [nickname](Organization *org) {return org->hasPlayer(nickname);});

		if (it != db->end()) {
			return (*it)->getPlayer(nickname);
		}

		throw std::runtime_error("Player not found!");
	}

	static Coach* findCoach(std::vector<Organization*> *db, std::string nickname) {

//		for (std::vector<Organization*>::iterator i = db->begin();
//				i != db->end(); ++i) {
//			if ((*i)->hasCoach()) {
//				if ((*i)->getCoach()->getNickname() == nickname) {
//					Coach *c = (*i)->getCoach();
//					return c;
//				}
//			}
//
//		}

		std::vector<Organization*>::iterator it = std::find_if(db->begin(), db->end(), [nickname](Organization* org){if(org->hasCoach()){return org->getCoach()->getNickname() == nickname;} else {return false;}});

		if(it != db->end()){
			return (*it)->getCoach();
		}


		throw std::runtime_error("Coach not found!");
	}

	static void checkPlayer(Player *pl, std::string team) {
		if (pl->getTeam() == team) {
			return;
		}

		throw std::runtime_error(
				"Player is not part of the team specified in the JSON file!");

	}

	static void checkCoach(Coach *c, std::string team) {
		if ((c->getTeam() == team)) {
			return;
		}

		throw std::runtime_error(
				"Player is not part of the team specified in the JSON file!");
	}

	static double manageTeam(std::vector<Organization*> *db, int numPlayersPerTeam, bool isTeam1, json data){

		std::string key = "";
		std::string team = "";
		double sumKD = 0;

		if (isTeam1) {
			key = "stats1";
			team = data["team1"];
		} else {
			key = "stats2";
			team = data["team2"];
		}


		for (int i = 0; i < numPlayersPerTeam; i++) {
				std::string nickname = data[key][i]["player"];
				Player *pl = findPlayer(db, nickname);

				// check if the player is part of the team specified in team1/team2 in the JSON file
				checkPlayer(pl, team);

				int kills = data[key][i]["kills"];
				int assists = data[key][i]["assists"];
				int deaths = data[key][i]["deaths"];

				double kd = customRound(kills / (double) deaths);

				PlayerMatch *pm = new PlayerMatch(kills, assists, deaths, kd);
				pl->addMatch(pm);
				sumKD += kd;
		}

		return sumKD;
	}



	static void newMatch(std::string filePath, std::vector<Organization*> *db) {

		// parse json file
		std::ifstream f(filePath);
		json data = json::parse(f);

		std::string team1 = data["team1"];
		std::string team2 = data["team2"];

		std::string coach1 = data["coach1"];
		std::string coach2 = data["coach2"];

		int numPlayers = data["numPlayers"];
		int numPlayersPerTeam = numPlayers / 2;



		// add match for every player of team 1
		double sumKD1 = manageTeam(db, numPlayersPerTeam, true, data);

		// add match for every player of team 2
		double sumKD2 = manageTeam(db, numPlayersPerTeam, false, data);

		// add match for the coach

		// coach for team 1
		Coach *c1 = findCoach(db, coach1);

		checkCoach(c1, team1);

		c1->addMatch(sumKD1 / numPlayersPerTeam);

		// coach for team 2
		Coach *c2 = findCoach(db, coach2);
		if (c2 != NULL) {
			checkCoach(c2, team2);
		}

		c2->addMatch(sumKD2 / numPlayersPerTeam);

	}
};

