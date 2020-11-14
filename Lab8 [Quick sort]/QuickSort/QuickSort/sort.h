#pragma once
#include <iostream>
#include <vector>
#include <fstream>

namespace intSort {

	std::vector<int> sortingArray;

	int ascendingIntPartition(int start, int end) {
		int pivot = sortingArray[end];
		int i = start - 1;

		for (int j = start; j < end; j++) {
			if (sortingArray[j] < pivot) {
				std::swap(sortingArray[++i], sortingArray[j]);
			}
		}

		std::swap(sortingArray[i + 1], sortingArray[end]);
		return (i + 1);
	}

	void ascendingIntQuickSort(int start, int end) {
		if (start < end) {
			int pivot = ascendingIntPartition(start, end);

			ascendingIntQuickSort(start, pivot - 1);
			ascendingIntQuickSort(pivot + 1, end);
		}
	}

	int descendingIntPartition(int start, int end) {
		int pivot = sortingArray[end];
		int i = start - 1;

		for (int j = start; j < end; j++) {
			if (sortingArray[j] > pivot) {
				std::swap(sortingArray[++i], sortingArray[j]);
			}
		}

		std::swap(sortingArray[i + 1], sortingArray[end]);
		return i + 1;
	}

	void descendingIntQuickSort(int start, int end) {
		if (start < end) {
			int pivot = descendingIntPartition(start, end);

			descendingIntQuickSort(start, pivot - 1);
			descendingIntQuickSort(pivot + 1, end);
		}
	}

	std::vector<int> intQuickSort(std::vector<int> arr, bool isAscending) {
		sortingArray = arr;
		int n = sortingArray.size();

		if (isAscending) {
			ascendingIntQuickSort(0, n - 1);
		}
		else {
			descendingIntQuickSort(0, n - 1);
		}

		return sortingArray;
	}

}

namespace charSort {

	std::vector<char> sortingArray;

	int ascendingCharPartition(int start, int end) {
		int pivot = sortingArray[end];
		int i = start - 1;

		for (int j = start; j < end; j++) {
			if (sortingArray[j] < pivot) {
				std::swap(sortingArray[++i], sortingArray[j]);
			}
		}

		std::swap(sortingArray[i + 1], sortingArray[end]);
		return (i + 1);
	}

	void ascendingCharQuickSort(int start, int end) {
		if (start < end) {
			int pivot = ascendingCharPartition(start, end);

			ascendingCharQuickSort(start, pivot - 1);
			ascendingCharQuickSort(pivot + 1, end);
		}
	}

	int descendingCharPartition(int start, int end) {
		int pivot = sortingArray[end];
		int i = start - 1;

		for (int j = start; j < end; j++) {
			if (sortingArray[j] > pivot) {
				std::swap(sortingArray[++i], sortingArray[j]);
			}
		}

		std::swap(sortingArray[i + 1], sortingArray[end]);
		return i + 1;
	}

	void descendingCharQuickSort(int start, int end) {
		if (start < end) {
			int pivot = descendingCharPartition(start, end);

			descendingCharQuickSort(start, pivot - 1);
			descendingCharQuickSort(pivot + 1, end);
		}
	}

	std::vector<char> charQuickSort(std::vector<char> arr, bool isAscending) {
		sortingArray = arr;
		int n = sortingArray.size();

		if (isAscending) {
			ascendingCharQuickSort(0, n - 1);
		}
		else {
			descendingCharQuickSort(0, n - 1);
		}

		return sortingArray;
	}

}