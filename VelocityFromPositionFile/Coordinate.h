#pragma once
#include "Decimal.h"
#include <array>

/*
This is the basic object for storing and manipulating coordinates.  Values are stored according
to the typedef Decimal.  Basic vector algebra is included to simplify finite-difference and linear
interpolation calculations.  When deferring to the base constructor here, the coordinates are
organized as (t,x,y,z)<->(0,1,2,3).
*/

class Coordinate {
private:
	static constexpr unsigned int size = 4; // only considering 4-vectors
	std::array<Decimal, size> coordinates = { 0,0,0,0 }; // purely storage container

protected:
	Coordinate() {} // default to zero values
	Coordinate(const Decimal timeCoordinate, const Decimal xCoordinate, const Decimal yCoordinate,
		const Decimal zCoordinate); // copy values into coordinates array

	// accessors for derived labels
	const Decimal& operator[](int index) const { return coordinates[index]; }
	Decimal& operator[](int index) { return coordinates[index]; }
	
public: // vector algebra, used by all
	const Coordinate operator+(const Coordinate& addedCoordinate) const;
	const Coordinate operator-(const Coordinate& subtractedCoordinate) const;
	const Coordinate operator*(const Decimal scaleFactor) const;
};

// defers scalar multiplication to the right-wise method defined in Coordinate
inline Coordinate operator*(const Decimal scaleFactor, const Coordinate& coordinate) {
	return coordinate * scaleFactor;
}