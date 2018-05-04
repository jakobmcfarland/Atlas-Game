/******************************************************************************
filename    CommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the command handler, which parses commands and executing functions.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct PlayerState PlayerState;
typedef struct WorldData WorldData;

/* Handles the command data and executes it against the game and world state */
void HandleCommand(CommandData* command, GameState *gameState, WorldData* worldData, PlayerState *playerState);