//
//  PBCCharacter.m
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/5/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#import "PBCCharacter.h"

@implementation PBCCharacter

@synthesize race;
@synthesize ruleset;

-(NSDictionary*)abilityScores
{
	return [abilityScores copy];
}

-(NSInteger)pointBuyValue
{
	return point_buy_value;
}

-(void)setPointBuyValue:(NSInteger)pointBuyValue
{
	points_remaining += pointBuyValue - point_buy_value;
	point_buy_value = pointBuyValue;
}

@synthesize pointsRemaining = points_remaining;

#pragma mark - Object lifetime

-(void)dealloc
{
	[race release];
	[ruleset release];
	
	[super dealloc];
}

-(id)initWithRuleset:(NSString*)a_ruleset
{
	self = [super init];
	if(self)
	{
		ruleset = a_ruleset;
		
		// Load the ruleset definition from <RULESET_NAME>_ruleset.plist.
		NSString* rulesetDefinitionPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@_ruleset", a_ruleset] ofType:@"plist"];
		NSDictionary* rulesetDefinition	= [NSDictionary dictionaryWithContentsOfFile:rulesetDefinitionPath];

		abilityScores = [[rulesetDefinition objectForKey:@"BaseAbilityScores"] mutableCopy];
		[abilityScores retain];

		minAbilityScores = [rulesetDefinition objectForKey:@"MinimumAbilityScore"];
		[minAbilityScores retain];
		maxAbilityScores = [rulesetDefinition objectForKey:@"MaximumAbilityScores"];
		[maxAbilityScores retain];
		pointCosts = [rulesetDefinition objectForKey:@"PointCosts"];
		[pointCosts retain];
		
		point_buy_value = [[[rulesetDefinition objectForKey:@"PointBuyValues"] firstObject] integerValue];
		points_remaining = point_buy_value;
	}
	return self;
}

-(id)initWithRuleset:(NSString*)a_ruleset andRace:(NSDictionary*)a_race
{
	self = [self initWithRuleset:a_ruleset];
	if(self)
	{
		race = a_race;
		[race retain];
	}
	return self;
}

#pragma mark - Utility methods

-(void)incrementAbilityScore:(NSString*)ability
{
	NSInteger abilityScore = [[abilityScores objectForKey:ability] integerValue];
	
	if(points_remaining > 0)
	{
		if(abilityScore < [[maxAbilityScores objectForKey:ability] integerValue])
		{
			NSInteger costIncrease = [[pointCosts objectForKey:[NSNumber numberWithInteger:(abilityScore + 1)]] integerValue] - [[pointCosts objectForKey:[NSNumber numberWithInteger:abilityScore]] integerValue];
			if(points_remaining >= costIncrease)
			{
				points_remaining -= costIncrease;
				abilityScore++;
				[abilityScores setObject:[NSNumber numberWithInteger:abilityScore] forKey:ability];
			}
		}
	}
}

-(void)decrementAbilityScore:(NSString*)ability
{
	
}

@end
