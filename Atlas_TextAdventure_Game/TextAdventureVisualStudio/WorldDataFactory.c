/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	/* Return the new room */
	return room;
}


/* TODO: Build all rooms */
Room* Room0_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "west", 1);

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, true);

	return room;
}

Room* Room1_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, true);

	return room;
}

Room* Room2_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room3_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room4_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room5_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room6_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room7_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room8_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room9_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room10_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room11_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	return room;
}

Room* Room12_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room13_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room14_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room15_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room16_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room17_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room18_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room19_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room20_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room21_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room22_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}

Room* Room23_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_Flooded(room, false);

	return room;
}


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 2;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());

	WorldData_SetRoom(worldData, 1, Room1_Build());

	/* TODO: add all rooms to the world data */

	/* return the new object */
	return worldData;
}