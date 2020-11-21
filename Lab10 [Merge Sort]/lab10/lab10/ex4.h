#pragma once
#include "mergeSort.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

struct fraction {
	int numerator;
	int denuminator;
	int gcd;
	double value;
};

namespace fractionSort {
	std::vector<fraction> sortingArray;

	void ascendingMerge(int l, int m, int r) {
		int leftSize = m - l + 1;
		int rightSize = r - m;

		std::vector<fraction> leftPart, rightPart;

		for (int i = 0; i < leftSize; i++) {
			leftPart.push_back(sortingArray[l + i]);
		}

		for (int j = 0; j < rightSize; j++) {
			rightPart.push_back(sortingArray[m + 1 + j]);
		}

		int i = 0;
		int j = 0;
		int k = l;

		while (i < leftSize && j < rightSize) {
			if (leftPart[i].value < rightPart[j].value) {
				sortingArray[k] = leftPart[i];
				i++;
			}
			else {
				sortingArray[k] = rightPart[j];
				j++;
			}
			k++;
		}

		while (i < leftSize) {
			sortingArray[k] = leftPart[i];
			i++;
			k++;
		}

		while (j < rightSize) {
			sortingArray[k] = rightPart[j];
			j++;
			k++;
		}
	}

	void ascendingMergeSort(int l, int r) {
		if (l < r) {
			int m = l + (r - l) / 2;

			ascendingMergeSort(l, m);
			ascendingMergeSort(m + 1, r);

			ascendingMerge(l, m, r);
		}
	}

	std::vector<fraction> sort(std::vector<fraction> arr) {
		sortingArray = arr;

		ascendingMergeSort(0, arr.size() - 1);

		return sortingArray;
	}
}

namespace ex4 {

	std::vector<fraction> fractions;

	int gcd(int a, int b) {
		if (a == 0)
			return b;
		if (b == 0)
			return a;

		if (a == b)
			return a;

		if (a > b)
			return gcd(a - b, b);
		return gcd(a, b - a);
	}

	void readData() {
		std::ifstream file("inEx4.txt");

		std::vector<std::vector<int>> arr;

		while (file.is_open()) {

			std::string line;

			while (getline(file, line)) {
				int value;
				std::vector<int> auxArr;
				std::stringstream lineStream(line);

				while (lineStream >> value) {
					auxArr.push_back(value);
				}

				arr.push_back(auxArr);
			}

			file.close();
		}

		for (int i = 0; i < arr[0].size(); i++) {
			fraction fraction;

			fraction.numerator = arr[0][i];
			fraction.denuminator = arr[1][i];
			fraction.gcd = gcd(fraction.denuminator, fraction.numerator);

			fractions.push_back(fraction);
		}
	}

	void eliminateNonDivisible() {
		for (int i = 0; i < fractions.size(); i++) {
			if (fractions[i].gcd == 1)
				fractions.erase(fractions.begin() + i);
		}

		for (int i = 0; i < fractions.size(); i++) {
			fractions[i].value = double(fractions[i].numerator) / double(fractions[i].denuminator);
		}
			
	}

	void writeData() {
		std::ofstream file("outEx4.txt");

		for (fraction f : fractions) {
			file << f.numerator << " ";
		}

		file << "\n";

		for (fraction f : fractions) {
			file << f.denuminator << " ";
		}
	}

	void ex4() {
		readData();

		eliminateNonDivisible();

		fractions = fractionSort::sort(fractions);

		writeData();
	}

}