#include "Grid.h"
#include <vector>
#include "PhysicsObject.h"
#include <cmath>
void Grid::createGrid(int gridSize, int spacing) {

	for (int i; i < floor(gridSize / spacing); i++) {
		std::vector<PhysicsObject> cell{};
		physGrid.push_back(cell);
	}
	return;
};

void Grid::populateGrid(std::vector<PhysicsObject> objectVector) {

	for (int i = 0; i < objectVector.size(); i++) {
		PhysicsObject physObj{ objectVector[i] };

		int xi{ static_cast<int>(floor(physObj.getCurrentPosition().getX() / spacing)) };
		int yi{ static_cast<int>(floor(physObj.getCurrentPosition().getY() / spacing)) };

		int index{ static_cast<int>(xi * gridSize + yi) };

		physGrid[index].push_back(physObj);
	};
	return;
};

void Grid::checkNeighbors(int index) {
	//TODO: CHECK NEIGHBORS, IMPLEMENT CODE TO CHECK NEIGHBOR CELLS WHEN
	//		NEAR BORDERS AND CORNERS (9)
	return;
};