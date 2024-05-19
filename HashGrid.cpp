#include "HashGrid.h"
#include <cmath>
#include "Vec2D.h"

Vec2D HashGrid::findIndex(std::vector<Vec2D> positionVector, int index) {
	float posX{ positionVector[index].getX() / spacing };
	float posY{ positionVector[index].getY() / spacing };
	
	Vec2D indexVector{ posX, posY };

	return indexVector;
};


int HashGrid::hashFunction(Vec2D indexVector) {
	
	int xi { static_cast<int>(floor(indexVector.getX() ) ) };
	int yi {static_cast<int>(floor(indexVector.getY() ) ) };


	int hash{ (xi * 92837111) ^ (yi * 689287499)};

	int modHash{ abs(hash) % tableSize};

	return modHash;

};

void HashGrid::createGrid() {
	for (int i = 0; i < tableSize; i++) {
		numParticlesInCell.push_back(0);
		particleMap.push_back(0);
	};

	int start{ 0 };

	for (int i = 0; i < tableSize; i++) {
		start += numParticlesInCell[i];
	};

};