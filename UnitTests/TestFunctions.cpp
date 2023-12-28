#include "pch.h"
#include "TestFunctions.h"

RandomGenerator TestFunctions::positionGenerator = RandomGenerator(TestFunctions::minPosition,
	TestFunctions::maxPosition);

float TestFunctions::randomPositionValue() {
	return positionGenerator.randomFloat();
}

float TestFunctions::randomTimeValue() {
	float randomValue = randomPositionValue();
	return std::abs(randomValue);
}

Position TestFunctions::randomPosition() {
	float time = randomTimeValue();
	float x = randomPositionValue();
	float y = randomPositionValue();
	float z = randomPositionValue();
	return Position(time, x, y, z);
}