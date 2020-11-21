#include <iostream>
#include <vector>

void heapify(std::vector<int> arr, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(std::vector<int> arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(std::vector<int> arr) {
	for(int i : arr)
		std::cout << i << " ";
	std::cout << "\n";
}

int main() {
	int n;
	std::cout << "Dati numarul de membri:";
	std::cin >> n;

	std::vector<int> arr;
	int temp = -1;
	for (int i = 0; i < n; i++) {
		arr.push_back(1);
	}

	std::cout << "Candidatii cu numar impar voteaza PRO si cei cu numar par voteaza CONTRA!!\n";
	std::cout << "DACA SUNT MENTIONATI IN PERECHEA DE CONFLICT DE INTERESE\nDaca membrii nu au fost mentionati inseamna ca sunt PRO";
	std::cout << "\nPentru a termina introduceti 0";
	std::cout << "\nDati perechile:\n";

	while (temp != 0) {
		std::cin >> temp;
		if (temp == 0) {
			break;
		}
		if (temp % 2 != 0) {
			arr[temp] = 0;
		}
		else {
			arr[temp] = 1;
		}
	}

	heapSort(arr, n);

	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += arr[i];
	}

	if (suma >= n * 2 / 3) {
		std::cout << "Poate fi ales";
	}
	else {
		std::cout << "Nu poate fi ales";
	}
}

