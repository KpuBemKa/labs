#pragma once
#include <iostream>
#include <vector>

namespace sort {

	std::vector<int> maxHeapify(std::vector<int> X, int n, int i) {

		int maxim = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && X[l] > X[maxim])
			maxim = l;

		if (r < n && X[r] > X[maxim]) maxim = r;

		if (maxim != i) {
			std::swap(X[i], X[maxim]);
			maxHeapify(X, n, maxim);
		}

		return X;

	}

	std::vector<int> minHeapify(std::vector<int> X, int n, int i) {

		int maxim = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && X[l] < X[maxim])
			maxim = l;

		if (r < n && X[r] < X[maxim])
			maxim = r;

		if (maxim != i) {
			std::swap(X[i], X[maxim]);
			maxHeapify(X, n, maxim);
		}

		return X;
	}

	std::vector<int> ascHeapSort(std::vector<int> X) {

		int n = X.size();

		int i = n / 2 - 1;
		while (i >= 0) {
			X = maxHeapify(X, n, i);

			i--;
		}

		i = n - 1;
		while (i >= 0) {
			std::swap(X[0], X[i]);
			X = maxHeapify(X, i, 0);

			i--;
		}

		return X;

	}

	std::vector<int> descHeapSort(std::vector<int> X) {

		int n = X.size();

		int i = n / 2 - 1;
		while (i >= 0) {
			X = minHeapify(X, n, i);

			i--;
		}

		i = n - 1;
		while (i >= 0) {
			std::swap(X[0], X[i]);
			X = minHeapify(X, i, 0);

			i--;
		}

		return X;
	}

}