/******************************************************************************
filename    InputProvider.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions related to user input.

All content © 2018 DigiPen (USA) Corporation, all rights reserved
******************************************************************************/
#pragma once

/* typedef for CommandData */
typedef struct CommandData CommandData;


/* GetInputFunc is the function pointer type for functions that get command strings */
typedef void(*GetInputFunc)(char* dest, int destLength);

/* Return the default input function */
GetInputFunc GetDefaultInputFunc();

/* Parse input provided via the given function into a verb and noun */
void ParseCommand(GetInputFunc inputFunc, CommandData* command);