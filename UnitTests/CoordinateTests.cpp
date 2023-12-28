#include "pch.h" // connect to Google test tool
#include "../Coordinate.h"
#include "../Position.h"
#include "RandomGenerator.h"

namespace CoordinateTests { // local functions and names

	// initialize random floats
	const int minPosition = -10000;
	const int maxPosition = 10000;
	RandomGenerator positionGenerator(minPosition, maxPosition);
	TEST(CoordinateTests, TestConstructor) {
		const float time = std::abs(positionGenerator.randomFloat());
		const float x = positionGenerator.randomFloat();
		const float y = positionGenerator.randomFloat();
		const float z = positionGenerator.randomFloat();
		Position position(time, x, y, z);
		EXPECT_FLOAT_EQ(position.timeInSeconds(), time) << "assigned " 
			<< time << " returned " << position.timeInSeconds();
	}

}