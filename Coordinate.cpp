#include "Coordinate.h"

Coordinate::Coordinate(const Decimal timeCoordinate, const Decimal xCoordinate,
	const Decimal yCoordinate, const Decimal zCoordinate) {
	coordinates[0] = timeCoordinate;
	coordinates[1] = xCoordinate;
	coordinates[2] = yCoordinate;
	coordinates[3] = zCoordinate;
}

const Coordinate Coordinate::operator+(const Coordinate& addedCoordinate) const {
	Coordinate coordinateSum = *this; // copy current Coordinate
	for (unsigned int index = 0; index < size; index++) {
		coordinateSum[index] +=  addedCoordinate[index];
	}
	return coordinateSum;
}

const Coordinate Coordinate::operator-(const Coordinate& subtractedCoordinate) const {
	Coordinate coordinateDifference = *this; // copy current Coordinate
	for (unsigned int index = 0; index < size; index++) {
		coordinateDifference[index] -= subtractedCoordinate[index];
	}
	return coordinateDifference;
}

const Coordinate Coordinate::operator*(const Decimal scaleFactor) const {
	Coordinate scaledCopyOfThisCoordinate = *this; // copy current coordinate
	for (unsigned int index = 0; index < size; index++) {
		scaledCopyOfThisCoordinate[index] *= scaleFactor;
	}
	return scaledCopyOfThisCoordinate;
}