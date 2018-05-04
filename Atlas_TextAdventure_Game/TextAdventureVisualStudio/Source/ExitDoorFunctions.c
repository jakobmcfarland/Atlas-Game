/******************************************************************************
filename    ExitDoorFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "ExitDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "PlayerState.h"
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void ExitDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData, PlayerState *playerState)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);
	UNREFERENCED_PARAMETER(gameState);

	/* the user has won the game! end the game, and let them know what happened. */
	GameState_EndGame(gameState, "You climb aboard, start the machine, and glide out of the facility into the open water.\n");
}


/* Build a "exit door" object */
Item* ExitDoor_Build()
{
	Item * item;
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("submersible", "A gleaming steel vehicle sits before you, offering a promise of freedom from this hellish place.\n", false, ExitDoor_Use, NULL, NULL);
}