#ifndef BENCH_HPP
#define BENCH_HPP

#pragma once

#include "../deps.hpp"
#include "../geometry/geometry.hpp"
#include "../types/types.hpp"
#include "../draw.hpp"

class Benchmark
{
private:

	ofstream output;
	unsigned long long operation;
	clock_t execution_time;
	clock_t setup_time;

public:
	Benchmark(string fname);
	~Benchmark();

	void log(string message);
};

Benchmark::Benchmark(string fname)
{
	output.open(fname.c_str());
	operation = 0;
	setup_time = clock();
}

Benchmark::~Benchmark()
{
	output.close();
}

#endif	//	BENCH_HPP



//	TODO:
//
//
//
