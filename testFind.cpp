#include "TAvl.h"
#include <chrono>
#include <map>
#include <iostream>


int main(int argc, char** argv) {
	if (argc != 2) {
		return 0;
	}
	std::chrono::time_point<std::chrono::system_clock> start, end;

	TAvl<int, int> t;
	std::map<int, int> test_map;

	int top = atoi(argv[1]);
	for (int i = 0; i <= top; i++) {
		t.Add(i, i);
		test_map.insert({i, i});
	}

	int time = 0;
	int map_time = 0;

	start = std::chrono::system_clock::now();
	for (int i = 0; i <= 1000000; i++) {
		t.Find(top);
	}
	end = std::chrono::system_clock::now();
	time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	// map
	start = std::chrono::system_clock::now();
	for (int i = 0; i <= 1000000; i++) {
		test_map.find(top);
	}
	end = std::chrono::system_clock::now();
	map_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	std::cout << "AVL TIME: " << time << "\nMAP TIME: " << map_time << std::endl;
	return 0;
}