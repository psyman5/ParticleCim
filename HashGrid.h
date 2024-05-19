#pragma once
#ifndef HASH_GRID
#define HASH_GRID
#endif // !HASH_GRID

#include <vector>
#include "Vec2D.h"

class HashGrid
{
public:
	float spacing{};
	int objectCount{};
	int tableSize{ };
	std::vector<int> numParticlesInCell{};
	std::vector<int> particleMap;

	HashGrid(float spacing, int objectCount, int tableSize) : spacing{ spacing }, objectCount{ objectCount }, tableSize{ objectCount } {};

	Vec2D findIndex(std::vector<Vec2D> positionVector, int index);

	int hashFunction(Vec2D indexVector);

	void createGrid();
};

