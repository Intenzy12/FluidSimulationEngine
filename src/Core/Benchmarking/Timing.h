#pragma once
#include "Core/Benchmarking/Timing.h"
#include <chrono>
#include <functional>

class Timer
{
public: 
	Timer(std::function<void(long long)> callbackFunction): start(std::chrono::high_resolution_clock::now()), callbackFunction(callbackFunction)
	{
	}

	~Timer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		callbackFunction(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::function<void(long long)> callbackFunction;
};
