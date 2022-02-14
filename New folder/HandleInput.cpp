#include "Game.h"

void Game::HandleInput(float fElapsedTime) {
	/* Mouse Handle */
	vMouse = { float(GetMouseX()), float(GetMouseY()) };
	vMouseCell = vMouse / vCellSize;
	vCell = vMouseCell; // implicit cast to integer, rounds down

	// Paint with left mouse button "solid" tiles
	if (GetMouse(0).bHeld) {
		sMap[vCell.y * vMapSize.x + vCell.x] = '#';

		vecSimulationSteps = { sMap };
		nSimulationStep = 0;
	}

	// Erase tiles with right mouse button or shift and left mouse button
	if (GetMouse(1).bHeld || (GetKey(olc::Key::SHIFT).bHeld && GetMouse(0).bHeld)) {
		sMap[vCell.y * vMapSize.x + vCell.x] = '.';

		vecSimulationSteps = { sMap };
		nSimulationStep = 0;
	}

	
	/* Simulation Handle */
	if (GetKey(olc::Key::MINUS).bPressed) nSimulationSpeed--;
	if (GetKey(olc::Key::EQUALS).bPressed) nSimulationSpeed++;

	if (GetKey(olc::Key::COMMA).bPressed) {
		if (GetKey(olc::Key::CTRL).bHeld) {
			nSimulationStep = 0;
		} else {
			if (nSimulationStep - 1 >= 0 && !vecSimulationSteps.empty()) {
				nSimulationStep--;
			}
		}
		sMap = vecSimulationSteps[nSimulationStep];
	}
	if (GetKey(olc::Key::PERIOD).bPressed) {
		if (GetKey(olc::Key::CTRL).bHeld) {
			nSimulationStep = vecSimulationSteps.size() - 1;
		} else {
			if (nSimulationStep + 1 < vecSimulationSteps.size()) {
				nSimulationStep++;
			}
		}
		sMap = vecSimulationSteps[nSimulationStep];
	}

	if (GetKey(olc::Key::SPACE).bPressed) {
		SimulationStep();
	}
	if (GetKey(olc::Key::O).bPressed && !bSimulationPlay) {
		bSimulationReverse = !bSimulationReverse;
		if (bSimulationReverse) bSimulationForward = false;
	}
	if (GetKey(olc::Key::P).bPressed && !bSimulationPlay) {
		bSimulationForward = !bSimulationForward;
		if (bSimulationForward) bSimulationReverse = false;
	}
	if (GetKey(olc::Key::ENTER).bPressed && 
		!(bSimulationForward || bSimulationReverse) && 
		nSimulationStep == vecSimulationSteps.size() - 1) {
		bSimulationPlay = !bSimulationPlay;
	}

	if (GetKey(olc::Key::BACK).bPressed) {
		sMap.clear();
		sMap.resize(vMapSize.x * vMapSize.y, '.');

		vecSimulationSteps = { sMap };
		nSimulationStep = 0;
	}

	if (GetKey(olc::Key::C).bPressed) {
		sMapCopy = sMap;
	}
	if (GetKey(olc::Key::V).bPressed) {
		sMap = sMapCopy;

		vecSimulationSteps = { sMap };
		nSimulationStep = 0;
	}

	// copy and paste
}