#include "pch.h"
#include "TestFunctions.h"
#include "../PositionData.h"

/*
Currently, the CoordinateData template is being tested via PositionData, which is just a typedef
of CoordinateData<Position>.
*/

namespace {
	TEST(CoordinateDataTests, TestConstructor) {
		PositionData positionData; // check for error/exception
	}

	TEST(CoordinateDataTests, TestAppend) {
		PositionData positionData;
		Position position = TestFunctions::randomPosition();
		positionData.appendCoordinate(position); // check for error/exception
	}

	TEST(CoordinateDataTests, TestAccessorValue) {
		PositionData positionData;
		Position position = TestFunctions::randomPosition();
		positionData.appendCoordinate(position);
		Position storedPosition = positionData[0];
		EXPECT_FLOAT_EQ(position.timeInSeconds(), storedPosition.timeInSeconds()) <<
			"accessed time is not equal to appended value";
		EXPECT_FLOAT_EQ(position.xInMeters(), storedPosition.xInMeters()) <<
			"accessed x coordinate is not equal to appended value";
		EXPECT_FLOAT_EQ(position.yInMeters(), storedPosition.yInMeters()) <<
			"accessed y coordinate is not equal to appended value";
		EXPECT_FLOAT_EQ(position.zInMeters(), storedPosition.zInMeters()) <<
			"accessed z coordinate is not equal to appended value";
	}

	TEST(CoordinateDataTests, TestAccessorAssignment) {
		PositionData positionData;
		Position initialPosition = TestFunctions::randomPosition();
		positionData.appendCoordinate(initialPosition);
		Position position = TestFunctions::randomPosition();
		positionData[0] = position;
		Position storedPosition = positionData[0];
		EXPECT_FLOAT_EQ(position.timeInSeconds(), storedPosition.timeInSeconds()) <<
			"assigned time is not equal to new value";
		EXPECT_FLOAT_EQ(position.xInMeters(), storedPosition.xInMeters()) <<
			"assigned x coordinate is not equal to new value";
		EXPECT_FLOAT_EQ(position.yInMeters(), storedPosition.yInMeters()) <<
			"assigned y coordinate is not equal to new value";
		EXPECT_FLOAT_EQ(position.zInMeters(), storedPosition.zInMeters()) <<
			"assigned z coordinate is not equal to new value";
	}

	TEST(CoordinateDataTests, TestIsEmpty) {
		PositionData positionData;
		EXPECT_TRUE(positionData.isEmpty()) << "empty PositionData returns false isEmpty() call";
		Position position = TestFunctions::randomPosition();
		positionData.appendCoordinate(position);
		EXPECT_FALSE(positionData.isEmpty()) << "filled PostionData returns true isEmpty() call";
	}

	TEST(CoordinateDataTests, TestSize) {
		PositionData positionData;
		int counter = 0;
		for (int loops = 0; loops < 10; loops++) {
			float value = TestFunctions::randomPositionValue();
			if (value < 0) { continue; }
			Position position = TestFunctions::randomPosition();
			positionData.appendCoordinate(position);
			counter++;
		}
		EXPECT_EQ(counter, positionData.size()) << "PositionData.size() does not accurately"
			<< " count the number of entries";
	}
}