/******************************************************************************
filename    InventoryCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "inventory" user command, which outputs
a list of the items in the player's inventory.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "inventory" command, which outputs a list of the items in the player's inventory */
void HandleInventoryCommand(CommandData* command, GameState *gameState, WorldData *worldData);