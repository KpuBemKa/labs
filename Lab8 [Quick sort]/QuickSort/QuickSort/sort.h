#pragma once
#include <iostream>
#include <vector>
#include <fstream>

namespace sort {

	std::vector<int> sortingArray;

	void showArray(std::vector<int> arr) {
	    std::ofstream file("out.txt", std::ofstream::app);

		for (int i : arr)
			file << i << " ";
		file << "\n";
		file.close();
	}

	int ascendingPartition(int start, int end) {

		int pivot = sortingArray[end]; // pivot
		int i = start - 1; // Index of smaller element

		for (int j = start; j < end; j++)
		{
			// If current element is smaller than the pivot
			if (sortingArray[j] < pivot)
			{
				i++; // increment index of smaller element
				std::swap(sortingArray[i], sortingArray[j]);
				showArray(sortingArray);
			}
		}
		std::swap(sortingArray[i + 1], sortingArray[end]);
		return (i + 1);

	}

	void ascendingQuickSort(int start, int end) {

		if (start < end) {
			int pivot = ascendingPartition(start, end);

			ascendingQuickSort(start, pivot - 1);
			ascendingQuickSort(pivot + 1, end);
		}

	}

	int descendingPartition(int start, int end) {

		int pivot = sortingArray[end];
		int i = start - 1;

		for (int j = start; j < end; j++) {

			if (sortingArray[j] > pivot) {
				i++;
				std::swap(sortingArray[i], sortingArray[j]);
				showArray(sortingArray);
			}

		}
		std::swap(sortingArray[i + 1], sortingArray[end]);
		return i + 1;

	}

	void descendingQuickSort(int start, int end) {

		if (start < end) {
			int pivot = descendingPartition(start, end);

			descendingQuickSort(start, pivot - 1);
			descendingQuickSort(pivot + 1, end);
		}

	}

	void quickSort(std::vector<int> arr, bool isAscending) {
		sortingArray = arr;
		int n = sortingArray.size();
		descendingQuickSort(0, n - 1);

		showArray(sortingArray);
	}

}
