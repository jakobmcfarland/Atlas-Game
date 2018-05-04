/******************************************************************************
filename    BreathCommandHandler.c
author      Max van de Kamp
DP email    maxwell.vandekamp@digipen.edu

Brief Description:
This file defines functions that handle the "breath" user command, which
refills the player's oxygen.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#include "stdafx.h" /* NULL */
#include "CommandHandlerFunctions.h" /* Function Declaration */
#include "GameState.h" /* GameState */
#include "CommandData.h" /* struct CommandData */
#include "PlayerState.h" /* Set player breath */
#include "Room.h" /* Room_GetNextRoomIndex */
#include "WorldData.h" /* WorldData_GetRoom */

/* Handles the breath command, which refills the players oxygen */
void HandleBreathCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState)
{
	Room* currentRoom; /* the room we are currently in */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL) || (playerState == NULL))
	{
		/*DEBUG: prints if room is invalid -Jakob*/
		printf("DEBUG: invalid\n");
		return; /* take no action if the parameters are invalid */
	}

	/* get the current room, based on the user state */
	currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* check if the player is in a room that is flooded */
	/* if the room is not flooded, allow the player to breath */
	if (!Room_GetFlooded(currentRoom))
	{
		/*Set the players oxygen to 2*/
		SetPlayerBreathe(playerState, 2);
		printf("You take a deep breath, refreshing your oxygen\n");
	}
	else
	{
		/*dont allow the player to breath*/
		printf("You can't breathe in a flooded room!\n");
	}

	
}