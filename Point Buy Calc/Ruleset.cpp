//
//  Ruleset.cpp
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/10/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#include "Ruleset.h"

Ruleset::Ruleset(const Ruleset &right):
	base_ability_scores(right.base_ability_scores),
	min_ability_scores(right.min_ability_scores),
	max_ability_scores(right.min_ability_scores),
	point_buy_values(right.point_buy_values),
	default_point_buy_value_key(right.default_point_buy_value_key),
	point_costs(right.point_costs)
	{ }