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
#include "Ruleset.h"
using namespace std;

class Character
{
private:
	const Ruleset *ruleset;
	const Race *race;
	
	map <string, int> ability_scores;
	
	int point_buy_value;
	int points_remaining;
	
public:
	// Constructors
	Character(Ruleset* ruleset);
	Character(Ruleset* ruleset, Race* race);
	
	// Accessors
	const Ruleset* getRuleset()
		{ return ruleset; }
	void setRuleset(Ruleset* r)
		{ ruleset = r; }
	
	const Race* getRace()
		{ return race; }
	void setRace(Race* r)
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
