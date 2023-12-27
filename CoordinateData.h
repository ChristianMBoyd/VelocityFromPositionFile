#pragma once
#include <vector>

// This template provides the base structure to store coordinates.

template<class coordinate>
class CoordinateData {
private:
	std::vector<coordinate> coordinateData;

protected:
	CoordinateData() : coordinateData() {}

public:
	coordinate& operator[](int index) { return coordinateData[index]; }
	const coordinate& operator[](int index) const { return coordinateData[index]; }

	int size() const { return coordinateData.size(); }
	bool isEmpty() const { return coordinateData.empty(); }
	void appendCoordinate(const coordinate& nextCoordinate) { coordinateData.push_back(nextCoordinate); }
};