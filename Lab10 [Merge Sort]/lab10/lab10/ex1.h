#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "mergeSort.h"

namespace ex1 {

	int minIntervalNumber, maxIntervalNumber;
	std::vector<int> complexNumbers;

	void readData() {
		std::ifstream file("inEx1.txt");

		while (file.is_open()) {
			file >> minIntervalNumber >> maxIntervalNumber;

			int n;
			file >> n;

			std::string readData;
			for (int i = 0; i < n; i++) {
				file >> readData;

				readData.erase(readData.end());

				complexNumbers.push_back(std::stoi(readData));
			}

			for (int i : complexNumbers) {
				i = abs(i);
			}

			file.close();
		}
	}

	void writeData() {
		std::ofstream file("outEx1.txt");

		for (int i : complexNumbers) {
			if (i < minIntervalNumber || i > maxIntervalNumber)
				file << i << "i" << "\n";
		}

		file.close();
	}

	void ex1() {
		readData();

		complexNumbers = sort::sort(complexNumbers, false);

		writeData();
	}

}