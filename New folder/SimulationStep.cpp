#include "Game.h"
#include <unordered_set>

void Game::SimulationStep() {
	string sUpdatedMap;
	sUpdatedMap.resize(vMapSize.x * vMapSize.y, '.');

	for (int y = 0; y < vMapSize.y; y++) {
		for (int x = 0; x < vMapSize.x; x++) {
			int nCurCell = y * vMapSize.x + x;

			/*
				0  -1, -1  top left
				1  -1,  0  left
				2  -1,  1  bottom left
				3   0, -1  top
				4   0,  1  bottom
				5   1, -1  top right
				6   1,  0  right
				7   1,  1  bottom right
			*/
			vector<int> vecNeighbours = {
				(y - 1) * vMapSize.x + (x - 1), y * vMapSize.x + (x - 1), (y + 1) * vMapSize.x + (x - 1),
				(y - 1) * vMapSize.x + x, (y + 1) * vMapSize.x + x,
				(y - 1) * vMapSize.x + (x + 1), y * vMapSize.x + (x + 1), (y + 1) * vMapSize.x + (x + 1),
			};

			unordered_set<int> setSkipNeighbour;
			if (x <= 0) {
				setSkipNeighbour.insert(0);
				setSkipNeighbour.insert(1);
				setSkipNeighbour.insert(2);
			}
			if (y <= 0) {
				setSkipNeighbour.insert(0);
				setSkipNeighbour.insert(3);
				setSkipNeighbour.insert(5);
			}
			if (x >= vMapSize.x - 1) {
				setSkipNeighbour.insert(5);
				setSkipNeighbour.insert(6);
				setSkipNeighbour.insert(7);
			}
			if (y >= vMapSize.y - 1) {
				setSkipNeighbour.insert(2);
				setSkipNeighbour.insert(4);
				setSkipNeighbour.insert(7);
			}

			int numNeighbours = 0;
			for (int i = 0; i < vecNeighbours.size(); i++) {
				if (setSkipNeighbour.find(i) != setSkipNeighbour.end()) continue;
				if (sMap[vecNeighbours[i]] == '#') {
					numNeighbours++;
				}
			}

			if (sMap[nCurCell] == '#' && (numNeighbours == 2 || numNeighbours == 3)) {
				sUpdatedMap[nCurCell] = '#';
			} else if (sMap[nCurCell] == '.' && numNeighbours == 3) {
				sUpdatedMap[nCurCell] = '#';
			} else if (sMap[nCurCell] == '#') {
				sUpdatedMap[nCurCell] = '.';
			} else {
				sUpdatedMap[nCurCell] = '.';
			}
		}
	}

	sMap = sUpdatedMap;

	if (nSimulationStep == vecSimulationSteps.size() - 1) {
		vecSimulationSteps.push_back(sMap);
		nSimulationStep = vecSimulationSteps.size() - 1;
	}
}