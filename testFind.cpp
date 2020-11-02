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

	TAvl<int, int> t;
	std::map<int, int> test_map;

	int tmp_val;
	for (int i = 0; i < top; ++i) {
		tmp_val = generator();
		t.Add(tmp_val, tmp_val);
		test_map.insert({tmp_val, tmp_val});
	}

	int time;
	int map_time;

	start = std::chrono::system_clock::now();
	for (int i = 0; i < top; ++i) {
		tmp_val = generator();
		t.Find(tmp_val);
	}
	end = std::chrono::system_clock::now();
	time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	// map
	start = std::chrono::system_clock::now();
	for (int i = 0; i < top; ++i) {
		tmp_val = generator();
		test_map.find(tmp_val);
	}
	end = std::chrono::system_clock::now();
	map_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	std::cout << "AVL TIME: " << time << "\nMAP TIME: " << map_time << std::endl;
	return 0;
}