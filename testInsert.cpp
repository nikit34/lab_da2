#include "TAvl.h"
#include <chrono>
#include <map>
#include <iostream>
#include <random>


int main(int argc, char** argv) {
	if (argc != 2) {
		return 0;
	}
	int top = atoi(argv[1]);
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::mt19937 generator(time(0));
	std::vector<int> randon_val(top);

	TAvl<int, int> t;
	std::map<int, int> test_map;

	for(int i = 0; i < top; ++i) {
		randon_val[i] = generator();
	}

	int time;
	int map_time;

	start = std::chrono::system_clock::now();
	for (int i = 0; i < top; ++i) {
		t.Add(randon_val[i], randon_val[i]);
	}
	end = std::chrono::system_clock::now();
	time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	start = std::chrono::system_clock::now();
	for (int i = 0; i < top; ++i) {
		test_map.insert({randon_val[i], randon_val[i]});
	}
	end = std::chrono::system_clock::now();
	map_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	std::cout << "AVL TIME: " << time << "\nMAP TIME: " << map_time << std::endl;
	return 0;
}