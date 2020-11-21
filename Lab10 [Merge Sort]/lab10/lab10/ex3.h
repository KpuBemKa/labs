#pragma once
#include "mergeSort.h"
#include <fstream>
#include <string>
#include <sstream>

namespace ex3 {

	std::vector<int> numbers;

	void readData() {
		std::ifstream file("inEx3.txt");

		while (file.is_open()) {
			std::string line;

			while (std::getline(file, line)) {
				int value;
				std::stringstream lineStream(line);

				while (lineStream >> value) {
					numbers.push_back(value);
				}
			}

			file.close();
		}
	}

	void writeData() {
		std::ofstream file("outEx3.txt");

		for (int i : numbers)
			file << i << " ";
	}

	void ex3() {
		readData();

		for (int i = 0; ; i++) {
			if (i >= numbers.size() - 1)
				break;

			if (numbers[i] > 0) {
				numbers.erase(numbers.begin() + i);
			}
		}

		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] % 2 != 0) {
				numbers.erase(numbers.begin() + i);
				i--;
			}
		}

		if (numbers.begin() == numbers.end()) {
			std::cout << "NU EXISTA";
			return;
		}

		numbers = sort::sort(numbers, true);

		writeData();
	}
}