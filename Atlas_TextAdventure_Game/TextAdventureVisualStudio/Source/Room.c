/******************************************************************************
filename    Room.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Room interface, which is used to manage rooms in the game.

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* NULL, malloc/free, printf, strcpy_s */
#include "Room.h" /* Function declarations */
#include "GameState.h" /* GameState */
#include "PlayerState.h" /* getPLayerBreathe */
#include "WorldData.h" /* WorldData */
#include "RoomExit.h" /* RoomExit_Add, RoomExit_Free, RoomExit_Print */
#include "ItemList.h" /* ItemList_Free, ItemList_Print */
#include "GameState.h"


/* The maximum length of a room description string */
#define MAX_ROOM_DESCRIPTION_LENGTH 256


/* A room in the game */
typedef struct Room
{
	char description[MAX_ROOM_DESCRIPTION_LENGTH]; /* The description of the room */
	ItemList* itemList; /* A list of items in the room */
	RoomExit* roomExitHead; /* A list of exits from the room */
	bool Flooded;  /*  Flooded boolean value, interacts with player's breath*/
} Room;


/* Helper: Print the list of items in a room */
void PrintRoomItems(ItemList *itemList);

/* Helper: Print the list of exits from a room */
void PrintRoomExits(RoomExit* roomExitList);


/* Create an Room object with the provided data */
Room* Room_Create(const char* description)
{
	Room *room; /* the new room object */
	
	/* allocate the memory for the new object */
	room = (Room*)malloc(sizeof(Room));
	if (room == NULL)
	{
		/*DEBUG: prints if room is null -Jakob*/
		printf("malloc failed\n");
		return NULL; /* malloc can fail! */
	}

	/* copy the data from the parameters to the new object */
	Room_SetDescription(room, description);

	/* initialize the new room's list pointers to NULL */
	room->itemList = NULL;
	room->roomExitHead = NULL;
	
	/* return the new Room object */
	return room;
}


/* Free the memory associated with the given room */
void Room_Free(Room** roomPtr)
{
	/* safety check on the parameters */
	if ((roomPtr == NULL) || (*roomPtr == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* free the item list in the room */
	ItemList_Free(&(*roomPtr)->itemList);

	/* free the room-exit list in the room */
	RoomExit_Free(&(*roomPtr)->roomExitHead);

	/* free the room object iteself */
	free(*roomPtr);

	/* clear the provided pointer*/
	*roomPtr = NULL;
}


/* Get a reference to the item list in the given room */
ItemList** Room_GetItemList(Room* room)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (room != NULL) ? &(room->itemList) : NULL;
}


/* Get the room index in the direction specified from the given room */
bool Room_GetNextRoomIndex(Room *room, const char* direction, int* outNextRoomIndex)
{
	/* safety check on the parameters */
	if (room == NULL) 
	{
		return false; /* return false if the parameters are invalid, since we can't perform the search */
	}

	return RoomExit_Find(room->roomExitHead, direction, outNextRoomIndex);
}


/* Add an exit to the given room */
void Room_AddRoomExit(Room* room, const char* direction, int nextRoomIndex)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* update the room's exit list with the new head */
	room->roomExitHead = RoomExit_Add(room->roomExitHead, direction, nextRoomIndex, true);
}


/* Add an exit to the given room, but don't display it in any printed help */
void Room_AddRoomExitShortcut(Room* room, const char* direction, int nextRoomIndex)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* update the room's exit list with the new head */
	room->roomExitHead = RoomExit_Add(room->roomExitHead, direction, nextRoomIndex, false);
}


/* Replace the description on the given room */
void Room_SetDescription(Room* room, const char* description)
{
	/* safety check on the parameters */
	if ((room == NULL) || (description == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* copy the parameter data into the given object */
	strcpy_s(room->description, MAX_ROOM_DESCRIPTION_LENGTH, description);
}


/* Print the description of the given room to standard output */
void Room_Print(Room *room, GameState* gameState, WorldData* worldData)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return;  /* take no action if the parameters are invalid */
	}

	/* print the room description */
	printf(room->description);

	/* print the set of items in the room */
	PrintRoomItems(room->itemList);

	/* print the set of exits in the given room */
	PrintRoomExits(room->roomExitHead);

	/* Helper: Prints the a warning if the room is flooded */
	PrintRoomFlooded(room);

	PrintFloodedRooms(gameState, worldData);
}


