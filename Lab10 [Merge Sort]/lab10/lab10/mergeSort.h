#pragma once
#include <iostream>
#include <vector>

namespace sort {

	std::vector<int> sortingArray;

	void ascendingMerge(int l, int m, int r) {
		int leftSize = m - l + 1;
		int rightSize = r - m;

		std::vector<int> leftPart, rightPart;

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
			if (leftPart[i] < rightPart[j]) {
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

	void descendingMerge(int l, int m, int r) {
		int leftSize = m - l + 1;
		int rightSize = r - m;

		std::vector<int> leftPart, rightPart;

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
			if (leftPart[i] > rightPart[j]) {
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

	void descendingMergeSort(int l, int r) {
		if (l < r) {
			int m = l + (r - l) / 2;

			descendingMergeSort(l, m);
			descendingMergeSort(m + 1, r);

			descendingMerge(l, m, r);
		}
	}

	std::vector<int> sort(std::vector<int> arr, bool isAscending) {
		sortingArray = arr;
		int n = sortingArray.size();

		if (isAscending)
			ascendingMergeSort(0, n - 1);
		else
			descendingMergeSort(0, n - 1);

		return sortingArray;
	}

}