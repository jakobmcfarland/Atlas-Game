#pragma once
#include "stdafx.h" /* bool */

/* The user state in the game */
typedef struct PlayerState
{
	/* the user's score */
	int breathe;

	/* If false, the game is over and should exit */
	bool isRunning;
} GameState;

/* Create an empty game state object */
GameState* GameState_Create();

/* Free the memory associated with a game-state object */
void GameState_Free(GameState** gameStatePtr);