/* Helper: Print the list of items in a room */
void PrintRoomItems(ItemList *itemList)
{
	/* safety check on the parameters */
	if (itemList == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* print a header for the list */
	printf("In this room, you see: ");

	/* print the list itself */
	ItemList_Print(itemList);

	printf(".\n");
}


/* Helper: Print the list of exits from a room */
void PrintRoomExits(RoomExit* roomExitList)
{
	/* safety check on the parameters */
	if (roomExitList == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* print a header for the list */
	printf("Exits are: ");

	/* print the list itself */
	RoomExit_Print(roomExitList);

	printf(".\n");
}

/*****
Functions below here.
by: Jakob McFarland
last edited: 5/1/2018
brief: functions that handle the flood logic for rooms
All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/


/* Set the flooded value of a room*/
void Room_SetFlooded(Room *room, bool flooded)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		/*printf("DEBUG: Room is Null\n");*/
		return;  /* take no action if the parameters are invalid */
	}

	/*printf("DEBUG: Flooded Got %i\n", flooded);*/

	room->Flooded = flooded;

	/*printf("DEBUG: Flooded set %i\n", room->Flooded);*/
}

/* Get the flooded value of a room*/
bool Room_GetFlooded(Room *room)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		/*printf("DEBUG: Room is Null\n");*/
		return 0;  /* take no action if the parameters are invalid */
	}

	/*printf("DEBUG: Flooded Got %i\n", room->Flooded);*/

	return room->Flooded;
}

/* Helper: Prints the a warning if the room is flooded */
void PrintRoomFlooded(Room *room)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if room is flooded*/
	if (room->Flooded)
	{
		/* print warning if the room is flooded */
		printf("Warning: The Room is Flooded!\n");
	}
}

/* sets the current amount of breathe */
void HandleFloodedRoom(PlayerState* playerState, GameState* gameState, Room* room)
{
	/* safety check on the parameters */
	if ((playerState == NULL) || (room == NULL))
	{
		return; /* take no action if no valid object was provided */
	}
	
	/* if the room is flooded, then remove one breathe from the playerState */
	if (room->Flooded)
	{
		/*printf("DEBUG: breathe at %i\n", GetPlayerBreathe(playerState));*/
		printf("Alert: You've lost oxygen!\n");
		SetPlayerBreathe(playerState, GetPlayerBreathe(playerState) - 1);
	}

	/* if the player's breathe is zero*/
	if (GetPlayerBreathe(playerState) <= 0)
	{
		/* end the game using the death exit message */
		GameState_EndGame(gameState, "You have drowned.\n");
	}
}

/* Handles the "go" command, which moves the user to another room */
void PrintFloodedRooms(GameState *gameState, WorldData *worldData)
{
	Room* currentRoom; /* the room we are currently in */
	int * nextRoomIndex = 0;
	int total = 0;
					   /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		/*DEBUG: prints if room is invalid -Jakob*/
		printf("invalid\n");
		return; /* take no action if the parameters are invalid */
	}

	/* get the current room, based on the user state */
	currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* check through all the exits in all directions*/
	nextRoomIndex = RoomExit_Find(currentRoom->roomExitHead, "north", nextRoomIndex);
	/*printf("%i\n", nextRoomIndex);*/
	if (Room_GetFlooded(WorldData_GetRoom(worldData, nextRoomIndex)))
	{
		/*puts("The room to the north is flooded");*/
		++total;
	}
	nextRoomIndex = RoomExit_Find(currentRoom->roomExitHead, "west", nextRoomIndex);
	/*printf("%i\n", nextRoomIndex);*/
	if (Room_GetFlooded(WorldData_GetRoom(worldData, nextRoomIndex)))
	{
		/*puts("The room to the west is flooded");*/
		++total;
	}
	nextRoomIndex = RoomExit_Find(currentRoom->roomExitHead, "east", nextRoomIndex);
	/*printf("%i\n", nextRoomIndex);*/
	if (Room_GetFlooded(WorldData_GetRoom(worldData, nextRoomIndex)))
	{
		/*puts("The room to the east is flooded");*/
		++total;
	}
	nextRoomIndex = RoomExit_Find(currentRoom->roomExitHead, "south", nextRoomIndex);
	/*printf("%i\n", nextRoomIndex);*/
	if (Room_GetFlooded(WorldData_GetRoom(worldData, nextRoomIndex)))
	{
		/*puts("The room to the south is flooded");*/
		++total;
	}

	/* output the successful action */
	/*printf("There are %i adjacent flooded rooms.\n", total);*/
}