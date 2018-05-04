/**
DoorFunctions.h
Jessica Gramer
2018.5.2
This is for the functions of the doors

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
**/

#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "ExitDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "WorldData.h" /* WorldData_GetRoom */
#include "GameFlags.h"
#include "Room.h"

/* Helper: The action performed when the exit door is used. */
void BayDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData, PlayerState *playerState)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);

	Room * room = WorldData_GetRoom(worldData, gameState->currentRoomIndex); /* Create a room for the ability to add exits and remove the door item */
	ItemList ** itemlist; /* An item list to remove the door item */
	

	/* Check the player inventory, and check to see if the key has been used */
	if (GameFlags_IsInList(gameState->gameFlags, "bayKeycardUsed"))
	{
		/* Add room exits */
		Room_AddRoomExit(room, "bay door", 19);

		/* Add room exit shortcuts */
		Room_AddRoomExitShortcut(room, "north", 19);
		Room_AddRoomExitShortcut(room, "n", 19);
		Room_AddRoomExitShortcut(room, "bay", 19);

		/* Tell the player what happened */
		printf("You open the door.\n");

		/* Remove the door item after adding the exits */
		/* Find the room list */
		itemlist = Room_GetItemList(room);

		/* Remove item and set list start to be the returned pointer */
		*itemlist = ItemList_Remove(*itemlist, ItemList_FindItem(*itemlist, "bay door"));

		/* Add to the user's score */
		GameState_ChangeScore(gameState, 5);
	}
	else
	{
		/* Warn the user that they need to find and use the keycards */
		printf("You need to use the keycard.\n");
	}
}

/* Helper: The action performed when the exit door is used. */
void HydroDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData, PlayerState *playerState)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);

	Room * room = WorldData_GetRoom(worldData, gameState->currentRoomIndex); /* Create a room for the ability to add exits and remove the current item */
	ItemList ** itemlist; /* An item list to remove the door item */


	/* Check the player inventory, and check to see if the key has been used */
	if (GameFlags_IsInList(gameState->gameFlags, "hydroKeycardUsed"))
	{
		/* Add room exits */
		Room_AddRoomExit(room, "hydro door", 11);

		/* Add room exit shortcuts */
		Room_AddRoomExitShortcut(room, "east", 11);
		Room_AddRoomExitShortcut(room, "e", 11);
		Room_AddRoomExitShortcut(room, "hydro", 11);

		/* Tell the player what happened */
		printf("You open the door.\n");

		/* Remove the door item after adding the exits */
		/* Find the room list */
		itemlist = Room_GetItemList(room);

		/* Remove item and set list start to be the returned pointer */
		*itemlist = ItemList_Remove(*itemlist, ItemList_FindItem(*itemlist, "hydro door"));

		/* Add to the user's score */
		GameState_ChangeScore(gameState, 5);
	}
	else
	{
		/* Warn the user that they need to find and use the keycards */
		printf("You need to use the keycard.\n");
	}
}

/* Build a "door" object */
Item* Door_Build(int num)
{
	Item *item = NULL;

	switch (num)
	{
	case 1:
		/* Create a "bay door" item, using the functions defined in this file */
		item = Item_Create("bay door", "This door goes north, it seems locked.\n", false, BayDoor_Use, NULL, NULL);
		break;
	case 2:
		/* Create a "hydor door" item, using the functions defined in this file */
		item = Item_Create("hydro door", "This door goes east, it seems locked.\n", false, HydroDoor_Use, NULL, NULL);
		break;
	default:
		/* Debug in case of changes */
		printf("There was an error in creating a door because the number %i doesn't belong to a door.\n", num);
		return NULL;
	}

	return item;
}