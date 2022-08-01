#include "Game.h"

int main() {
	// ShowCursor(false);

	Game game;

	if (game.Construct(512, 384, 2, 2))
		game.Start();
	else
		wcout << L"Could not construct console" << endl;

	return 0;
}