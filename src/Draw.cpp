#include "Game.h"

void Game::Draw() {
	Clear(olc::BLACK);
	SetPixelMode(olc::Pixel::MASK);

	// Draw Map
	for (int y = 0; y < vMapSize.y; y++) {
		for (int x = 0; x < vMapSize.x; x++) {
			char cell = sMap[y * vMapSize.x + x];
			if (cell == '#')
				FillRect(olc::vi2d(x, y) * vCellSize, vCellSize, olc::GREEN);

			// Draw Cell border
			DrawRect(olc::vi2d(x, y) * vCellSize, vCellSize, olc::DARK_GREY);
		}
	}

	DrawString({ 10, 5 }, to_string(nSimulationSpeed) + " " + to_string(nSimulationStep), olc::WHITE);

	// Draw Mouse
	// FillCircle(vMouse, 4.0f, olc::RED);
	DrawSprite(vMouse, sprMouse);
}