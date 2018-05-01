/*****
PlayerStateFactory.c
by: Jakob McFarland
last edited: 4/30/2018
brief: builds a PlayerState object for use by the game
All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

#include "PlayerStateFactory.h" /* Function declarations */
#include "PlayerState.h" /* struct PlayerState,PlayerState_Create */

/* Create the player state for a new game */
PlayerState* CreateInitialPlayerState()
{
	PlayerState* initialPlayerState; /* the new PlayerState object we will return */

	 /* create an empty PlayerState object */
	initialPlayerState = PlayerState_Create();

	if (initialPlayerState != NULL)
	{
		/* the user starts with a breath of one*/
		SetPlayerBreathe(initialPlayerState, 1);
	}

	/* return the new object */
	return initialPlayerState;
}