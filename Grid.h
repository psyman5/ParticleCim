#pragma once
#define GRID_CLASS

#include <vector>
#include "PhysicsObject.h"
class Grid
{
public:
	int spacing{};
	int gridSize{};
	std::vector<std::vector<PhysicsObject>> physGrid{};

	Grid(int spacing, int gridSize) : spacing{ spacing }, gridSize{ gridSize } {};

	void createGrid(int gridSize, int spacing);

	void populateGrid(std::vector<PhysicsObject> objectVector);

	void checkNeighbors(int index);
};

