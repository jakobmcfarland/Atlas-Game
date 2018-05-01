/*****
PlayerStateFactory.h
by: Jakob McFarland
last edited: 4/30/2018
brief: header for PlayerStateFactory.c
All content © 2018 DigiPen (USA) Corporation, all rights reserved.
*****/

#pragma once

typedef struct PlayerState PlayerState;

/* Create the game state for a new game */
PlayerState* CreateInitialPlayerState();