#pragma once
#include "Position.h"
#include "CoordinateData.h"

// This typedef uses the CoordinateData template to dynamically store Position entries.

typedef CoordinateData<Position> PositionData;