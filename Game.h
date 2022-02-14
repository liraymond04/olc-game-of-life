#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "olcPixelGameEngine.h"

class Game : public olc::PixelGameEngine {
public:
	Game() {
		sAppName = "Conway's Game of Life";
	}

private:
	/* Map */
	olc::vi2d vMapSize = { 32, 24 };
	olc::vi2d vCellSize = { 16, 16 };
	string sMap;

	/* Mouse */
	olc::vf2d vMouse;
	olc::vf2d vMouseCell;
	olc::vi2d vCell;
	olc::Sprite* sprMouse;

	/* Simulation */
	int nSimulationStep = 0;
	float fSimulationCounter = 0;

	int nSimulationSpeed = 10;
	bool bSimulationPlay = false;

	bool bSimulationForward = false;
	bool bSimulationReverse = false;

	string sMapCopy = "";

	vector<string> vecSimulationSteps;

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void HandleInput(float fElapsedTime);
	void Draw();

	void HandleSimulationPlay(float fElapsedTime);
	void SimulationStep();
};

#endif // !GAME_H