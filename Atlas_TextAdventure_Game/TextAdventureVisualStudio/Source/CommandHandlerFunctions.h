/******************************************************************************
filename    CommandHandlerFunctions.h
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the various user commands
which are already implemented in the library

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct PlayerState PlayerState;
typedef struct WorldData WorldData;


/* Handles the "help" command, whic outputs a list of available verbs */
void HandleHelpCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "quit" command, which immediately exits the game */
void HandleQuitCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "go" command, which moves the user to another room */
void HandleGoCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "drop" user command, which drops an item in inventory to the current room.*/
void HandleDropCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "inventory" command, which outputs a list of the items in the player's inventory */
void HandleInventoryCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "look" command, which outputs a description of an item or the current room */
void HandleLookCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "take" command, which removes an item from the current room and adds it to the user's inventory */
void HandleTakeCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the "use" command, which calls an item-specific function on a given item */
void HandleUseCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* TODO ADVANCED: create aditional commands (add handler function declarations here)
   this may require the creation of additional .c files to implement the command functions */

/* Handles the "read" command, which calls a function upon an item to read what is hidden within (add score points) */
void HandleReadCommand(CommandData* command, GameState* gameState, WorldData* worldData, PlayerState *playerState);

/* Handles the "toggle" command, which will invert the flood level of other rooms*/
void HandleToggleCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);

/* Handles the breath command, which refills the players oxygen */
void HandleBreathCommand(CommandData* command, GameState *gameState, WorldData *worldData, PlayerState *playerState);
