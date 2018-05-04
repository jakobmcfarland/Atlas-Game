/*****
PlayerStateFactory.h
by: Jakob McFarland
last edited: 4/30/2018
brief: header for PlayerState.c
All content © 2018 DigiPen (USA) Corporation, all rights reserved.

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

#pragma once
#include "stdafx.h" /* bool */

/* The user state in the game */
typedef struct PlayerState
{
	/* the user's score */
	int breathe;

} PlayerState;

/* Create an empty game state object */
PlayerState* PlayerState_Create();

/* Free the memory associated with a game-state object */
void PlayerState_Free(PlayerState** playerStatePtr);

/* gets the current amount of breathe the player has */
int GetPlayerBreathe(PlayerState* playerStatePtr);

/* sets the current amount of breathe */
void SetPlayerBreathe(PlayerState* playerStatePtr, int value);