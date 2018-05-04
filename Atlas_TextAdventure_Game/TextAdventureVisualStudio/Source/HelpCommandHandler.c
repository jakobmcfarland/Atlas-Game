/******************************************************************************
filename    HelpCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "help" user command, which outputs
a list of the available verbs.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER */
#include "CommandHandlerFunctions.h" /* Function Declaration */
#include "CommandList.h" /* CommandList_Print */
#include "CommandData.h" /* struct CommandData */


/* Handles the "help" command, which outputs a list of available verbs */
void HandleHelpCommand(CommandData *command, GameState *gameState, WorldData *worldData, PlayerState *playerState)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	UNREFERENCED_PARAMETER(playerState);

	/* output the command list */
	CommandList_Print(command->commandList);
}