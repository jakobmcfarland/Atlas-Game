/******************************************************************************
filename    ReadCommandHandler.c
author      Jessica Gramer

Brief Description:
This file defines functions that handle the "read" user command, which calls
the note-specific function on a given item

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "CommandHandlerFunctions.h" /* Function Declaration */
#include "CommandData.h" /* Gamestate */
#include "GameState.h" /* struct GameState */
#include "Item.h" /* Item_Print */
#include "ItemList.h" /* ItemList_FindItem */

/* Handles the "read" command, which calls an item-specific function on a given item */
void HandleReadCommand(CommandData* command, GameState* gameState, WorldData* worldData, PlayerState *playerState)
{
	UNREFERENCED_PARAMETER(playerState);

	Item* usedItem; /* the item to be read */
	ItemFunc readFunc; /* The function to be called for the given item when it is used */
	CommandContext readContext = CommandContext_Item_Inventory; /* the context used for the "use" function*/

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL) || (playerState == NULL))
	{
		return;  /* take no action if the parameters are invalid */
	}

	/* search for the item in the user's inventory, which takes precedence over the current room */
	usedItem = ItemList_FindItem(gameState->inventory, command->noun);
	if (usedItem != NULL);
	else
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not have a %s.\n", command->noun);
		return;
	}

	/* get the "use" function for this item, if any */
	readFunc = Item_GetReadFunc(usedItem);
	if (readFunc == NULL)
	{
		/* no "use" function was defined, so the item cannot be read - inform the user of the problem and take no action*/
		printf("You cannot read a %s.\n", command->noun);
		return;
	}

	/* call the "read" function with the appropriate context */
	readFunc(readContext, gameState, worldData);

}