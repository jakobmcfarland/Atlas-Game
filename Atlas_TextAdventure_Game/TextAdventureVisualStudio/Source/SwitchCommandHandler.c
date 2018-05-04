/*****
SwitchCommandHandler.h
by: Jakob McFarland
last edited: 5/1/2018
brief: File that defines the "toggle" command, which will invert the flood level of other rooms
All content © 2018 DigiPen (USA) Corporation, all rights reserved.

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

#include "stdafx.h" /* NULL, printf */
#include "CommandHandlerFunctions.h" /* Function Declaration */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Add, ItemList_Remove */
#include "Item.h" /* Item_IsCarryable, ItemFunc, Item_GetTakeFunc */

/* Handles the "toggle" command, which will invert the flood level of other rooms*/
void HandleToggleCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState)
{
	UNREFERENCED_PARAMETER(playerState);

	Item* toggleItem; /* the item from the room that is being toggled */
	Room* room; /* the current room */
	ItemList** roomItemPtr; /* the list of items in the current room */
	ToggleFunc toggleFunc; /* The function to be called for the given item when it is toggled */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL) || (playerState == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* retrieve the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* get the current room's item list */
	roomItemPtr = Room_GetItemList(room);
	if (roomItemPtr == NULL)
	{
		return; /* there was no room or item list pointer - something is wrong.  take no action */
	}

	/* find the item in the current room's item list, using the command noun */
	toggleItem = ItemList_FindItem(*roomItemPtr, command->noun);
	if (toggleItem == NULL)
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not see a %s here.\n", command->noun);
		return;
	}

	/* get the "take" function for this item, if any (it is optional) */
	toggleFunc = Item_GetToggleFunc(toggleItem);
	if (toggleFunc != NULL)
	{
		/* inform the user of the successful action */
		printf("You have toggled the %s.\n", command->noun);

		/*printf("DEBUG: toggleFunc got\n");*/
		/* call the take function with the Room context, since that's where the item was */
		/* inform the user of the successful action */
		printf("You have toggled the %s.\n", command->noun);
		toggleFunc(worldData, Item_GetIndexs(toggleItem));
	}
	else
	{
		/* inform the user of the failed action */
		printf("You cannot toggle the %s.\n", command->noun);
	}

}