//
//  Character.cpp
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/8/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#include "Character.h"
using namespace std;

// Constructors

Character::Character(string ruleset):
ruleset(ruleset)
{
	
}

Character::Character(string ruleset, Race race):
ruleset(ruleset),
race(race)
{
	
}

// Functions

void Character::increment_ability_score(string ability)
{
	int score = ability_scores[ability];
	
	if(score < max_ability_scores[ability])
	{
		int cost_increase = point_costs[score + 1] - point_costs[score];
		if(points_remaining >= cost_increase)
		{
			points_remaining -= cost_increase;
			score++;
			ability_scores[ability] = score;
		}
	}
}

void Character::decrement_ability_score(string ability)
{
	int score = ability_scores[ability];
	
	if(score > min_ability_scores[ability])
	{
		int cost_decrease = point_costs[score] - point_costs[score - 1];
		points_remaining += cost_decrease;
		score++;
		ability_scores[ability] = score;
	}
}
