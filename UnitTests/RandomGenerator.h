#pragma once
#include <random>
#include <chrono>
#include <cmath>

// This is a basic RNG implementation for generating test cases

class RandomGenerator {
private:
	std::uniform_real_distribution<float> distribution;
	std::default_random_engine randomEngine;
	float randomMin, randomMax;

private:
	void initialize();

public:
	RandomGenerator();
	RandomGenerator(const float randomMin, const float randomMax);

	void setNewMinAndMax(const float randomMin, const float randomMax);

	float randomFloat();
	int randomInt();
};