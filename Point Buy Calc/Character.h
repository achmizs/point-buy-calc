//
//  Character.h
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/8/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#ifndef __Point_Buy_Calc__Character__
#define __Point_Buy_Calc__Character__

#include <iostream>
#include <map>
#include <vector>
#include "Race.h"
using namespace std;

class Character
{
private:
	string ruleset;
	Race race;
	
	map <string, int> ability_scores;
	
	map <string, int> min_ability_scores;
	map <string, int> max_ability_scores;
	vector <int> point_costs;
	
	int point_buy_value;
	int points_remaining;
	
public:
	// Constructors
	Character(string ruleset);
	Character(string ruleset, Race race);
	
	// Accessors
	string getRuleset()
		{ return ruleset; }
	void setRuleset(string r)
		{ ruleset = r; }
	
	Race getRace()
		{ return race; }
	void setRace(Race r)
		{ race = r; }
	
	int getPointBuyValue()
		{ return point_buy_value; }
	void setPointBuyValue(int pbv)
	{
		points_remaining += pbv - point_buy_value;
		point_buy_value = pbv;
	}
	
	int pointsRemaining()
		{ return points_remaining; }
	
	int getAbilityScore(string ability)
		{ return ability_scores[ability]; }
	void increment_ability_score(string ability);
	void decrement_ability_score(string ability);
};

#endif /* defined(__Point_Buy_Calc__Character__) */
