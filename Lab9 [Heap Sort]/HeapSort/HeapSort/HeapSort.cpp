#include <iostream>
#include <vector>
using namespace std;

vector<int> maxHeapify(vector<int> X, int n, int i) {

	int maxim = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && X[l] > X[maxim])
		maxim = l;

	if (r < n && X[r] > X[maxim]) maxim = r;

	if (maxim != i) {
		swap(X[i], X[maxim]);
		maxHeapify(X, n, maxim);
	}

	return X;

}

vector<int> minHeapify(vector<int> X, int n, int i) {

	int maxim = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && X[l] < X[maxim])
		maxim = l;

	if (r < n && X[r] < X[maxim])
		maxim = r;

	if (maxim != i) {
		swap(X[i], X[maxim]);
		maxHeapify(X, n, maxim);
	}

	return X;
}

vector<int> ascHeapSort(vector<int> X) {

	int n = X.size();

	int i = n / 2 - 1;
	while (i >= 0){
		X = maxHeapify(X, n, i);

		i--;
	}

	i = n - 1;
	while (i >= 0){
		swap(X[0], X[i]);
		X = maxHeapify(X, i, 0);

		i--;
	}

	return X;

}

vector<int> descHeapSort(vector<int> X) {

	int n = X.size();

	int i = n / 2 - 1;
	while (i >= 0) {
		X = minHeapify(X, n, i);

		i--;
	}

	i = n - 1;
	while (i >= 0) {
		swap(X[0], X[i]);
		X = minHeapify(X, i, 0);

		i--;
	}

	return X;
}

void afisareMasiv(vector<int> X) {

	int n = X.size();

	int i = 0;
	while (i < n) {
		cout << X[i] << " ";

		i++;
	}
	cout << "\n";
}

void selector(vector<vector<int>> X) {

	int n = X.size();

	vector<int> Y;

	for (int i = 0; i < n; i++) {

		if (i % 2 == 0) {
			Y = ascHeapSort(X[i]);
			afisareMasiv(Y);
		}
		else {
			Y = descHeapSort(X[i]);
			afisareMasiv(Y);
		}

	}

}

vector<vector<int>> bidimensionalMaxHeapify(vector<vector<int>> X, int n, int m, int i) {

	int n = X.size();
	int m = X[0].size();

	int maxim = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && X[l] > X[maxim])
		maxim = l;

	if (r < n && X[r] > X[maxim])
		maxim = r;

	if (maxim != i) {
		swap(X[i], X[maxim]);
		bidimensionalMaxHeapify(X, n, m, maxim);
	}

	return X;

}

vector<vector<int>> bidimensionalHeapSort(vector<vect)

int main() {
	vector<vector<int>> X = { {1, 3, 2}, {5, 4, 6}, {9, 7, 8}, {11, 10, 12} };

	cout << "Masivul care trebuie sortat:\n";
	int i = 0;
	while (i < X.size()) {
		afisareMasiv(X[i]);

		i++;
	}



	cout << "Masivul sortat:\n";
	selector(X);
}
