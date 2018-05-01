
#include "PlayerStateFactory.h" /* Function declarations */
#include "PlayerState.h" /* struct GameState, GameState_Create */

/* Create the game state for a new game */
PlayerState* CreateInitialGameState()
{
	PlayerState* initialPlayerState; /* the new GameState object we will return */

								 /* create an empty GameState object */
	initialPlayerState = PlayerState_Create();

	/* the user starts with a score of 0 */
	initialPlayerState->breathe = 1;

	/* return the new object */
	return initialPlayerState;
}