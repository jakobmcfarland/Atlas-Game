/******************************************************************************
filename    Item.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the Item interface, which is used to manage items in the game.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#pragma once
#define SWITCH_INDEXS_SIZE 3

#include "stdafx.h" /* bool */
#include "CommandContext.h" /* enum CommandContext */

typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Forward declaration for the Item type */
typedef struct Item Item;

/* The function pointer type for item-operation functions */
typedef void(*ItemFunc)(CommandContext context, GameState* gameState, WorldData* worldData);
/* toggle function pointer */
typedef void(*ToggleFunc)(WorldData *worldData, int indexs[]);


/* Create a new Item object with the provided data */
Item* Item_Create(const char* name, const char* description, bool isCarryable, ItemFunc useFunc, ItemFunc takeFunc, ItemFunc dropFunc);

/* Free the memory associated with a given Item object */
void Item_Free(Item** itemPtr);

/* Retrieve the name of the given item */
const char* Item_GetName(Item* item);

/* Retrieve the description of the given item */
const char* Item_GetDescription(Item* item);

/* Retrieve whether the item is carryable */
bool Item_IsCarryable(Item* item);

/* Retrieve the "use" function for this item, if any */
ItemFunc Item_GetUseFunc(Item* item);

/* Retrieve the "take" function for this item, if any */
ItemFunc Item_GetTakeFunc(Item* item);

/* Retrieve the "drop" function for this item, if any */
ItemFunc Item_GetDropFunc(Item* item);

/* Retrieve the "read" function for this item, if any */
ItemFunc Item_GetReadFunc(Item* item);

/* Retrieve the "toggle" function for this item, if any */
ToggleFunc Item_GetToggleFunc(Item* item);

/* Print a description of the item to standard output */
void Item_Print(Item* item);

/* Retrieve the indexs value for this item, if any */
int * Item_GetIndexs(Item* item);

/* Set the indexs value for this item, if any */
void Item_SetIndexs(Item* item, int indexs[]);

/* Set the size value for this item, if any */
void Item_SetOtherFunc(Item* item, ItemFunc func, ToggleFunc toggleFunc);