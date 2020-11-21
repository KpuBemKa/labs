#pragma once
#include "mergeSort.h"

namespace ex2 {

	std::vector<int> nullElements;

	int searchVector(int position) {
		for (int i = 0; i < nullElements.size(); i++) {
			if (nullElements[i] == position)
				return i;
		}

		return -1;
	}

	std::vector<int> ex2(std::vector<int> arr, bool isAscending) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				nullElements.push_back(i);
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				arr.erase(arr.begin() + i);
			}
		}

		arr = sort::sort(arr, isAscending);

		int i = 0;
		while (i < arr.size()) {
			int searchingElementPosition = searchVector(i);

			if (searchingElementPosition > -1) {
				arr.insert(arr.begin() + i, 0);
			}

			i++;
		}

		return arr;
	}

}