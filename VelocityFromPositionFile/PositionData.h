#pragma once
#include "Position.h"
#include "CoordinateData.h"

/*
This typedef uses the CoordinateData template to store Position objects in a fixed order.
*/

typedef CoordinateData<Position> PositionData;