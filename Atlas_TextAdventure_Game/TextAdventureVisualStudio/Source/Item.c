/******************************************************************************
filename    Item.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Item interface, which is used to manage items in the game.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#include "stdafx.h" /* NULL, printf, malloc/free, strcpy_s */
#include "Item.h" /* Function declarations */


/* the maximum length of an item's name */
#define MAX_ITEM_NAME_LENGTH 16 

/* the maximum length of an item's description */
#define MAX_ITEM_DESCRIPTION_LENGTH 128


/* An item in the game */
typedef struct Item
{
	char name[MAX_ITEM_NAME_LENGTH];	/* the name of the item, used for noun matching */
	char description[MAX_ITEM_DESCRIPTION_LENGTH];	/* a description of the item */
	bool isCarryable;	/* if true, the item can be put in the user's inventory*/
	ItemFunc useFunc;	/* a function called when the user uses this item, if any */
	ItemFunc takeFunc;	/* a function called when the user takes this item, if any */
	ItemFunc dropFunc;	/* a function called when the user uses this item, if any */
	ToggleFunc toggleFunc;	/* a function called when the user toggles this item, if any */
	ItemFunc readFunc;	/* a function called when the user reads this item, if any */
	int indexs[SWITCH_INDEXS_SIZE];
} Item;


/* Create a new Item object with the provided data */
Item* Item_Create(const char* name, const char* description, bool isCarryable, ItemFunc useFunc, ItemFunc takeFunc, ItemFunc dropFunc)
{
	Item *item; /* the new item to be returned */

	/* safety check on required parameters */
	if (name == NULL) 
	{
		return NULL; /* do not create a new object if the parameters are invalid*/
	}

	/* allocate the memory for a new object */
	item = (Item*)malloc(sizeof(Item));
	if (item == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* copy the data from the parameters into the new object */
	strcpy_s(item->name, MAX_ITEM_NAME_LENGTH, name);
	if (description != NULL)
	{
		strcpy_s(item->description, MAX_ITEM_DESCRIPTION_LENGTH, description);
	}
	item->isCarryable = isCarryable;
	item->useFunc = useFunc;
	item->takeFunc = takeFunc;
	item->dropFunc = dropFunc;
	item->toggleFunc = NULL;
	item->readFunc = NULL;

	/* return the new object */
	return item;
}


/* Free the memory associated with a given Item object */
void Item_Free(Item** itemPtr)
{
	/* safety check on the parameters */
	if ((itemPtr == NULL) || (*itemPtr == NULL)) 
	{
		return;  /* take no action if the parameters are invalid */
	}

	/* free the given item */
	free(*itemPtr);
	
	/* clear the provided pointer */
	*itemPtr = NULL;
}


/* Retrieve the name of the given item */
const char* Item_GetName(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->name : NULL;
}


/* Retrieve the description of the given item */
const char* Item_GetDescription(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->description : NULL;
}


/* Retrieve whether the item is carryable */
bool Item_IsCarryable(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return false (not carryable) */
	return (item != NULL) ? item->isCarryable : false;
}


/* Retrieve the "use" function for this item, if any */
ItemFunc Item_GetUseFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->useFunc : NULL;
}

/* Retrieve the "take" function for this item, if any */
ItemFunc Item_GetTakeFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->takeFunc : NULL;
}


/* Retrieve the "drop" function for this item, if any */
ItemFunc Item_GetDropFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->dropFunc : NULL;
}

/* Retrieve the "read" function for this item, if any */
ItemFunc Item_GetReadFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->readFunc : NULL;
}

/* Retrieve the "toggle" function for this item, if any */
ToggleFunc Item_GetToggleFunc(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (item != NULL) ? item->toggleFunc : NULL;
}

/* Print a description of the item to standard output */
void Item_Print(Item* item)
{
	const char* description; /* the description of the provided item */

	/* safety check on the parameters */
	if (item == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}
	
	/* get the current description */
	description = Item_GetDescription(item);
	if ((description != NULL) && (strnlen_s(description, MAX_ITEM_DESCRIPTION_LENGTH) > 0))
	{
		/* the item has a non-trival description - output it */
		printf("%s\n", description);
		return;
	}

	/* the item had no useful description, so output its name instead*/
	description = Item_GetName(item);
	printf("You see a %s.\n", description);
}

/* Retrieve the indexs value for this item, if any */
int * Item_GetIndexs(Item* item)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	if (item != NULL)
	{
		/*printf("DEBUG: get Indexs: First %i\n", (item->indexs)[0]);*/
		return item->indexs;
	}

	return NULL;
	
}

/* Set the indexs value for this item, if any */
void Item_SetIndexs(Item* item, int indexs[])
{
	int i;

	if ((item != NULL) && (indexs != NULL))
	{
		/*printf("DEBUG: set Indexs: First %i\n", indexs[0]);*/
		for (i = 0; i < SWITCH_INDEXS_SIZE; ++i)
		{
			item->indexs[i] = indexs[i];

		}
	}
	return;
}

/* Set the alternate functions */
void Item_SetOtherFunc(Item* item, ItemFunc func, ToggleFunc toggleFunc)
{
	if ((item != NULL) && (toggleFunc != NULL))
	{
		item->toggleFunc = toggleFunc;
	}
	if ((item != NULL) && (func != NULL))
	{
		item->readFunc = func;
	}

	return;
}


