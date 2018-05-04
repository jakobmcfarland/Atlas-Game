/*****
SwitchFunctions.c
by: Jakob McFarland
last edited: 5/1/2018
brief: defines the functions used to create switches, untakeable items contained 
within levels that be toggled with the toggle command to flood/unflood rooms.

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/
#include "stdafx.h"
#include "SwitchFunctions.h"
#include "Room.h"
#include "Item.h"
#include "WorldData.h"

typedef struct WorldData WorldData;

/* Helper: The action performed when the switch is toggled. */
void SwitchPanel_toggle(WorldData *worldData, int indexs[])
{
	Room* currentRoom; /* the room we are currently modifying */
	int i;

	/*printf("DEBUG: SwitchPanel_toggle Called \n");*/

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	/*UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);*/

	/* safety check on the parameters */
	if (indexs == NULL)
	{
		/*printf("DEBUG: indexs/size is Null\n");*/
		return; /* take no action if the parameters are invalid */
	}

	/*invert all rooms at the supplied indexs*/
	for (i = 0; i < SWITCH_INDEXS_SIZE; ++i)
	{
		/*printf("DEBUG: %i Index %i \n", indexs[i], i);*/
		currentRoom = WorldData_GetRoom(worldData, indexs[i]);
		Room_SetFlooded(currentRoom, !Room_GetFlooded(currentRoom));
		if (indexs[i] != -1)
		{
			/* printf("Flooded get %i\n", Room_GetFlooded(currentRoom)); */
			if (Room_GetFlooded(currentRoom))
			{
				printf("Room %i has been flooded!\n", indexs[i]);
			}
			else
			{
				printf("Room %i has been drained!\n", indexs[i]);
			}
		}
	}
}

/* Build a "SwitchPanel" object */
Item* SwitchPanel_Build(int indexs[])
{
	Item * switchItem;

	/* Create a "switch  panel" item, using the functions defined in this file */
	switchItem = Item_Create("lever", "A section of wall panel housing a large, yellow lever imbedded within a shallow cavity.\n", false, NULL, NULL, NULL);
	
	Item_SetOtherFunc(switchItem, NULL, SwitchPanel_toggle);
	Item_SetIndexs(switchItem, indexs);
	/*printf("DEBUG: Get Indexs %i\n", (Item_GetIndexs(switchItem))[0]);*/

	return switchItem;
}