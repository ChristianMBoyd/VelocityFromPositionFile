#include "pch.h" // connect to Google test tool
#include "../Coordinate.h"
#include "../Position.h"
#include "TestFunctions.h"

/*
Currently, the coordinate operations are being tested via the inherited class Position. Since 
Position only extends named accessors, the only distinction is implicitly testing these accessors.
*/

namespace {
	TEST(CoordinateTests, TestConstructor) {
		const float time = TestFunctions::randomTimeValue();
		const float x = TestFunctions::randomPositionValue();
		const float y = TestFunctions::randomPositionValue();
		const float z = TestFunctions::randomPositionValue();
		Position position(time, x, y, z);
		EXPECT_FLOAT_EQ(position.timeInSeconds(), time) << "assigned " 
			<< time << " returned " << position.timeInSeconds();
		EXPECT_FLOAT_EQ(position.xInMeters(), x) << "assigned "
			<< x << " returned " << position.xInMeters();
		EXPECT_FLOAT_EQ(position.yInMeters(), y) << "assigned "
			<< y << " returned " << position.yInMeters();
		EXPECT_FLOAT_EQ(position.zInMeters(), z) << "assigned "
			<< z << " returned " << position.zInMeters();
	}

	TEST(CoordinateTests, TestAddition) {
		const Position firstPosition = TestFunctions::randomPosition();
		const Position secondPosition = TestFunctions::randomPosition();
		const Position sumPosition = firstPosition + secondPosition;
		float sum = firstPosition.timeInSeconds() + secondPosition.timeInSeconds();
		EXPECT_FLOAT_EQ(sumPosition.timeInSeconds(), sum) << "Evaluated "
			<< firstPosition.timeInSeconds() << " - " << secondPosition.timeInSeconds()
			<< " as " << sumPosition.timeInSeconds();
		sum = firstPosition.xInMeters() + secondPosition.xInMeters();
		EXPECT_FLOAT_EQ(sumPosition.xInMeters(), sum) << "Evaluated "
			<< firstPosition.xInMeters() << " - " << secondPosition.xInMeters()
			<< " as " << sumPosition.xInMeters();
		sum = firstPosition.yInMeters() + secondPosition.yInMeters();
		EXPECT_FLOAT_EQ(sumPosition.yInMeters(), sum) << "Evaluated "
			<< firstPosition.yInMeters() << " - " << secondPosition.yInMeters()
			<< " as " << sumPosition.yInMeters();
		sum = firstPosition.zInMeters() + secondPosition.zInMeters();
		EXPECT_FLOAT_EQ(sumPosition.zInMeters(), sum) << "Evaluated "
			<< firstPosition.zInMeters() << " - " << secondPosition.zInMeters()
			<< " as " << sumPosition.zInMeters();
	}

	TEST(CoordinateTests, TestSubtraction) {
		const Position firstPosition = TestFunctions::randomPosition();
		const Position secondPosition = TestFunctions::randomPosition();
		const Position differencePosition = firstPosition - secondPosition;
		float difference = firstPosition.timeInSeconds() - secondPosition.timeInSeconds();
		EXPECT_FLOAT_EQ(differencePosition.timeInSeconds(), difference) << "Evaluated "
			<< firstPosition.timeInSeconds() << " - " << secondPosition.timeInSeconds()
			<< " as " << differencePosition.timeInSeconds();
		difference = firstPosition.xInMeters() - secondPosition.xInMeters();
		EXPECT_FLOAT_EQ(differencePosition.xInMeters(), difference) << "Evaluated "
			<< firstPosition.xInMeters() << " - " << secondPosition.xInMeters()
			<< " as " << differencePosition.xInMeters();
		difference = firstPosition.yInMeters() - secondPosition.yInMeters();
		EXPECT_FLOAT_EQ(differencePosition.yInMeters(), difference) << "Evaluated "
			<< firstPosition.yInMeters() << " - " << secondPosition.yInMeters()
			<< " as " << differencePosition.yInMeters();
		difference = firstPosition.zInMeters() - secondPosition.zInMeters();
		EXPECT_FLOAT_EQ(differencePosition.zInMeters(), difference) << "Evaluated "
			<< firstPosition.zInMeters() << " - " << secondPosition.zInMeters()
			<< " as " << differencePosition.zInMeters();
	}

	TEST(CoordinateTests, TestScalarMultiplication) {
		const Position position = TestFunctions::randomPosition();
		const float scaleFactor = TestFunctions::randomPositionValue();
		const Position scaledPosition = scaleFactor * position;
		float product = scaleFactor * position.timeInSeconds();
		EXPECT_FLOAT_EQ(scaledPosition.timeInSeconds(), product) << "Evaluated "
			<< scaleFactor << " * " << position.timeInSeconds() << " as "
			<< scaledPosition.timeInSeconds();
		product = scaleFactor * position.xInMeters();
		EXPECT_FLOAT_EQ(scaledPosition.xInMeters(), product) << "Evaluated "
			<< scaleFactor << " * " << position.xInMeters() << " as "
			<< scaledPosition.xInMeters();
		product = scaleFactor * position.yInMeters();
		EXPECT_FLOAT_EQ(scaledPosition.yInMeters(), product) << "Evaluated "
			<< scaleFactor << " * " << position.yInMeters() << " as "
			<< scaledPosition.yInMeters();
		product = scaleFactor * position.zInMeters();
		EXPECT_FLOAT_EQ(scaledPosition.zInMeters(), product) << "Evaluated "
			<< scaleFactor << " * " << position.zInMeters() << " as "
			<< scaledPosition.zInMeters();
	}
}