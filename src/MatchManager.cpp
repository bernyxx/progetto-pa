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
#include "../nlohmann/json.hpp"
#include "Player.hpp"

using json = nlohmann::json;


class MatchManager{

	static Player* findPlayer(std::vector<Player*> *db,std::string nickname){

		for (std::vector<Player*>::iterator i = db->begin(); i != db->end(); ++i) {
			if((*i)->getName() == nickname){
				return *i;
			}
		}

		throw "Player not found!";
	}

	static void checkPlayer(Player* pl, std::string team1, std::string team2){
		if ((pl->getTeam() == team1) || (pl->getTeam() == team2)){
			return;
		}

		throw "checkPlayer ERROR: Player is not part of the team specified in the JSON file!";
	}

	static void newMatch(std::vector<Player*> *db, std::string filePath){

		// parse json file
		std::ifstream f(filePath);
		json data = json::parse(f);

		std::string team1 = data["team1"];
		std::string team2 = data["team2"];

		for(int i=0; i<10; i++){
			std::string nickname = data["stats"][i]["player"];
			Player* pl = findPlayer(db, nickname);

			// check if the player is part of the team specified in team1/team2 in the JSON file
			checkPlayer(pl, team1, team2);


			//TODO: Smart pointer
			PlayerMatch* pm = new PlayerMatch(18, 3, 19);
			pl->addMatch(pm);
		}


		std::cout << data["stats"][0]["kills"] << std::endl;
	}
};

