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

	int top = atoi(argv[1]);
	for (int i = 0; i <= top; i++) {
		t.Add(i, i);
	}

	std::map<int, int> test_map;

	int time = 0;
	int map_time = 0;

	for (int i = 0; i <= 1000000; i++) {
		start = std::chrono::system_clock::now();
		t.Find(top);
		end = std::chrono::system_clock::now();
		time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

		// map
		start = std::chrono::system_clock::now();
		test_map.find(top);
		end = std::chrono::system_clock::now();
		map_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	std::cout << "AVL TIME: " << time << "\nMAP TIME: " << map_time << std::endl;
	return 0;
}