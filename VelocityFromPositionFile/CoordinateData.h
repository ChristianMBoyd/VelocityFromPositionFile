#pragma once
#include <vector>

/*
This is the basic object used to store coordinate data, which is specified by the template 
parameter.  Only essential operations are provided, with inherited classes defining their own 
useful constructors.
*/

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