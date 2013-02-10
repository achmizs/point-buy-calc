//
//  Ruleset.h
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/10/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#ifndef __Point_Buy_Calc__Ruleset__
#define __Point_Buy_Calc__Ruleset__

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Ruleset
{
private:
	map <string, int> base_ability_scores;
	map <string, int> min_ability_scores;
	map <string, int> max_ability_scores;
	
	map <string, int> point_buy_values;
	string default_point_buy_value_key;
	
	vector <int> point_costs;
	
public:
	// Constructors
	Ruleset();
	Ruleset(const Ruleset &right);
	
	// Operators
	
	// Accessors
	int baseAbilityScore(string ability) const
		{ return base_ability_scores.at(ability); }
	int maxAbilityScore(string ability) const
		{ return max_ability_scores.at(ability); }
	int minAbilityScore(string ability) const
		{ return min_ability_scores.at(ability); }
	int pointCost(int score) const
		{ return point_costs[score]; }
	
	int pointBuyValue(string pbv_name)
		{ return point_buy_values[pbv_name]; }
	int defaultPointBuyValue()
		{ return point_buy_values[default_point_buy_value_key]; }
};

#endif /* defined(__Point_Buy_Calc__Ruleset__) */
