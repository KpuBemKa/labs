#include "sort.h"

void showIntVector(std::vector<int> arr) {
	for (int i : arr)
		std::cout << i << " ";
	std::cout << "\n";
}

void showCharVector(std::vector<char> arr) {
	for (char i : arr)
		std::cout << i << " ";
	std::cout << "\n";
}

int main() {

	std::vector<int> intArr = { 49, 63, 64, 54, 98, 14, 67, 55, 60, 58 };
	std::vector<char> charArr = { 'B', 'F', 'E', 'H', 'A', 'C', 'I', 'D', 'G'};

	std::cout << "Vectorul initial:\n\t";
	showIntVector(intArr);
	intArr = intSort::intQuickSort(intArr, true);
	std::cout << "Vectorul sortat crescator:\n\t";
	showIntVector(intArr);

	intArr = intSort::intQuickSort(intArr, false);
	std::cout << "Vectorul sortat descrescator:\n\t";
	showIntVector(intArr);

	std::cout << "\n-================================-\n\n";

	std::cout << "Vectorul initial:\n\t";
	showCharVector(charArr);
	charArr = charSort::charQuickSort(charArr, true);
	std::cout << "Vectorul sortat descrescator:\n\t";
	showCharVector(charArr);

	charArr = charSort::charQuickSort(charArr, false);
	std::cout << "Vectorul sortat descrescator:\n\t";
	showCharVector(charArr);

}
