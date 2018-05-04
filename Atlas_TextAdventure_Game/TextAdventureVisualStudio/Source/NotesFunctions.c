/******************************************************************************
filename    NotesFunctions.c
author      Nicole Smith and Max van de Kamp


Brief Description:
This file defines the functions to create a specific item, the "Notes".

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "NotesFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the notes are taken. */
void Notes_Take(CommandContext context, GameState* gameState, WorldData* worldData, PlayerState *playerState)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the note might be used, whenever it is picked up. */
	printf("You grab the note and stuff it away.\n");

	GameState_ChangeScore(gameState, 5);
}


/* Helper: The action performed when the note is used. */
void Notes_Read1(CommandContext context, GameState* gameState, WorldData* worldData)
{
				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the note - inform the user of the problem and take no action */
		printf("You must have a note before you can read it.\n");
		return;
	}
	else 
	{
		/*print message*/
		printf("September 12, 1962\nWell, we\'re finally here. The facility is finally complete and we can get to work. The US government has tasked us with creating a biological weapon to utilize against the growing Soviet threat. With the recently discovered toxins on the sea floor, I think we can exceed all expectations.\nSigned, Dr. Christian Payne\n");

		GameState_ChangeScore(gameState, 5);
	}

}

void Notes_Read2(CommandContext context, GameState* gameState, WorldData* worldData)
{
				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the note - inform the user of the problem and take no action */
		printf("You must have a note before you can read it.\n");
		return;
	}
	else
	{
		/*print message*/
		printf("October 7, 1962\nProgress on the bioweapon is exceeding all projections. The toxin has already been refined and causes catastrophic total organ failure when directly ingested. However, Dr. Li, who administered the toxin, seems to be experiencing some insomnia and nervous fidgeting. This is likely a coincidence, but we\'ll keep an eye on it.\nSigned, Dr. Christian Payne\n");

		GameState_ChangeScore(gameState, 5);
	}

}

void Notes_Read3(CommandContext context, GameState* gameState, WorldData* worldData)
{
				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the note - inform the user of the problem and take no action */
		printf("You must have a note before you can read it.\n");
		return;
	}
	else
	{
		/*print message*/
		printf("October 15, 1962\nDr. Li\'s condition continues to worsen. We are now forced to consider the high likelihood that close proximity to the toxin causes severe insomnia, loss of muscle control, and possibly insanity; All of which have been observed in Dr. Li. We\'ve quarantined the doctor but must continue pushing. Our part in the destruction of communism cannot be halted by the loss of one doctor\nSigned, Dr. Christian Payne\n");

		GameState_ChangeScore(gameState, 5);
	}

}

void Notes_Read4(CommandContext context, GameState* gameState, WorldData* worldData)
{
				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the note - inform the user of the problem and take no action */
		printf("You must have a note before you can read it.\n");
		return;
	}
	else
	{
		/*print message*/
		printf("October 19, 1962\nDr. Li has reached a point of complete insanity. Dr. White and Dr. Jacobs have both began to display the symptoms Li showed two weeks ago. We\'ve had to quarantine all of them in the southern portion of the research center. The crew is becoming worried, and they\'re not alone. It could just been the isolation, but I\'ve been hearing whispering voices in the back of my conscious. The crew cannot know. I must stand strong as their leader.\nSigned, Dr. Christian Payne\n");

		GameState_ChangeScore(gameState, 5);
	}

}

void Notes_Read5(CommandContext context, GameState* gameState, WorldData* worldData)
{
				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the note out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the note - inform the user of the problem and take no action */
		printf("You must have a note before you can read it.\n");
		return;
	}

	/*print message*/
	printf("October 28, 1962\nInsanity has taken it\'s hold on nearly all of the crew. Me and Dr. Smith have locked ourselves in the submersible bay. The whispering voices are now screaming. Not even sleep silences their tormented screams. Unending. Unrelenting. I know they will take over soon. Perhaps I will end it before it gets to that point. But we\'re a long way from heaven here, three miles below the surface. And awfully close to hell.\nSigned, Dr. Christian Payne\n");

	GameState_ChangeScore(gameState, 5);
	return;

}


/* Build a "notes" object */
Item* Notes_Build(int i)
{
	/* Create a "notes" item, using the functions defined in this file */
	/*makes the item based on which note is being made*/
	if (i == 1)
	{ 
		/* Create the item */
		Item* item = Item_Create("note 1", "Dr. Payne\'s notes", true, NULL, Notes_Take, NULL);

		/* Set the read function */
		Item_SetOtherFunc(item, Notes_Read1, false);

		/* Return the new item */
		return item;
	}
	else if(i == 2)
	{
		/* Create the item */
		Item* item = Item_Create("note 1", "Dr. Payne\'s notes", true, NULL, Notes_Take, NULL);

		/* Set the read function */
		Item_SetOtherFunc(item, Notes_Read1, NULL);

		/* Return the new item */
		return item;
	}
	else if (i == 3)
	{
		/* Create the item */
		Item* item = Item_Create("note 1", "Dr. Payne\'s notes", true, NULL, Notes_Take, NULL);

		/* Set the read function */
		Item_SetOtherFunc(item, Notes_Read1, NULL);

		/* Return the new item */
		return item;
	}
	else if (i == 4)
	{
		/* Create the item */
		Item* item = Item_Create("note 1", "Dr. Payne\'s notes", true, NULL, Notes_Take, NULL);

		/* Set the read function */
		Item_SetOtherFunc(item, Notes_Read1, NULL);

		/* Return the new item */
		return item;
	}
	else if (i == 5)
	{
		/* Create the item */
		Item* item = Item_Create("note 1", "Dr. Payne\'s notes", true, NULL, Notes_Take, NULL);

		/* Set the read function */
		Item_SetOtherFunc(item, Notes_Read1, NULL);

		/* Return the new item */
		return item;
	}
	return NULL;
}