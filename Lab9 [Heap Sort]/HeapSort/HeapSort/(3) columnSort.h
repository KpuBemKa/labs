#pragma once
#include <iostream>
#include <vector>
#include "(1) heapSort.h"

namespace columnSort {

	std::vector<std::vector<int>> matrixToSort;
	std::vector<std::vector<int>> columns;

	std::vector<std::vector<int>> sortMatrixRows(std::vector<std::vector<int>> arr) {
		for (int i = 0; i < arr.size(); i++) {
			if (i % 2 == 0)
				arr[i] = sort::ascHeapSort(arr[i]);
			else
				arr[i] = sort::descHeapSort(arr[i]);
		}

		return arr;
	}

	void getColumns() {
		std::vector<int> column;

		for (int i = 0; i < matrixToSort.size(); i++) {
			for (int j = 0; j < matrixToSort[0].size(); j++)
				column.push_back(matrixToSort[j][i]);
				columns.push_back(column);
			column.clear();
		}
	}

	std::vector<std::vector<int>> sort(std::vector<std::vector<int>> arr) {
		matrixToSort = arr;

		getColumns();

		columns = sortMatrixRows(columns);
		matrixToSort.clear();

		for (int i = 0; i < columns.size(); i++) {
			std::vector<int> column;
			for (int j = 0; j < columns[0].size(); j++) {
				column.push_back(columns[j][i]);
			}
			matrixToSort.push_back(column);
		}

		return matrixToSort;
	}

	void showMatrix(std::vector<std::vector<int>> arr) {
		for (std::vector<int> i : arr) {
			for (int j : i)
				std::cout << j << " ";
			std::cout << "\n";
		}
	}

}

	