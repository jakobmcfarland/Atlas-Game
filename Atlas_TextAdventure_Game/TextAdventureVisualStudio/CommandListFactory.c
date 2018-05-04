/******************************************************************************
filename    CommandFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the CommandList factory, creating the commands used 
in this game.

All content © 2018 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* NULL */
#include "CommandListFactory.h" /* Function declarations */
#include "CommandList.h" /* CommandList and CommandList_Add */
#include "CommandHandlerFunctions.h" /* all Handle___Command functions */


/* Create the command list with all commands used in this game.*/
CommandList* CreateCommandList()
{
	/* The command list to be returned, starting empty */
	CommandList* commandList = NULL; 
	CommandList** cmdListPtr = &commandList;
	
	/*
	* NOTES: - Add the commands in the reverse of the order they'll be used, to reduce searching.
	*		 - Short alias commands do not show up in help.
	*/

	/* Create the "help" command */
	CommandList_Add(cmdListPtr, "help", HandleHelpCommand, true);
	/* TODO BASIC: add support for a short alias "h" */
	CommandList_Add(cmdListPtr, "h", HandleHelpCommand, false);

	/* Create the "quit" command */
	CommandList_Add(cmdListPtr, "quit", HandleQuitCommand, true);
	/* Create the "q" shotcut for the quit command */
	CommandList_Add(cmdListPtr, "q", HandleQuitCommand, false);

	/* Create the "drop" command */
	CommandList_Add(cmdListPtr, "drop", HandleDropCommand, true);
	/* Create the "d" shotcut for the drop command */
	CommandList_Add(cmdListPtr, "d", HandleDropCommand, false);

	/* Create the "take" command */
	CommandList_Add(cmdListPtr, "take", HandleTakeCommand, true);
	/* Create the "ta" shotcut for the take command */
	CommandList_Add(cmdListPtr, "ta", HandleTakeCommand, false);

	/* Create the "use" command */
	CommandList_Add(cmdListPtr, "use", HandleUseCommand, true);
	/* Create the "u" shotcut for the use command */
	CommandList_Add(cmdListPtr, "u", HandleUseCommand, false);

	/* Create the "look" command */
	CommandList_Add(cmdListPtr, "look", HandleLookCommand, true);
	/* Create the "l" shotcut for the look command */
	CommandList_Add(cmdListPtr, "l", HandleLookCommand, false);

	/* Create the "inventory" command */
	CommandList_Add(cmdListPtr, "inventory", HandleInventoryCommand, true);
	/* Create the "i" shotcut for the inventory command */
	CommandList_Add(cmdListPtr, "i", HandleInventoryCommand, false);

	/* Create the "go" command */
	CommandList_Add(cmdListPtr, "go", HandleGoCommand, true);
	/* Create the "g" shotcut for the go command */
	CommandList_Add(cmdListPtr, "g", HandleGoCommand, false);

	/* New Commands */

	/* Create the "toggle" command */
	CommandList_Add(cmdListPtr, "toggle", HandleToggleCommand, true);
	CommandList_Add(cmdListPtr, "flip", HandleToggleCommand, true);
	/* Create the "to" shortcut for the toggle command */
	CommandList_Add(cmdListPtr, "to", HandleToggleCommand, false);
	CommandList_Add(cmdListPtr, "f", HandleToggleCommand, false);

	/* Create the "breathe" command.*/
	CommandList_Add(cmdListPtr, "breathe", HandleBreathCommand, true);
	/* Create the "b" shortcut for the toggle command */
	CommandList_Add(cmdListPtr, "b", HandleBreathCommand, false);

	/* Create the "read" command */
	CommandList_Add(cmdListPtr, "read", HandleReadCommand, true);
	/* Create the "r" shortcut for the read command */
	CommandList_Add(cmdListPtr, "r", HandleReadCommand, false);

	/* return the newly created command list */
	return commandList;
}