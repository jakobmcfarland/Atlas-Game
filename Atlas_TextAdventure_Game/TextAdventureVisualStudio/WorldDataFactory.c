/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "Item.h" /*SWITCH_INDEXS_SIZE*/
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */
#include "SwitchFunctions.h" /* SwitchPanel_Build */
#include "DoorFunctions.h" /* Door_Build */
#include "KeycardFunctions.h" /* Keycard_Build */
#include "NotesFunctions.h" /* Notes_Build */



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
	Room_SetFlooded(room, false);

	/* Return the new room */
	return room;
}


/* TODO: Build all rooms */
Room* Room0_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("Blinding fluorescent light illuminates the facility\'s main hub. The only visual respite from the sterile environment comes in the form of a large glass dome making up the ceiling, inexplicably holding up the millions of gallons of black water above it. \n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	/* Room_AddRoomExit(room, "north", 19);
	Room_AddRoomExit(room, "east", 11); */
	Room_AddRoomExit(room, "west", 1);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "cheatcode404atlas", 23);
	Room_AddRoomExitShortcut(room, "w", 1);

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Door_Build(1));
	ItemList_AddItem(Room_GetItemList(room), Door_Build(2));


	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room1_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("The entrance to the research center is lit only by various flashing lights and blaring alarms. The only functioning monitor flashes a damning message:\"CRITICAL HULL FAILURE. HALLWAYS FLOODED\".\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 8);
	Room_AddRoomExit(room, "east", 0);
	Room_AddRoomExit(room, "west", 2);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 8);
	Room_AddRoomExitShortcut(room, "e", 0);
	Room_AddRoomExitShortcut(room, "w", 2);

	/* Items
	add items to the room */
	/* add note 1 to the room */
	ItemList_AddItem(Room_GetItemList(room), Notes_Build(1));

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room2_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("The research center hallway is pitch black, with no functioning electronics. The claustrophobic white walls seem to press closer with each second, and feels more like a coffin than a place of scientific discovery.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 3);
	Room_AddRoomExit(room, "east", 1);
	Room_AddRoomExit(room, "west", 4);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 3);
	Room_AddRoomExitShortcut(room, "e", 1);
	Room_AddRoomExitShortcut(room, "w", 4);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room3_Build()
{
	Room* room;
	int indexs[SWITCH_INDEXS_SIZE];

	/* Create the room
	include an initial room description */
	room = Room_Create("This room is filled with tanks and pumps, with thick steel pipes filling every open space. A control panel sits in the center of the room, featuring cracked pressure gauges, flashing warning lights, and one large lever marked \"Emergency liquid purge\".\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 2);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 2);

	/* Items
	add items to the room */
	indexs[0] = 2;
	indexs[1] = 4;
	indexs[2] = -1;
	ItemList_AddItem(Room_GetItemList(room), SwitchPanel_Build(indexs));

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room4_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This room is nothing but a mess of wires, shattered glass, and destroyed scientific equipment. Wall panels rest on the ground, exposing cables and controls, explaining the complete lack of functioning electronics.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 6);
	Room_AddRoomExit(room, "east", 2);
	Room_AddRoomExit(room, "west", 5);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 6);
	Room_AddRoomExitShortcut(room, "e", 2);
	Room_AddRoomExitShortcut(room, "w", 5);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room5_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This must be the main control hub of the research center. Every surface is covered in lights, switches, and screens. The few monitors still functioning confirm your suspicions that something went very wrong here with a plethora of warning messages.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 4);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "e", 4);

	/* Items
	add items to the room */
	/* add the keycard to the hydroponic area to room 5 */
	ItemList_AddItem(Room_GetItemList(room), Keycard_Build(1));


	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room6_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("Flickering lights illuminate a grotesque landscape: a black, tar-like substance covers much of the room. Cages line the wall, each containing the same disturbing reality, an unmoving primate covered in cysts, with dried foam cresting each one\'s lips.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 4);
	Room_AddRoomExit(room, "south", 7);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 4);
	Room_AddRoomExitShortcut(room, "s", 7);

	/* Items
	add items to the room */
	/* add the second note to the room */
	ItemList_AddItem(Room_GetItemList(room), Notes_Build(2));


	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room7_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This claustrophobic space is was clearly used for storage. The walls and floors are covered in various parts, scientific equipment, and samples.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 6);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 6);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room8_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This room contains racks of clothing and various types of protective gear, much of which seem to have been grabbed in a panicked haste, as various pieces of equipment are strewn across the space.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExit(room, "south", 9);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 1);
	Room_AddRoomExitShortcut(room, "s", 9);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room9_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This must have been where the researchers slept. Beds are built into indents in the walls, usually accompanied by cracked photos of families and loved ones. The malfunctioning lighting and bleak silence makes their smiles more unsettling than reassuring.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 8);
	Room_AddRoomExit(room, "east", 10);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 8);
	Room_AddRoomExitShortcut(room, "e", 10);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room10_Build()
{
	Room* room;
	int indexs[SWITCH_INDEXS_SIZE];

	/* Create the room
	include an initial room description */
	room = Room_Create("You enter another control room. Once again most things are not functioning, however, a large pneumonic steel lever maked \"purge hydroponic production lab liquid\" draws your attention.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "west", 9);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "w", 9);

	/* Items
	add items to the room */
	indexs[0] = 12;
	indexs[1] = 15;
	indexs[2] = -1;
	ItemList_AddItem(Room_GetItemList(room), SwitchPanel_Build(indexs));

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room11_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the entrance to the hydroponic growth facilities. It seems to be considerably less dilapidated than the research center, with the fluorescent lights still functioning properly and no damage to the wall or floor paneling.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 12);
	Room_AddRoomExit(room, "west", 0);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "e", 12);
	Room_AddRoomExitShortcut(room, "w", 0);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room12_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("Small chambers used for growing various plants line the walls. Most plants have been uprooted or are long dead. This facility\'s ability to sustain life has long since passed.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 13);
	Room_AddRoomExit(room, "east", 15);
	Room_AddRoomExit(room, "west", 11);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 13);
	Room_AddRoomExitShortcut(room, "e", 15);
	Room_AddRoomExitShortcut(room, "w", 11);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room13_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("You enter a small hallway. An inch of water blankets the floor of the otherwise pristine space, offering a soggy reminder of the disaster that has occurred here.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 12);
	Room_AddRoomExit(room, "south", 14);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 12);
	Room_AddRoomExitShortcut(room, "s", 14);

	/* Items
	add items to the room */
	/* add not 3 to the room */
	ItemList_AddItem(Room_GetItemList(room), Notes_Build(3));


	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room14_Build()
{
	Room* room;
	int indexs[SWITCH_INDEXS_SIZE];

	/* Create the room
	include an initial room description */
	room = Room_Create("This room is clearly the maintenance and control area for this section of the facility. You spot an important looking control panel amist the flashing lights and blaring alarms. It features a large steel lever marked \"purge research center liquid\".\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 13);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 13);

	/* Items
	add items to the room */
	indexs[0] = 8;
	indexs[1] = 9;
	indexs[2] = -1;
	ItemList_AddItem(Room_GetItemList(room), SwitchPanel_Build(indexs));

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room15_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("More growth chambers cover every square inch of this room. Mildew completely covers the walls, and strange, unidentified aquatic plants struggle to survive in their neglected hydroponic enclosures.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 16);
	Room_AddRoomExit(room, "west", 12);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "e", 16);
	Room_AddRoomExitShortcut(room, "w", 12);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room16_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("The walls of this room are covered in green aquatic growths, which have inexplicably grown despite a complete lack of light. You desperately wish to return to a room with light, and have to crawl on all fours to avoid slipping on the slick floors.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 17);
	Room_AddRoomExit(room, "south", 18);
	Room_AddRoomExit(room, "west", 15);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 17);
	Room_AddRoomExitShortcut(room, "s", 18);
	Room_AddRoomExitShortcut(room, "w", 15);

	/* Items
	add items to the room */
	/* add note 4 to the room */
	ItemList_AddItem(Room_GetItemList(room), Notes_Build(4));


	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room17_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This room seems like some kind of recreational facility. The weight machines and television viewing area would look inviting if it wasn\'t for exposed and malfunctioning wiring, static flatscreen, and algae-covered weights.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 16);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 16);

	/* Items
	add items to the room */
	/* add keycard to the submersible bay to room 16*/
	ItemList_AddItem(Room_GetItemList(room), Keycard_Build(2));


	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room18_Build()
{
	Room* room;
	int indexs[SWITCH_INDEXS_SIZE];

	/* Create the room
	include an initial room description */
	room = Room_Create("This control room is surprisingly functional, which somehow adds to the bleakness of your situation, as every monitor can successfully flash the damning error and warning messages. There is another large steel level in the center of the controls.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 16);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 16);

	/* Items
	add items to the room */
	indexs[0] = 20;
	indexs[1] = 21;
	indexs[2] = 22;
	ItemList_AddItem(Room_GetItemList(room), SwitchPanel_Build(indexs));

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room19_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("You walk into the entrance of the submersible bay. The yellow industrial striping lining the walls, along with blaring red alarms, gives you a feeling of being in a nuclear reactor mid meltdown. And perhaps you are. In some, twisted, metaphorical sense.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 21);
	Room_AddRoomExit(room, "south", 0);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 21);
	Room_AddRoomExitShortcut(room, "s", 0);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

	return room;
}

Room* Room20_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is some kind of control center for the Submersible expeditions into the deep ocean. Windows look out into the dark waters, offering a constant reminder of just how trapped and confined you are.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 21);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "e", 21);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room21_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("The room is dominated by three large fuel tanks. Pumps and tubing connect the tanks and walls, taking up much of the remaining space. Hopefully the submersibles are fueled, because the fueling control panel seems far from functional.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 19);
	Room_AddRoomExit(room, "east", 22);
	Room_AddRoomExit(room, "west", 20);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 19);
	Room_AddRoomExitShortcut(room, "e", 22);
	Room_AddRoomExitShortcut(room, "w", 20);

	/* Items
	add items to the room */
	/* add note 5 to the room */
	ItemList_AddItem(Room_GetItemList(room), Notes_Build(5));

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room22_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is likely where mechanical work is done on the submersibles, as lifts and tools occupy much of the room. You begin to pray the mechanics kept the submersibles functional before realizing no gods can hear you from the bottom of the Atlantic.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 23);
	Room_AddRoomExit(room, "west", 21);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "n", 23);
	Room_AddRoomExitShortcut(room, "w", 21);

	/* Items
	add items to the room */

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, true);

	return room;
}

