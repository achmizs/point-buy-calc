//
//  Race.h
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/8/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#ifndef __Point_Buy_Calc__Race__
#define __Point_Buy_Calc__Race__

#include <iostream>
#include <map>

using namespace std;

class Race
{
private:
	map <string, int> ability_mods;
	string name;
	
public:
	// Constructors
	Race(string name, string* ability_names, int* ability_mod_values, int num_abilities):
		name(name)
		{
			for(int i = 0; i < num_abilities; i++)
				ability_mods[ability_names[i]] = ability_mod_values[i];
		}
	Race(const Race &right):
		ability_mods(right.ability_mods),
		name(right.name)
		{ }
	
	// Operators
	Race operator=(const Race &right)
	{
		ability_mods = right.ability_mods;
		name = right.name;
		
		return *this;
	}
	
	// Accessors
	string getName();
	int abilityMod(string ability);
};

#endif /* defined(__Point_Buy_Calc__Race__) */
