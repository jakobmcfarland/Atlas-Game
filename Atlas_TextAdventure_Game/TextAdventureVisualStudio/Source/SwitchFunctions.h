/*****
SwitchFunctions.h
by: Jakob McFarland
last edited: 5/1/2018
brief: header for SwitchFunctions.c
All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

#pragma once

typedef struct Item Item;
typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;
typedef struct Room Room;

/* Helper: The action performed when the switch is toggled. */
void SwitchPanel_toggle(WorldData *worldData, int indexs[]);

/* Build a "SwitchPanel" object */
Item* SwitchPanel_Build(int indexs[]);