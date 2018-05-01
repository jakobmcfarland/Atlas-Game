/*****
PlayerState.c
by: Jakob McFarland
last edited: 4/30/2018
brief: an object that stores information about the player, such as the player's breathe value
All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

/* from PlayerState.h: stdafx.h, used here for NULL, malloc/free, printf */
#include "PlayerState.h" /* Function declarations */

/* Create an empty game state object */
PlayerState* PlayerState_Create()
{
	PlayerState* playerState; /* the new object we will return */

						  /* allocate memory for the new object */
	playerState = (PlayerState*)malloc(sizeof(PlayerState));
	if (playerState == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* assign empty values to all members */
	playerState->breathe = 0;
	/* return the new object */
	return playerState;
}

/* Free the memory associated with a game-state object */
void PlayerState_Free(PlayerState** playerStatePtr)
{
	/* safety check on the parameters */
	if ((playerStatePtr == NULL) || (*playerStatePtr == NULL))
	{
		return; /* take no action if no valid object was provided */
	}

	/* free the object */
	free(*playerStatePtr);

	/* set the incoming pointer to NULL*/
	*playerStatePtr = NULL;
}

/* gets the current amount of breathe the player has */
int GetPlayerBreathe(PlayerState** playerStatePtr)
{
	/* safety check on the parameters */
	if ((playerStatePtr == NULL) || (*playerStatePtr == NULL))
	{
		return 0; /* take no action if no valid object was provided */
	}

	return (*playerStatePtr)->breathe;
}

/* sets the current amount of breathe */
void SetPlayerBreathe(PlayerState** playerStatePtr, int value)
{
	/* safety check on the parameters */
	if ((playerStatePtr == NULL) || (*playerStatePtr == NULL))
	{
		return; /* take no action if no valid object was provided */
	}

	(*playerStatePtr)->breathe = value;
}