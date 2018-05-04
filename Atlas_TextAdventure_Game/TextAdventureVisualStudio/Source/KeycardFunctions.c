/******************************************************************************
filename    NotesFunctions.c
author      Nicole Smith


Brief Description:
This file defines the functions to create a specific item, the "keycard".

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "KeycardFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "GameState.h"
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the notes are taken. */
void Keycard_Take(CommandContext context, GameState* gameState, WorldData* worldData, PlayerState *playerState)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the note might be used, whenever it is picked up. */
	printf("You grab the small keycard.\n");
}


/* Helper: The action performed when the note is used. */
void Keycard_Hydro_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* keyCard; /* The keycard in the player's inventory */

				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the keycard - inform the user of the problem and take no action */
		printf("You must have the keycard before you can use it.\n");
		return;
	}
	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the keycard here.\n");
		return;
	}

	/* check if the door has already been open */
	if (GameFlags_IsInList(gameState->gameFlags, "hydroKeycardUsed"))
	{
		/* the player already used the keycard - inform the user of the problem and take no action */
		printf("You already used the keycard here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the keycard in the player's inventory - it should be there, since we are in the Inventory context */
		keyCard = ItemList_FindItem(gameState->inventory, "hydroponic keycard");

		/* Remove the brick from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, keyCard);

		/* Tell the user what they did */
		printf("You press the keycard to the reader and open the door to the Hydroponic sector.\n");

		
		/*flag that door is open */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "hydroKeycardUsed");
	}

}

/* Helper: The action performed when the note is used. */
void Keycard_Bay_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* keyCard; /* The keycard in the player's inventory */

				   /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the keycard - inform the user of the problem and take no action */
		printf("You must have the keycard before you can use it.\n");
		return;
	}
	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the keycard here.\n");
		return;
	}

	/* check if the door has already been open*/
	if (GameFlags_IsInList(gameState->gameFlags, "bayKeycardUsed"))
	{
		/* the player already used the keycard - inform the user of the problem and take no action */
		printf("You already used the keycard here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the keycard in the player's inventory - it should be there, since we are in the Inventory context */
		keyCard = ItemList_FindItem(gameState->inventory, "bay keycard");

		/* Remove the brick from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, keyCard);

		/* Tell the user what they did */
		printf("You press the keycard to the reader and open the door to the Submersible Bay sector.  Your heart begins to race.\n");

		/* flag that door is open*/
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "bayKeycardUsed");
	}

}


/* Build a "notes" object */
Item* Keycard_Build(int i)
{
	/* Create a "keycard" item, using the functions defined in this file */
	/*makes the item based on which keycard is being made*/
	if (i == 1)
	{
		return Item_Create("hydro keycard", "A keycard to the Hydroponic sector", true, Keycard_Hydro_Use, Keycard_Take, NULL);
	}
	else if (i == 2)
	{
		return Item_Create("bay keycard", "A keycard to the Submersible Bay sector", true, Keycard_Bay_Use, Keycard_Take, NULL);
	}

	return NULL;
}