Room* Room23_Build()
{
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("You finally reach the submersible staging area.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 22);

	/* Exit Shortcuts
	allows navigation between rooms */
	Room_AddRoomExitShortcut(room, "s", 22);

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/*  set the Flooded boolean value, interacts with player's breath*/
	Room_SetFlooded(room, false);

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
	int roomCount = 24;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to Oxygen:\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());
	WorldData_SetRoom(worldData, 4, Room4_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());
	WorldData_SetRoom(worldData, 6, Room6_Build());
	WorldData_SetRoom(worldData, 7, Room7_Build());
	WorldData_SetRoom(worldData, 8, Room8_Build());
	WorldData_SetRoom(worldData, 9, Room9_Build());
	WorldData_SetRoom(worldData, 10, Room10_Build());
	WorldData_SetRoom(worldData, 11, Room11_Build());
	WorldData_SetRoom(worldData, 12, Room12_Build());
	WorldData_SetRoom(worldData, 13, Room13_Build());
	WorldData_SetRoom(worldData, 14, Room14_Build());
	WorldData_SetRoom(worldData, 15, Room15_Build());
	WorldData_SetRoom(worldData, 16, Room16_Build());
	WorldData_SetRoom(worldData, 17, Room17_Build());
	WorldData_SetRoom(worldData, 18, Room18_Build());
	WorldData_SetRoom(worldData, 19, Room19_Build());
	WorldData_SetRoom(worldData, 20, Room20_Build());
	WorldData_SetRoom(worldData, 21, Room21_Build());
	WorldData_SetRoom(worldData, 22, Room22_Build());
	WorldData_SetRoom(worldData, 23, Room23_Build());

	/* return the new object */
	return worldData;
}