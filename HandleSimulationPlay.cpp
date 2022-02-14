#include "Game.h"

void Game::HandleSimulationPlay(float fElapsedTime) {
	if (bSimulationPlay) { // Forward
		fSimulationCounter += (float)nSimulationSpeed * fElapsedTime;
		if (fSimulationCounter >= 1) {
			SimulationStep();
			fSimulationCounter = 0;
		}
	} else if (bSimulationForward) {
		fSimulationCounter += (float)nSimulationSpeed * fElapsedTime;
		if (fSimulationCounter >= 1) {
			if (nSimulationStep + 1 >= vecSimulationSteps.size()) {
				bSimulationForward = false;
			} else {
				nSimulationStep++;
				sMap = vecSimulationSteps[nSimulationStep];
			}
			fSimulationCounter = 0;
		}
	} else if (bSimulationReverse) { // Backward
		fSimulationCounter += (float)nSimulationSpeed * fElapsedTime;
		if (fSimulationCounter >= 1) {
			if (nSimulationStep - 1 < 0) {
				bSimulationReverse = false;
			} else {
				nSimulationStep--;
				sMap = vecSimulationSteps[nSimulationStep];
			}
			fSimulationCounter = 0;
		}
	} else {
		fSimulationCounter = 0;
	}
}