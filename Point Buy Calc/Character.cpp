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

Character::Character(Ruleset* ruleset):
ruleset(ruleset)
{
	
}

Character::Character(Ruleset* ruleset, Race* race):
ruleset(ruleset),
race(race)
{
	
}

// Functions

void Character::increment_ability_score(string ability)
{
	int score = ability_scores[ability];
	
	if(score < ruleset->maxAbilityScore(ability))
	{
		int cost_increase = ruleset->pointCost(score + 1) - ruleset->pointCost(score);
		if(points_remaining >= cost_increase)
		{
			points_remaining -= cost_increase;
			ability_scores[ability] = ++score;
		}
	}
}

void Character::decrement_ability_score(string ability)
{
	int score = ability_scores[ability];
	
	if(score > ruleset->minAbilityScore(ability))
	{
		int cost_decrease = ruleset->pointCost(score) - ruleset->pointCost(score - 1);
		points_remaining += cost_decrease;
		ability_scores[ability] = --score;
	}
}
