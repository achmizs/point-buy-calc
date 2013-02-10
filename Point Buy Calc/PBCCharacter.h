//
//  PBCCharacter.h
//  Point Buy Calc
//
//  Created by Sandy Achmiz on 2/5/13.
//  Copyright (c) 2013 Said Achmiz. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - PBCCharacter class declaration

@interface PBCCharacter : NSObject
{
	NSString* ruleset;
	NSDictionary* race;
	
	NSMutableDictionary* abilityScores;
	
	NSDictionary* minAbilityScores;
	NSDictionary* maxAbilityScores;
	NSDictionary* pointCosts;
	
	NSInteger point_buy_value;
	NSInteger points_remaining;
}

@property (nonatomic, retain) NSString* ruleset;
@property (nonatomic, retain) NSDictionary* race;

@property (nonatomic, readonly) NSDictionary* abilityScores;

@property NSInteger pointBuyValue;
@property (readonly) NSInteger pointsRemaining;

-(id)initWithRuleset:(NSString*)ruleset;
-(id)initWithRuleset:(NSString*)ruleset andRace:(NSDictionary*)race;

-(void)incrementAbilityScore:(NSString*)ability;
-(void)decrementAbilityScore:(NSString*)ability;

@end
