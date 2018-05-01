/******************************************************************************
filename    Room.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the Room interface, which is used to manage rooms in the game.

******************************************************************************/
#pragma once
#include "stdafx.h" /* bool */

typedef struct ItemList ItemList;


/* Forward declaration of the Room type */
typedef struct Room Room;


/* Forward declaration of the PlayerState type */
typedef struct PlayerState PlayerState;

/* Forward declaration of the GameState type */
typedef struct GameState GameState;

/* Create an Room object with the provided data */
Room* Room_Create(const char* description);

/* Free the memory associated with the given room */
void Room_Free(Room** roomPtr);

/* Get a reference to the item list in the given room */
ItemList** Room_GetItemList(Room* room);

/* Get the room index in the direction specified from the given room */
bool Room_GetNextRoomIndex(Room *room, const char* direction, int* outNextRoomIndex); 

/* Add an exit to the given room */
void Room_AddRoomExit(Room* room, const char* direction, int nextRoomIndex);

/* Add an exit to the given room */
void Room_AddRoomExitShortcut(Room* room, const char* direction, int nextRoomIndex);

/* Replace the description on the given room */
void Room_SetDescription(Room* room, const char* description);

/* Print the description of the given room to standard output */
void Room_Print(Room *room);

/* Set the flooded value of a room*/
void Room_Flooded(Room *room, bool flooded);

/* if the room is flooded, then remove one breathe from the playerState */
void HandleFloodedRoom(PlayerState* playerState, GameState* gameState, Room* room);

/* Helper: Prints the a warning if the room is flooded */
void PrintRoomFlooded(Room *room);