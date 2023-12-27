#pragma once

/*
This typedef is to remove explicit dependence of the calculation on double, float, etc.; instead,
the internals of Decimal can be altered to accommodate greater or lesser desired precision.
*/

typedef float Decimal;