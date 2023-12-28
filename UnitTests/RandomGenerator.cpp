#include "pch.h"
#include "RandomGenerator.h"

// defaults to random values within the unit line, (-1,1)
RandomGenerator::RandomGenerator() : randomMin(-1.0), randomMax(1.0) {
	initialize();
}

RandomGenerator::RandomGenerator(const float randomMin, const float randomMax) : randomMin(randomMin), randomMax(randomMax) {
	if (randomMin > randomMax) {
		this->randomMax = randomMin;
		this->randomMin = randomMax;
	}
	initialize();
}

void RandomGenerator::initialize() {
	distribution = std::uniform_real_distribution<float>(randomMin, randomMax);
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	randomEngine = std::default_random_engine(seed);
}

void RandomGenerator::setNewMinAndMax(const float randomMin, const float randomMax) {
	this->randomMin = randomMin;
	this->randomMax = randomMax;
	initialize();
}

float RandomGenerator::randomFloat() {
	return distribution(randomEngine);
}

int RandomGenerator::randomInt() {
	return int(randomFloat());
}