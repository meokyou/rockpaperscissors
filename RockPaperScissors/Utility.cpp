#include "Utility.h"

const std::int8_t Utility::Random(std::int8_t lowerBound, std::int8_t upperBound)
{
	return std::rand() % (upperBound - lowerBound + 1) + lowerBound;
}