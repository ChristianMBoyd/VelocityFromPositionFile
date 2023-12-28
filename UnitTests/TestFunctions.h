#pragma once
#include "RandomGenerator.h"
#include "../Coordinate.h"
#include "../Position.h"

namespace TestFunctions {

	// initialize random floats
	const int minPosition = -10000;
	const int maxPosition = 10000;
	extern RandomGenerator positionGenerator;

	float randomPositionValue();
	float randomTimeValue();
	Position randomPosition();
}
