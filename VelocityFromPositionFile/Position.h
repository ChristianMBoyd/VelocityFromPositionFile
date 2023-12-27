#pragma once
#include "Decimal.h"
#include "Coordinate.h"

// This object extends the Coordinate class to store positions, with named component accessors.

struct Position : Coordinate {
	Position() : Coordinate() {}
	Position(const Decimal timeInSeconds, const Decimal xInMeters, const Decimal yInMeters,
		const Decimal zInMeters) :
		Coordinate(timeInSeconds, xInMeters, yInMeters, zInMeters) {}
	Position(const Coordinate& coordinate) : Coordinate(coordinate) {}

	// name-qualified accessors

	const Decimal& timeInSeconds() const { return operator[](0); }
	Decimal& timeInSeconds() { return operator[](0); }

	const Decimal& xInMeters() const { return operator[](1); }
	Decimal& xInMeters() { return operator[](1); }

	const Decimal& yInMeters() const { return operator[](2); }
	Decimal& yInMeters() { return operator[](2); }

	const Decimal& zInMeters() const { return operator[](3); }
	Decimal& zInMeters() { return operator[](3); }
};