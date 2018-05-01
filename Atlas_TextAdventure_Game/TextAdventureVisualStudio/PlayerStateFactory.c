/*****
PlayerStateFactory.c
by: Jakob McFarland
last edited: 4/30/2018
brief: builds a PlayerState object for use by the game
All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

#include "PlayerStateFactory.h" /* Function declarations */
#include "PlayerState.h" /* struct GameState, GameState_Create */

/* Create the game state for a new game */
PlayerState* CreateInitialGameState()
{
	PlayerState* initialPlayerState; /* the new GameState object we will return */

								 /* create an empty GameState object */
	initialPlayerState = PlayerState_Create();

	/* the user starts with a score of 0 */
	initialPlayerState->breathe = 1;

	/* return the new object */
	return initialPlayerState;
}